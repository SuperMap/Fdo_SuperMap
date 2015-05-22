#pragma once

class UJBufferImage
{
private:	
	UGint m_nWidth, m_nHeight;
public:
	UJBufferImage();
	UJBufferImage(UGint width,UGint height);
	~UJBufferImage();
	UGint GetWidth();
	UGint GetHeight();
	void SetSize(UGint width,UGint height);
	UGuint* GetColors();
    
	UGImage* m_pUGImage;
};
