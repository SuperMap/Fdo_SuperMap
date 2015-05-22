// UGGridOptions.h: interface for the UGGridOptions class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGGRIDOPTIONS_H)
#define UGGRIDOPTIONS_H

#include "UGGridAnalystHeaders.h"
#include "Algorithm/UGRect2D.h"

namespace UGC{	

class GRIDANALYST_API UGGridOptions  
{
public:
	//! \brief How to calculate the result grid?
	enum InterpolationType
	{
		FromPoints = 0,
		FromContours = 1,
		FromPointsNContours = 2
	};
	//! \brief This enum is specificaly for the contour and contour&point interpolation
	enum InterpolationMode
	{
		FourDirections = 0,
		EightDirections = 1
	};
	//! \brief Interpolation methods supported by SuperMap GIS 
	//! \brief The following methods is interploating GRID from scattering points
	enum InterpolationMethods
	{
		IDW = 0,			//! Inverse Distance Weighted Method
		Kriging = 1,		//! Kriging
		MINC  =  2,			//! Minium Curvature
		TrendSurface = 3,	//! Trend Surface/Polynomial Regression
		RBF = 4,			//! Radial Basis Functions
		IDW2 = 5,			//! Modified Shepard's Method 
		TIN = 6,			//! Triangulation with Linear Interpolation	
	};
	//!\brief Specific for the Kriging Mode
	enum VariogramMode
	{
		ExponentialMode = 0,
		GaussianMode = 1,
		Linear = 3,
		Logarithmic = 4,
		NuggetEffect = 5,
		Power = 6,
		Quadratic = 7,
		RationalQuadratic = 8,
		Spherical = 9
	};	
	//!\brief Anisotropy can be expressed with the shape of ellipse;
	//!please refer to corresponding reference
	struct Anisotropy  
	{
		Anisotropy()
		{
			m_fMajorRadius = 0.0f;
			m_fMinorRadius = 0.0f;
			m_fAngle = 0.0f;
		}
		UGfloat m_fMajorRadius; //!the major radius of the ellipse
		UGfloat m_fMinorRadius; //!the minor radius of the ellipse
		UGfloat m_fAngle;  //!the orientation of the ellipse
	};
	struct SearchOptions
	{
		SearchOptions()
		{
			m_bNoSearch = FALSE;
			m_bIsFixedRadis = FALSE;
			m_nSearchCount = 12;
			m_dSearchRadius = 0.0f;
		}
		UGbool m_bNoSearch;//! Use all all the data in the dataset;	
		UGbool m_bIsFixedRadis;
		UGint m_nSearchCount;
		UGdouble m_dSearchRadius;
	};

public:
	UGGridOptions();
	~UGGridOptions();

	void SetInterpolationMethods(const InterpolationMethods methods);
	InterpolationMethods GetInterpolationMethods(void)const;

	void SetAnisotropy(const Anisotropy& aniso);
	Anisotropy GetAnisotropy(void)const;
	
	void SetReportEnable(UGbool bEnable);
	UGbool GetReportEnable(void)const;
		
	void SetBreakLine(UGDatasetVector* pBreakLine);
	UGDatasetVector* GetBreakLine(void)const;
	
	void SetFaultLine(UGDatasetVector* pFaultLine);
	UGDatasetVector* GetFaultLine(void)const;
	
	void SetOutputBounds(const UGRect2D& rcBounds);
	UGRect2D GetOutputBounds(void)const;
	//! \brief set the resolution of the result grid dataset;
	void SetResolution(UGdouble fResolution);
	UGdouble GetResolution(void)const;
	
	//! \brief Set the power we used to calculate the distance;
	void SetPower(UGint nPower);
	UGint GetPower(void)const;
	
	//! \brief Set the semivariogram we used, specifically for the Kriging Methods.
	void SetVariogramMode(VariogramMode nMode);
	VariogramMode GetVariogramMode(void)const;

	//! \brief Set the options when we do searching .
	void SetSearchOptions(SearchOptions nSearchOptions);
	SearchOptions GetSearchOptions()const;
    //! \brief Set the tolerance between 2 points
	UGdouble GetTolerance(void)const;
	void SetTolerance(UGdouble dTolerance);

	UGdouble GetRange(void)const;
	void SetRange(UGdouble dRange);

	UGdouble GetSill(void)const;
	void SetSill(UGdouble dSill);

	UGdouble GetNugget(void)const;
	void SetNugget(UGdouble dNugget);

	InterpolationType GetInterpolationType(void)const;
	void SetInterpolationType(UGGridOptions::InterpolationType enType);

	InterpolationMode GetInterpolationMode(void)const;
	void SetInterpolationMode(InterpolationMode enMode);

	void SetTension(UGdouble dTension);
	UGdouble GetTension()const;

	void SetSmooth(UGdouble dSmooth);
	UGdouble GetSmooth()const;

	void SetStream(UGStream* pStream);
	UGStream* GetStream();

	void SetMaxPointCountInNode(UGint nMaxPointCount);
	UGint GetMaxPointCountInNode()const;

	void SetMaxPointCountForInterpolation(UGint nMaxPointCount);
	UGint GetMaxPointCountInterpolation()const;

	void SwitchQuadTree(UGbool bSwitch);
	UGbool GetSwitchQuadTree()const;

	void SetLagSize(UGdouble dLagSize);
	UGdouble GetLagSize()const;

	void SetLagNums(UGint nNums);
	UGint GetLagNums()const;

protected:
	//the following is the general options for every methods
	InterpolationType m_enInterpType;		//determin the type of the source dataset
	InterpolationMethods m_enInterpMethod;  //the mothods to interpolation
	Anisotropy m_Anisotropy;				//anisotropy is the basic nature in geography enviroment
	SearchOptions m_SearchOptions;			//some search options.
	UGbool m_bReportEnable;					//Switch on/off the report generation
	UGDatasetVector* m_pBreakLine;			//Breakline
	UGDatasetVector* m_pFault;				//Fault
	UGStream* m_pStream;					//The stream to save the final report.
	UGRect2D m_rcBounds;					//Define the bounds of the output rasterdataset
	UGdouble m_dResolution;					//Define the resolution of the rasterdataset	
	UGdouble m_dTolerance;					//we treat the points as the same if the distanace among them is less than the tolerance
	UGint m_nPower;							//the power of the distance.
	InterpolationMode  m_enMode;			//specifically for the grid generation from contours or the contours N points.
   
	//the following is specified for some trees we used.
	UGint m_nMax;							//specified the max points in one quadtree node.
	UGint m_nMax2;							//specified the max points for calculation.
  	UGbool m_bSwitchTree;					//determine whether to use the quadtree method to interpolate grid with kriging.
											//if m_bSwitchTree is true,it will use quadtree
	
	
	//! the following is specified to the Kriging Methods
	VariogramMode m_VariogramMode;			//Vairogram Type
	UGdouble	m_dRange;					//just for the advanced users.			
	UGdouble	m_dSill;					//just for the advanced users.
	UGdouble	m_dNugget;					//just for the advanced users.
	UGdouble    m_dLagSize;					//the size of lag(步长)
	UGint       m_nLagNums;					//the counts of lags,这两个用来减少计算变差函数参数时的计算量

	//! the following is specified to RBF
	UGdouble  m_dTension; 
	UGdouble m_dSmooth; 

};	

}

#endif // !defined(UGGRIDOPTIONS_H)






















