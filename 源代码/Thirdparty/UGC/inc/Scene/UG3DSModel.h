// UG3DSModel.h: interface for the UG3DSModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DSMODEL_H__C2B90449_7153_444F_B4A1_3229B6A8332D__INCLUDED_)
#define AFX_UG3DSMODEL_H__C2B90449_7153_444F_B4A1_3229B6A8332D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGModel.h"

namespace UGC
{
	//有符号
	typedef UGuchar Byte;
	typedef UGushort Word;
	typedef UGuint DWord;
class SCENE_API UG3DSModel:public UGModel  
{
public:
	UG3DSModel();
	UG3DSModel(const UGString& strModelPath );
	virtual ~UG3DSModel();
	
protected:
	virtual UGbool ReadModel(const UGString& filename);
	virtual void GenRenderOperation();
	//virtual void Unitize();

private:
 void BeforeLoading();
 void AfterLoading();

	/*--与Mesh网格数据信息有关的数据存储函数-----------*/
 void UseObject();
 void  UseObjectName(const UGString& name);	      //0x4000
 void  UseTriMesh();                              //0x4100
 UGReal* UseMeshVertex(UGint nCount);             //0x4110
 void* UseMeshFace(UGint nCount);                 //0x4120
 void  UseMeshMaterialName(const UGString& name); //0x4130
 void* UseMeshTexCoord(UGint nCount);              //0x4140
 void UseMeshLocalO(UGfloat x,UGfloat y,UGfloat z){}
 void UseMeshLocalN(UGfloat x,UGfloat y,UGfloat z){}
 void UseMeshLocalV(UGfloat x,UGfloat y,UGfloat z){}
 void UseMeshLocalU(UGfloat x,UGfloat y,UGfloat z){}

	/*--与Material材质数据信息有关的数据存储函数--------*/
 void UseMaterial();
 void UseMaterialName(const UGString& name);
 void UseMaterialMapFileName(const UGString& name);  
 void UseMaterialAmbient(Byte red,Byte green,Byte blue);
 void UseMaterialDiffuse(Byte red,Byte green,Byte blue);
 void UseMaterialSpecular(Byte red,Byte green,Byte blue);
 void UseMaterialShininess(Word shin);
 void UseMaterialTransparency(Word trans);
 void UseMeshMaterialFacet(Word num,Word* pFaceIndex,const UGString& matName);

protected:	
		struct UG3dsString
		{
			UGchar string[256];
		};
		
		class SCENE_API UG3dsFile
		{//负责文件的字节流的读取
		public:
			UG3dsFile():m_pFile(0){}
			~UG3dsFile(){ Close();}
			
			UGbool Open(const UGString& fileName);
			void Close();
			UGbool CheckFileFormat();
			void Seek(UGlong offset, UGint origin);
			size_t Read( void *buffer, size_t size, size_t count)
			{return fread(buffer,size,count,m_pFile);}
			
			Byte  ReadByte();
			UGushort  ReadWord();
			DWord ReadDword();
			UGfloat ReadFloat();
			UGint ReadString(UG3dsString& str);
			
			FILE* m_pFile;
		};
		
		//{{=====3DS Chunk块标识=========================		
		enum
		{
			    SM3DS_PRIMARY = 0x4D4D,    //主块(Primary Chunk)
				
				//{{主编辑块
				SM3DS_EDIT = 0x3D3D,       //主编辑块(Edit Chunk)
				
				SM3DS_EDIT_OBJECT = 0x4000,//物体信息块
				
				SM3DS_TRIMESH_INFO = 0x4100,//三角网格信息
				
				SM3DS_MESH_VERTEX = 0x4110, //顶点列表
				SM3DS_MESH_FACE   = 0x4120, //三角面列表
				SM3DS_FACE_MAT    = 0x4130,
				SM3DS_FACE_SMOOTH = 0x4150,
				SM3DS_MESH_TEXCOORD = 0x4140, //纹理坐标
				SM3DS_MESH_LOCAL    = 0x4160, //转换矩阵
				
				
				
				SM3DS_EDIT_MAT =0xAFFF,
				
				SM3DS_MAT_NAME =0xA000,    //材质名称
				SM3DS_MAT_AMBIENT        = 0xA010, //材质的环境颜色
				SM3DS_MAT_DIFFUSE        = 0xA020, //材质的散射颜色
				SM3DS_MAT_SPECULAR       = 0xA030, //材质的镜面反射颜色
				SM3DS_MAT_SHININESS      = 0xA040, //材质的镜面反射参数
				SMEDS_MAT_TRANSPARENT    = 0xA050, //材质的透明度
				SM3DS_MAT_TEXTURE        = 0xA200,
				SM3DS_MAT_TEXTUREMAPFILE = 0xA300,   //纹理贴图的文件名称
				
				//}}主编辑块
				
				//{{关键帧块 KeyFrame Chunk
				SM3DS_PRIM_KEY =0xB000,
				SM3DS_KEY_INFO =0xB008,
				SM3DS_KEY_MESH =0xB002,
				SM3DS_KEYF_HIERARCY =0xB010,
				SM3DS_KEYF_DUMMY    =0xB011,
				SM3DS_KEYF_PIVOT    =0xB013,
				SM3DS_TRACK_POS     =0xB020,
				SM3DS_TRACK_ROT     =0xB021,
				SM3DS_TRACK_SCL     =0xB022,
				SM3DS_KEYF_NODEID   =0xB030,
				//}}关键帧Chunk
				
				//some chunks in all others
				SM3DS_RGB_FLOAT        = 0x0010,
				SM3DS_RGB_BYTE         = 0x0011,
				SM3DS_RGB_BYTE_GAMMA   = 0x0012,
				SM3DS_RGB_FLOAT_GAMMA  = 0x0013,
				SM3DS_PERCENTAGE_WORD  = 0x0030,  //0~100的数值
				SM3DS_PERCENTAGE_FLOAT = 0x0031
				
		};
		//}}=====3DS Chunk块标识===================
		
		/*----------------------------------------------------------------------
		chunk是3ds文件的基本构成单位。每一个chunk包括一个头和一个主体。
		chunk的头又由两部分组成：
		1、ID of Chunk(块的标识，ID表示chunk的含义，长一个字)
		2、Length of Chunk(块的长度『以字节为单位，包括头和主体』，长一个双字)
		-----------------------------------------------------------------------*/
		typedef struct CHUNK_3DS_HEADER 
		{
			UGushort ID;
			UGuint Length;
		}UG3dsChunk;
		
		
		void ReadByteRGB(Byte &red,Byte &green,Byte &blue);
		void ReadFloatRGB(UGfloat &red,UGfloat &green,UGfloat &blue);
		void ReadBytePercentage(Byte &per);
		void ReadFloatPercentage(UGfloat &per);
		
		void ReadChunkHeader(UG3dsChunk& chunk);
		
		void ProcessPrimaryChunk();
		void ProcessEditChunk(DWord length);
		void ProcessKeyFrameChunk(DWord length);
		
		void ProcessObjectChunk(DWord length);
		void ProcessMaterialChunk(DWord length);
		
		void ProcessTriMeshChunk(DWord length);
		
		//{{读取网格数据
		void ReadMeshVertexs();
		void ReadMeshTexCoords();
		void ReadMeshFaces(DWord length);
		void ReadMeshLocal();
		//}}
		
		void ProcessMatTextureChunk(DWord length);  //纹理
		void ReadAmbientColor(DWord length);
		void ReadDiffuseColor(DWord length);
		void ReadSpecularColor(DWord length);
		void ReadShininess(DWord length);
		void ReadTransparency(DWord length);
		
protected:
	UG3dsFile m_3dsFile;
	UGString m_TmpMeshName;

	};
	//{{========C3ds==========================================
inline void UG3DSModel::ReadChunkHeader(UG3dsChunk& chunk)
{
	chunk.ID = m_3dsFile.ReadWord();
	chunk.Length = m_3dsFile.ReadDword();
}
//}}========C3ds==========================================

}



#endif // !defined(AFX_UG3DSMODEL_H__C2B90449_7153_444F_B4A1_3229B6A8332D__INCLUDED_)
