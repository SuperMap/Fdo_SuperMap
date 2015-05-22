/* 
	\file UGPMedian.h
	\brief MTSP分析需要一个类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(UGPMEDIAN_H)
#define UGPMEDIAN_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"

namespace UGC {

class   BossaRandom 
{
	/* Period parameters */  
#define BOSSARANDOMN 624
#define BOSSARANDOMM 397
#define MATRIX_A 0x9908b0df   /* constant vector a */
#define UPPER_MASK 0x80000000 /* most significant w-r bits */
#define LOWER_MASK 0x7fffffff /* least significant r bits */
	
	/* Tempering parameters */   
#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y)  (y >> 11)
#define TEMPERING_SHIFT_S(y)  (y << 7)
#define TEMPERING_SHIFT_T(y)  (y << 15)
#define TEMPERING_SHIFT_L(y)  (y >> 18)
	
	static UGuint mt[BOSSARANDOMN]; /* the array for the state vector  */
	static  UGint mti; /* mti==N+1 means mt[N] is not initialized */
	
	/* initializing the array with a NONZERO seed */
	static void sgenrand(UGuint seed) 
	{
		mt[0]= seed & 0xffffffff;
		for (mti=1; mti<BOSSARANDOMN; mti++)
			mt[mti] = (69069 * mt[mti-1]) & 0xffffffff;
	}
	
	static UGuint genrand() 
	{
		UGuint y;
		static UGuint mag01[2]={0x0, MATRIX_A};
		
		if (mti >= BOSSARANDOMN) { /* generate N words at one time */
			 UGint kk;
			
			if (mti == BOSSARANDOMN+1)   /* if sgenrand() has not been called, */
				sgenrand(4357); /* a default initial seed is used   */
			
			for (kk=0;kk<BOSSARANDOMN-BOSSARANDOMM;kk++) {
				y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
				mt[kk] = mt[kk+BOSSARANDOMM] ^ (y >> 1) ^ mag01[y & 0x1];
			}
			for (;kk<BOSSARANDOMN-1;kk++) {
				y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
				mt[kk] = mt[kk+(BOSSARANDOMM-BOSSARANDOMN)] ^ (y >> 1) ^ mag01[y & 0x1];
			}
			y = (mt[BOSSARANDOMN-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
			mt[BOSSARANDOMN-1] = mt[BOSSARANDOMM-1] ^ (y >> 1) ^ mag01[y & 0x1];
			
			mti = 0;
		}
		
		y = mt[mti++];
		y ^= TEMPERING_SHIFT_U(y);
		y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
		y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
		y ^= TEMPERING_SHIFT_L(y);
		
		return y; 
	}
	
public:
	static void randomize (UGuint s) 
	{
		if (s == 0) randomize();
		else sgenrand(s);
	}
	
#ifdef Bossa_UNIX
	static void randomize() {randomize (UGuint(time(NULL) + getpid()));/*time(NULL) + getpid());*/}
#else
	static void randomize() {randomize (UGuint(time(NULL)));/*randomize (time(NULL));*/}
#endif
	
	BossaRandom () {randomize();}
	static UGuint getRand () {return genrand();}
	
	static UGuint getNonZero () {
		UGuint u;
		do {u = getRand();} while (u==0);
		return u;
	}
	
	static  UGint getInteger ( UGint inf,  UGint sup) 
	{
		 UGint i = (inf + (UGuint)getRand() % (sup - inf + 1));
		return i;
	}
	
	static float getFloat () 
	{
		float f = (float) ((float)(getRand()) / (UGuint)0xffffffff);
		return f;
	}
	
	static UGdouble getDouble () 
	{
		return ((UGdouble)getRand() / (UGuint)0xffffffff);
	}
};


class   PMInstance 
{
	protected:
		enum {NOMETRIC, MATRIX, EUCLIDEAN, GEO, HYBRID}; 
		virtual  UGint getMetric() = 0;

	public:
		PMInstance() {};
		PMInstance(PMInstance *original,  UGint *of,  UGint *oc) {};
		virtual ~PMInstance() {};
		virtual  UGint *getCloser ( UGint i, UGdouble v) = 0;
		virtual void setP ( UGint _p) = 0;
		virtual UGdouble getFacDist ( UGint f,  UGint g) = 0;		
		virtual UGdouble getDist    ( UGint u,  UGint f) = 0;
		virtual  UGint getM() = 0; 
		virtual  UGint getN() = 0;
		virtual  UGint getP() = 0; 
		virtual UGdouble getFloydTime() {return 0.0;}
		virtual UGdouble getOracleTime() {return 0.0;}
};

class   PMConfig 
{
	public:
		//------------
		// parameters
		//------------
		 UGint graspit;        //grasp iterations
		 UGint tabuit;         //tabu iterations
		UGdouble itenure;     //maximum tenure for insertion moves in tabu
		UGdouble rtenure;     //maximum tenure for removal moves in tabu
		UGdouble alpha;       //randomization factor in greedy algorithm
		 UGint elite;          //size of the pool of elite solutions
		UGbool grasp_fi;	    //execute fast interchange instead of local search?
		UGbool pair_search;   //execute pair search after local search?
		UGbool output;        //output file with solution?
		UGchar outname [256]; //name of the output file
		UGchar ch [256];      //constructive heuristic
		UGbool run_grasp;     //run grasp?
		UGbool run_tabu;      //run tabu search?
		UGbool run_mst;		//run mst constructive heuristic?
		UGbool run_greedy;    //run greedy algorithm?
		UGbool run_pgreedy;   //run proportional greedy algorithm?
		UGbool run_random;    //run random algorithm?
		UGbool run_pworst;    //run smart random?
		UGbool run_vns;       //run full vns? (HM)
		UGbool run_vnds;      //run vnds? (HM)
		UGbool run_rvns;      //run rvns?
		UGbool run_rpg;       //run RPG (random plus greedy)?
		UGbool test_pr;       //test path-relinking?
		UGbool run_preverse;   //run randomized reverse greedy algorithm?
		UGbool use_mix;       //use mix of constructive algorithms?
		 UGint tc;             //number of rounds in routine to test constr. heuristics (if positive)
		UGdouble rpg;         //factor to use in randomized greedy   
		UGdouble run_sample;      //run sample constructive algorithm?
		UGdouble sample_fraction; //fraction of the options to be sampled by the algorithm
		
		UGbool partials;      //print partial results?
		UGbool postopt;       //execute post-optimization?
		UGbool tls;           //test local search?
		UGdouble tlstime;       //mintime for local search test

		UGdouble cf;  //cache factor; used in the local search
					//size of cache (for nearby facilities) will be ceil (cf * m / p)
					//if cf < 0, will use m

		UGchar ls [256];  //local search method
		UGchar cmg [256]; //combination meathod used by GRASP
		UGchar cmp [256]; //combination method used in the post-optimization phase				

		 UGint vns_k;          //max k for vns

		 UGint vnds_k;         //max k for vnds
		 UGint vnds_b;         //max b for vnds

		 UGint rvns_k;         //max k for rvns
		 UGint rvns_r;         //max r for rvns
		
		 UGint pvalue;         //command-line specified value for p
		 UGint seed;           //random seed
		
		PMConfig();
		
		UGchar **argv;
		 UGint argc;
		 UGint arg; //current argument being read
		
		UGbool readBool (const UGchar *field, UGbool &variable, UGbool value = true) 
		{
			if (strcmp (argv[arg], field)==0) 
			{
				variable = value;
				arg++;
				return true;
			}
			return false;
		}

		UGbool readInt (const UGchar *field,  UGint &variable) 
		{
			if (strcmp (argv[arg], field)==0) 
			{
				arg++;
				if (arg==argc) 
				{
				//	fprintf (stderr, "WARNING: Option %s requires an input parameter.\n", field);
					return false;
				}
				variable = atoi (argv[arg]);
				arg++;
				return true;
			}
			return false;
		}				

		UGbool readChar (const UGchar *field, UGchar &variable) {
			if (strcmp (argv[arg], field)==0) {
				arg++;
				if (arg==argc) {
					fprintf (stderr, "WARNING: Option %s requires a UGchar parameter.\n", field);
					return false;
				}
				variable = argv[arg][0];
				arg++;
				return true;
			}
			return false;
		}

		UGbool readDouble (const UGchar *field, UGdouble &variable) {
			if (strcmp (argv[arg], field)==0) {
				arg++;
				if (arg==argc) {
					fprintf (stderr, "WARNING: Option %s requires a UGdouble value.\n", field);
					return false;
				}
				variable = atof (argv[arg]);
				arg++;
				return true;
			}
			return false;
		}

		UGbool readString (const UGchar *field, UGchar *variable) {
			if (strcmp (argv[arg], field)==0) {
				arg++;
				if (arg==argc) {
					fprintf (stderr, "WARNING: Options %s requires a string value.\n", field);
					return false;
				}
				strcpy (variable, argv[arg]);
				arg++;
				return true;
			}
			return false;
		}
};

class   IntDouble 
{
	public:
		 UGint id;
		UGdouble value;
		static  UGint compare (const void *_a, const void *_b);
};

inline  UGint operator < (IntDouble c1, IntDouble c2) {return (c1.value < c2.value);}
inline  UGint operator <= (IntDouble c1, IntDouble c2) {return (c1.value < c2.value);}
inline  UGint operator == (IntDouble c1, IntDouble c2) {return (c1.value == c2.value);}
inline  UGint operator >= (IntDouble c1, IntDouble c2) {return (c1.value >= c2.value);}
inline  UGint operator > (IntDouble c1, IntDouble c2) {return (c1.value > c2.value);}

class   UnsignedIntPair 
{
	public:
		UGuint a;
		UGuint b;
};

inline  UGint operator < (UnsignedIntPair x, UnsignedIntPair y) {
	return (x.a<y.a || (x.a==y.a && x.b<y.b));
}

inline  UGint operator <= (UnsignedIntPair x, UnsignedIntPair y) {
	return (x.a<y.a || (x.a==y.a && x.b<=y.b));
}

inline  UGint operator > (UnsignedIntPair x, UnsignedIntPair y) {
	return (x.a>y.a || (x.a==y.a && x.b>y.b));
}

inline  UGint operator >= (UnsignedIntPair x, UnsignedIntPair y) {
	return (x.a>y.a || (x.a==y.a && x.b>=y.b));
}

inline  UGint operator == (UnsignedIntPair x, UnsignedIntPair y) {
	return (x.a==y.a && x.b==y.b);
}


/***********************************************
 *
 * aux function: randomly permutes the first n
 * elements of vector v (starting at 1)
 *
 ***********************************************/

class   RFW 
{
	public: 
		static void fatal (const UGchar *fund, const UGchar *msg);		
		static void shuffle ( UGint *v,  UGint n);
		static  UGint getRank (UGdouble *v,  UGint size,  UGint pos);
		static  UGint argmin (UGdouble *v,  UGint p1,  UGint p2);
		static  UGint getWeightedIndex (UGdouble *v,  UGint p1,  UGint p2, UGdouble x, UGdouble factor=1);
		static  UGint argmax (UGdouble *v,  UGint p1,  UGint p2);
		static  UGint randomSmallest (UGdouble *v,  UGint p1,  UGint p2,  UGint s);
		static  UGint randomLargest (UGdouble *v,  UGint p1,  UGint p2,  UGint s);
		static void bound ( UGint &c,  UGint min,  UGint max);
		static UGbool stripPath (UGchar *str);
		static UGbool stripExtension (UGchar *str);
		static UGdouble deg2rad (UGdouble d);
		static UGdouble dms2rad ( UGint d,  UGint m,  UGint s);
		static UGdouble l2norm (UGdouble x, UGdouble y, UGdouble z);
		static UGdouble sphered (UGdouble lg1, UGdouble lt1, UGdouble lg2, UGdouble lt2);
		static  UGint intcomp (const void *a, const void *b);
		static inline UGdouble pow (UGdouble n, UGdouble i) {
			if (i==1) return n;
			if (i==0) return 1;
			if (n==0) return 0;
			return (exp (i * log(n)));
		}
};

template <class T>  UGint partition (T *array,  UGint p1,  UGint p2, T pvt) 
{
	T *i, *j, tmp;

	i = &array[p1-1]; //- 1; //l - 1;
	j = &array[p2+1]; //r + 1;

	while (1) {
	    do {i++;} while (*i < pvt);
		do {j--;} while (pvt < *j);
		if (i >= j) break;

		//in this point *i>=pvt and *j<=pvt
		//swap them
		tmp = *i; *i = *j; *j = tmp;
	};
	//facts: *i>=pvt, *j<=pvt

	return (i - &array[p1]) + p1; //this is a valid position to insert the pvt; 
	          //note that it can be greater than r (can be r+1) 
}

template <class T>  UGint argmin (T *array,  UGint p1,  UGint p2) 
{
	 UGint m = p1;
	for (p1=p1+1; p1<=p2; p1++) {
		if (array[p1] < array[m]) m = p1;
	}
	return m;
}

template <class T> inline void partialShuffle (T *array,  UGint left,  UGint aright,  UGint sright) 
{
	T temp;
	
	for ( UGint i=left; i<=sright; i++) 
	{
		//UGint j = BossaRandom::getInteger (i, aright);
		BossaRandom bossaRandom;
		UGint j = bossaRandom.getInteger(i, aright);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

template <class T> void resize (T** array, UGuint oldsize, UGuint newsize) 
{
	if (oldsize == newsize) return;

	fprintf (stderr, "Preparing to resize.\n");

	T* o = *array;          //old array
	T *n;
	try {	
		n = new T [newsize]; //new array
	} catch (...) {
		fprintf (stderr, "Not enough memory.\n");
	}
	if (n==NULL) fprintf (stderr, "Not enough memory.\n");
	
	fprintf (stderr, "New array created.\n");
	 UGint minsize = (oldsize < newsize) ? oldsize : newsize;

	fprintf (stderr, "Minsize is %d.\n", minsize);
	for ( UGint i=0; i<minsize; i++) {n[i] = o[i];}
	delete [] o;
	*array = n;

	fprintf (stderr, "Array resized.\n");
}

template <class T> class BossaStack 
{
	private:
		T *stack;
		 UGint top, size;

		void fatal (const UGchar *func, const UGchar *msg) {
			fprintf (stderr, "BossaStack::%s: %s\n", func, msg);
			exit (-1);
		}

	public:
		UGbool isFull() {return (top==size);}

		void push (T i) {
			top++; 
			if (top>size) fatal ("push", "stack full");
			stack[top] = i;
		}

		T pop() {
			if (isEmpty()) fatal ("pop", "stack empty"); 
			return (stack[top--]);
		};

		UGbool isEmpty() {return (top==0);};

		 UGint getNElements() {return top;}

		T peek ( UGint p) {
			if ((p<1)||(p>top)) fatal ("peek", "index out of bounds");
			return (stack[p]);
		}

		BossaStack ( UGint s) {
			if (s<1) fatal ("BossaStack", "invalid size");
			top = 0;
   			size = s;
			stack = new T [size+1];
		};

		~BossaStack () {delete [] stack;};
};


template <class T> class BossaAllocator 
{
	private:
		 UGint maxsize;
		BossaStack <T*> *available;
		T *object_list;

		void fatal (const UGchar *func, const UGchar *msg) 
		{
			fprintf (stderr, "BossaAllocator::%s: %s.\n", func, msg); exit (-1);
		}

		void initStack () {
			for ( UGint i=0; i<maxsize; i++) available->push(&object_list[i]);
		}		

	public:
		BossaAllocator ( UGint size) {
			maxsize = size;
			object_list = new T [maxsize];
			available = new BossaStack <T*> (maxsize);
			initStack();
		}

		T *allocate () {
			if (available->isEmpty()) fatal ("allocate", "no object available");
			return available->pop();
		}
		
		void deallocate (T *obj) {
			if (obj<&object_list[0] || obj>=&object_list[maxsize]) {fatal ("deallocate", "invalid object");}
			available->push (obj);
		}

		~BossaAllocator () {
			delete [] object_list;
			delete available;
		}
};

template <class T> class BossaVertexHeapUnit 
{
	public:
		 UGint vertex;   //label of the vertex
	  	T distance;  //distance from the other vertices
};

template <class T> class BossaArrayUnit 
{
	public:
		T value;
		 UGint mark;
		BossaArrayUnit () {mark = 0;}
};

template <class T> class BossaArray 
{
	private:
		 UGint globalmark;
		BossaArrayUnit <T> *array;
		T defvalue; //default value
		 UGint size;

	public:
		T getDefault () {return defvalue;}
		inline  UGint getSize() {return size;}

		/* careful: default value will be undefined here */
		BossaArray ( UGint maxindex) {
			array = new BossaArrayUnit <T> [maxindex+1];
			size = maxindex;
			globalmark = 1;
		}


		BossaArray ( UGint maxindex, T value) {
			array = new BossaArrayUnit <T> [maxindex+1];
			size = maxindex;
			globalmark = 1;
			defvalue = value;
		}

		inline T get ( UGint x) {return getValue(x);}

		inline T getValue ( UGint x) {
			#ifdef BOSSA_DEBUG
			if (x > size) {
				fprintf (stderr, "BossaArray::getValue: index out of bounds (%d > %d).\n", x, size);
				exit (-1);
			}
			#endif
			if (globalmark == array[x].mark) return array[x].value;
			else return defvalue;
		}

		inline void setValue ( UGint x, T v) {
			#ifdef BOSSA_DEBUG
			if (x > size) {
				fprintf (stderr, "Array index out of bounds (%d > %d).\n", x, size);
				exit (-1);
			}
			#endif
			array[x].value = v;
			array[x].mark = globalmark;		
		}

		void reset() {globalmark++;}

		void reset ( UGint maxindex, T value) {
			defvalue = value;
			if (maxindex != size) {
				delete [] array;
				size = maxindex;
				array = new BossaArrayUnit <T> [size + 1];
				globalmark = 1;
				defvalue = value;
			} else reset();
		}

		void reset (T value) {
			defvalue = value;
			reset();
		}

		void copyFrom (BossaArray <T> *other) {
			reset (other->getSize(), other->getDefault());
			for ( UGint i = 1; i <= getSize(); i++) {
				this->setValue (i, other->getValue(i));
			}
		}

		~BossaArray () {delete [] array;}

};


template <class T> class BossaVertexHeap 
{
	private:
  		inline void up ( UGint);   //standard heap operation
  		inline void down ( UGint); //standard heap operation
  		inline void swap ( UGint,  UGint);  //swap two positions

  		 UGint nextpos;	//position of next insertion
  		BossaVertexHeapUnit <T> *h;
		BossaArray < UGint> *heappos;
			//position of each element in the heap
			//convention: 
			//   0 -> not yet inserted
			//   lastpos+1 -> already removed

  		 UGint lastpos;

 	public:

		inline T getValue ( UGint pos) {return h[pos].distance;}
		inline  UGint getVertex ( UGint pos) {return (h[pos].vertex);}; //vertex in position pos
		inline UGbool alreadyProcessed ( UGint v) {return (heappos->getValue(v) == lastpos + 1);}

		//new stuff
		inline T getElementValue ( UGint v) {return (getValue(heappos->getValue(v)));}
		inline UGbool contains ( UGint v) {return ((heappos->getValue(v)!=0)&&(heappos->getValue(v)!=lastpos+1));}

  		inline UGbool isEmpty () {return (nextpos == 1);}
  		inline  UGint getSize() {return (nextpos-1);}
  		inline  UGint getMaxSize() {return (lastpos);}

		void removeElement ( UGint);
		void removeFirst ( UGint&, T&);  //O(log n)
  		UGbool insert ( UGint vertex, T distance, UGbool force = true); //O(log n)
		void update ( UGint vertex, T distance);
		void heapify ();
		UGbool check();
		UGbool pushBack ( UGint vertex, T distance);

		void reset () {nextpos = 1; heappos->reset();} //O(1)

		BossaVertexHeap ( UGint n); //constructor O(n)
  		~BossaVertexHeap (); //O(1)
  		void outputHeap ( UGint); //O(n)
};

//-------------
// Constructor
//-------------
template <class T> BossaVertexHeap<T>::BossaVertexHeap ( UGint n) 
{
	nextpos = 1;
  	lastpos = n;
  	h = new BossaVertexHeapUnit <T> [n+1];
  	heappos = new BossaArray < UGint> (n+1, 0);
}

//------------
// Destructor
//------------
template <class T> BossaVertexHeap<T>::~BossaVertexHeap() 
{
	delete [] h;
	delete heappos;
}

//--------------------------
// Output heap in pre-order
//--------------------------
template <class T> void BossaVertexHeap<T>::outputHeap ( UGint pos) 
{
	if (pos < nextpos) {
	    	printf("(%d %d)",getValue(pos),getVertex(pos));
   		outputHeap(2*pos);
		outputHeap(2*pos+1);
  	}
  	else printf("-");
}

//------------------------------------
// Swap elements in positions a and b
//------------------------------------
template <class T> void BossaVertexHeap<T>::swap ( UGint a,  UGint b) 
{
	BossaVertexHeapUnit <T> tmp = h[a];
  	h[a] = h[b];
  	h[b] = tmp;
	heappos -> setValue (h[a].vertex, a);
	heappos -> setValue (h[b].vertex, b);
}

//------------------------------------
// Standard up operation performed on 
// the element in the n-th position
//------------------------------------
template <class T> void BossaVertexHeap<T>::up ( UGint n) 
{
	if ((n>1) && (getValue(n/2) > getValue(n))) 
	{ 
		swap (n,n/2);                           
		up (n/2);										
  	}
}

//------------------------------------------
// Move the element currently in position n
// down to an appropriate position.
//------------------------------------------
template <class T> void BossaVertexHeap<T>::down ( UGint n) 
{
	BossaVertexHeapUnit <T> tmp;
	T minchild;
	 UGint two_n;

	if ((two_n = 2*n) < nextpos) 
	{
		tmp = h[n];
		do {
			minchild = getValue(two_n);
			if (((two_n+1)<nextpos) && (minchild>getValue(two_n+1))) minchild = getValue(two_n+1);
			if (tmp.distance > minchild) { 
				if (minchild == getValue(two_n)) 
				{		
					h[n] = h[two_n];
					heappos->setValue (h[n].vertex, n);
					n = two_n;               
				} 
				else 
				{
					h[n] = h[two_n+1];
					heappos->setValue (h[n].vertex,n);
					n = two_n + 1;		
				}
				two_n = 2*n;
			} else break;
		} while (two_n < nextpos);
		h[n] = tmp;
		heappos->setValue (h[n].vertex, n);
	}
}

//---------------------------------------------------
// Remove the element with the highest priority from 
// the heap. Its label and  value are returned.
//---------------------------------------------------
template <class T> void BossaVertexHeap<T>::removeFirst ( UGint& vertex, T& value) 
{
	vertex = h[1].vertex;  
	value = getValue(1);

  	h[1] = h[nextpos-1];	

	heappos -> setValue (h[1].vertex, 1);
	heappos -> setValue (vertex, lastpos + 1);	

  	nextpos --;					
  	down(1);					
}

//------------------------------
// heapify operation
//------------------------------
template <class T> void BossaVertexHeap<T>::heapify () 
{
	 UGint i;
	for (i=(nextpos-1)/2; i >= 1; i--) down(i);
}

template <class T> UGbool BossaVertexHeap<T>::check() 
{
	 UGint i;
	for (i = nextpos - 1; i > 1; i--)
	{
		if (h[i].distance < h[i/2].distance) 
		{
			fprintf (stderr, "%d (%d) is child of %d (%d). There are %d elements.\n", 
				h[i].distance, i, h[i/2].distance, i/2, nextpos - 1);
			return false;
		}
	}

	for ( UGint i = 1; i < nextpos; i++) 
	{
		if (heappos->getValue (h[i].vertex) != i) 
		{
			fprintf (stderr, "Element %d thinks it is in position %d, but it isn't.\n", h[i].vertex, i);
			return false;
		}
	}

	for ( UGint i = 1; i <= lastpos; i++) 
	{
		 UGint pos = heappos->getValue (i);
		if ((pos > 0) && (pos <= lastpos)) 
		{
			if (pos >= nextpos) 
			{
				fprintf (stderr, "Element %d's reported position (%d) is out of bounds (there are only %d elements).\n", i, pos, nextpos - 1);
				return false;
			}
			if (h[pos].vertex != i) 
			{
				fprintf (stderr, "Element %d is not in the position he thinks he is (%d); %d is there.\n", i, pos, h[pos].vertex);
				return false;
			}
		}
	}
		

	return true;
}

template <class T> UGbool BossaVertexHeap<T>::pushBack ( UGint v, T distance) 
{
	if (contains(v)) return false;
	h[nextpos].vertex = v;
	h[nextpos].distance = distance;
	heappos->setValue (v, nextpos);
  	nextpos++;
	return true;
}



template <class T> void BossaVertexHeap<T>::removeElement ( UGint vertex) 
{
	 UGint pos = heappos->getValue (vertex);

	//fprintf (stderr, "Removing element %d, value=%d, position=%d, nextpos=%d, lastpos=%d\n", vertex, h[pos].distance, pos, nextpos, lastpos);	
	
	if ((pos!=0) && (pos!=lastpos+1)) { //element actually belongs to the heap

		heappos->setValue (vertex, lastpos+1); //element will no longer belong to the heap
		nextpos --;  //one fewer element

		if ((nextpos != 1) && (nextpos != pos)) { //not empty, not last
			//update heap

			h[pos] = h[nextpos]; //last element replaces the removed one
			heappos->setValue (h[pos].vertex, pos); //let the element know his new position
		
			if ((pos>1) && (h[pos].distance<=h[pos/2].distance)) up(pos);
			else down(pos);
		}
	}
}

//--------------------------------------------
// Insert an element into the heap
// (if the element is already in the heap,
// its priority is updated as necessary)
//--------------------------------------------

template <class T> UGbool BossaVertexHeap<T>::insert ( UGint vertex, T distance, UGbool force) 
{
	 UGint prevpos = heappos->getValue (vertex);
	if ((prevpos != 0) && (prevpos != lastpos + 1)) 
	{ //already in heap
		if (h[prevpos].distance < distance) return false;
		else {
			h[prevpos].distance = distance;
			up (prevpos);
			return true;
		}
	}
	if ((prevpos == lastpos + 1) && !force) return false;

	h[nextpos].vertex = vertex;
	h[nextpos].distance = distance;
	heappos -> setValue (vertex, nextpos);
	up(nextpos);
  	nextpos++;
	return true;
}

template <class T> void BossaVertexHeap<T>::update ( UGint vertex, T distance) {
	if (!contains(vertex)) insert (vertex, distance, true);
	else {
		T current_distance = getElementValue (vertex);
		if (distance == current_distance) return; //nothing to do
		if (distance < current_distance) insert (vertex, distance, true); //increase priority
		if (distance > current_distance) { //decrease priority
			 UGint current_pos = heappos->getValue (vertex);
			h[current_pos].distance = distance;
			down(current_pos);
		}
	}
}


class   PMSolution 
{
	private:
		PMInstance *instance;
		 UGint p; //number of facilities in the solution (may differ from instance)
		 UGint n; //number of users
		 UGint m; //number of potential facilities
		 UGint *faclist;  //list of all facilities, first p are the solution
		 UGint *facpos;   //facpos[i] = j  -> facility i is in faclist[j]		
		 UGint *closest;  //closest[i] = j -> facility j (which must be in the solution) is the closest to i
		 UGint *closest2; //closest[i] = j -> facility j is the second closest to i
		UGdouble *closestd; //distance to the closest
		UGdouble *closest2d; //distance to the second closest
		UGbool *consistent; 
		 UGint inconsistencies;
			

		void fatal (const UGchar *func, const UGchar *msg); //standard error message
		void swappos ( UGint i,  UGint j); //swap facilities in positions i and j
		
	public:	

		//------------------------------------------------
		// check if f is close enough so as to become the
		// closest or second closest --- if it is, update
		//------------------------------------------------
		inline void upgrade ( UGint i,  UGint f) {
			UGdouble dif = instance->getDist(i,f); //distance from i to f
			if (dif <= getDistClosest2(i)) {     //only interested if closer than 2nd closest
				UGdouble d1 = getDistClosest(i);
				if (dif <= d1) {                     //if also closer than first closest...
					setClosest2 (i,closest[i],d1); //old closest becomes 2nd closetst
					setClosest (i,f,dif);          //f is the new closest
				} else {
					setClosest2 (i,f,dif);         //f becomes new second closest
				}
			}
		}

		//--------------------------------
		// Marks vertex i as inconsistent
		//--------------------------------
		void makeInconsistent( UGint i) {
			if (consistent[i]) {
				consistent[i] = false;
				inconsistencies++;
			}
		}

		//--------------------------------------------
		// marks vertex i as consistent --- call this 
		// only if you know what you're doing
		//--------------------------------------------
		void forceConsistent ( UGint i) {
			if (!consistent[i]) {
				consistent[i] = true;
				inconsistencies--;
			}
		}
		
		void GetSolution(UGArray<UGuint> &arrCenterIndex);

		//------------
		// basic data
		//------------
		inline PMInstance *getInstance() {return instance;} //instance
		inline  UGint getFacility ( UGint i) {return faclist[i];} //label of the i-th facility
		inline  UGint getP() {return p;} //number of facilities in the solution
		inline  UGint getN() {return n;} //number of cities
		inline  UGint getM() {return m;} //number of potential facilities
		inline  UGint getPosition ( UGint f) {return facpos[f];} //position of the i'th facility
		inline UGbool contains( UGint i) {return (facpos[i] <= p);}

		//-----------------------
		// closeness information
		//-----------------------
		inline  UGint    getClosest      ( UGint i) {return closest[i];}
		inline  UGint    getClosest2     ( UGint i) {return closest2[i];}
		inline UGdouble getDistClosest  ( UGint i) {return closestd[i];}
		inline UGdouble getDistClosest2 ( UGint i) {return closest2d[i];}
		inline void   setClosest      ( UGint i,  UGint f) {setClosest (i,f,instance->getDist(i,f));}		
		inline void   setClosest2     ( UGint i,  UGint f) {setClosest2(i,f,instance->getDist(i,f));}
		inline void   setClosest      ( UGint i,  UGint f, UGdouble v) {closest[i] = f; closestd[i] = v;}
		inline void   setClosest2     ( UGint i,  UGint f, UGdouble v) {closest2[i] = f; closest2d[i] = v;}
		void ensureConsistency (); //ensure solution is consistent
		void updateClosest ( UGint i);

		//------------------------------
		// dealing with other solutions
		//------------------------------
		void copyFrom (PMSolution *s);         //copy the contents of an existing solution
		 UGint computeDifference (PMSolution *s); //symmetric diff. between this and another solution
		UGbool equals (PMSolution *s);           //check if this is identical to s

		//---------------------
		// solution management
		//---------------------
		PMSolution (PMInstance *inst);             //constructor: empty solution (no facilities)		
		UGdouble calcCost();	                       //compute solution cost
		void reset();                              //remove all facilities
		void add ( UGint f, UGbool update);             //add f to the solution
		void swap ( UGint rem,  UGint ins, UGbool update); //swap facilities rem and  UGint
		void remove ( UGint f, UGbool update);          //remove f from solution
		~PMSolution ();                            //destructor
};

class   PMConstructive 
{
private:
	enum {RPG, RGREEDY, PGREEDY, PWORST, PREVERSE, MST, SAMPLE, MIX, NMETHODS};
	UGchar method_name [256];  //name of the current method
	UGdouble param [NMETHODS]; //default parameters for all methdos
	 UGint method;              //current method
	
	static void fatal (const UGchar *func, const UGchar *msg);
	UGbool tryMethod (UGchar *m, const UGchar *name,  UGint code,  UGint np);
public:
	PMConstructive () {setMethod ("rpg:1");} //constructor; default is random solution
	
	//--------------------------------------------------
	// routines dealing the 'current' or default method
	//--------------------------------------------------
	void setMethod (UGchar *m);      //define current method
	void run(PMSolution *s);       //run current method
	
	//-------------------------
	// constructive algorithms
	//-------------------------
	static void addRandom (PMSolution *s,  UGint k);
	static void pworst    (PMSolution *s,  UGint *candlist=NULL, UGdouble exponent=1, UGbool stats=false);
	static void greedy    (PMSolution *s, UGbool proportional=false, UGdouble alpha=0,  UGint *candlist=NULL);
	static void rpg       (PMSolution *s, UGdouble rfrac, UGbool stats=false);
	static void preverse  (PMSolution *s, UGbool stats=false);
	static void mst       (PMSolution *s, UGbool stats=false);
	static void sample    (PMSolution *s, UGdouble frac, UGbool stats=false);
};

class   PMDistanceOracle 
{
private:
	 UGint m;            //number of potential facilities
	 UGint n;            //number of customers
	 UGint p;            //number of facilities in the solution
	PMInstance *inst; //instance to which this oracle refers
	 UGint **list;       //list[i] is the list of elements associated with i
	 UGint *templist;    //buffer area; getCloser returns a pointer to this
	
	void fatal (const UGchar *func, const UGchar *msg); //error messages
	void checkList( UGint i);                          //debug: check if the list makes sense
	UGdouble init_time;                               //initialization time (how UGint it took to run the constructor)
	inline  UGint getSize( UGint i) {return list[i][0];}  //number of the elements in the i-th list
	UGdouble getMaxValue( UGint i);                      //maximum value represented by the i-th list
	void initArrays();		                        //create all the lists
	
public:
	static UGdouble cache_factor; //lists will have size equal to (m/p) times this
	
	PMDistanceOracle (PMInstance *_inst);    //constructor
	~PMDistanceOracle ();                    //destructor
	UGdouble getInitTime() {return init_time;} //how UGint did it take to initialize?
	
	 UGint *getCloser ( UGint i, UGdouble v);       
};

class   PMElite 
{
private:
	 UGint cap;          //total number of solutions allowed
	PMSolution **s;   //list of solutions
	UGdouble *v;        //list of solution values
	PMInstance *inst; //instance to which the solutions... are solutions
	 UGint consistent;   //number of consistent solutions
	
	void fatal (const UGchar *func, const UGchar *msg);
	void promote( UGint i);
	void sort();
	 UGint getMostSimilar (PMSolution *t,  UGint p1,  UGint p2);	
	UGbool isUnique(PMSolution *t);
	
public:
	PMElite (PMInstance *_inst,  UGint _cap);
	 UGint getRandomDifferent(PMSolution *t,  UGint p1,  UGint p2);
	//void outputToFiles (const UGchar *prefix);
	void outputDifferences (FILE *file);
	void output (FILE *file, UGbool complete = false);
	UGdouble getSolution ( UGint i, PMSolution *sol);
	UGbool add (PMSolution *t, UGdouble c); //,  UGint pos=0);
	void computeDifferences ( UGint *diff, PMSolution *t);
	 UGint getMostDifferent (PMSolution *t);
	void reset();
	void checkConsistency ( UGint i);
	~PMElite();
	
	inline  UGint count () {return cap;}
	inline  UGint countConsistent () {return consistent;}
	inline PMInstance* getInstance() {return inst;}
	inline  UGint getCapacity() {return cap;}
	inline UGdouble getSolutionCost ( UGint i) {return v[i];}
};

class   PMGraphNode 
{
public:
	UGdouble value;
	 UGint neighbor;
	PMGraphNode *next;
};

class   PMGraph 
{
private:
	 UGint n; //number of vertices
	 UGint m; //number of edges
	 UGint added; //number of edges actually added
	BossaAllocator <PMGraphNode> *allocator;
	PMGraphNode **nodes;
	BossaVertexHeap <UGdouble> *heap;
	
	void addNeighbor ( UGint i,  UGint j, UGdouble v) 
	{
		PMGraphNode *node = allocator->allocate();
		node->value = v;
		node->neighbor = j;
		node->next = nodes[i];
		nodes[i] = node;
	}
	
	void deleteNeighborhood ( UGint i) 
	{
		PMGraphNode *x = nodes[i];
		for (x=nodes[i]; x!=NULL; x=x->next) 
		{
			allocator->deallocate(x); //this doesn't destroy x
		}
		nodes[i] = NULL;
	}
	
	
public:
	
	 UGint getNEdges() {return m;}
	
	void dijkstra ( UGint r, UGdouble *d) 
	{
		heap->reset();
		heap->insert (r,0);
		
		while (!heap->isEmpty()) 
		{
			 UGint v; UGdouble cost; 
			heap->removeFirst(v, cost);
			d[v] = cost;
			for (PMGraphNode *x=nodes[v]; x!=NULL; x=x->next) 
			{
				heap->insert (x->neighbor, x->value + cost, false);
			}
		}
	}
	
	PMGraph ( UGint _n,  UGint _m) 
	{
		n = _n; 
		m = _m;
		heap = new BossaVertexHeap <UGdouble> (n+1);
		nodes = new PMGraphNode* [n+1];
		for ( UGint i=1; i<=n; i++) nodes[i] = NULL;
		allocator = new BossaAllocator <PMGraphNode> (2*m);
	}
	
	void addEdge ( UGint i,  UGint j, UGdouble v) 
	{
		addNeighbor (i, j, v);
		addNeighbor (j, i, v);
	}
	
	~PMGraph() 
	{	
		for ( UGint i=1; i<=n; i++)    //this is not strictly necessary, but...
			deleteNeighborhood (i); 
		delete [] nodes;
		delete allocator;
		delete heap;
	}
	
	void output (FILE *file) 
	{
		for ( UGint i=1; i<=n; i++) 
		{
			fprintf (file, "%d: ", i);
			for (PMGraphNode *x=nodes[i]; x!=NULL; x=x->next) 
			{
				fprintf (file, "%d ", x->neighbor);
			}
			fprintf (file, "\n");
		}
	}
};

class PMMatrixInstance:public PMInstance 
{
private:
	UGdouble oracle_time;
	void reset();
	void fatal (const UGchar *func, const UGchar *msg);
	PMDistanceOracle *oracle;
	
protected:
	void resetDistances();
	void initOracle() {oracle = new PMDistanceOracle (this);}
	UGdouble **d; //distance matrix
	 UGint n; //number of nodes (users)
	 UGint p; //number of facilities in the solution
	 UGint m; //number of potential facilities
	
public:
	PMMatrixInstance();		
	PMMatrixInstance (PMInstance *original,  UGint *of,  UGint *oc);
	~PMMatrixInstance();		
	
	virtual UGdouble getOracleTime() {return oracle->getInitTime();}
	virtual  UGint getMetric() {return MATRIX;}
	virtual  UGint *getCloser ( UGint i, UGdouble v) {return oracle->getCloser(i,v);}
	void readPMM(UGdouble* dCostMatrx, UGint nDemandCount, UGint nCandicateCount, UGint nMedianCount);
	void printMatrix (FILE *file);
	
	virtual UGdouble getFacDist ( UGint f,  UGint g) {
		if (f>m || g>m) fatal ("getFacDist", "facility number out of range");
		return d[f][g]; //assumes facilities and users are the same thing
	}
	
	virtual UGdouble getDist ( UGint u,  UGint f) {
		if (u>n) fatal ("getDist", "customer number out of range");
		if (f>m) fatal ("getDist", "facility number out of range");
		return d[u][f];
	}
	
	virtual  UGint  getM() {return m;} 
	virtual  UGint  getN() {return n;}
	virtual  UGint  getP() {return p;}
	virtual void setP ( UGint _p) {p = _p;}
};

class PMHybridInstance:public PMInstance 
{
	private:
		virtual void fatal (const UGchar *func, const UGchar *msg);
		PMDistanceOracle *oracle;
		PMInstance *original;
		 UGint original_n;         //original number of users
		 UGint original_m;         //original number of potential facilities
		 UGint *original_closest;  //for every facility, represents the element that is closest to i
		 UGint *original_closest_2; //for every facility, represents the second closest element to i (among the original ones)
		UGbool *fixed_original;   //if true, the facility was in both original solutions
		 UGint *clabel; //clabel[i] = original label of customer i
		 UGint *flabel; //flabel[i] = original label of facility i
		UGdouble *cud; //distance from a customer to the universal facility
		 UGint m;       //number of facilities in this instance (including the 'universal' facility)
		 UGint n;       //number of customers in this instance
		 UGint p;       //number of facilities that must be open in this instance
		
		void initOracle() {oracle = new PMDistanceOracle (this);}
		UGdouble base_cost;

		void updateOriginalCloseness ( UGint f);

	public:

		virtual  UGint getMetric() {return HYBRID;}
		PMHybridInstance();
		inline  UGint *getCloser( UGint i, UGdouble v) {return oracle->getCloser(i,v);}
			
		void restoreSolution (PMSolution *solcur, PMSolution *solorg);

		PMHybridInstance (PMSolution *s, PMSolution *t);
		//PMHybridInstance (PMInstance *original, UGbool *customers, UGbool *facilities);

		inline UGdouble getBaseCost () {return base_cost;}
		inline  UGint getFacLabel ( UGint i) {return flabel[i];}
		inline  UGint getLabel ( UGint i) {return clabel[i];}
		inline UGbool isFixedOriginal ( UGint i) {return fixed_original[i];}

		void original2sub (PMSolution *solorg, PMSolution *solsub);

		~PMHybridInstance();
		UGdouble getFacDist ( UGint f,  UGint g);

		UGdouble getDist ( UGint u,  UGint f);

		UGdouble getFloydTime() {return 0.0;}
		virtual  UGint getP() {return p;}
		virtual  UGint getN() {return n;}
		virtual  UGint getM() {return m;}
		virtual void setP( UGint _p) {p = _p;}
};

class   RFWStats 
{
public:
	static  UGint dcmp (const void *a, const void *b) {
		UGdouble da = *(UGdouble *)a;
		UGdouble db = *(UGdouble *)b;
		
		if (da<db) return -1;
		if (da>db) return 1;
		return 0;
	}
	
	
	static UGdouble sum (UGdouble *v,  UGint p1,  UGint p2) {
		UGdouble total = 0;
		for ( UGint i=p1; i<=p2; i++) total += v[i];
		return total;
	}
	
	static UGdouble average (UGdouble *v,  UGint p1,  UGint p2) {
		UGdouble n = (UGdouble) (p2 - p1 + 1);
		return sum(v,p1,p2) / n;
	}
	
	static UGdouble sumsq (UGdouble *v,  UGint p1,  UGint p2) {
		UGdouble total = 0;
		for ( UGint i=p1; i<=p2; i++) total += (v[i]*v[i]);
		return total;
	}
	
	static  UGint argmin (UGdouble *v,  UGint p1,  UGint p2) {
		 UGint m = p1;
		for ( UGint i=p1+1; i<=p2; i++) {
			if (v[i]<v[m]) m = i;
		}
		return m;
	}
	
	static UGdouble minR (UGdouble *v,  UGint p1,  UGint p2) {
		return v[argmin(v,p1,p2)];
	}
	
	static  UGint argmax (UGdouble *v,  UGint p1,  UGint p2) {
		 UGint m=p1;
		for ( UGint i=p1; i<=p2; i++) {
			if (v[i]>v[m]) m = i;
		}
		return m;
	}
	
	static UGdouble maxR (UGdouble *v,  UGint p1,  UGint p2) {
		return v[argmax(v,p1,p2)];
	}
	
	static UGdouble variance (UGdouble *v,  UGint p1,  UGint p2) {
		UGdouble ssq = sumsq (v, p1, p2);
		UGdouble avg = average (v, p1, p2);
		UGdouble n = (UGdouble) (p2 - p1 + 1);
		UGdouble var = (ssq / n) - avg * avg;
		
		return var;
	}
	
	static UGdouble stddev (UGdouble *v,  UGint p1,  UGint p2) {
		return sqrt (variance(v,p1,p2));
	}
	
	static void output (FILE *file, UGdouble *v,  UGint p1,  UGint p2) {
		for ( UGint i=p1; i<=p2; i++) {
			fprintf (file, " %.1f", v[i]);
		}
		fprintf (stderr, "\n");
	}
	
	
	
	//return the position of the last element strictly less than x
	static  UGint partition (UGdouble x, UGdouble *v,  UGint p1,  UGint p2) 
	{
		 UGint left = p1;
		 UGint right = p2;
		
		output (stderr, v, p1, p2);
		
		while (1) {
			if (left>=right) break;
			if (v[left]<x) left++; 
			else if (v[right]>x) right--;
			else {
				UGdouble temp = v[left];
				v[left] = v[right];
				v[right] = temp;
				left++;
				right--;
			}
		}
		output (stderr, v, p1, p2);
		return right;
		
	}
	
	static void sort (UGdouble *v,  UGint p1,  UGint p2) 
	{
		qsort (&v[p1], p2-p1+1, sizeof (UGdouble), &RFWStats::dcmp);
	}
	
	static UGbool sorted (UGdouble *v,  UGint p1,  UGint p2) 
	{
		for ( UGint i=p1+1; i<=p2; i++) {
			if (v[i]<v[i-1]) return false;
		}
		return true;
	}
	
	static UGdouble getk ( UGint k, UGdouble *v,  UGint p1,  UGint p2) 
	{
		if (!sorted(v,p1,p2)) sort (v, p1, p2); 
		return v[k];
	}
	
	static UGdouble median (UGdouble *v,  UGint p1,  UGint p2) 
	{
		if (!sorted(v,p1,p2)) sort (v, p1, p2);
		 UGint n = p2 - p1 + 1;
		 UGint n2 = n/2 + 1;
		
		if (n%2 == 0) {
			return (v[n2] + v[n2-1]) / 2;
		} else {
			return (v[n2]);
		}
	}
};

class   PMSearch 
{
	public:
		virtual void getCandidates ( UGint *rcand,  UGint *icand) = 0;
		virtual UGbool reportMove ( UGint r,  UGint i, UGdouble profit) = 0;
		virtual UGbool firstImprovement () = 0;
};

/******************
 *
 * Path-relinking
 *
 ******************/

class PMSearchPathRelinking:public PMSearch 
{
private:
	 UGint p;       //number of facilities
	 UGint *insert; //list of candidates for insertion (insert[0] is the size)
	 UGint *remove; //list of candidates for removal   (remove[0] is the size)
	PMInstance *inst;
	
	void fatal (const UGchar *func, const UGchar *msg);	
public:
	virtual UGbool firstImprovement () {return false;}
	void setSolutions (PMSolution *source, PMSolution *target);
	PMSearchPathRelinking (PMInstance *_inst);
	virtual void getCandidates ( UGint *rcand,  UGint *icand);
	virtual UGbool reportMove ( UGint r,  UGint i, UGdouble profit);		
	virtual ~PMSearchPathRelinking ();
};

/****************************************
 *
 * local search
 *
 ****************************************/

class PMSearchLocal:public PMSearch 
{
private:
	UGbool *solution;
	 UGint p;
	 UGint m;
	 UGint it; //number of local search iterations performed
	void fatal (const UGchar *func, const UGchar *msg); 
	
public:
	virtual UGbool firstImprovement () {return false;}
	virtual UGbool reportMove ( UGint r,  UGint i, UGdouble profit);
	virtual void getCandidates ( UGint *rcand,  UGint *icand); //get sorted lists of candidates
	inline  UGint getIterations () {return it;}		
	PMSearchLocal (PMSolution *s);
	virtual ~PMSearchLocal ();
};

/************************************
 *
 * search routines for Tabu Search
 *
 ************************************/

class PMSearchTabu:public PMSearch 
{
private:
	UGbool *solution;
	 UGint *itabu, *rtabu;
	 UGint n;
	 UGint p;
	 UGint it; //iteration of the tabu search
	 UGint itenure, rtenure;
	 UGint maxit;
	
	void fatal (const UGchar *func, const UGchar *msg); 
public:
	virtual UGbool firstImprovement () {return false;}
	virtual UGbool reportMove ( UGint r,  UGint i, UGdouble profit);
	virtual void getCandidates ( UGint *rcand,  UGint *icand);
	void setInsertTenure ( UGint i) {itenure = i;}
	void setRemoveTenure ( UGint i) {rtenure = i;}
	 UGint getInsertTenure () {return itenure;}
	 UGint getRemoveTenure () {return rtenure;}
	PMSearchTabu (PMSolution *s,  UGint _maxit);
	virtual ~PMSearchTabu ();
};


/***********************************
 *
 * nodes used in the sparse matrix
 *
 ***********************************/

class   ExtraNode 
{
public:
	 UGint node;
	UGdouble value;
	ExtraNode *next;
};

/**********************************
 *
 * The SearchTables class itself
 *
 **********************************/

class   SearchTables 
{
private:
	 UGint m;
	 UGint p;
	UGdouble tolerance;
	BossaAllocator <ExtraNode> *allocator;
	UGbool using_list;
	void fatal (const UGchar *func, const UGchar *msg);
	ExtraNode *allocate() {return allocator->allocate();}
	void deallocate(ExtraNode *x) {allocator->deallocate(x);}
	
	 UGint cur_center; //vicinity we're looking at
	UGdouble *cur_vector; //vector for that vicinity (used in matrix mode)
	ExtraNode *cur_node; //used in list node
	ExtraNode *add (ExtraNode *current,  UGint i, UGdouble v);
	
public:
	UGdouble **extra;   //a matrix
	UGdouble *save;
	UGdouble *lose;
	ExtraNode **list; //a list (only one of these two is used)
	inline UGbool usingList() {return using_list;}
	SearchTables ( UGint _m,  UGint _p, UGbool _using_list);
	
	void setCurrent ( UGint i) {
		cur_center = i;
		if (using_list) {cur_node = list[cur_center];}
		else {cur_vector = extra[cur_center];}
	}
	
	void deleteRow( UGint i);
	
	~SearchTables ();
	
	inline void addExtra  ( UGint i, UGdouble v) {
		if (using_list) {
			cur_node = add (cur_node, i, v);
		} else {
			cur_vector[i] += v;
		}
	}
	
	void reportMove ( UGint ins,  UGint rem) {
		if (usingList()) {
			deleteRow(rem);
		} else {
			extra[ins] = extra[rem];
			extra[rem] = NULL;
		}
	}
};
// 
// #ifdef BOSSA_UNIX
// #include <unistd.h>
//#endif


#define CUTOFF 10

//****************************
// STACKSORT
//****************************

template <class T> void insbin (T * left, T * right) {
  T *middle, *lower, *upper, *i, *j, temp;
  for (i = left + 1; i <= right; i++) {
    temp = *(upper = i);
    lower = left;
    while (lower < upper) {
      if (temp > (*(middle=lower+((upper-lower)>>1)))) 
	lower = middle + 1;
      else 
	upper = middle;
    }
    j = i;
    while (j > lower) {*(j--) = *(j-1);}  
    *lower = temp;
  }
}


template <class T> void bubsort (T * left, T * right) {
  T *i, temp;
   UGint s, steps = ( UGint) (right - left);
  for (s = 0; s < steps; s++) {
    for (i = left; i < right; i++) {
      if (*i > *(i+1)) {
        temp = *i;
        *i = *(i+1);
        *(i+1) = temp;
      }
    }
  }  
}


template <class T> void stksort (T * left, T * right) {
  T *i, *j, **top;
  T * bestpos [100];
  T maxval;
  
  * (top = bestpos) = (*(top+1) = left) - 1;

  for (i = right; i > left; i--) {
    maxval = **top;
    for (j = *(top+1); j <= i; j++) 
      if (*j >= maxval)	maxval = *(*(++top) = j);
      **(top--) = *i;
      *i = maxval;
  }
}

template <class T> void stksort1 (T * left, T * right) {
  T *i, *j, **top;
  T ** bestpos = new T* [right - left + 1];
  T maxval;
  
  * (top = bestpos) = (*(top+1) = left) - 1;

  for (i = right; i > left; i--) {
    maxval = **top;
    for (j = *(top+1); j <= i; j++) 
      if (*j >= maxval)	maxval = *(*(++top) = j);
    **(top--) = *i;
    *i = maxval;
  }
  delete [] bestpos;
}

//********************************************
//
// INSERTIONSORT
//
//********************************************

#define insertion_sort_1(lft,rgt) 	\
  register T *j;					\
  T  value;				\
  T *i;					\
  for (i = (lft) + 1; i <= (rgt); i++) {\
    value = *(j=i);			\
    while (value < *(--j)) {*(j+1)=*j;}	\
    *(j+1) = value;			\
  }

//assumes that left-1 contains the sentinel
template <class T> void inssort1 (T * left, T * right) {
  insertion_sort_1(left,right);
}

#define insertion_sort_2(lft,rgt)					\
  register T *j;											\
  T minv, maxv;								\
  T *i;									\
  for (i = (lft)+((rgt)-(lft)+1)%2; i<=(rgt); i+=2) {			\
    if (*(i+1) >= *(j=i)) {maxv = *(i+1); minv = *i;}   		\
    else {minv = *(i+1); maxv = *i;}					\
    while (maxv < *(--j)) {*(j+2) = *j;} 				\
    *((j++)+2) = maxv; 							\
    while (minv < *(--j)) {*(j+1) = *j;} 				\
    *(j+1) = minv;							\
  }



//assumes that left-1 contains the sentinel
template <class T> void inssort2 (T * left, T * right) {
  insertion_sort_2(left,right)
}

//************************************************
//
// QUICKSORT
//
// - median-of-three
// - non-recursive
// - for instances smaller than CUTOFF, apply a
//   different algorithm (Insertion, 2-Insertion
//   or Stacksort)
//
//************************************************

#define DECLARATIONS() \
register T *i, *j;\
 T * stack[64], **top = stack, pvt, tmp, *left, *right, *mid;

//medthree: sorts v[left], pvt (originally v[mid]) and v[right]. v[mid] ends up inconsistent
#define MEDTHREE()\
pvt = *(mid = (left + (right - left) / 2));                   \
if (pvt < *((i)=(left))) {(pvt) = *(left); *(left) = *(mid);};\
if (*right < pvt) {                                           \
   tmp = *right; *right = pvt;                                \
   if (tmp < *left) {pvt = *left; *left = tmp;}               \
    else pvt = tmp;                                           \
}

//partition of the elements; at the end, i will point to the first element of the >= part and j to the last of the <= one
#define PARTITION() 		\
while (1) {			\
  do {i++;} while (*i < pvt);	\
  do {j--;} while (pvt < *j);	\
  if (i >= j) break;		\
  tmp = *i; *i = *j; *j = tmp;	\
};

//replace *i with the pivot
#define RESTORE_PIVOT() 	\
if (i < right) {		\
  *(right-1) = *i; *i = pvt;	\
} else {*(--i) = pvt;}

#define PUSH_SUBPROBLEMS() 	\
if (i - left > right - i) {	\
  *top++ = left;		\
  *top++ = i-1;			\
  left = i+1;			\
} else {			\
  *top++ = i+1;			\
  *top++ = right;		\
  right = i-1;			\
}

#define GET_SUBPROBLEM() if (--top < stack) break; right = *top; left = *--top;

#define FIND_SENTINEL()                                             \
	minelem = l;                                                    \
	right = l + CUTOFF;						                        \
	if (right > r) right = r;                                       \
	for (i = l+1; i<= right; i++) if (*i < *minelem) minelem = i;	\
	tmp = *l;							                            \
    	*l = *minelem;                                              \
	*minelem = tmp;

//************************
// 'PURE' QUICKSORT
//************************

template <class T> void purequick (T * l, T * r) {
  DECLARATIONS();
  left = l; right = r;
  while (1) {
    if (right - left > 1) {  //3 or more elements
      MEDTHREE();
      if (right - left > 2) {  //more than 3 elements
	*mid = *(j = right-1); //transfer
	PARTITION();
	RESTORE_PIVOT();
	PUSH_SUBPROBLEMS();
      } else { //base case: 3 elements
	*mid = pvt;
	GET_SUBPROBLEM();
      }
    } else { //base case: 2 elements
      if (*left > *right) {tmp = *left; *left = *right; *right = tmp;}
      GET_SUBPROBLEM();
    }
  }
}

//**********************************//
// QUICKSORT USING INSERTION SORT //
//**********************************//

template <class T> void sedquick (T * l, T * r) {
  DECLARATIONS();
  T * minelem;
  left = l; right = r;
  while (1) {
    if (right - left > CUTOFF) {
      MEDTHREE();
      *mid = *(j = right - 1);
      PARTITION();
      RESTORE_PIVOT();
      PUSH_SUBPROBLEMS();
    } else {GET_SUBPROBLEM();}
  }
  FIND_SENTINEL();
  {insertion_sort_1(l+1,r);}
  //inssort1 (l+1,r);
}

//**********************************//
// QUICKSORT USING 2-INSERTION SORT //
//**********************************//

template <class T> void sedquick2 (T * l, T * r) {
  DECLARATIONS();
  T * minelem;
  left = l; right = r;
  while (1) {
    if (right - left > CUTOFF) {
      MEDTHREE();
      *mid = *(j = right - 1);
      PARTITION();
      RESTORE_PIVOT();
      PUSH_SUBPROBLEMS();
    } else {GET_SUBPROBLEM();}
  }
  FIND_SENTINEL();
  {insertion_sort_2 (l+1,r);} //call 2-Insertion Sort
};

//**********************************//
// QUICKSORT USING STACKSORT        //
//**********************************//

template <class T> void sedquickstk1 (T * l, T * r) {
  DECLARATIONS();
  T * minelem;
  left = l; right = r;
  while (1) {
    if (right - left > CUTOFF) {
      MEDTHREE();
      *mid = *(j = right - 1);
      PARTITION();
      RESTORE_PIVOT();
      PUSH_SUBPROBLEMS();
    } else {GET_SUBPROBLEM();}
  }
  FIND_SENTINEL();
  stksort1 (l+1,r); //call 2-Insertion Sort
};

//***************************//
// QUICKSORT USING STACKSORT //
//***************************//

template <class T> void sedquickstk (T * l, T * r) 
{
	DECLARATIONS();
	T *minelem;
	T **bptop, *lastptr;
	T * bestpos [100];
	T *maxptr;
	T maxval;
	
	left = l; right = r;
	while (1) {
		if (right - left > CUTOFF) {
			MEDTHREE();
			*mid = *(j = right - 1);
			PARTITION();   
			RESTORE_PIVOT();
			PUSH_SUBPROBLEMS();
		} else {
			if (left == l) {	//we need a sentinel...
				minelem = l;
				for (i = l+1; i<= right; i++) if (*i < *minelem) minelem = i;
				tmp = *l;
				*l = *minelem;
				*minelem = tmp;
				left ++; //stacksort must begin in the second position
			}
			//application of stacksort
			* (bptop = bestpos) = left - 1;
			lastptr = left;
			for (i = right; i > left; i--) {
				maxval = *(maxptr = *(bptop--));
				for (j = lastptr; j <= i; j++) {
					if (*j >= maxval) {
						*(++bptop) = maxptr;
						maxval = *(maxptr = j);
					}
				}
				*maxptr = *i;
				*i = maxval;
				lastptr = maxptr;
			}
			//end of stacksort
			GET_SUBPROBLEM();
		}
	}
};

//***************************//
// QUICKSORT USING STACKSORT //
//***************************//

template <class T> void sedquick_each (T * l, T * r) 
{
	DECLARATIONS();
	T *minelem;
	left = l; right = r;
	while (1) {
		if (right - left > CUTOFF) {
			MEDTHREE();
			*mid = *(j = right - 1);
			PARTITION();   
			RESTORE_PIVOT();
			PUSH_SUBPROBLEMS();
		} else {
			if (left == l) {	//we need a sentinel...
				minelem = l;
				for (i = l+1; i<= right; i++) if (*i < *minelem) minelem = i;
				tmp = *l;
				*l = *minelem;
				*minelem = tmp;
				left ++; //insertion sort must begin in the second position
			}
			//application of insertion sort
			{insertion_sort_1(left,right);}
			GET_SUBPROBLEM();
		}
	}
};

//***************************//
// QUICKSORT USING STACKSORT //
//***************************//

template <class T> void sedquick_each_2 (T * l, T * r) {
  DECLARATIONS();
  T *minelem;
  T **bptop, *lastptr;
  T * bestpos [100];
  T *maxptr;
  T maxval;
  
  left = l; right = r;
  while (1) {
    if (right - left > CUTOFF) {
      MEDTHREE();
      *mid = *(j = right - 1);
      PARTITION();   
      RESTORE_PIVOT();
      PUSH_SUBPROBLEMS();
    } else {
      if (left == l) {	//we need a sentinel...
			minelem = l;
			for (i = l+1; i<= right; i++) if (*i < *minelem) minelem = i;
			tmp = *l;
			*l = *minelem;
			*minelem = tmp;
			left ++; //insertion sort must begin in the second position
      }
      //application of insertion sort
	  {insertion_sort_2(left,right);}


      GET_SUBPROBLEM();
    }
  }
};

class PMRecorder {
	public: 
		 UGint best_iteration;
		UGdouble best_time;
		UGdouble best_value;

		PMRecorder () {
			best_time = 0;
			best_iteration = 0;
			best_value = INFINITEBIG;
			//best_value = INFINITYBIG;
		}

		UGbool report ( UGint iteration, UGdouble time, UGdouble value) {
			if (value < best_value) {
				best_value = value;
				best_time = time;
				best_iteration = iteration;
				return true;
			}
			return false;
		}
};

class   UGPMedian
{//NETWORKANALYST_API
public:
	UGPMedian();
	virtual ~UGPMedian();

public:
	static UGbool PMedianProcess(UGdouble* dMatrix, UGint nDemandCount, UGint nCandicateCount, UGint nMedianCount, 
		UGArray<UGuint> &arrCenterIndex);

private:
	static UGdouble grasp(PMSolution *s, PMConstructive *constructive,  UGint it, PMElite *elite,
						UGchar *lsmethod,UGchar *combmethod,UGbool stats,UGbool partials);
	static UGdouble combineSub(PMSolution *t, PMSolution *s1, PMSolution *s2);
	static UGdouble combine(PMSolution *t, PMSolution *s1, PMSolution *s2, const UGchar* method);
	static void pathRelinking(PMSolution *best_s, PMElite *elite, const UGchar *method, UGbool stats = false);
	static void tabu(PMSolution *s,  UGint it,  UGint itenure,  UGint rtenure,  UGint nelite);
	static void runLocalSearch (PMSolution *s, UGchar *lsmethod);
	static void vns(PMSolution *opt_s,  UGint kmax,  UGint rmax, UGbool rvns, PMElite *elite, UGbool stats);
	static void fastInterchange (PMSolution *s,  UGint *itcount = NULL);
	static void update(PMSolution *s,  UGint in,  UGint out);
	static UGdouble vnds(PMSolution *s, PMElite *elite,  UGint kmax,  UGint bmax, UGbool verb);
	static UGdouble combine_r(PMSolution *t, PMSolution *s1, PMSolution *s2, const UGchar* method);
	static UGdouble combinePartial(PMSolution *t, PMSolution *s1, PMSolution *s2);
	static UGdouble combineSubPR(PMSolution *t, PMSolution *s1, PMSolution *s2);
	static void move(PMSolution *s,  UGint in,  UGint *out, UGdouble *w);
	static PMInstance* readInstance(UGdouble* dCostMatrx, UGint nDemandCount, UGint nCandicateCount, UGint nMedianCount);
	static void updateClosest(PMSolution *s,  UGint u,  UGint *closest,  UGint *closest2);
	static void removeRandom(PMSolution *s,  UGint c);
	static void updateArrays(PMSolution *s, UGbool *affected, SearchTables *tab, UGbool add);
	static UGdouble bestNeighbor(PMSolution *s, SearchTables *tab,  UGint *rcand,  UGint *icand,  UGint *bestr,  UGint *besti,UGbool first);
	static UGdouble search(PMSolution *s, UGbool best_improvement, PMSearch *sm, PMElite *elite, UGbool use_list);
	static void initializeClosest(PMSolution *s,  UGint *closest,  UGint *closest2);
	static UGbool calc1medians(PMSolution *s);
	static UGbool clusterSearch(PMSolution *s);
	static void localSearch(PMSolution *s, UGbool best_improvement, UGbool uselist,  UGint *itcount=NULL, UGbool stats=false) ;
	static UGdouble combinePR(PMSolution *t, PMSolution *s1, PMSolution *s2);
	
};

}

#endif // !defined(AFX_SM_PMEDIAN_H_INCLUDED_)

