#include "NetworkAnalyst/UGSection.h"
#include "Engine/UGDatasetVector.h"
#include "Base/ugdefs.h"
#include "Geometry/UGGeoLineM.h"

#ifndef UGROUTE_H
#define UGROUTE_H

namespace UGC {

typedef struct tagIndexTemp
{
	UGint nID;
	UGint nIndex;
}NetIndexTemp;

class NETWORKANALYST_API UGRoute 
{
public:
	/*! \brief 缺省构造函数
	*/
	UGRoute();
	/*! \brief 使用其他线性数据（线，网络，刻度线）来构造Route
	*	\param pLinearDt 线性数据集指针；Route的各种计算都将基于这个数据集的数据
	
	*  \remarks
	*/
	UGRoute(UGDatasetVector* pLinearDt);
	
	/*! \brief 拷贝构造函数
	*	\param Route	一个已存在的Route对象，其内容被复制到UGRoute中

	*  \remarks
	*/
	UGRoute(const UGRoute& Route);
	
	/*! \brief  重载赋值操作符
	*	\param Route 一个已存在的Route对象，其内容被复制到UGRoute中

	*  \remarks Route相等
	*/
	UGRoute& operator=(const UGRoute& Route);

	/*! \brief 重载等号操作符
	*	\param Route 一个已存在的Route对象，把它和UGRoute进行比较是否相等

	*  \remarks Route相等的条件是 \n
		1 RouteID相同 \n
		2 每一段Section都相同 \n
		3 所对应的线性数据集指针相同 \n

        m_GeoLineM不影响Route的相等性
	*/
	UGbool operator==(const UGRoute& Route)const;	

	/*! \brief 重载不等号操作符
	*	\param Route 把它和UGRoute进行比较是否相等

	*  \remarks 判断条件和==操作符一致
	*/
	UGbool operator!=(const UGRoute& Route)const;

	/*! \brief 析构函数
	*	\param 
	
	*  \remarks
	*/
	~UGRoute();

public:
	enum RouteCoordPri
	{
		ArcOder    = 0,  //按照数据存储顺序
		UpperLeft  = 1,  //
		UpperRight = 2,
		LowerLeft  = 3,
		LowerRight = 4,
		ExistedPoint=5   //从一个指定的坐标点      
	};
	/*!	\brief	增加一个Section \n
	 *	\param sectionNew     新Section       
	
	 *	\return	返回新加的Section的索引

	 *  \remarks	 
	*/
	
	UGint Add(const UGSection& sectionNew);

	void SetSectionSize(UGint nSectoinSize);
	
	/*!	\brief	删除一个Section \n
	 *	\param nIndex     Section索引

	 *  \remarks	 
	*/
	void RemoveSectionAt(UGint nIndex);

	/*!	\brief	删除所有Section \n
	 *  \remarks	 
	*/
	void RemoveAllSection();

	/*!	\brief	得到指定索引的Section \n
	 *	\param nIndex     Section索引
	 *	\return	返回Section
	 *  \remarks	 
	*/
	UGSection GetSectionAt(UGint nIndex)const;

	/*!	\brief	得到指定索引的Section的引用 \n
	 *	\param nIndex     Section索引
	 *	\return	返回Section的索引
	 *  \remarks	 
	*/
	UGSection& GetElementAt(UGint nIndex);

	/*!	\brief	设置指定索引的Section \n
	 *	\param nIndex     Section索引
	 *  \param Section    要加入Route的新Section
	 
	 *  \remarks	 
	*/
	UGbool SetSectionAt(UGint nIndex, UGSection& Sectoin);
	
	/*!	\brief	得到当前Route的Section数目 \n
	 *	\return	返回Section的数量
	 *  \remarks	 
	*/
	UGint GetSectionCount();

public:
	/*!	\brief	得到指定索引的Section \n
	 *	\return	返回Route的ID 

	 *  \remarks	 
	*/
    UGint GetRouteID();
	
	
	/*!	\brief	设置Route对应的物理线数据集 \n
	 *	\param	pLinearDt 线性数据集（一般是网络）

	 *  \remarks	 
	*/
	void SetLinearDataset(UGDatasetVector* pLinearDt);
public:

	/*!	\brief	从一组Section生成一个刻度线对象
	 *	\param	rcpRoutePri		确定连接Sections的优先方向。缺省为UpperLeft
	 
	 *  \param  strFieldMeasure 线性数据集中存储Measure值的字段.如果设置为Empty,函数则
	                            按照section中m_dFromMeasure,m_dToMeasure设置线标
	 *	\param  bIsSetBlank		对于没有指定Measure的节点，是否设置其刻度为空。
	                            缺省为FALSE;也就是说如果没有指定Measure,就推算其刻度 
	 *	\param 	dStartMeasure   起始线标
	 *	\param 	rcpRoutePri     查找起始点的优先顺序
	 *	\param 	bIsSetBlank	    是否把未指定线标的控制点的线标设置为空
	 *	\param	bIsGapEnabled	是否允许路线有间隔；缺省为TRUE,就是允许有间隔
	 *	\param 	pPointRef		当rcpRoutePri = ExistedPoint，即从一个指定点查找时，指定点的坐标
	 *  \param  dTolerance		线段容限.小于容限的线段自动连成一条线

	 *  \return 创建成功返回TRUE;有任何错误异常返回FALSE.
	 *  \remarks 这个方法所设置的各个参数值会被UGRoute记录下来。再次调用函数时，只需调用不带参数的
	             GetGeoLineM方法，就能够自动按照上次设定的参数计算 
	 */
	 UGbool GetGeoLineM(UGGeoLineM& geoLineM,
					 const UGString& strFieldMeasure,
					 UGdouble dStartMeasure = 0.0,
					 RouteCoordPri rcpRoutePri = ArcOder,
					 UGbool bIsSetBlank = FALSE,
					 UGbool bIsGapEnabled = TRUE,
					 UGPoint2D* pPointRef = NULL,
					 UGdouble dTolerance = EP);
	

	/*! \brief  使用缺省参数构造刻度线
	 *	\return 返回刻度线的指针
	 *  \remarks
	 */
	UGbool GetGeoLineM(UGGeoLineM& geoLineM);

    /*  \brief  从一个记录集生成一条LineM。即把一组线按照参数要求的形式变成一条LineM
	 *	\param	pRecordset      线，网络数据集弧段，LineM记录集
	 *	\param	geoLineM        计算结果
	 *	\param	rcpRoutePri		确定连接Sections的优先方向。缺省为UpperLeft
	 
	 *  \param  strFieldMeasure 线性数据集中存储Measure值的字段。如果设置为empty，则按照长度设置线标 
	 *	\param  bIsSetBlank		对于没有指定Measure的节点，是否设置其刻度为空。
	                            缺省为FALSE;也就是说如果没有指定Measure,就推算其刻度 
	 *	\param 	dStartMeasure   起始线标
	 *	\param 	rcpRoutePri     查找起始点的优先顺序
	 *	\param 	bIsSetBlank	    是否把未指定线标的控制点的线标设置为空
	 *	\param	bIsGapEnabled	是否允许路线有间隔；缺省为TRUE,就是允许有间隔
	 *	\param 	pPointRef		当rcpRoutePri = ExistedPoint，即从一个指定点查找时，指定点的坐标
	 *  \param  dTolerance		线段容限.小于容限的线段自动连成一条线

	 *  \return 创建成功返回TRUE;有任何错误异常返回FALSE.
	 *  \remarks 
	*/
	UGbool GetGeoLineM(UGRecordset* pRecordset,
					 UGGeoLineM& geoLineM,	
					 const UGString& strFieldMeasure = (""),
					 UGdouble dStartMeasure = 0.0,
					 RouteCoordPri rcpRoutePri = ArcOder,
					 UGbool bIsSetBlank = FALSE,
					 UGbool bIsGapEnabled = TRUE,
					 UGPoint2D* pPointRef = NULL,
					 UGdouble dTolerance = EP);

	/*! \brief 内插Measure
	 *  \param nFromIndex   起始Section索引
	 *  \param nToIndex     终止Section索引
	 *  \return 
	 *  \remark
	*/
    UGbool InerpolateMeasure(UGuint nFromIndex,UGuint nToIndex);  

	/*! \brief 外推Measure
	 *  \param nExtropolateStyle   外推方式
	 *  \param nFromIndex   起始Section索引
	 *  \param nToIndex     终止Section索引
	 *  \return 
	 *  \remark
	*/
	//UGbool ExtrapolateMeasure(UGuint nFromIndex,UGuint nToIndex = 0,UGGeoLineM::SmHowToComputeMeasure nExtropolateStyle = UGGeoLineM::SmExtropolateBefore); 
	
	
	/*! \brief 刻度平移
	 *  \param dOffset   平移量
	 *  \return 
	 *  \remark
	*/
	void OffsetMeasure(UGdouble dOffset);	  

	/*! \brief 从距离得到刻度
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGdouble GetMAtDistance(UGdouble dDistance );
	
	/*! \brief 根据距离设置刻度
	 *  \param 
	 *  \return
	 *  \remark
	*/
	void SetMAsDistance();  

	
	/*! \brief  从刻度得到距离
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGdouble GetDistanceAtM(UGdouble dMeasure);
	
	/*! \brief 从刻度得到坐标
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGPoint2D GetCoordinateAtM(UGdouble dMeasure);

	
	/*! \brief 从刻度得到曲线
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool GetSubCurveAtM(UGGeoLine& GeoLine,UGdouble dFromMeasure,UGdouble dToMeasure );  

	/*! \brief 推算无刻度位置处的刻度值
	 *  \param 
	 *  \return
	 *  \remark
	*/
	void CaculateNoM();     

	/*! \brief 在指定位置插入刻度值
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool InsertMAtDistance(UGdouble dDistance,UGdouble dMeasure); 

	/*! \brief 	翻转刻度
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool ReversMOrder();      

	/*! \brief 从字段、长度更新刻度
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool UpdataBy();  

	/*! \brief 从字段、长度重新标注刻度
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool CalibrateBy();

	

//	ConvertToNetWork();

//	Calibrate();
//	Measure();
	
	
//	CreateFromNetWork();
	
	UGbool Split();

private:
	/*! \brief 根据距离线起点的百分比得到点的坐标
	 *	\param pLine  线指针 这条线一定是简单线 否则返回点坐标为(0,0)
	 *  \param dPos   距离线起点的百分比.如60,表示百分之60
	 *  \param pIndex 线的起点和结果点之间，距结果点最近的一个线控制点索引号.
	 *  \return 返回结果点坐标
	 *  \remark
	 */
	UGPoint2D GetXYAtPos(UGGeoLine* pLine, UGdouble dPos, UGint* pIndex  = NULL);

	/*! \brief 得到距离某个点最近的几何对象
	 *	\param arrGeometryID 几何对象的ID
	 *  \param arrGeometry   几何对象指针 
	 *  \param pntRef        参考点
	 *  \param bAscending    几何对象的起点和参考点最近为TRUE,终点和参考点最近为FALSE 
	 *  \return 返回几何对象在数组中的索引号
	 *  \remarks 这里只是求出几何对象的起点和终点，然后计算这些点和参考点的距离最近的
	 */
	UGint GetNearestGeometry(const UGArray<UGint>& arrGeometryID, 
		                    const UGArray<UGGeometry*>& arrGeometry, 
							const UGPoint2D& pntRef,UGbool& bAscending);
	/*! \brief  求一组刻度线中距参考点最近的对象
	 *	\param arrPointsM  刻度线坐标
	 *  \param pntRef      参考点坐标
	 *  \return  返回最近的刻度线在数组中的索引号
	 *  \remarks  几何对象的起点和参考点的距离最近，就认为几何对象和参考点最近
	 */
	UGint GetNearestGeometry(const UGArray<UGPoint3D*>& arrPointsM,
							const UGPoint2D& pntRef);

	/*! \brief  根据优先次序得到需要的参考点
	 *	\param  pRecordset 记录集
	 *  \param  rcpPri     优先次序
	 *  \return 返回参考点坐标
	 *  \remarks 根据pRecordset所在的数据集计算参考点。UpperLeft就是左上角，其他类推
	            如果pRecordset为NULL,则对m_pDtLinear计算
	 */
    UGPoint2D GetRefPoint(UGRecordset* pRecordset,RouteCoordPri rcpPri);

	/*! \brief  把一条普通线(可以是复杂线)转成刻度线
	 *	\param  pGeoLine      普通线指针
	 *  \param  pPointM       结果指针。应该被调用者释放
	 *  \param  nPointsMCount 刻度线控制点数目
	 *  \param  dStartMeasure 起始刻度
	 *  \param  dMeasure      线刻度值
	 *  \param  bIsGapEnabled 如果线有多个子对象，是否允许间隔
	 *  \param  bAscending    如果从线起点起算，为TRUE;从终点起算为FALSE
	 *  \param  dTolerance    计算间隔的容限
	 *  \return 返回刻度线控制点的数目
	 *  \remarks 如果线有多个子对象，且子对象并不连续。程序只会生成一条简单的刻度线
	            方法如下：
	            1.如果允许间隔(bIsGapEnabled == TRUE):会把把这些子对象连接成一条线。
				  如果不希望这种效果，应该把对象打散成多个简单对象，然后处理。
                2.如果不允许间隔(bIsGapEnabled != TRUE):只把首尾相连的对象加入，
				  并在第一个间隔跳出 
	 */
	UGint ConvertLineToM(UGGeoLine* pGeoLine, 
						UGPoint3D* pPointM,UGint nPointsMCount, 
						UGdouble dStartMeasure = 0.0,UGdouble dMeasure = -1.0,
						UGbool bIsGapEnabled = TRUE, UGbool bAscending = TRUE, 
						UGdouble dTolerance = EP);	
	
	/*! \brief  两点的距离是否在容限内
	 *	\param  pnt1
	 *  \param  pnt2
	 *	\param  dTolerance
	 *  \return 
	 *  \remarks             
	 */	
	UGbool IsPointsInTolerance(const UGPoint2D& pnt1,const UGPoint2D& pnt2,UGdouble dTolerance);

	/*! \brief  把section转成一组刻度线
	 *	\param  arrPointsM  
	 *  \param  arrPointsMCount
	 *	\param  strFieldMeasure 
	 *	\param  dStartMeasure
	 *  \return 
	 *  \remarks 如果strFieldMeasure为空，则使用section的FromM和ToM来计算Measure。
	            否则，根据线数据集strFieldMeasure字段和dStartMeasure来计算Measure。
	 */	
	UGbool SectionToPointsM(UGArray<UGPoint3D*>& arrPointsM,
						  UGArray<UGint>& arrPointsMCount,
						  const UGString& strFieldMeasure, 
						  UGdouble dStartMeasure = 0.0);
	
	UGString BuildQueryFilter(UGArray<UGuint> &arrKeys,const UGString strFieldName);
	
private:
	
	UGDatasetVector* m_pDtLinear;/// 物理线数据集
	
	void q_Sort(UGSection *pData, UGint nCount);
	UGint FindIndex(UGint nArcID,UGSection* pSection,UGint nCount);

	UGint FindIndex(UGint nArcID,NetIndexTemp* pNetIndex,UGint nCount);
	

private:
	/*! \brief Section数组 
	 */
	UGArray<UGSection> m_Route; 
	
	/*! \brief Route ID
	*/
	UGint m_nRouteID;
	
	/*! \brief 刻度线对象
	*/
	UGGeoLineM m_GeoLineM;

	/*! \brief 是否需要重新构建刻度线。当m_Route发生变化时为真。
	*/
	UGbool m_bIsNeedRebuild;

	/*! \brief 存储刻度信息的字段
	*/
	UGString m_strFieldMeasure;

	/*! \brief 起始线标
	*/
	UGdouble m_dStartMeasure;
	/*! \brief 连接线段时的优先次序
	*/
    RouteCoordPri m_rcpRoutePri;

	/*! \brief 对于没有刻度值的节点是否设置刻度为空
	*/
    UGbool m_bIsSetBlank ;

	/*! \brief 是否允许刻度线有间隔
	*/
    UGbool m_bIsGapEnabled;

	/*! \brief 依次连接的起点
	 *	
	 */
	UGPoint2D* m_pntRef; 
	
	/*! \brief 连接线段的容限；如果线段的间隔小于容限，就连成一段线
	*/
    UGdouble m_dTolerance;
};

}

#endif
