// UGODBCEditRecordset.h: interface for the UGODBCEditRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCEDITRECORDSET_H__1C3999AE_CE83_4B30_A906_93F4E72BA8C0__INCLUDED_)
#define AFX_UGODBCEDITRECORDSET_H__1C3999AE_CE83_4B30_A906_93F4E72BA8C0__INCLUDED_

#include "UGODBCRecordset.h"

namespace UGC
{

class UGEXPORT UGODBCEditRecordset : public UGODBCRecordset
{
public:
	UGODBCEditRecordset();
	virtual ~UGODBCEditRecordset();

public:
	//! \brief  更新，提交修改
	virtual UGint Update();

	//! \brief  取消修改
	virtual UGbool CancelUpdate();

	//! \brief  是否可添加
	virtual UGbool CanAppend();
	
	//! \brief  是否可更新
	virtual UGbool CanUpdate();

	//! \brief  开始修改数据
	virtual UGbool Edit();

	//! \brief 增加新记录,成功，返回TRUE值，失败返回FALSE值；
	//! \param *pGeometry [in] 添加的Geometry指针
	//! \param bReturnID=FALSE [in] 此参数已经不起作用。
	//! \return True 和 False 的值
	//! \remarks 如果想得到新对象的ID，那么马上调用GetId方法
	virtual UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE);

	//! \brief  删除当前记录
	virtual UGbool Delete();

	//! \brief  通过字段名设置当前记录的字段值,值为变体类型
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGVariant& varVal);
	
	//! \brief  通过字段名设置当前记录的字段值,值为字符串类型
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGString& strVal);
	
	//! \brief  通过索引序号设置当前记录的字段值,值为变体类型
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGVariant& varVal);

	//! \brief  通过索引序号设置当前记录的字段值,值为字符串类型
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGString& strVal);

	//! \brief  通过字段名设置字段值为空
	virtual UGbool SetFieldValueNull(const UGString& strName);

	//! \brief  通过索引设置字段值为空
	virtual UGbool SetFieldValueNull(UGint nIndex);


	//! \brief  刷新记录
	virtual void FlushCurrentRecord();

	//! \brief  给定相应的数,向前或向后移动记录指针
	virtual UGbool Move(UGint nRows);

	//! \brief  移动记录指针到最前
	virtual UGbool MoveFirst();

	//! \brief  移动记录指针到最后
	virtual UGbool MoveLast();

	//! \brief  向下移动一位记录指针
	virtual UGbool MoveNext();

	//! \brief  向上移动一位记录指针
	virtual UGbool MovePrev();

	//! \brief  移动记录指针到指定位置
	virtual UGbool MoveTo(UGint nRow);

	//! \brief  通过ID定位记录指针
	virtual UGbool SeekID(UGint nID);

	//! \brief  取得几何对象，返回的几何对象指针在函数内分配内存，
	//! \brief  外面负责删除，否则会有内存泄漏
	virtual UGbool GetGeometry(UGGeometry*& pGeometry);

	//! \brief  通过字段名获取字段值
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varVal);

	//! \brief  通过索引序号获取字段值
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varVal);

	//! \brief  获取当前记录的ID
	virtual UGint GetID();

	//! \brief 删除所有的记录
	virtual UGbool DeleteAll();

	//! \brief  复制字段值,strSrcField和
	//! \brief  strDestField必须都存在且字段类型匹配
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);

protected:
	//! \brief 	General查询
	virtual UGbool CreateWithGeneral(const UGQueryDef &querydef);

	//! \brief IDs查询
	virtual UGbool CreateWithIDs(UGint *pIDs,UGint nCount,UGString &strFieldName);

	//! \brief 	Bounds查询
	/// \param	[in]	  rc2Bounds 查询范围
	//! \return	bool
	virtual UGbool CreateWithBounds(const UGRect2D &rc2Bounds, UGint nOptions, UGint  nMode);
	
	//! \brief  设置当前记录的几何对象
	virtual UGbool SetGeometry(UGGeometry &geometry);

	//! \brief  重新计算内存
	void ReAllocGeoBuffer(UGint nRawSize);

	//! \brief  重新绑定
	void RebindGeoBuffer(UGint nRawSize);

	//! \brief  计算内存位置
	UGint GetFieldBufferPos(UGint nPos);

	//! \brief AddNew之后，如果想得到字段值，可以这样处理
	//! \param strName [in] 字段名字
	//! \param varVal [out] 字段值
	//! \return 主要思路是要保持AddNew之后的效果。一旦AddNew那么游标就在AddNew的位置。
	UGbool GetAddNewFieldValue(const UGString& strName,UGVariant& varVal);

private:
	//! \brief  取数据
	UGbool FetchData(const UGString & strSQL);

	//! \brief  取ID
	UGbool FetchIDs();

	//! \brief  判断字段是否已经更改
	UGbool IsFieldModifyed(const UGString &strFieldName);

	//! 获取当前记录ID
	UGint GetRealID();

	//! \brief  版本数据集的编辑
	UGint U_UpdateDataVersion();

	//! \brief  版本数据集删除操作
	UGbool U_DeleteWithDV();



protected:
	UGint m_nCurrentID;
	UGint m_nCurrentDataIndex;

	UGODBCBinds m_CurrentBinds;
	UGODBCBind  m_OdbcBind;
	UGFieldInfos m_CurrentModifiedFieldInfos;

	UGRect2D m_RectOldBounds;
	UGRect2D m_RectNewBounds;

	/// \brief 当前游标中的空间对象,只有在编辑的时候才起到作用
	UGGeometry* m_pGeometry;
};

}

#endif // !defined(AFX_UGODBCEDITRECORDSET_H__1C3999AE_CE83_4B30_A906_93F4E72BA8C0__INCLUDED_)
