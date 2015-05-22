//=====================================================================================
// 项目名：			SuperMap Foundation Class (SFC) Library 2.0
// 作  者：			尹星,
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	06/21/1999
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为SuperMap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGQTreeManager.h
// 类  名：			UGQTreeManager
// 父  类：			
// 子  类：			
// 功能说明：		 处理有关四叉树操作的类。
// 调用说明：		此类主要用于处理在做局部显示时，选择要显示的对象，以及我们用文件代替数据库时，
//					对二维对象的编码建立每一个对象的索引，以便查找。在我们用文件代替数据库时，
//					可以用此类提供的接口处理用户使用SQL语言作以及我们自己定义的空间数据库的操作。
//------------------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////
//使用方法：
//------------------------------------------------------------------------------------------------
//构造了此类的对象后，如用SetEntireBounds()函数确定了整个的矩形，可以使用下列函数：
//		GetIndex()
//		GetRect()
//		Separete()
//------------------------------------------------------------------------------------------------
//若用Create()函数建立了树的存储结构，则可以使用下列函数：
//		Add()
//		Delete()
//		GetKeyNum()
//------------------------------------------------------------------------------------------------
//若既用SetEntireBounds()函数确定了整个的矩形又用Create()函数建立了树的存储结构则可以使用下列函数：
//		GetKeys()
//------------------------------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////
/* 修改说明：
 *		2007.09.24	guohui	为本头文件添加注释
 */
#if !defined(SMQTREEMANAGER_H)
#define SMQTREEMANAGER_H

#include "Base/UGString.h"
#include "UGRect2D.h"
#include "UGQTree.h"

namespace UGC {

class ALGORITHM_API UGQTreeManager
{
public:

	//! \brief 		缺省构造函数
	//! \return 	void
	UGQTreeManager();

	//! \brief 		析够函数
	//! \return 	void
	virtual ~UGQTreeManager();

public:

	//! \brief 		
	//! \return 	
	//! \param 		
	//! \remarks 	

	//! \brief 		获取数据大小
	//! \return 	UGint
	UGint GetDataSize();

	//! \brief 		查询rcBound范围内的所有结点
	//! \return 	UGbool
	//! \param 		rcBound			查询的bounds
	//! \param 		arCertainIDs	肯定在范围内的结点
	//! \param 		arMaybeIDs		可能在范围内的结点
	//! \remarks 	
	UGbool Query(const UGRect2D& rcBound,UGArray<UGint>& arCertainIDs,UGArray<UGint>& arMaybeIDs);
	
	//! \brief 		在某个节点上加入一个键值。
	//! \return 	void
	//! \param 		Index		结点索引.Index是用GetIndex()函数得到的，是一个15层的树的索引.
	//! \param 		Key			键值.Key代表一个对象的键值。
	//! \remarks 	需要先用 create() 建好这棵树。
	void Add(UGint Index,UGuint Key);				

	//! \brief 		建立树的存储结构
	//! \return 	UGbool
	//! \param 		nSep	对整个矩形划分次数，决定了树的层数 = nSep + 1。
	//! \remarks 	
	UGbool Create(UGint nSep);			

	//! \brief 		删除整个这棵树
	//! \return 	void
	//! \remarks 	需要事先用 create() 函数建立好这棵树。
	void Delete();

	//! \brief 		删除一个节点上的所有键值
	//! \return 	void
	//! \param 		Index	节点索引
	//! \remarks 	需要事先用 create() 函数建立好这棵树。
	void Delete(UGint Index);

	//! \brief 		删除一个节点上的某一个键值
	//! \return 	void
	//! \param 		Index	节点索引
	//! \param 		Key		键值
	//! \remarks 	需要事先用 create() 函数建立好这棵树。适用于用户删除数据库中的某些对象时我们对数据库的处理
	void Delete(UGint Index,UGuint Key);

	//! \brief 		得到一个点对象的索引值，
	//! \return 	UGint
	//! \param 		Point	点坐标
	//! \remarks 	需要事先用SetEntireBounds()函数确定了整个的矩形
	UGint GetIndex(const UGPoint2D &Point);

	//! \brief 		得到一个对象的索引值
	//! \return 	UGint
	//! \param 		ItemRect	对象的外包矩形，
	//! \remarks 	需要事先用SetEntireBounds()函数确定了整个的矩形
	UGint GetIndex(UGRect2D ItemRect);

	//! \brief 		得到树中已加入的对象的数量
	//! \return 	UGint
	//! \remarks 	需要事先用create()函数建立好这棵树。
	UGint GetKeyNum();

	//! \brief 		得到一个索引值所代表的矩形
	//! \return 	UGbool
	//! \param 		Index		索引值
	//! \param 		Rect		返回的矩形
	//! \remarks 	需要事先用SetEntireBounds()函数确定了整个的矩形
	UGbool GetRect(UGint Index,UGRect2D &Rect);
	
	//! \brief 		设置整个的矩形的大小
	//! \return 	void
	//! \param 		rc2Entire	矩形范围
	//! \remarks 	以后可以进行取索引值等的操作
	void SetEntireBounds(UGRect2D rc2Entire);

	//! \brief 		获取整个矩形的大小
	//! \return 	UGRect2D
	//! \remarks 	
	UGRect2D GetEntireBounds() const;

	//! \brief 		是否为空
	//! \return 	UGbool
	//! \remarks 	
	UGbool IsEmpty();

	//! \brief 		把R树数据保存到内存数组中
	//! \return 	UGbool
	//! \param 		arData	用来保存R树的数组。
	//! \remarks 	
	UGbool Store(UGMemoryStream& arData);

	//! \brief 		从内存数组中载入R树数据并构建R树。
	//! \return 	UGbool
	//! \param 		arData	R树数据
	//! \remarks 	
	UGbool Load(UGMemoryStream &arData);

protected:		// 与查询相关的函数

	//! \brief 		创建查询条件
	//! \return 	UGString
	//! \param 		rcBound			查询范围
	//! \remarks 	
	UGString BuildFilter(const UGRect2D& rcBound);

	//! \brief 		得到某一个矩形范围theRect内的对象的键值前的准备工作
	//! \return 	void
	//! \param 		theRect			查询范围
	//! \param 		nSep			指定了将包容这个矩形的最小矩形再划分多少次
	//! \param 		nabsSep			指定了当把theRect矩形被分割到整个矩形被分割了nSep次而形成的小矩形的大小的时候就停止再分割了。
	//! \remarks 	在准备得到某一个矩形范围theRect内的对象的键值前调用。	
	//				需要事先用SetEntireBounds()函数确定了整个的矩形，且也需要事先用 create()函数建立好这棵树。	
	void PrepareGetKeys(UGRect2D theRect,UGint nSep,UGint nabsSep);

	//用来遍历已经找到的键值的函数。
	/////////////////////////////////////////////////////////////////////////
	//得到下一个肯定在指定矩形中的对象的Key值。需事先调用PrepareGetKeys()函数。
	UGbool GetNextCertainKey(UGuint &Key);

	//! \brief 		得到下一个可能在指定矩形中的对象的Key值
	//! \return 	UGbool
	//! \param 		Key			获取的键值
	//! \remarks 	需事先调用PrepareGetKeys()函数。
	UGbool GetNextMaybeKey(UGuint &Key);
	
	//! \brief 		得到下一个可能在指定矩形中的对象的Key值
	//! \return 	UGbool
	//! \param 		Key			获取的键值
	//! \remarks 	
	UGbool GetNextHoldKey(UGuint &Key);

	//! \brief 		将指向可能的键值的光标移向第一个可能的键值。
	//! \return 	UGbool
	//! \param 
	//! \remarks
	UGbool MaybeKeysMoveFirst();

	//! \brief		将指向肯定的键值的光标移向第一个肯定的键值。
	//! \return 	UGbool
	//! \param 
	//! \remarks
	UGbool CertainKeysMoveFirst();

private:

	//! \brief		得到一个索引值代表的节点的父节点的索引值。
	//! \return 	UGint
	//! \param		Index		索引
	//! \remarks
	UGint GetParent(UGint Index);

	//! \brief		得到一个索引值所代表的节点为根的树上的节点所对应的索引的范围。
	//! \return 	UGbool
	//! \param		Index			索引
	//! \param		nMinSubIndex	最小索引
	//! \param		nMaxSubIndex	最大索引
	//! \remarks
	UGbool GetIndexRange(UGint nIndex,UGint& nMinSubIndex,UGint& nMaxSubIndex);

	//! \brief		得到一个索引值所代表的节点为根的树上的节点所对应的索引的范围
	//! \return 	UGbool
	//! \param		baseIndex		索引
	//! \param		nMinSubIndex	最小索引
	//! \param		nMaxSubIndex	最大索引
	//! \remarks	要与Seperate()方法得到的Certain的数组中的索引相结合使用。
	UGbool GetIndexPro(UGint baseIndex,UGint& MinIndex,UGint& MaxIndex);
//{{ by guohui 2007.09.30 外部无法使用 暂时封闭
//	//! \brief		获取索引值
//	//! \return 	void
//	//! \param		theRect			
//	//! \param		pHoldArray		
//	//! \param		pMaybeArray		
//	//! \param		pCertainArray	
//	//! \param		nSep			
//	//! \param		nabsSep			
//	//! \remarks	与GetKeys()函数类似，所不同的是得到的是索引值，用户可以根据索引值到数据库中查询相应
//	//				的对象，需要事先用SetEntireBounds()函数确定了整个的矩形。
//	void Separete(UGRect2D theRect,
//				UGArray<UGint> *pHoldArray,
//				UGArray<UGint>* pMaybeArray,
//				UGArray<UGint>* pCertainArray ,
//				UGint nSep,
//				UGint nabsSep);
//}} by guohui 2007.09.30 外部无法使用 暂时封闭

	//! \brief		得到被四个方向的界限包围着的所有的所有索引值，放在两个数组中。
	//! \return 	void
	//! \param		CurIndex			
	//! \param		nLayer		
	//! \param		left		
	//! \param		top	
	//! \param		right			
	//! \param		bottom			
	//! \param		pHoldArray			
	//! \param		pMaybeArray			
	//! \param		pCertainArray			
	//! \remarks	
	void GetInnerIndex(UGint CurIndex,
						UGint nLayer,
						double left,
						double top,
						double right,
						double bottom,
						UGArray<UGint> *pHoldArray,
						UGArray<UGint> *pMaybeArray,
						UGArray<UGint> *pCertainArray);

//用法同公共的方法--GetKeys()一样，只是为了对两种Index不同的处理才分成俩个数组存储

	//! \brief		得到一个索引值它在树中所位于的层数
	//! \return 	UGbool
	//! \param		Index			索引
	//! \param		nLayer			返回层数
	//! \remarks	要与Seperate()方法得到的Certain的数组中的索引相结合使用。
	UGbool GetLayer ( UGint Index,UGint& nLayer );

	//! \brief		
	//! \return 	
	//! \param		
	//! \param		
	//! \remarks	
	void GetNextIndex(UGbool bLeft,UGint& CurLayer,UGint& CurIndex);

	//! \brief		
	//! \return 	
	//! \param		
	//! \param		
	//! \remarks	
	UGRect2D GetNextRect(UGint Index,
						UGint CurLayer,
						UGint CurIndex,
						UGRect2D CurRect);
	
	
private:
	
	//-------- 在得到选中的对象时用到的私有变量。
	UGbool			m_bHoldKeys				;
	UGArray<UGint> *m_pCertainArray			;		//	查询到的结点的数组
	UGint			m_Certain_CurIndexPos	;		//	数组的当前位置
	UGint			m_Certain_CurIndex		;		//	当前的四叉树结点的编码 m_Certain_CurIndex = m_pCertain[m_Certain_CurIndexPos];
	UGint			m_Certain_Max			;
	UGint			m_Certain_Min			;
	UGArray<UGint>* m_pCertain_CurKeyArray	;		//	当前结点中的Keys,m_pCertain_CurKeyArray = m_theTree.GetKeys(m_Certain_CurIndex);
	UGint			m_Certain_CurKeyPos		;
	UGArray<UGint> *m_pHoldArray			;
	UGint			m_Hold_CurIndex			;
	UGArray<UGint> *m_pHold_CurKeyArray		;
	UGint			m_Hold_CurKeyPos		;
	UGArray<UGint> *m_pMaybeArray			;
	UGint			m_Maybe_CurIndexPos		;
	UGint			m_Maybe_CurIndex		;
	UGint			m_Maybe_Max				;			
	UGint			m_Maybe_Min				;
	UGArray<UGint>* m_pMaybe_CurKeyArray	;
	UGint			m_Maybe_CurKeyPos		;
private:  
	
	UGRect2D		m_rc2Entire				;		//	整个的矩形的大小
	UGQTree			m_theTree				;		//	四叉排序树类的对象
};

}

#endif // !defined(SMQTREEMANAGER_H__BF7FEB36_1177_11D3_A5F0_0080C8EE6140__INCLUDED_)

