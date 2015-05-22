/**  \file UGGLRenderSys.h
   \brief   OpenGL渲染系统
   \auothor malq
   \attetion
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>更新说明：</b>\n
	<em>1、第一条说明。\n
	<em>2、第二条说明。\n
*/

#if !defined(AFX_UGGLRENDERSYS_H__E87F3D39_C520_427D_9F11_72CB26885C13__INCLUDED_)
#define AFX_UGGLRENDERSYS_H__E87F3D39_C520_427D_9F11_72CB26885C13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGRenderSys.h"
#include "GLRenderSys/UGGLSupport.h"
#include "Scene/UGSceneConfig.h"
#include "Scene/UGMatrix4d.h"
#include "Base/UGFileStdio.h"
#include "Scene/UGRenderWindow.h"
#include "Scene/UG3DWindowTypes.h"


namespace UGC 
{
	
//! \brief OpenGL渲染类
class GLRENDERSYS_API UGGLRenderSys : public UGRenderSys
{
public:

	//! \brief 构造函数
	UGGLRenderSys(); 
	//! \brief 析构函数
	virtual ~UGGLRenderSys();
	//! \brief 获取引擎名称。
	//! \return 引擎名称。
	//! \remarks 引擎名称唯一。
	const UGString& GetName(void) const;
	//! \brief 获取错误描述。
	//! \param errorNumber 错误号[in]。
	//! \return 错误描述。
	virtual UGString GetErrorDescription(UGint errorNumber) const;
	//! \brief 获取配置参数。
	//! \return 配置参数。
	UGConfigOptionMap& GetConfigOptions(void);
	//! \brief 设置配置参数。
	//! \param &name 配置参数名称[in]。
	//! \param &value 配置参数新值[in]。
	virtual void SetConfigOption(const UGString &name, UGString &value);
	//! \brief 更新配置参数。
	//! \return 配置参数字符串。
	UGString ValidateConfigOptions(void);
	
	//! \brief 初始化显示引擎。
	//! \param hWnd 外来窗口句柄[in]。
	//! \return 渲染窗口。
	virtual UGRenderWindow *Initialize(Window hWnd);
	//! \brief 重新初始化。
	virtual void ReInitialize();
	//! \brief 完成清理工作。
	virtual void ShutDown(void);
	//! \brief 渲染对象。
	//! \param &ro 被渲染对象[in]。
	virtual void Render(UGRenderOperation &ro);
	//! \brief  帧开始，GL是靠顶点数组完成绘制这里面没有做任何事情
	virtual void BeginFrame();
	//! \brief  帧结束，没有做任何事情
	virtual void EndFrame();
	//! \brief  交换前后缓存
	virtual void Present();
	//! \brief 创建窗口对象。
	//! \param hWnd 外部窗口句柄[in]。
	//! \return 窗口对象。
	virtual UGRenderWindow *CreateRenderWindow(Window hWnd, NameValuePairList *miscParams = 0);
	
	
	//! \brief 设置环境光。
	//! \param r 红分量[in]。
	//! \param g 绿分量[in]。
	//! \param b 蓝分量[in]。
	virtual void SetAmbientLight(UGfloat r, UGfloat g, UGfloat b);
	//! \brief 设置渲染模式。
	//! \param so 渲染模式[in]。
	virtual void SetShadingType(ShadeOptions so);
	//! \brief 设置光源状态。
	//! \param enabled true为开启,false为关闭[in]。
	virtual void SetLightingEnabled(UGbool enabled);
	//! \brief 使用光源。
	//! \param lights 光源对象[in]。
	//! \param limit 光源上限[in]。
	virtual void UseLights(const UGLightList& lights, UGuint limit);
	
	// modified by luofx 07.12.5
//	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled);
//	virtual UGbool GetLightEnabled(UGint nLightID);
//	virtual void SetLightPos(UGint nLightID,UGfloat x,UGfloat y,UGfloat z,UGfloat w);
	

//	virtual void SetDepthBufferEnabled(UGbool bEnabled = TRUE);
	//! \brief 设置深度缓存参数。
	//! \param depthTest 缺省为true true为启动深度测试,false为关闭深度测试[in]。
	//! \param depthWrite 缺省为true true可写,false为不可写[in]。
	//! \param depthFunction  缺省为CMPF_LESS_EQUAL, 比较函数[in]。
	virtual void SetDepthBufferParams(UGbool depthTest = true, UGbool depthWrite = true, 
		CompareFunction depthFunction = CMPF_LESS_EQUAL);
	//! \brief 设置深度缓存状态。
	//! \param enabled 缺省为true,true为开启,false为关闭 [in]。
	virtual void SetDepthBufferCheckEnabled(UGbool enabled = true);
	//! \brief 设置缓存是否可写。
	//! \param enabled 缺省为true, true为可写,false为不可写 [in]。
	virtual void SetDepthBufferWriteEnabled(UGbool enabled = true);
	//! \brief 设置深度缓存比较函数。
	//! \param func 缺省为CMPF_LESS_EQUAL,比较函数 [in]。
	virtual void SetDepthBufferFunction(CompareFunction func = CMPF_LESS_EQUAL);
	//! \brief 设置可写颜色缓存。
	//! \param red 红色分量[in]。
	//! \param green 绿色分量[in]。
	//! \param blue 蓝色[in]。
	//! \param alpha alpha分量[in]。	
	virtual void SetColourBufferWriteEnabled(UGbool red, UGbool green, UGbool blue, UGbool alpha);
	//! \brief 设置深度偏差。
	//! \param bias 偏差值[in]。
	virtual void SetDepthBias(UGushort bias);
	//! \brief 设置模版缓存状态。
	//! \param enabled true为启动模版缓存, false为关闭模版缓存[in]。
	virtual void SetStencilCheckEnabled(UGbool enabled);
	//! \brief 设置模版缓存参数。
	//! \param CMPF_ALWAYS_PASS 比较函数[in]。
	//! \param refValue 缺省为0 模版参考值[in]。
	//! \param mask 0xFFFFFFFF 掩码值[in]。
	//! \param stencilFailOp 缺省为SOP_KEEP 模版测试失败函数[in]。
	//! \param depthFailOp 缺省为SOP_KEEP 深度测试失败函数[in]。
	//! \param passOp 缺省为SOP_KEEP 通过函数[in]。
	//! \param twoSidedOperation 缺省为false,true为两边都运算,false相反[in]。
	virtual void SetStencilBufferParams(CompareFunction func = CMPF_ALWAYS_PASS, 
            UGuint refValue = 0, UGuint mask = 0xFFFFFFFF, 
            StencilOperation stencilFailOp = SOP_KEEP, 
            StencilOperation depthFailOp = SOP_KEEP,
            StencilOperation passOp = SOP_KEEP, 
            UGbool twoSidedOperation = false);
	//! \brief 清理帧缓存。
	//! \param buffers 状态标志[in]。
	//! \param colour 缺省为UGColorValue::Black 清屏颜色[in]。
	//! \param depth 缺省为1.0f 深度缓存值[in]。
	//! \param stencil 缺省为0 模版值[in]。
	virtual void ClearFrameBuffer(UGuint buffers, 
		const UGColorValue& colour = UGColorValue::Black, 
		UGReal depth = 1.0f, UGushort stencil = 0);
	
	//! \brief 设置世界矩阵。
	//! \param &m 世界矩阵[in]。
	virtual void SetWorldMatrix(const UGMatrix4d& m);
	virtual UGMatrix4d& GetWorldMatrix();
	//! \brief 设置视图矩阵。
	//! \param &m 视图矩阵[in]。
	virtual void SetViewMatrix(const UGMatrix4d& m);
	virtual UGMatrix4d& GetViewMatrix();
	//! \brief 设置投影矩阵。
	//! \param &m 投影矩阵[in]。
	virtual void SetProjectionMatrix(const UGMatrix4d &m);
	virtual UGMatrix4d& GetProjectionMatrix();
	//! \brief 转换矩阵。
	//! \param matrix 源矩阵[in]。
	//! \param dest 目标矩阵[out]。
	//! \param forGpuProgram 缺省为false [in]。
	//! \remarks 右手坐标系转换成左手坐标系。
	virtual void ConvertProjectionMatrix(const UGMatrix4d& matrix,
            UGMatrix4d& dest, UGbool forGpuProgram = false);
	//! \brief 生成投影矩阵。
	//! \param fovy 角度[in]。
	//! \param aspect 宽高比[in]。
	//! \param nearPlane 近平面z值[in]。
	//! \param farPlane 远平面z值[in]。
	//! \param dest 生成矩阵[out]。
	//! \param forGpuProgram 缺省为false [in]。
	virtual void MakeProjectionMatrix(const UGAngle& fovy, UGReal aspect, UGReal nearPlane, 
		UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false);
	//! \brief 生成投影矩阵。
	//! \param left 左x坐标值[in]。
	//! \param right 右x坐标值[in]。
	//! \param bottom 底y坐标值[in]。
	//! \param top 上y坐标值[in]。
	//! \param nearPlane 近平面z值[in]。
	//! \param farPlane 远平面z值[in]。
	//! \param dest 生成矩阵[out]。
	//! \param forGpuProgram 缺省为false[in]。
	virtual void MakeProjectionMatrix(UGReal left, UGReal right, UGReal bottom, UGReal top, 
            UGReal nearPlane, UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false);
	//! \brief 生成平行投影矩阵。
	//! \param fovy 角度[in]。
	//! \param aspect 宽高比[in]。
	//! \param nearPlane 近平面z值[in]。
	//! \param farPlane 远平面Z值[in]。
	//! \param dest 生成矩阵[out]。
	//! \param forGpuProgram 缺省为false[in]。
	virtual void MakeOrthoMatrix(const UGAngle& fovy, UGReal aspect, UGReal nearPlane, 
		UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false);
	virtual void MakeOrhtoMatrix(UGReal left, UGReal right, UGReal bottom, 
								 UGReal top, UGReal near, UGReal far, UGMatrix4d& dest);
	//! \brief 生成倾斜深度矩阵。
	//! \param matrix 生成矩阵[out]。
	//! \param plane 平面[in]。
	//! \param forGpuProgram [in]。
	virtual void ApplyObliqueDepthProjection(UGMatrix4d& matrix, const UGPlane& plane, 
            UGbool forGpuProgram);

//	virtual UGMatrix4d SetProjectionMatrix(UGReal fovy, UGReal aspect, UGReal nearPlane, 
//		UGReal farPlane);
//	virtual UGMatrix4d SetViewMatrix(UGVector3R cameraPosition, 
//		UGVector3R cameraTarget, 
//		UGVector3R cameraUpVector, 
//		UGAngle Tilt, UGAngle Bank, UGAngle Heading, UGReal dDistance);
	//! \brief 世界坐标投影成屏幕坐标。
	//! \param &v 世界坐标[in]。
	//! \param &win 屏幕坐标[out]。
	virtual void Project(const UGVector3R &v, UGVector3R &win);
	//! \brief 屏幕坐标转换成世界坐标。
	//! \param &win 屏幕坐标[in]。
	//! \param &v 世界坐标[out]。
	virtual void UnProject(const UGVector3R &win,UGVector3R &v);
	
	// 生成选择射线
	virtual void MakePickRadial(const UGint x, const UGint y, 
		                        UGVector3R& nPos, UGVector3R& fPos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO);
	virtual void UnMakePickRadial(UGfloat& x, UGfloat& y, UGfloat& z, UGVector3R& Pos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO);

	//! \brief 设置视口。
	//! \param *pViewport 视口对象指针[in]。
	virtual void SetViewport(UGViewport *pViewport);



    // malq下面这两个函数也暂时不用,改成后面2参数的两个
//	virtual void Project(const UGVector3R &v, 
//		const UGMatrix4d &ViewMatrix, const UGMatrix4d &projMatrix, 
//		const UGViewport &viewPort, UGVector3R &win);
//	virtual void UnProject(const UGVector3R &win, 
//		const UGMatrix4d &ViewMatrix, const UGMatrix4d &projMatrix, 
//		const UGViewport &viewPort, UGVector3R &v);

	//! \brief 设置纹理。
	//! \param unit 纹理通道索引[in]。
	//! \param enabled true为启动,false为取消[in]。
	//! \param &texname 纹理名称[in]。
	virtual void SetTexture(UGuint unit, UGbool enabled, const UGString &texname);
	virtual UGuint SetTexture(UGuint unit, UGuint size, UGuchar* textureData);
	virtual void SetQuadTexture(UGuint bindId);
	//! \brief 设置纹理坐标系。
	//! \param unit 纹理单元索引号[in]。
	//! \param index 纹理坐标索引号[in]。
	virtual void SetTextureCoordSet(UGuint unit, UGuint index);
	//! \brief 计算纹理坐标值。
	//! \param unit 纹理单元[in]。
	//! \param m 计算纹理坐标值方法[in]。
	//! \param frustum 视锥体，包括六个面[in]。
	virtual void SetTextureCoordCalculation(UGuint unit, TexCoordCalcMethod m, 
            const UGFrustum* frustum = 0);
	//! \brief 设置纹理混合模式。
	//! \param unit 纹理单元索引号[in]。
	//! \param bm 颜色混合类[in]。
	virtual void SetTextureBlendMode(UGuint unit, const UGLayerBlendModeEx& bm);
	//! \brief 设置纹理单位的过滤项。
	//! \param unit 纹理单元索引号[in]。
	//! \param ftype 过滤项[in]。
	//! \param filter 滤波方法[in]。
	virtual void SetTextureUnitFiltering(UGuint unit, FilterType ftype, FilterOptions filter);
	//! \brief 设置纹理单元最大各向性值。
	//! \param unit 纹理单元索引号[in]。
	//! \param maxAnisotropy 最大各向性值[in]。
	virtual void SetTextureLayerAnisotropy(UGuint unit, UGuint maxAnisotropy);
	//! \brief 设置纹理单元纹理地址处理模式。
	//! \param unit 纹理单元索引号[in]。
	//! \param uvw UVW纹理地址对象[in]。
	virtual void SetTextureAddressingMode(UGuint unit, const UGTextureUnitState::UVWAddressingMode& uvw);
	//! \brief 设置纹理单元边框颜色。
	//! \param unit 纹理单元索引号[in]。
	//! \param colour 颜色值[in]。
	virtual void SetTextureBorderColour(UGuint unit, const UGColorValue& colour);
	//! \brief 设置纹理单元纹理矩阵。
	//! \param unit 纹理单元索引号[in]。
	//! \param xform 纹理单元矩阵[in]。
	virtual void SetTextureMatrix(UGuint unit, const UGMatrix4d& xform);	
	//! \brief 设置按比例混合。
	//! \param sourceFactor 源因子[in]。
	//! \param destFactor 目的因子[in]。
	virtual void SetSceneBlending(SceneBlendFactor sourceFactor, SceneBlendFactor destFactor);
	//! \brief 设置Aplpha测试，一般用作对透明处理。
	//! \param func Alpha比较函数[in]。
	//! \param value Alpha参考值[in]。
	virtual void SetAlphaRejectSettings(CompareFunction func, UGuchar value);
	GLint ConvertCompareFunction(CompareFunction func) const;
	//! \brief 设置透明度。
	//! \param fOpacity 透明度值[in]。
	virtual void SetOpacity(UGfloat fOpacity);	
	//! \brief 融合Alpha值。
	virtual void BlendAlpha();	



	//! \brief 删除列表。
	//! \param listIndex 列表索引[in]。
	//! \remarks 列表操作对于GL有效，D3D无效。
	virtual void DeleteList(UGint listIndex);
	//! \brief 调用列表。
	//! \param listIndex 列表索引[in]。
	virtual void CallList(UGint listIndex);	
	// modified by luofx 07.12.5
//	virtual void SetRenderDetail(SceneDetailLevel renderDetail);
	//! \brief 设置剔除模式。
	//! \param mode 剔除模式[in]。
	virtual void SetCullingMode(CullingMode mode);
	//! \brief 设置绘制多边形类型。
	//! \param level 类型枚举常量[in]。
	virtual void SetPolygonMode(PolygonMode level);
	//! \brief 确定物体前面，剔除物体后面。
	//! \param enFrontFace 确定物体前面方法[in]。
	//! \attention 参数建议采用枚举常量，要不然用起来相当费劲。
	//! \attention 同时要同一这个函数。
	virtual void SetPolyFrontFace(UGint  enFrontFace);
	//! \brief 设置雾。
	//! \param mode 雾生成模式[in]。
	//! \param colour 雾颜色[in]。
	//! \param expDensity 雾浓度[in]。
	//! \param linearStart 雾效开始Z值[in]。
	//! \param linearEnd 雾效结束Z值[in]。
	virtual void SetFog(FogMode mode = FOG_NONE, const UGColorValue& colour = UGColorValue::White, 
		UGReal expDensity = 1.0, UGReal linearStart = 0.0, UGReal linearEnd = 1.0);
	// modified by luofx 07.12.5
//	virtual void SetFogEnable(UGbool bEnable);
//	virtual UGbool GetFogEnable();
//	virtual void RenderFog(UGfloat fStart,UGfloat fEnd);
	//! \brief 设置是否渲染点精灵。
	//! \param enabled 如果渲染设置true，否则设置false[in]。
	virtual void SetPointSpritesEnabled(UGbool enabled);
	//! \brief 设置点精灵的渲染参数。
	//! \param size 点大小[in]。
	//! \param attenuationEnabled True则constant,linear,quadratic参数用来计算点尺寸。False则无效[in]。
	//! \param constant 计算点尺寸大小所用公式常数[in]。
	//! \param linear 计算点尺寸大小所用公式一次项系数[in]。
	//! \param quadratic 计算点尺寸大小所用公式二次项系数[in]。
	//! \param minSize 点大小最小值[in]。
	//! \param maxSize 点大小最大值[in]。
	virtual void SetPointParameters(UGReal size, UGbool attenuationEnabled, 
			UGReal constant, UGReal linear, UGReal quadratic, 
			UGReal minSize, UGReal maxSize);


	//! \brief 获取顶点元素类型。
	//! \return 顶点元素类型。
	virtual VertexElementType GetColourVertexElementType(void) const;
	//! \brief 启用顶点声明。
	//! \param decl 顶点声明[in]。
	virtual void SetVertexDeclaration(UGVertexDeclaration* decl);
	//! \brief 设置绑定顶点缓冲。
	//! \param binding 顶点缓冲绑定对象[in]。
	virtual void SetVertexBufferBinding(UGVertexBufferBinding* binding);


	void TextOut2DText(const UGchar* s,const UGVector3R& vecPos);
	void TextOut3DText( const UGchar* s,const UGVector3R& vecPos,const UGColorValue& colorText,UGint* & pCharList);
	//! \brief 绘制字体。
	virtual void SetRenderFont();	

	// 添加绘制BoundingBox函数
	virtual void DrawBoundingBox(const UGBoundingBox& boundingBox);
	virtual void DrawRadia(const UGVector3R& vecStart, const UGVector3R& vecEnd, const UGVector3R& vecIntersect);
	

//------------------------------------------------------------------
//                      OpenGLRenderSys自定义函数     
//-------------------------------------------------------------------
	//! \brief 获取纹理类型。
	//! \param nTextureType 索引号[in]。
	//! \return 纹理类型常量。
	GLenum GetGLTextureType(UGuint nTextureType) const;	
	//! \brief 设置光源位置
	//virtual void SetLightPos(UGint nLightID,UGfloat x,UGfloat y,UGfloat z,UGbool bLatLongPos);
	//! \brief 显示出位图字体
//	void PrintBitmapFont( const UGchar* s);	
	//! \brief 显示带边框字体
//	void PrintOutLinesFont(const UGchar* s,const UGVector3R& vecPos,const UGColorValue& colorOutLines,const UGColorValue& colorFont);
	
	//! \brief 		得到扫描行的字节个数
	//! \return 	UGint
	//! \param 		ePixelFormat 象素的格式
	//! \param 		nWidth       一行象素的个数
	//! \remarks 		
	//virtual void  RenderTriangles(UGReal* pVertexData=NULL,UGReal* pTexCoordData=NULL,UGReal* pFacetNormsData=NULL,UGReal* pVertexNormsData=NULL);
    
	//! \brief 初始对象函数
	void InitGL();

	//! \brief 矩阵生成GL使用数组，列主序。
	//! \param gl_matrix[16] 矩阵生成后数组[in]。
	//! \param m 矩阵[in]。
	void MakeGLMatrix(UGfloat gl_matrix[16], UGMatrix4d& m);
	
	//! \brief 绘制单个点精灵。
	//! \param x 点x值[in]。
	//! \param y 点y值[in]。
	//! \param z 点z值[in]。
	//! \param bDistChange true为设置计算点大小公式中ABC参数，false为使用默认值[in]。
	//! \param pQuadratic 保存A,B,C值首地址[in]。
	virtual void RenderSpritePoint(UGdouble x,UGdouble y,UGdouble z,UGbool bDistChange,UGfloat* pQuadratic);	
	//! \brief 绘制多个顶点点精灵。
	//! \param pVertex 顶点数值首地址[in]。
	//! \param nVertexCount 顶点个数[in]。
	//! \param bDistChange true为设置计算点大小公式中ABC参数，false为使用默认值[in]。
	//! \param pQuadratic 保存A,B,C值首地址[in]。
	virtual void RenderSpritePoint(UGReal* pVertex,UGint nVertexCount,UGbool bDistChange,UGfloat* pQuadratic, UGint selectedPointIndex = -1);
	//! \brief 绘制单个普通点。
	//! \param x 点x值[in]。
	//! \param y 点y值[in]。
	//! \param z 点z值[in]。
	//! \param bPointSmooth 缺省为FALSE，true为光滑点，false为非光滑点[in]。
	virtual void RenderSimplePoint(UGdouble x,UGdouble y,UGdouble z,UGbool bPointSmooth=FALSE);
	//! \brief 绘制多个普通点。
	//! \param pVertex 顶点首地址[in]。
	//! \param nVertexCount 顶点个数[in]。
	//! \param bPointSmooth 缺省为FALSE，true为光滑点，false为非光滑点[in]。
	virtual void RenderSimplePoint(UGReal* pVertex,UGint nVertexCount,UGbool bPointSmooth=FALSE, UGint selectedPointIndex = -1);
	//! \brief 设置点线颜色。
	//! \param colorValue 颜色值[in]。
	virtual void  SetSingleColor(const UGColorValue& colorValue);
	//! \brief 设置点大小。
	//! \param fSize 大小值[in]。
	virtual void SetPointSize(UGReal fSize);
	//! \brief 设置线宽。
	//! \param fSize 线宽值[in]。
	virtual void SetLineWidth(UGReal fSize);

	//! \brief 设备上下文初始化。
	virtual void OneTimeContextInitialization();	

	//! \brief 设置光源位置方向。
	//! \param lt 光源对象指针[in]。
	//! \param lightindex 光源号[in]。
	void SetGLLightPositionDirection(UGLight* lt, GLenum lightindex);	
	
	//! \brief 设置光源。
	//! \param index 光源号[in]。
	//! \param lt 光源对象指针[in]。
	void SetGLLight(UGint index, UGLight* lt);	
	
	//! \brief 设置光源。
	void SetLights();	

	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled);
	virtual UGbool GetLightEnabled(UGint nLightID);

private:

	//! \brief 获取多重纹理最大数
	UGushort GetNumTextureUnits(void);

	//! \brief 这个函数有问题
	void MakeRowGLMatrix(UGdouble glMatrix[16], const UGMatrix4d& mat);
	
	//! \brief 这个函数有问题
	void MakeColGLMatrix(UGdouble glMatrix[16], const UGMatrix4d& mat);
	
	//! \brief 删除没有使用纹理
//	void DeleteUnusedTextures();

	//! \brief 初始化配置参数。
	void InitConfigOptions(void);
	
	virtual void Render2DImage(UGint xStart,UGint yStart,UGint nWidth,UGint nHeight, UGbool bIsNeedRotate = FALSE, UGdouble dAngle = 0.0f);
	
protected:
	
	//! \brief OpenGL基本信息管理类
	UGGLSupport* m_pGLSupport;
	
	//! \brief 纹理坐标数组
	UGint m_TextureCoordIndex[SMSCN_MAX_TEXTURE_COORD_SETS];

	//! \brief 窗口矩阵??
	UGMatrix4d m_ViewMatrix;

	//! \brief 世界坐标矩阵
	UGMatrix4d m_WorldMatrix;

	UGdouble m_dAngleFromCurToPole;

private:
	
	//! \brief Store last depth write state
	UGbool m_bDepthWrite;

	//! \brief Store last stencil mask state
	UGuint m_nStencilMask;

	//! \brief Store last colour write state
	UGbool m_bColourWrite[4];
	
	//! \brief Number of fixed-function texture units
	UGushort mFixedFunctionTextureUnits;
	
	 //! \brief 光源指针数组。
     UGLight* m_pLights[MAX_LIGHTS];
	 
	 //! \brief 当前光源。
	 UGuint m_nCurrentLights;

};

extern "C" GLRENDERSYS_API UGRenderSys* CreateRenderSys();

}
#endif // !defined(AFX_UGGLRENDERSYS_H__E87F3D39_C520_427D_9F11_72CB26885C13__INCLUDED_)
