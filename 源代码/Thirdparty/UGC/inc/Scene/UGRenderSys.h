// UGRenderSys.h: interface for the UGRenderSys class.
//
//////////////////////////////////////////////////////////////////////
/* 
	\file UGRenderSys.h
	\brief 该文件是虚拟显示引擎的头文件。
	\author 张艳良、马柳青
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGRENDERSYS_H__2777C030_C1E5_46EB_9998_A09FFE2AB29F__INCLUDED_)
#define AFX_UGRENDERSYS_H__2777C030_C1E5_46EB_9998_A09FFE2AB29F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGConfigOptionMap.h"
#include "Scene/UGMatrix4d.h"
#include "Scene/UGColorValue.h"
#include "Scene/UGLight.h"
#include "Scene/UGTextureUnitState.h"
#include "Scene/UGHardwareVertexBuffer.h"
#include "Scene/UGRenderWindow.h"
#include "Scene/UG3DWindowTypes.h"


namespace UGC 
{

	typedef UGDict<UGString, UGRenderTarget * > RenderTargetMap;
	typedef UGDict<UGuchar, UGRenderTarget * > RenderTargetPriorityMap;

	typedef UGDict<UGString, UGString> NameValuePairList;
/// Enum describing the ways to generate texture coordinates

//! \brief 自动生成纹理坐标方案枚举常量。
//! \remarks 每一个常量对应于一种自动生成纹理坐标常量。
enum TexCoordCalcMethod
{
    /// No calculated texture coordinates
	// 不计算纹理坐标常量
    TEXCALC_NONE,

    /// Environment map based on vertex normals
    // 计算环境纹理坐标常量
	TEXCALC_ENVIRONMENT_MAP,
    
	/// Environment map based on vertex positions
    // 计算平面环境纹理坐标常量
	TEXCALC_ENVIRONMENT_MAP_PLANAR,
    
	// 计算反射环境纹理坐标常量
	TEXCALC_ENVIRONMENT_MAP_REFLECTION,
    
	// 计算一般纹理坐标常量
	TEXCALC_ENVIRONMENT_MAP_NORMAL,
    
	/// Projective texture
	// 计算投影纹理坐标常量
    TEXCALC_PROJECTIVE_TEXTURE
};

/// Enum describing the various actions which can be taken onthe stencil buffer

//! \brief 模板缓存操作枚举常量。
enum StencilOperation
{
    /// Leave the stencil buffer unchanged
	// 保存模板缓存值不变
    SOP_KEEP,

    /// Set the stencil value to zero
    // 设置模板缓存值清空为零
	SOP_ZERO,

    /// Set the stencil value to the reference value
    // 替换原来的模板缓存
	SOP_REPLACE,

    /// Increase the stencil value by 1, clamping at the maximum value
    // 模板缓存值增加一
	SOP_INCREMENT,

    /// Decrease the stencil value by 1, clamping at 0
    // 模板缓存值减少一
	SOP_DECREMENT,

    /// Increase the stencil value by 1, wrapping back to 0 when incrementing the maximum value
    // 模板缓存值增加一，若超过最大值则赋值为零
	SOP_INCREMENT_WRAP,

    /// Decrease the stencil value by 1, wrapping when decrementing 0
	// 模板缓存值减少一，若达到最小值则不再减少
    SOP_DECREMENT_WRAP,

    /// Invert the bits of the stencil buffer
    // 模板缓存值位取反
	SOP_INVERT

};


//! \brief 虚拟显示引擎类，从该类派生D3D和OpenGL显示引擎。。
//! \remarks 这是一个抽象基类。
class SCENE_API UGRenderSys  
{

public:

	//! \brief 构造函数。
	UGRenderSys();	
	//! \brief 析构函数。
	virtual ~UGRenderSys();
	

	//! \brief 获取显示引擎名称。
	//! \return 返回显示引擎的名称。
	virtual const UGString& GetName(void) const = 0;
	//! \brief 根据错误号获取错误描述。
	//! \param errorNumber 错误号[in]。
	//! \return 返回错误描述。
	virtual UGString GetErrorDescription(UGint errorNumber) const = 0;
	//! \brief 获取三维常量容限。
	//! \return 容限对象。
	const UGRenderSystemCapabilities* GetCapabilities(void) const;	
	//! \brief 获取显示引擎配置项组。	
	//! \return 返回显示引擎配置项组。
	virtual UGConfigOptionMap& GetConfigOptions(void) = 0;
	//! \brief 给指定的配置项赋值。
	//! \param name 指定的配置项的名称[in]。
	//! \param value 指定的配置项的值[in]。
	virtual void SetConfigOption(const UGString &name, UGString &value) = 0;
	//! \brief 验证设置好的显示引擎的配置项。
	//! \return 如果有错误则返回错误信息，如果没有错误则返回空字符串。
	virtual UGString ValidateConfigOptions(void) = 0;

	
	//! \brief 初始化显示引擎。
	//{{这个函数跟Ogre中不一致 修改人:罗飞雄 2007-10-18 10:33:10
	//}}修改原因 修改人:罗飞雄  2007-10-18 10:33:10
	virtual UGRenderWindow *Initialize(Window hWnd) = 0;
	//! \brief 当有配置项改变后，重新初始化显示引擎。
	virtual void ReInitialize() = 0;
	//! \brief 关闭显示引擎并释放相关资源。
	virtual void ShutDown(void);
	//! \brief 渲染函数。
	//! \param &ro 渲染数据[in]。
	virtual void Render(UGRenderOperation &ro) = 0;
	//! \brief 更新所有渲染对象。
	virtual void UpdateAllRenderTargets(void);
	//! \brief  设置所有渲染窗口对象的字体为同一字体
	void  SetRenderTargetsFont(const UGTextStyle& textStyle);
	//! \brief 开始渲染。
	virtual void BeginFrame() = 0;	
	//! \brief 结束渲染。
	virtual void EndFrame() = 0;
	//! \brief 绑定目标对象。
	//! \param &target 目标对象[in]。
	virtual void AttachRenderTarget( UGRenderTarget &target );		
	//! \brief 获取当前活动目标对象。
	//! \param &name 名称[in]。
	//! \return 目标对象指针。
	virtual UGRenderTarget *GetRenderTarget( const UGString &name );	
	//! \brief 创建窗口对象。
	//! \param hWnd 外部窗口句柄[in]。
	//! \param 0 获取参数配置列表[in]。
	//! \return 窗口对象指针。
	virtual UGRenderWindow *CreateRenderWindow(Window hWnd, NameValuePairList *miscParams = 0) = 0;


//	virtual HardwareOcclusionQuery* createHardwareOcclusionQuery(void) = 0;
//	virtual void destroyHardwareOcclusionQuery(HardwareOcclusionQuery *hq);
//	RenderTexture * createRenderTexture( const String & name, unsigned int width, unsigned int height,
//		 	TextureType texType = TEX_TYPE_2D, PixelFormat internalFormat = PF_X8R8G8B8, 
//			const NameValuePairList *miscParams = 0 ); 
//	virtual MultiRenderTarget * createMultiRenderTarget(const String & name) = 0; 
//	virtual void destroyRenderWindow(const String& name);
//	virtual void destroyRenderTexture(const String& name);
//	virtual void destroyRenderTarget(const String& name);
	
//	virtual RenderTarget * detachRenderTarget( const String &name );
//	typedef MapIterator<Ogre::RenderTargetMap> RenderTargetIterator;
//	virtual RenderTargetIterator getRenderTargetIterator(void) 
//	{
//		return RenderTargetIterator( mRenderTargets.begin(), mRenderTargets.end() );
//	}
//	virtual void setScissorTest(UGbool enabled, size_t left = 0, size_t top = 0,
//  	          size_t right = 800, size_t bottom = 600) = 0;
//	virtual void bindGpuProgram(GpuProgram* prg);
//	virtual void bindGpuProgramParameters(GpuProgramType gptype, GpuProgramParametersSharedPtr params) = 0;
//	virtual void bindGpuProgramPassIterationParameters(GpuProgramType gptype) = 0;
//	virtual void unbindGpuProgram(GpuProgramType gptype);
//	virtual UGbool isGpuProgramBound(GpuProgramType gptype);
//	virtual void setClipPlanes(const UGPlaneList& clipPlanes) = 0;
//	virtual void _initRenderTargets(void);
//	virtual void _notifyCameraRemoved(const Camera* cam);


	//! \brief 设置全局光的颜色和强度。
	//! \param r Red分量[in]。
	//! \param g Green分量[in]。
	//! \param b Blue分量[in]。
	virtual void SetAmbientLight(UGfloat r, UGfloat g, UGfloat b) = 0;
	//! \brief 设置灯光的阴影模式。
	//! \param so 阴影模式[in]。
	virtual void SetShadingType(ShadeOptions so) = 0;	
	//! \brief 设置是否启用灯光效果，默认为0号光源。
	//! \param enabled 如果启用设置为true，否则设置为false[in]。
	virtual void SetLightingEnabled(UGbool enabled) = 0;	
	//! \brief 设置使用的灯光列表及数目。
	//! \param lights 灯光列表[in]。
	//! \param limit 使用的灯光数目[in]。
	//! \remarks 可以指定同一个列表，不断的变更数目。
	virtual void UseLights(const UGLightList& lights, UGuint limit) = 0;			
	//! \brief 开启关闭光源。
	//! \param nLightID 光源索引号[in]。
	//! \param bEnabled TRUE为开启，FALSE为关闭[in]。
	//! \remarks 与上面SetLightingEnable功能有点重复。
	//! \remarks D3D没有实现该函数，GL没有实现SetLightingEnable函数
	//! \attention 建议统一该函数。
	// modified by luofx  07.12.5
//	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled)=0;
	//! \brief 得到光源状态。
	//! \param nLightID 这个参数没有起作用[in]。
	//! \remarks GL返回是灯光0状态，D3D没有实现。
	//! \attention 重新设计该函数。
	// modified by luofx 07.12.5
//	virtual UGbool GetLightEnabled(UGint nLightID)=0;
	//! \brief 设置光源位置。
	//! \param nLightID 光源ID[in]。
	//! \param x 位置X轴分量[in]。
	//! \param y 位置Y轴分量[in]。
	//! \param z 位置Z轴分量[in]。
	//! \param w 齐次坐标分量[in]。
	//! \remarks GL实现，D3D没有实现。
	//! \attention 建议同一函数功能。
//	virtual void SetLightPos(UGint nLightID,UGfloat x,UGfloat y,UGfloat z,UGfloat w)=0;

	//! \brief 这个函数与SetDepthBufferCheckEnabled重复。
	//! \param TRUE [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	// modified by luofx 07.12.5
//	virtual void SetDepthBufferEnabled(UGbool bEnabled = TRUE) = 0;
	
	//! \brief 设置是否启用W-Buffer。
	//! \param enabled 如果启用设置为true，否则设置为false[in]。
	//! \remarks W-Buffer是比Z缓存更精细的缓存，该函数针对于D3D。
	void SetWBufferEnabled(UGbool enabled);
	//! \brief 获取是否启用了W-Buffer。
	//! \return 如果启用了则返回true，否则返回false。
	UGbool GetWBufferEnabled(void) const;	
		//! \brief 设置深度缓存参数。
	//! \param depthTest 是否启动深度测试，TRUE启动，FALSE关闭[in]。
	//! \param depthWrite 是否屏蔽深度测试，TRUE深度缓存只读，FALSE可读写[in]。
	//! \param depthFunction 深度缓存比较函数，缺省为不大于[in]。
	virtual void SetDepthBufferParams(UGbool depthTest = true, UGbool depthWrite = true, 
		CompareFunction depthFunction = CMPF_LESS_EQUAL) = 0;	
	//! \brief 设置是否启动深度缓存测试。
	//! \param enabled TRUE为启动，FALSE为关闭[in]。
	virtual void SetDepthBufferCheckEnabled(UGbool enabled = true) = 0;
	//! \brief 设置屏蔽深度缓存。
	//! \param enabled TRUE为只读，FALSE为可读可写[in]。
	virtual void SetDepthBufferWriteEnabled(UGbool enabled = true) = 0;
	//! \brief 设置深度缓存测试比较函数。
	//! \param func 比较函数[in]。
	virtual void SetDepthBufferFunction(CompareFunction func = CMPF_LESS_EQUAL) = 0;	
	//! \brief 设置屏蔽颜色缓存。
	//! \param red TRUE为屏蔽红色分量颜色缓存，FALSE为相反[in]。
	//! \param green TRUE为屏蔽绿色分量颜色缓存，FALSE为相反[in]。
	//! \param blue TRUE为屏蔽蓝色分量颜色缓存，FALSE为相反[in]。
	//! \param alpha TRUE为屏幕Alpha分量，FALSE为相反[in]。
	virtual void SetColourBufferWriteEnabled(UGbool red, UGbool green, UGbool blue, UGbool alpha) = 0;	
	//! \brief 设置深度偏差，用于多边形偏移。
	//! \param bias 恒定偏移量[in]。
	virtual void SetDepthBias(UGushort bias) = 0;	
	//! \brief 设置模板缓存检测是否有效。
	//! \param enabled TRUE开启模板缓存检测，FALSE则关闭[in]。
	virtual void SetStencilCheckEnabled(UGbool enabled) = 0;	
	//! \brief 设置模板缓存参数。
	//! \param func 比较函数常量[in]。
	//! \param refValue 参考值，用来与模板缓存中值进行比较[in]。
	//! \param mask 掩码，若参考值与缓存中值进行比较但只对mask值为1位进行比较[in]。
	//! \param stencilFailOp 模板缓存操作类型[in]。
	//! \param depthFailOp 模板缓存操作类型[in]。
	//! \param passOp 模板缓存操作类型[in]。
	//! \param twoSidedOperation 是否针对两边进行操作，TRUE代表是，FALSE代表否[in]。
	virtual void SetStencilBufferParams(CompareFunction func = CMPF_ALWAYS_PASS, 
            UGuint refValue = 0, UGuint mask = 0xFFFFFFFF, 
            StencilOperation stencilFailOp = SOP_KEEP, 
            StencilOperation depthFailOp = SOP_KEEP,
            StencilOperation passOp = SOP_KEEP, 
            UGbool twoSidedOperation = false) = 0;	
	//! \brief 清理缓存。
	//! \param buffers 缓存类型[in]。
	//! \param colour 颜色值，用于清理颜色缓存[in]。
	//! \param depth 深度，用于清理深度缓存[in]。
	//! \param stencil 模板值，用于清理模板缓存[in]。
	virtual void ClearFrameBuffer(UGuint buffers, 
		const UGColorValue& colour = UGColorValue::Black, 
		UGReal depth = 1.0f, UGushort stencil = 0) = 0;
	

	//! \brief 设置世界矩阵。
	//! \param &m 世界矩阵[in]。
	virtual void SetWorldMatrix(const UGMatrix4d &m) = 0;
	virtual UGMatrix4d& GetWorldMatrix() = 0;
	//! \brief 设置多个世界矩阵。
	//! \param m 世界矩阵[in]。
	//! \param count 矩阵数目[in]。
	virtual void SetWorldMatrices(const UGMatrix4d* m, UGushort count);	
	//! \brief 设置视矩阵。
	//! \param &m 视矩阵[in]。
	virtual void SetViewMatrix(const UGMatrix4d &m) = 0;	
	virtual UGMatrix4d& GetViewMatrix() = 0;
	//! \brief 设置投影矩阵。
	//! \param &m 投影矩阵[in]。
	virtual void SetProjectionMatrix(const UGMatrix4d &m) = 0;
	virtual UGMatrix4d& GetProjectionMatrix() = 0;
		//! \brief 转换投影矩阵。
	//! \param matrix 源投影矩阵[in]。
	//! \param dest 目标投影矩阵[out]。
	//! \param forGpuProgram TRUE为右手坐标系；FALSE为左手坐标系[in]。
	virtual void ConvertProjectionMatrix(const UGMatrix4d& matrix,
            UGMatrix4d& dest, UGbool forGpuProgram = false) = 0;	
	//! \brief 生成透视投影矩阵。
	//! \param fovy 透视投影角度[in]。
	//! \param aspect 宽高比[in]。
	//! \param nearPlane 近视面Z值[in]。
	//! \param farPlane 远视面Z值[in]。
	//! \param dest [out]保存生成投影矩阵。
	//! \param forGpuProgram TRUE为右手坐标系；FALSE为左手坐标系[in]。
	virtual void MakeProjectionMatrix(const UGAngle& fovy, UGReal aspect, UGReal nearPlane, 
		UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false) = 0;	
	//! \brief 生成透视投影矩阵。
	//! \param left 左坐标[in]。
	//! \param right 右坐标[in]。
	//! \param bottom 下坐标[in]。
	//! \param top 顶部坐标[in]。
	//! \param nearPlane 近视面Z值[in]。
	//! \param farPlane 远视面Z值[in]。
	//! \param dest 保存生成矩阵[out]。
	//! \param forGpuProgram TRUE为右手坐标系；FALSE为左手坐标系[in][in]。
	virtual void MakeProjectionMatrix(UGReal left, UGReal right, UGReal bottom, UGReal top, 
            UGReal nearPlane, UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false) = 0;	
	//! \brief 生成正视投影矩阵。
	//! \param fovy 角度[in]。
	//! \param aspect 宽高比[in]。
	//! \param nearPlane 近视面Z值[in]。
	//! \param farPlane 远视面Z值[in]。
	//! \param dest 保存生成矩阵[out]。
	//! \param forGpuProgram [in]。
	virtual void MakeOrthoMatrix(const UGAngle& fovy, UGReal aspect, UGReal nearPlane, 
		UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false) = 0;	
	//! \brief 应用倾斜深度投影。
	//! \param matrix 投影矩阵[in]。
	//! \param plane [in]。
	//! \param forGpuProgram [in]。
	virtual void ApplyObliqueDepthProjection(UGMatrix4d& matrix, const UGPlane& plane, 
            UGbool forGpuProgram) = 0;	
	//! \brief 生成投影变换矩阵，MakeProjectionMatrix类似。
	//! \param fovy 角度[in]。
	//! \param aspect 宽高比[in]。
	//! \param nearPlane 近视面Z值[in]。
	//! \param farPlane 远视面Z值[in]。
	//! \return 投影矩阵。		
	// modified by luofx 07.12.5
//	virtual UGMatrix4d SetProjectionMatrix(UGReal fovy, UGReal aspect, UGReal nearPlane, 
//				UGReal farPlane)=0;			
	//! \brief 设置模型视角矩阵。
	//! \param cameraPosition 相机位置[in]。
	//! \param cameraTarget 相机焦点[in]。
	//! \param cameraUpVector 相机向上方向[in]。
	//! \param Tilt 物体顺时针绕X轴旋转角度[in]。
	//! \param Bank 废弃，OpenGL中没有使用到[in]。
	//! \param Heading 物体绕顺时针绕Z轴旋转角度[in]。
	//! \param dDistance 物体沿Z轴向后移距离[in]。
	//! \return 模型视角矩阵。
	//! \remarks D3D和GL实现有些不一样。
	//! \attention 建议重新整理这个函数。
//	virtual UGMatrix4d SetViewMatrix(UGVector3R cameraPosition, 
//									UGVector3R cameraTarget, 
//									UGVector3R cameraUpVector, 
//									UGAngle Tilt, UGAngle Bank, UGAngle Heading, UGReal dDistance) = 0;	
	//! \brief 世界坐标转换成Windows坐标。
	//! \param &v 世界坐标[in]。
	//! \param &win Windows坐标[out]。
	//! \remarks D3D没有实现。
	//! \attention 建议重新实现这个函数。
	virtual void Project(const UGVector3R &v, UGVector3R &win) = 0;
	virtual void MakePickRadial(const UGint x, const UGint y, UGVector3R& nPos, UGVector3R& fPos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO) = 0;
	virtual void UnMakePickRadial(UGfloat& x, UGfloat& y, UGfloat& z, UGVector3R& Pos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO) = 0;
	//! \brief Windows坐标转换成世界坐标。
	//! \param &win Windows坐标[in]。
	//! \param &v 世界坐标[out]。
	//! \remarks 在D3D和GL都存在。
	//! \attention 。		
	virtual void UnProject(const UGVector3R &win,UGVector3R &v) = 0;
	//! \brief 设置裁剪平面。
	//! \param index 裁剪面索引号[in]。
	//! \param &p 裁剪面[in]。
	virtual void SetClipPlane (UGushort index, const UGPlane &p);	
//  virtual void SetClipPlane (UGushort index, UGReal A, UGReal B, UGReal C, UGReal D) = 0;//  
//  virtual void enableClipPlane (UGushort index, UGbool enable) = 0;
	//! \brief 设置视口。
	//! \param &viewport 视口对象[in]。
	virtual void SetViewport(UGViewport *pViewport) = 0;
	//! \brief 获取视口对象。
	//! \return 视口对象指针。
	virtual UGViewport* GetViewport(void);	
	

	//! \brief 设置多重纹理中纹理单元格式。
	//! \param texUnit 纹理单元序号，OpenGL总共只能有0-31个纹理单元[in]。
	//! \param tl 纹理单元相关参数对象[in]。
	//! \attention 这个完成绑定纹理，自动计算纹理坐标，设置纹理矩阵等相关功能。
	virtual void SetTextureUnitSettings(UGuint texUnit, UGTextureUnitState& tl);	
	//! \brief 取消纹理单元格式设置。
	//! \param texUnit 纹理单元序列号[in]。
	//! \attention 目前没有实现
	virtual void DisableTextureUnit(UGuint texUnit);
	//! \brief 取消所有纹理单元格式设置。
	//! \param texUnit 起始索引号[in]。
	virtual void DisableTextureUnitsFrom(UGuint texUnit);
	//! \brief 设置纹理单元滤波方法。
	//! \param unit 纹理单元索引号[in]。
	//! \param minFilter 最小滤波方法[in]。
	//! \param magFilter 最大滤波方法[in]。
	//! \param mipFilter mipmap滤波方法[in]。
	virtual void SetTextureUnitFiltering(UGuint unit, FilterOptions minFilter,
            FilterOptions magFilter, FilterOptions mipFilter);	
		//! \brief 设置纹理单元是否启动。
	//! \param unit 纹理单元索引号[in]。
	//! \param enabled 是否启动，TRUE为启动，FALSE为关闭[in]。
	//! \param &texname 纹理单元名称[in]。
	virtual void SetTexture(UGuint unit, UGbool enabled, const UGString &texname) = 0;
	//! \brief 设置纹理坐标系。
	//! \param unit 纹理单元索引号[in]。
	//! \param index 纹理坐标索引号[in]。
	virtual void SetTextureCoordSet(UGuint unit, UGuint index) = 0;	
	//! \brief 计算纹理坐标值。
	//! \param unit 纹理单元[in]。
	//! \param m 计算纹理坐标值方法[in]。
	//! \param frustum 视锥体，包括六个面[in]。
	virtual void SetTextureCoordCalculation(UGuint unit, TexCoordCalcMethod m, 
            const UGFrustum* frustum = 0) = 0;	
	//! \brief 设置纹理混合模式。
	//! \param unit 纹理单元索引号[in]。
	//! \param bm 颜色混合类[in]。
	virtual void SetTextureBlendMode(UGuint unit, const UGLayerBlendModeEx& bm) = 0;
	//! \brief 设置纹理单位的过滤项。
	//! \param unit 纹理单元索引号[in]。
	//! \param ftype 过滤项[in]。
	//! \param filter 滤波方法[in]。
	virtual void SetTextureUnitFiltering(UGuint unit, FilterType ftype, FilterOptions filter) = 0;	
	//! \brief 设置纹理单元最大各向性值。
	//! \param unit 纹理单元索引号[in]。
	//! \param maxAnisotropy 最大各向性值  [in]。
	virtual void SetTextureLayerAnisotropy(UGuint unit, UGuint maxAnisotropy) = 0;	
	//! \brief 设置纹理单元纹理地址处理模式。
	//! \param unit 纹理单元索引号[in]。
	//! \param uvw UVW纹理地址对象[in]。
	virtual void SetTextureAddressingMode(UGuint unit, const UGTextureUnitState::UVWAddressingMode& uvw) = 0;	
	//! \brief 设置纹理单元边框颜色。
	//! \param unit 纹理单元索引号[in]。
	//! \param colour 颜色值[in]。
	virtual void SetTextureBorderColour(UGuint unit, const UGColorValue& colour) = 0;	
	//! \brief 设置纹理单元纹理矩阵。
	//! \param unit 纹理单元索引号[in]。
	//! \param xform 纹理单元矩阵[in]。
	virtual void SetTextureMatrix(UGuint unit, const UGMatrix4d& xform) = 0;		
	//! \brief 设置按比例混合。
	//! \param sourceFactor 源因子[in]。
	//! \param destFactor 目的因子[in]。
	virtual void SetSceneBlending(SceneBlendFactor sourceFactor, SceneBlendFactor destFactor) = 0;	
	//! \brief 设置Aplpha测试，一般用作对透明处理。
	//! \param func Alpha比较函数[in]。
	//! \param value Alpha参考值[in]。
	virtual void SetAlphaRejectSettings(CompareFunction func, UGuchar value) = 0;	
	//! \brief 设置透明度。
	//! \param fOpacity 透明度系数[in]。
	//! \return 。
	//! \remarks 虚拟引擎中函数没有实现体，在GL中实现，D3D没有实现。
	//! \attention 讨论该函数然后实现。
	virtual void SetOpacity(UGfloat fOpacity);
	//! \brief 设置颜色融合。
	//! \param  [in]。
	//! \return 。
	//! \remarks 虚拟引擎中函数没有实现体，在GL中实现，D3D没有实现。
	//! \attention 讨论该函数然后实现。
	virtual void BlendAlpha();


	//! \brief 删除显示列表。
	//! \param listIndex 显示列表ID[in]。
	//! \return 。
	//! \remarks 虚拟引擎中函数没有实现体，在GL中实现，D3D没有实现。
	//! \attention 讨论该函数然后实现。
	virtual void DeleteList(UGint listIndex);
	//! \brief 调用显示列表。
	//! \param listIndex 显示列表ID[in]。
	//! \return 。
	//! \remarks 虚拟引擎中函数没有实现体，在GL中实现，D3D没有实现。
	//! \attention 讨论该函数然后实现。
	virtual void CallList(UGint listIndex);
	//! \brief 设置绘制渲染细节模式。
	//! \param renderDetail 绘制模式[in]。
	// modified by luofx 07.12.5
//	virtual void SetRenderDetail(SceneDetailLevel renderDetail)=0;	
	
	//! \brief 设置剔除模式。
	//! \param mode 剔除模式[in]。
	virtual void SetCullingMode(CullingMode mode) = 0;	
	//! \brief 获取剔除模式。
	//! \return 剔除模式对象。
	virtual CullingMode GetCullingMode(void) const;	
	//! \brief 设置绘制多边形类型。
	//! \param level 类型枚举常量[in]。
	virtual void SetPolygonMode(PolygonMode level) = 0;	
	//! \brief 确定物体前面，剔除物体后面。
	//! \param enFrontFace 确定前面方法[in]。
	//! \return 。
	//! \remarks GL中实现，D3D无实现。
	//! \attention 参数建议采用枚举常量，要不然用起来相当费劲。
	//! \attention 同时要同一这个函数。
	virtual void SetPolyFrontFace(UGint  enFrontFace)=0;
	//! \brief 设置是否等待Vertical Blank。
	//! \param enabled 如果等待设置为true，否则设置为false[in]。
	//! \remarks 这个功能是作出图像速度或质量的选择。
	void SetWaitForVerticalBlank(UGbool enabled);	
	//! \brief 获取是否等待Vertical Blank。
	//! \return 如果等待则返回true，否则返回false。
	UGbool GetWaitForVerticalBlank(void) const;
	//! \brief 设置雾。
	//! \param mode 雾生成模式，所指为不同雾方程[in]。
	//! \param colour 雾颜色[in]。
	//! \param expDensity 雾浓度[in]。
	//! \param linearStart 雾效开始Z值[in]。
	//! \param linearEnd 雾效结束Z值[in]。
	virtual void SetFog(FogMode mode = FOG_NONE, const UGColorValue& colour = UGColorValue::White, 
		UGReal expDensity = 1.0, UGReal linearStart = 0.0, UGReal linearEnd = 1.0) = 0;

	//! \brief 设置雾状态。
	//! \param bEnable TRUE为启动，FALSE为关闭[in]。
	//! \remarks GL实现，D3D没有实现。
	//! \attention 建议同一函数功能。		
    // modified by luofx 07.12.5
//	virtual void SetFogEnable(UGbool bEnable)=0;

	//! \brief 获取雾是否打开状态。
	//! \param  [in]。
	//! \return TRUE为打开，FALSE为关闭。
	//! \remarks GL实现，D3D没有实现。
	//! \attention 建议同一函数功能。
	// modified by luofx 07.12.5
//	virtual UGbool GetFogEnable()=0;
	//! \brief 绘制雾。
	//! \param fStart 雾效果起始位置[in]。
	//! \param fEnd 雾效果结束位置[in]。
	//! \return 。
	//! \remarks 这个在虚拟引擎中没有实现，在GL实现，D3D无实现。
	//! \attention 整理一下该函数。
	// modified by luofx 07.12.5
//	virtual void RenderFog(UGfloat fStart,UGfloat fEnd);
//	virtual void _setSurfaceParams(const ColourValue &ambient,
//            const ColourValue &diffuse, const ColourValue &specular,
//            const ColourValue &emissive, Real shininess,
//            TrackVertexColourType tracking = TVC_NONE) = 0;
	//! \brief 设置渲染点精灵状态。
	//! \param enabled true为打开，false为关闭[in]。
	virtual void SetPointSpritesEnabled(UGbool enabled) = 0;	
	//! \brief 设置点精灵的渲染参数。
	//! \param size 点大小[in]。
	//! \param attenuationEnabled 眼睛看到点尺寸是否可以通过参数调节，True则constant,linear,quadratic参数用来计算点尺寸。False则无效[in]。
	//! \param constant 计算点尺寸大小所用公式常数[in]。
	//! \param linear 计算点尺寸大小所用公式一次项系数[in]。
	//! \param quadratic 计算点尺寸大小所用公式二次项系数[in]。
	//! \param minSize 点大小最小值[in]。
	//! \param maxSize 点大小最大值[in]。
	virtual void SetPointParameters(UGReal size, UGbool attenuationEnabled, 
			UGReal constant, UGReal linear, UGReal quadratic, 
			UGReal minSize, UGReal maxSize) = 0;	



	//! \brief 初始化顶点和面数目。
	virtual void BeginGeometryCount(void);	
	//! \brief 获取面数目。
	virtual UGuint GetFaceCount(void) const;
	//! \brief 获取顶点数目。
	virtual UGuint GetVertexCount(void) const;		
	//! \brief 转换颜色值为整数值。
	//! \param colour 原始颜色值[in]。
	//! \param pDest 换算后整数值[in]。
	virtual void ConvertColourValue(const UGColorValue& colour, UGuint* pDest);		
	//! \brief 获取顶点元素类型。
	//! \param void [in]。
	//! \return 顶点元素类型。
	virtual VertexElementType GetColourVertexElementType(void) const = 0;	
//	virtual UGReal getHorizontalTexelOffset(void) = 0;
//	virtual UGReal getVerticalTexelOffset(void) = 0;
//	virtual UGReal getMinimumDepthInputValue(void) = 0;
//	virtual UGReal getMaximumDepthInputValue(void) = 0;	
	//! \brief 设置m_unCurrentPassIterationCount变量值。
	//! \param count 传入值[in]。
	void SetCurrentPassIterationCount(const UGuint count);		
	//! \brief 设置当前顶点声明，例如顶点数据源。
	//! \param decl 顶点数据集数据格式对象[in]。
	virtual void SetVertexDeclaration(UGVertexDeclaration* decl) = 0;	
	//! \brief 设置顶点数据缓冲区绑定。
	//! \param binding 记录所有顶点缓冲区绑定状态对象[in]。
	virtual void SetVertexBufferBinding(UGVertexBufferBinding* binding) = 0;
//	virtual void setNormaliseNormals(UGbool normalise) = 0;
	//! \brief 这个函数在OGRE中没有使用到，这个函数设置一个变量值。
	//! \param invert [in]。
	virtual void SetInvertVertexWinding(UGbool invert);		


	//! \brief 显示二维字体。
	//! \param s 字符集合[in]。
	//! \param vecPos 位置[in]。
	//! \param colorOutLines 边框颜色，没有起作用[in]。
	//! \param colorFont 字体颜色[in]。
	//! \remarks GL实现，D3D没有实现。
	//! \attention 建议整理一下该函数功能。
	virtual void TextOut2DText( const UGchar* s,const UGVector3R& vecPos);
	//! \brief 绘制三维字体。
	//! \param s 字符集[in]。
	//! \param vecPos 位置矢量[in]。
	//! \param colorFont 字体颜色[in]。
	//! \param colorOutLines 没有起作用 [in]。
	//! \param &pCharList 字符显示列表串[in]。
	//! \remarks GL实现，D3D没有实现。
	//! \attention 建议整理一下该函数功能。
	virtual void TextOut3DText(const UGchar* s,const UGVector3R& vecPos, const UGColorValue& colorText,UGint* &pCharList);
	//! \brief 虚拟引擎中函数没有实现体，在GL中实现，D3D没有实现。
	//! \param  [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 讨论该函数然后实现。
	virtual void SetRenderFont();
		// malq-2007-11-14-绘制精灵点
	virtual void RenderSpritePoint(UGdouble x,UGdouble y,UGdouble z,UGbool bDistChange,UGfloat* pQuadratic)=0;
	// malq-2007-11-14-绘制精灵点
	virtual void RenderSpritePoint(UGReal* pVertex,UGint nVertexCount,UGbool bDistChange,UGfloat* pQuadratic, UGint selectedPointIndex = -1)=0;
	// malq-2007-11-20-绘制普通点 
	virtual void RenderSimplePoint(UGdouble x,UGdouble y,UGdouble z,UGbool bPointSmooth=FALSE)=0;
	// malq-2007-11-20-绘制普通点 
	virtual void RenderSimplePoint(UGReal* pVertex,UGint nVertexCount,UGbool bPointSmooth=FALSE, UGint selectedPointIndex = -1)=0;
	// malq-2007-11-19设置点线的颜色
	virtual void  SetSingleColor(const UGColorValue& colorValue)=0;
	virtual void SetPointSize(UGReal fSize)=0;
	virtual void SetLineWidth(UGReal fSize)=0;


	void NotifyCameraRemoved(const UGMomentumCamera* cam);
	virtual void DrawBoundingBox(const UGBoundingBox& boundingBox) = 0;
	virtual void DrawRadia(const UGVector3R& vecStart, const UGVector3R& vecEnd, const UGVector3R& vecIntersect) = 0;
	
	// 临时使用光照函数
	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled) = 0;
	virtual UGbool GetLightEnabled(UGint nLightID) = 0;
	virtual void Render2DImage(UGint xStart,UGint yStart,UGint nWidth,UGint nHeight, UGbool bIsNeedRotate = FALSE, UGdouble dAngle = 0.0f) = 0;

protected:
	//! \brief The render targets。
    RenderTargetMap m_RenderTargets;
	//! \brief The render targets, ordered by priority。
	RenderTargetPriorityMap m_PrioritisedRenderTargets;
	//! \brief The Active render target。
	UGRenderTarget *m_pActiveRenderTarget;
	//! \brief TextureManager。
	UGTextureManager* m_pTextureManager;

	//! \brief 地形管理器。
	UGTerrainManager *m_pTerrainManager;
	//! \brief 三维引擎中变量容限值
	UGRenderSystemCapabilities *m_pCapabilities;
	//! \brief 这个变量不知道什么意思。
	//! \remarks 备注信息。
	UGuint m_unCurrentPassIterationCount;
	//! \brief 这个变量页不知道什么意思。
	//! \remarks 备注信息。
	UGbool m_bInvertVertexWinding;
	//! \brief 顶点数目	
	UGuint m_unVertexCount;
	//! \brief 面数目
	UGuint m_unFaceCount;

	//! \brief 剔除模式，枚举常量
	CullingMode m_CullingMode;	
	UGbool m_bVSync;
	UGbool m_bWBuffer;
	
	//! \brief 有效视口对象。
	UGViewport* m_pActiveViewport;	

	//! \brief世界矩阵，模型视点矩阵，投影矩阵
	UGMatrix4d m_WorldMatrix;
	UGMatrix4d m_ModelViewMatrix;
	UGMatrix4d m_ProjectMatrix;

	//! \brief 模型矩阵数组。
	UGMatrix4d m_WorldMatrices[256];	
};


}
#endif // !defined(AFX_UGRENDERSYS_H__2777C030_C1E5_46EB_9998_A09FFE2AB29F__INCLUDED_)
