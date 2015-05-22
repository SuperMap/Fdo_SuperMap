//=====================================================================================
// 项目名：			SuperMap Foundation Class (SFC) Library 2.0
// 作  者：			尹星，宋关福
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为SuperMap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			SmQTree.h
// 类  名：			UGQTree
// 父  类：			
// 子  类：			
// 功能说明：		可排序线性四叉树管理:创建，增加节点，删除节点,检索等 
// 调用说明：		最多只支持15层四叉树
//=====================================================================================
/* 修改说明：
 *		2007.09.21	guohui	为本头文件添加注释
 */
#if !defined(SMQTREE_H)
#define SMQTREE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGMemoryStream.h"

namespace UGC{

class ALGORITHM_API UGQTree  
{
public:
	UGQTree();
	~UGQTree();
public: //method

	//! \brief 		创建一棵nSep层的四叉树
	//! \return 	UGbool
	//! \param 		nSep	四叉树层数	
	//! \remarks 	nSep属于区间[0,MAX_LAYER].层数从0开始
	UGbool Create(UGint nSep);

	//! \brief 		删除整棵树
	//! \return 	void
	//! \remarks 	
	void Delete();				

	//! \brief		把R树数据保存到内存数组中。
	//! \param		arData 用来保存R树的数组。
	//! \return		UGbool 
	//! \remarks 	成功则返回TRUE。
	UGbool Store(UGMemoryStream& arData);

	//! \brief		从内存数组中载入R树数据并构建R树。
	//! \param		arData R树数据。
	//! \return		UGbool 
	//! \remarks 	成功则返回TRUE。
	UGbool Load(UGMemoryStream &arData,UGint& nPos);

	//! \brief		在节点上增加一个键值
	//! \param		Index 节点索引。
	//! \param		key	  键值
	//! \return		UGbool 
	//! \remarks 	成功则返回TRUE。
	UGbool Add(UGint Index,UGuint Key);

	//! \brief		删除一个节点
	//! \param		Index 节点索引。
	//! \return		void
	void Delete (UGint Index);

	//! \brief		删除一个节点上的键值
	//! \param		Index 节点索引。
	//! \param		key	  键值
	//! \return		void
	void Delete(UGint Index,UGuint Key);
	
	//! \brief		检查索引值是否合法
	//! \param		Index 节点索引。
	//! \return		UGbool 
	//! \remarks 	成功则返回TRUE。
	UGbool Check(UGint &Index);

	//! \brief		计算索引对应子树下的最大和最小索引值
	//! \param		Index 节点索引。
	//! \param		Min	  最小值
	//! \param		Max   最大值
	//! \return		void
	void GetIndexBound(UGint Index,UGint &Min,UGint &Max);

	//! \brief		取得节点上的所有键值
	//! \param		Index 节点索引。
	//! \return		UGArray<UGint>*
	//! \remarks 	返回指针，外面不要释放(delete)。
	UGArray<UGint>* GetKeys(UGint Index);
	
	//! \brief		取得节点上的所有键值
	//! \param		Index 节点索引。
	//! \return		void
	void GetKeys(UGint Index,UGArray<UGint> &Keys);

	//! \brief		批量转换索引值
	//! \param		pArray 索引
	//! \return		UGbool
	UGbool Convert(UGArray<UGint> *pArray);
	
public:	//properties

	//! \brief		获取大小
	//! \return		UGint
	UGint GetDataSize();

	//! \brief		是否为空
	//! \return		UGbool
	UGbool IsEmpty();		

	//! \brief		深度
	//! \return		UGint
	UGint GetDeepth() const;

	//! \brief		键值数目
	//! \return		UGint
	UGint GetKeyCount() const;

	//! \brief		节点数目
	//! \return		UGint
	UGint GetIndexNumber();	

protected:
	UGint m_nKeyCount;
	UGint m_nMaxLayer;	
	UGArray<UGint>** m_pNodeData;
private:

	//! \brief		找到父节点
	//! \return		UGint
	UGint GetParent(UGint Index);

	//! \brief		获取所有键值
	//! \return		void
	void GetAllKeys(UGint Index,UGArray<UGint> &Keys,UGbool bLink);

	//! \brief		转换15层
	//! \return		void
	UGbool Convert(UGint Index,UGint& ConvertedIndex);
};

}
#endif // !defined(SMQTREE_H__76970517_17D9_11D3_A60D_0080C8EE6140__INCLUDED_)
