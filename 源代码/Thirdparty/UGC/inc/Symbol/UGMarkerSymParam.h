// UGMarkerSymParam.h: 

#ifndef UG_MARKERSYMPARAM_H
#define UG_MARKERSYMPARAM_H

#include "UGSymPoint.h"
#include "Algorithm/UGPoint.h"

namespace UGC 
{

class UGPen;
class UGBrush;
class UGFont;
class UGRgn;


/** 点符号坐标转换及显示参数
	@remarks
		该类有2个作用：
		1。在真正绘制之前，调用坐标转换函数Transform()，
		   将点符号的定义点坐标转换为画布上的逻辑坐标；
		2。记录绘制显示时的一些控制参数，如下：
				    m_Color --> 符号显示的颜色   
			   m_bHighlight --> 符号是否要高亮显示
				m_pntAnchor --> 符号原点在显示区域中的对应点(称为Anchor，在显示坐标下)
			 m_nDisplaySize --> 符号在显示设备上需要显示的大小(单位由显示设备的映射模式来确定)
				   m_dAngle --> 符号旋转的角度(单位:度)
				   m_dScale --> 符号显示缩放的比例系数(基于m_nDisplaySize的大小基础上缩放)
		   外部在调用点符号的绘制函数UGPointSymbol::Draw()之前，要先
		   设定该类中的这些显示控制参数，设定后再传递给Draw函数
*/
class SYMBOL_API UGMarkerSymParam  
{
public:

	/** 该数据结构体用于点符号笔划绘制过程中，记录新创建的GDI对象指针
	*/
	struct UGGraphicsObjects
	{
		UGGraphicsObjects();
		//deleted by xielin 这里用析构，再release下编译drawing工程编译不过，原因还不清楚，现在修改成提供deleteall方法，外面调用一下来释放
		//~UGGraphicsObjects();

		void NewPen();
		void NewBrush();
		void NewFont();
		void NewRgn();
		void DeleteAll();

		UGPen*   m_pOldPen;
		UGBrush* m_pOldBrush;
		UGFont*  m_pOldFont;

		//! UGC的虚拟引擎创建(new)出GDI对象，注意：使用后需要自己来释放
		UGPen*   m_pNewPen;
		UGBrush* m_pNewBrush;
		UGFont*  m_pNewFont;

		//! 为HitTest而准备的Rgn,仅用于点符号的HitTest中,不会被选入到graphics中
		UGRgn*  m_pNewRgn;

	};

public:
	UGMarkerSymParam();
	//added by xielin 增加析构函数
	~UGMarkerSymParam();
public:	
	void SetAngle(UGdouble dAngle)
	{
		m_dAngle = dAngle;
	}

	UGdouble GetAngle() const
	{
		return m_dAngle;
	}
	
	void SetAnchor(const UGPoint& pntAnchor)
	{
		m_pntAnchor = pntAnchor;
	}

	const UGPoint& GetAnchor() const
	{
		return m_pntAnchor;
	}
	
	void SetColor(UGColor color)
	{
		m_Color = color;
	}

	UGColor GetColor() const
	{
		return m_Color;
	}
	
	void SetScale(UGdouble dScale,UGdouble dScaleX=0)
	{
		m_dScale = dScale;
		//{{ 添加设置x方向的缩放比例系数 modified by dongfei 2007-03-29
		m_dScaleX = dScaleX;
		//}} 添加设置x方向的缩放比例系数 modified by dongfei 2007-03-29
	}

	UGdouble GetScale() const
	{
		return m_dScale;
	}
	//! \brief 获取X方向的缩放比例系数 added by dongfei 2007-03-29
	UGdouble GetScaleX() const
	{
		return m_dScaleX;
	}
	void SetHighlight(UGbool bHighlight = true)
	{
		m_bHighlight = bHighlight;
	}

	UGbool IsHighlight() const
	{
		return m_bHighlight;
	}

	void SetDisplaySize(UGint nSize)
	{
		m_nDisplaySize = nSize;
	}

	UGint GetDisplaySize() const
	{
		return m_nDisplaySize;
	}

	void SetPointSymOrg(const UGSymPoint& pntOrg)
	{
		m_pntPointSymOrg = pntOrg;
	}
	
	const UGPoint* GetPointBuffer() const
	{
		return m_PointBuf.GetData();
	}

	UGPoints& GetBuffer()
	{
		return m_PointBuf;
	}

	UGint GetPointCount() const
	{
		return m_PointBuf.GetSize();
	}

	void SetDeviceYAxisDirection(UGbool bYAxisUp)
	{
		m_bDeviceAxisYUp = bYAxisUp;
	}

	UGbool IsDeviceYAxisUp()
	{
		return m_bDeviceAxisYUp;
	}

	UGMarkerSymParam::UGGraphicsObjects& GetGraphicsObject()
	{
		return ms_GObjects;
	}

	const UGMarkerSymParam::UGGraphicsObjects& GetGraphicsObject() const
	{
		return ms_GObjects;
	}
	
	/** 将符号的『点定义坐标』转换为显示区域内的『显示逻辑坐标』
		pSymPoints: 点定义坐标
		nCount：    点的个数
		bRotate：   是否旋转
	*/
	void Transform(const UGSymPoint* pSymPoints, UGint nCount, UGbool bRotate = TRUE );
	void Transform(const UGPoint* pPoints, UGint nCount, UGbool bRotate = TRUE );

	//added by lugw 2007-04-16
	//! \brief 符号的透明度
	void SetTransPercent(UGint nTransPercent);
	UGint GetTransPercent();

	//! \brief 符号的渐变相关设置
	void SetGradientEndColor(UGColor EndColor);
	UGColor GetGradientEndColor();

	void SetGradientRadian(UGdouble dRadian);
	UGdouble GetGradientRadian();

	void SetGradientHOffsetCenter(UGint nHOffsetCenter);
	UGint GetGradientHOffsetCenter();

	void SetGradientVOffsetCenter(UGint nVOffsetCenter);
	UGint GetGradientVOffsetCenter();

	void SetGradientGradientType(UGint nType);
	UGint GetGradientGradientType();

protected:

	UGdouble Minus(UGdouble value)
	{
		//如果显示设备Y轴正方向向上，就取负值，否则不取负值
		return m_bDeviceAxisYUp ? -value : value;
	}
	
private:
    //! 符号显示的颜色
 	UGColor m_Color;

	//! 符号是否要高亮显示
	UGbool  m_bHighlight;

	//! 符号原点在显示区域中的对应点，也就是符号所要显示的位置(称为Anchor，在显示坐标下)
	UGPoint m_pntAnchor; 

	//! 符号在显示设备上需要显示的大小(单位由显示设备的映射模式来确定)
	UGint m_nDisplaySize;

	//! 符号旋转的角度(单位:度)
	UGdouble m_dAngle;

	//! 符号显示缩放的比例系数(基于m_nDisplaySize的大小基础上缩放)
	UGdouble m_dScale;   
	//! brief 添加一个X方向的缩放比例系数，如果为0，则采用与m_dScale相同的系数，这时
	//m_dScale表示整个符号的比例系数，不为0，则m_dScale是高度的比例系数 added by dongfei 
	//2007-03-29
	UGdouble m_dScaleX;

	//! 显示设备坐标系Y轴是否向上(用于将符号点定义坐标转换成显示逻辑坐标,在Transform()函数中用到)
	UGbool m_bDeviceAxisYUp; 

	//! 点符号在符号坐标系统中的原点(符号点坐标转换时需要这个信息,在Transform()函数中用到)
	UGSymPoint m_pntPointSymOrg;
	
	//! 逻辑点串缓冲，用来存放转换后的逻辑坐标点(UGSymPoint-->UGPoint)
	UGPoints m_PointBuf;

	//modified by xielin 2007-12-27 现在要支持多线程，全局就不行了，改掉
	//! 用于点符号绘制过程中记录新创建GDI对象和graphics选入新对象前的原来的old对象
	//! 静态成员变量，整个程序中共享一份就够了
	UGMarkerSymParam::UGGraphicsObjects ms_GObjects;
	
	//! \brief 符号的透明度
	UGint m_nTransPercent;

	//! \brief 符号的渐变相关参数
	UGColor              m_EndColor;       //渐变的背景色
	UGdouble             m_dRadian;        //渐变的角度
	UGint                m_nHOffsetCenter; //渐变的水平偏移量
	UGint                m_nVOffsetCenter; //渐变的竖直偏移量
	UGint				 m_nGradientType;  //渐变的类型
};

}

#endif
