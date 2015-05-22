// UGFrameStamp.h: interface for the UGFrameStamp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGFRAMESTAMP_H)
#define UGFRAMESTAMP_H

#if defined(__sgi) || (defined(WIN32) && !defined(__MWERKS__))
	#include <time.h>
#else
	#include <ctime>
	using std::tm;
#endif

#include "Graphics3D/UGGraphics3DHeaders.h"

namespace UGC{
class GRAPHICS3D_API UGFrameStamp  
{
public:
	UGFrameStamp();
	virtual ~UGFrameStamp();
public:
	
	UGFrameStamp& operator = (const UGFrameStamp& fs);
	
	void SetFrameNumber(int fnum) { m_nFrameNumber = fnum; }
	UGint GetFrameNumber() const { return m_nFrameNumber; }
	
	void SetReferenceTime(double refTime) { m_nReferenceTime = refTime; }
	UGdouble GetReferenceTime() const { return m_nReferenceTime; }
	
	void SetCalendarTime(const tm& calendarTime);
	void GetCalendarTime(tm& calendarTime) const;

protected:
     
	UGint     m_nFrameNumber;
	UGdouble  m_nReferenceTime;
	
	UGint tm_sec;            /* Seconds.        [0-60] (1 leap second) */
	UGint tm_min;            /* Minutes.        [0-59] */
	UGint tm_hour;           /* Hours.          [0-23] */
	UGint tm_mday;           /* Day.            [1-31] */
	UGint tm_mon;            /* Month.          [0-11] */
	UGint tm_year;           /* Year            - 1900.  */
	UGint tm_wday;           /* Day of week.    [0-6] */
	UGint tm_yday;           /* Days in year.   [0-365]    */
	UGint tm_isdst;           /* DST.           [-1/0/1]*/
	
};
}

#endif // !defined(AFX_UGFRAMESTAMP_H__7B4DBED6_AA56_4295_808A_11785DAE0F01__INCLUDED_)
