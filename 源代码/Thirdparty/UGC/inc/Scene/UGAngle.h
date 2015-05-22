/* 
	\file UGAngle.h
	\brief 角度类。
	\author malq,zhangyl
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGANGLE_H__5C430A40_48C7_4E22_8AF1_2860A95001EF__INCLUDED_)
#define AFX_UGANGLE_H__5C430A40_48C7_4E22_8AF1_2860A95001EF__INCLUDED_

#include "Scene/UGPrerequisites.h"

namespace UGC 
{

//! \brief 角度类。
class SCENE_API UGAngle  
{

public:
	
	//! \brief 构造函数。
	UGAngle();	
	
	//! \brief 析构函数。
	virtual ~UGAngle();	

	//! \brief 重载赋值运算。
	//! \param value 角度对象
	void operator =(UGAngle value);
	
	//! \brief 重载赋值运算。
	//! \param value 弧度
	void operator =(UGdouble value);
	
	//! \brief 重载等于运算。
	//! \param obj 等号右边角度对象[in]。
	//! \return true为相等，false为不相等。
	UGbool operator ==(const UGAngle& obj)const;	
	
	//! \brief 重载不相等运算。
	//! \param obj 不等号右边角度对象[in]。
	//! \return true为相等，false为不相等。
	UGbool operator !=(const UGAngle& obj)const;	
	
	//! \brief 重载小于运算。
	//! \param obj 小于号右边角度对象[in]。
	//! \return true为小于，false为不小于。	
	UGbool operator <(const UGAngle& obj)const;

	//! \brief 重载大于运算。
	//! \param obj 大于符号右边角度对象[in]。
	//! \return true为大于，false为不大于。
	UGbool operator >(const UGAngle& obj)const;	

	//! \brief 重载相加运算。
	//! \param obj 加号右边角度对象[in]。
	//! \return 相加后角度对象。
	UGAngle operator +(const UGAngle& obj)const;	
	
	//! \brief 重载加等运算。
	//! \param obj 加等号右边角度对象[in]。
	void operator +=(const UGAngle& obj);  	
	
	//! \brief 重载减号运算。
	//! \param obj 减号右边角度对象[in]。
	//! \return 相减后角度对象。
	UGAngle operator -(const UGAngle& obj)const;	
	
	//! \brief 重载乘法运算。
	//! \param dTimes 乘数[in]。
	//! \return 相乘后角度对象。
	UGAngle operator *(UGReal  dTimes)const;
	
	//! \brief 重载除法运算。
	//! \param dDivisor 除数[in]。
	//! \return 相除后角度对象。
	UGAngle operator /(UGReal  dDivisor)const;	

	//! \brief 获取角度。
	//! \return 角度。
	UGReal GetDegrees() const;	
	
	//! \brief 设置弧度。
	//! \param dRadian 弧度[in]。
	void SetRadian(UGReal dRadian);	
	
	//! \brief 获取弧度。
	//! \return 弧度。
	UGReal GetRadian() const;	
	
	//! \brief 弧度转换成角度对象。
	//! \param dRadians 弧度[in]。
	//! \return 角度对象。
	static UGAngle FromRadians(UGReal dRadians);	
	
	//! \brief 角度转换成角度对象。
	//! \param dDegrees 角度[in]。
	//! \return 角度对象。
	static UGAngle FromDegrees(UGReal dDegrees);	
	
	//! \brief 判断是否为合法实数。
	//! \return true为合法，false为非法。
	UGbool IsNaN()const;	
	
	//! \brief 弧度转换到-PI到PI范围。
	void NormalizeLon();
	//! \brief 弧度转换到-PI到PI范围。
	void NormalizeLat();
	//! \brief 弧度转换到0到2*PI范围。
	void Normalize();

	//! \biref 设置半径伸缩比率
	void SetRadianRatio(UGdouble ratio);

	//! \brief 零常量。
	const static UGAngle ZERO;

	//! \brief 非法常量。
	const static UGAngle NaN;

private:
	
	//! \brief 弧度。
	UGReal m_dRadian;
};

}
#endif // !defined(AFX_UGANGLE_H__5C430A40_48C7_4E22_8AF1_2860A95001EF__INCLUDED_)
