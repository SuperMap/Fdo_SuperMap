/*! \file	 UGXVisual.h
 *  \brief	 provide colormap in corresponding display mode, Display, Visual Type. 6 stipples included.
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGXVisual.h,v 1.5 2007/07/20 01:10:07 xielin Exp $
 */

#ifndef UGXVISUAL_H
#define UGXVISUAL_H

#include "Base/ugdefs.h"

namespace UGC {

//! Visual type
enum UGXVisualType 
{
	VISUALTYPE_UNKNOWN,                 /// Undetermined visual type
	VISUALTYPE_MONO,                    /// Visual for drawing into 1-bpp surfaces
	VISUALTYPE_TRUE,                    /// True color
	VISUALTYPE_INDEX,                   /// Index [palette] color
	VISUALTYPE_GRAY                     /// Gray scale
};

//! Visual describes pixel format of a drawable
class XGRAPHICS_API UGXVisual 
{
protected:
	UGuint        m_nDepth;                  // Visual depth, significant bits/pixel
	UGuint        m_nNumred;                 // Number of reds
	UGuint        m_nNumgreen;               // Number of greens
	UGuint        m_nNumblue;                // Number of blues
	UGuint        m_nNumcolors;              // Total number of colors
	UGuint        m_nMaxcolors;              // Maximum number of colors
	UGXVisualType  m_nType;                   // Visual type
	void         *m_colormap;                // Color map, if any

	// X11
	void         *m_display;
	void         *m_visual;               // Application visual [Visual]

public:
	UGPixel       rpix[16][256];          // Mapping from red -> pixel
	UGPixel       gpix[16][256];          // Mapping from green -> pixel
	UGPixel       bpix[16][256];          // Mapping from blue -> pixel
	UGPixel       lut[256];               // Color lookup table
	
private:
	// X11 Functions
	void setuptruecolor();
	void setupdirectcolor();
	void setuppseudocolor();
	void setupstaticcolor();
	void setupgrayscale();
	void setupstaticgray();
	void setupcolormap();

public:
	//! Construct default visual
	UGXVisual();
	UGXVisual(const UGXVisual &);
	UGXVisual &operator=(const UGXVisual &);

public:		
	//! \brief Get visual type
	UGXVisualType GetType() const { return m_nType; }
		
	//! \brief Get depth, i.e. number of significant bits in color representation
	UGuint GetDepth() const { return m_nDepth; }
	
	//! \brief Get number of colors
	UGuint GetNumColors() const { return m_nNumcolors; }
	
	//! \brief Get number of reds
	UGuint GetNumRed() const { return m_nNumred; }
	
	//! \brief Get number of greens
	UGuint GetNumGreen() const { return m_nNumgreen; }
	
	//! \brief Get number of blues
	UGuint GetNumBlue() const { return m_nNumblue; }
	
	//! \brief Get device pixel value for color
	UGPixel GetPixel(UGColor clr);
	
	//! \brief Get color value for device pixel value
	UGColor GetColor(UGPixel pix);
	
	//! \brief Get maximum number of colors
	UGuint GetMaxColors() const { return m_nMaxcolors; }

	//! \brief Get the X11's Visual
	void *GetVisual() const { return m_visual; }

	//! \brief Get the X11's Colormap
	void *GetColormap() const { return m_colormap; }

	//! \brief Get the X11 Display
	void *GetDisplay() const { return m_display; }
	
	//! \brief SingleTon Mode, Generate one Object only.
	static UGXVisual& GetInstance(); 

	//! \brief Destructor
public:
	~UGXVisual();
};	

}

#endif


