/*!  \file	 UGProgress.h
*  \brief	 进程条类
*  \author	 caogf, zengzm
*  \attention 
*  Copyright(c) 1996-2004 SuperMap GIS Technologies, Inc.<br>
*  All Rights Reserved
*/
#if !defined(UGPROGRESS_H)
#define UGPROGRESS_H
#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGTime.h"
#include "Base/UGDict.h"
#include "Base/UGThread.h"
#include <stack>

namespace UGC{

//! \brief 进程条信息回调函数
//! \remarks add the argument bCancel to communicate with the outside functions.caogf
typedef void (*ProgressProc)(void* pParam, const UGchar* pchTitle,const UGchar* pchMessage,
							 UGint nPercent, const UGchar* pchRemainTime,UGbool& bCancel);

//! \brief 进程条类。
/**
进程条的作用是为了在进行长时间操作的时候,能定期反馈给用户进展情况的信息,
避免用户误以为程序已经进入死机状态.
在进行较长时间的操作时,必须提供进程条信息(用户可选择是否启用),
这些长时间的操作包括(但不限于):
数据转化,
对数据集/记录集的各种空间分析, 
对数据集/记录集的赋值,追加,建立空间索引等, 
简单而言,就是除了和用户进行交互式操作(地图浏览,交互式编辑)等之外,
操作时间超过5秒的,都必须考虑使用进程条.<br>

进程条的样式可参考如下:<br>
|-------------------------------------------------|<br>
|进程条主题信息(如：正在导入shape文件)            |<br>
|												  |<br>
|进程信息(如：正在导入面对象(10/1000))			  |<br>
|	||||||||(进程位置)							  |<br>
|_________________________________________________|<br>
<br>
UGC类库中，UGProgress的一般的使用方法如下：<br>
UGProgress pProgress = NULL;<br>
if(bUseProgress) //由用户给出是否使用进程条<br>
{<br>
	pProgress = new UGProgress();<br>
	pProgress->SetTitleMessage(UGS_IMPORT_SHAPE); // "正在导入shape文件"<br>
	pProgress->SetProgressPos(0);<br>
}<br>
for(int i=0; i<ObjCount; i++)<br>
{<br>
	if (pProgress)<br>
	{<br>
		pProgress->SetMessage(UGC_IMPORT_REGION, i, ObjCount); // 正在导入面对象(10/1000)<br>
		int nPos = i*100/ObjCount;<br>
		pProgress->SetProgressPos(nPos);<br>
		// 以后还要处理pProgress->IsCancel()的信息<br>
	}<br>
}<br>
delete pProgress;<br>
pProgress = NULL;<br>
<br>
对于比较复杂的情况, 如某个功能要分成几个部分,每个部分都需要设置进程条, 
或者一个函数使用了进程条,但是其内部要调用的函数也需要使用进程条, 
为了避免出现用户的一个操作出现多次从0-100的进程显示,可以如下使用:<br>
UGProgress pProgress = NULL;<br>
if(bUseProgress) //由用户给出是否使用进程条<br>
{<br>
	pProgress = new UGProgress();<br>
	pProgress->SetTitleMessage("进行拓扑分析"); <br>
	pProgress->SetProgressPos(0);<br>
}<br>
//第一步假设求出交点, 进程条分配50%<br>
if (pProgress)<br>
{<br>
	pProgress->SetBothPosRange(0, 50); //从 0-50<br>
}<br>
for(int i=0; i<ObjCount; i++)<br>
{<br>
	if (pProgress)<br>
	{<br>
		pProgress->SetMessage("正在求出交点"); <br>
		int nPos = i*100/ObjCount; // 这里仍然是 从 0-100,进程条内部会处理为 从 0-50<br>
		pProgress->SetProgressPos(nPos);<br>
		// 以后还要处理pProgress->IsCancel()的信息<br>
	}<br>
}<br>
<br>
//第二步假设为创建出网络数据集, 进程条分配剩余的50%<br>
if (pProgress)<br>
{<br>
	pProgress->SetBothPosRange(50, 100); //从 50-100<br>
}<br>
for(int j=0; j<ObjCount; j++)<br>
{<br>
	if (pProgress)<br>
	{<br>
		pProgress->SetMessage("正在创建网络数据集"); <br>
		int nPos = j*100/ObjCount; // 这里仍然是 从 0-100,进程条内部会处理为 从 50-100<br>
		pProgress->SetProgressPos(nPos);<br>
		// 以后还要处理pProgress->IsCancel()的信息<br>
	}<br>
}<br>
delete pProgress;<br>
pProgress = NULL;<br>
<br>
对于函数嵌套函数使用进程条的情况,则应该把进程条作为参数(或者成员变量).
对于Pos的设定, 可以通过SetBothPosRange,以及PushPosRange和PopPosRange来联合使用.
简单而言,就是在要调用一个函数之前,调用PushPosRange;调用之后,立即调用PopPosRange;
在每个函数中,都认为自己拥有 [0,100]的pos 范围. 具体请参考单元测试代码CUGProgressTest::testMultiPos中的使用<br>
注:以前自己计算的代码也可以照样使用,不需要修改.<br>
<br><br>

UGC的用户(组件产品)在使用UGProgress时,应该:<br>
1)编写处理得到进程条回调信息的处理函数<br>
void MyProgressProc(void* pParam, const UGchar* pchTitle,const UGchar* pchMessage,
							 UGint nPercent, const UGchar* pchRemainTime,UGbool& bCancel)<br>
{<br>
	// 这里把得到的各类信息展现给用户<br>
	// 注意bCancel尚未起到作用,请UGC上层产品暂时不要提供出去<br>
}<br>
2)通过UGCallback设置进程条的回调函数<br>
UGProgress::SetProgressProc(MyProgressProc);<br>
*/
class BASE_API UGProgress
{
public:
	//! \brief 默认构造函数
	UGProgress();
	//! \brief 析构函数
	~UGProgress();

public:
	//! \brief 设置进程条信息的回调函数指针
	//! \param pProgressFun 进程条回调指针
	//! \param pParam 附加参数，默认为NULL
	static void SetProgressProc(ProgressProc pProgressFun, void* pParam=NULL);	

	//! \brief 设置进程条主题信息
	//! \param strTitleMsg 进程条主题信息
	void SetTitleMessage(const UGString& strTitleMsg);
	//! \brief 通过字符串资源ID和格式化信息,构造完整信息,并且设置为进程条主题信息
	//! \param nResID 字符串资源id, 作为格式化信息
	//! \param ... 不定参数,类似于printf("", ...)中的...
	void SetTitleMessage(UGint nResID, ...);
	
	//! \brief 设置进程条信息
	//! \param strMessage 当前进程信息
	void SetMessage(const UGString& strMessage);

	//! \brief 通过字符串资源ID和格式化信息,构造完整信息,并且设置为进程信息
	//! \param nResID 字符串资源id, 作为格式化信息
	//! \param ... 不定参数,类似于printf("", ...)中的...
	void SetMessage(UGint nResID, ...);
	
	//! \brief 设置进程条的百分比位置(从0到100)
	//! \param nPercent 百分比位置
	//! \return 返回上一个Pos
	UGint SetProgressPos(UGint nPercent);

	//! \brief 设置后续使用过程中进程条可用的起始和终止位置范围
	//! \param nStartPos 起始位置(百分比值)
	//! \param nEndPos 终止位置(百分比值)
	//! \remarks 该Pos是相对Pos,即在上层函数已经分配给本函数的范围内,再按照[0,100]来进行分配
	void SetBothPosRange(UGint nStartPos, UGint nEndPos);
	
	//! \brief 得到可用的起始物理位置
	//! \return 返回可用的起始物理位置
	UGint GetStartPos() const;

	//! \brief 得到可用的终止物理位置
	//! \return 返回可用的终止物理位置
	UGint GetEndPos() const;

	//! \brief 得到可用的物理位置区间大小
	//! \return 返回可用的物理位置区间大小
	UGint GetPosRange() const;

	//! \brief 把当前Pos Range压栈
	//! \remarks 在函数多层调用时使用
	void PushPosRange();

	//! \brief 从Pos Range栈中弹出最上层
	//! \remarks 在函数多层调用时使用
	void PopPosRange();

	//! \brief 得到进程条绝对位置
	//! \remarks 为了支持多层嵌套进程条和方便使用, SetBothPosRange等和Pos相关的函数,都采用的是相对位置;
	//! 这里增加得到绝对位置的方法,以便在测试时进行核对. 一般没有必要使用
	UGint GetAbsolutePos(int nPercent) const;

	//! \brief 清空进程条的各类信息
	void Clear(); 

	//! \brief 得到用户是否取消的信息,以便类库中能进行中断撤销; 目前尚未使用
	UGbool IsCanceled();

	//! \brief 是否显示进程条
	//! \remarks 可以获得是否显示进程条; 设置进程条是否显示通过UGRegistry::Root().SetAt("ShowProgress", "true")来进行,
	//!			设置后对已经存在的进程条对象不起作用
	UGbool IsShow() const;

private:
	UGString m_strTitle; // 保留起来的Progress Title
	UGString m_strMessage; // 保留起来的Progress Msg
	// 保留起来的上一次的Percent; 默认为-1, 这样第一次也可以刷新了
	UGint m_nLastPercent; 
	
	// 在调用SetProgressPos时,如果不到1%,一般是不刷新的; 
	// 但是,如果时间间隔超过了ms_nRefreshInterval(默认为5秒),也刷新一下,防止长时间不刷新
	static const UGint ms_nRefreshInterval; // 时间单位: 秒
	
	UGTime m_tmStart; // 当前进程条开始时记录下来的时间点,
	UGTime m_tmLast; // 上一次进程条更新时记录下来的时间点
	UGString m_strRemainTime; // 剩余时间的显示字符串
	UGbool m_bCancel;//考虑取消
	//! 是否显示进程条,在构造函数中读取ugc.xml配置
	UGbool m_bShowProgress;

	//UGint m_nStartPos; //起始位置,默认为0
	//UGint m_nEndPos; // 终止位置,默认为100

	struct PosRange
	{
		UGint m_nStartPos;
		UGint m_nEndPos;
		PosRange(){
			m_nStartPos = 0;
			m_nEndPos = 100;
		}
	};
	//! 当前的Pos Range(绝对位置)
	PosRange m_curPosRange;

	//! Pos Range的堆栈(绝对位置), 用来控制多层嵌套的进程条设置
	std::stack<PosRange> m_PosRanges;
	
//＝＝＝＝＝回调相关处理＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
	struct UGProgProc 
	{
		UGProgProc(){
			m_pProgressFun = NULL;
			m_pParam = NULL;
		}
		ProgressProc m_pProgressFun;
		void* m_pParam;
	};
	static UGDict<UGuint, UGProgProc> ms_ProgProc;

//	! \brief 进程条回调函数指针
//		static ProgressProc	ms_pProgressFun;
//		static void* ms_pParam;

	//! 多线程保护
	static UGMutex ms_mutex;

private:
	//! \brief 计算剩余时间
	UGString GetRemainTimeInfo(UGint nPercent, UGbool &bRefresh); 

	//! \brief 调用回调函数
	void ProgCallback(const UGchar* pchTitle,const UGchar* pchMessage,
				UGint nPercent, const UGchar* pchRemainTime);

	//! \brief 根据percent和pos range的绝对范围, 得到绝对Pos
	UGint GetAbsolutePos(UGint nPercent, PosRange posRangeTotal) const;
};

}

#endif // !defined(UGPROGRESS_H)
