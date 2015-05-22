/* 
	\file UGD3DRenderSys.h
	\brief D3D渲染引擎类文件。
	\author 张艳良 luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGD3DRENDERSYS_H__6736EEA2_1529_43BA_87AF_CE7A52A398E3__INCLUDED_)
#define AFX_UGD3DRENDERSYS_H__6736EEA2_1529_43BA_87AF_CE7A52A398E3__INCLUDED_

#include "Scene/UGRenderSys.h"
#include "D3dRenderSys/UGD3D9Mappings.h"
#include "Algorithm/UGRect2D.h"

namespace UGC
{

class UGD3D9DriverList;
class UGD3D9Driver;



//! \brief D3D渲染引擎类
class D3DRENDERSYS_API UGD3DRenderSys : public UGRenderSys
{

public:

	//! \brief 构造函数。
	UGD3DRenderSys();	
	//! \brief 析构函数。
	virtual ~UGD3DRenderSys();		
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
	void SetConfigOption(const UGString &name, UGString &value);		
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
	//! \brief 桢起始。
	virtual void BeginFrame();	
	//! \brief 帧结束。
	virtual void EndFrame();		
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
	//! \brief 设置光源状态。
	//! \param nLightID 光源ID[in]。
	//! \param bEnabled true开启,false为关闭[in]。
	// modified by luofx 07.12.5
//	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled);	
	//! \brief 获取光源状态。
	//! \param nLightID 光源ID[in]。
	// modified by luofx 07.12.5
//	virtual UGbool GetLightEnabled(UGint nLightID);	
	//! \brief 设置光源位置。
	//! \param nLightID 光源ID[in]。
	//! \param x 位置x分量[in]。
	//! \param y 位置y分量[in]。
	//! \param z 位置z分量[in]。
	//! \param w 位置w分量[in]。
	// modified by luofx 07.12.5
//	virtual void SetLightPos(UGint nLightID,UGfloat x,UGfloat y,UGfloat z,UGfloat w);
	


	//! \brief 设置深度缓存是否启动。
	//! \param bEnable 缺省为true,true为启动,false为关闭[in]。
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
	virtual void SetWorldMatrix(const UGMatrix4d &m);	
	//! \brief 设置视图矩阵。
	//! \param &m 视图矩阵[in]。
	virtual void SetViewMatrix(const UGMatrix4d &m);	
	//! \brief 设置投影矩阵。
	//! \param &m 投影矩阵[in]。
	virtual void SetProjectionMatrix(const UGMatrix4d &m);	
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
	//! \brief 生成倾斜深度矩阵。
	//! \param matrix 生成矩阵[out]。
	//! \param plane 平面[in]。
	//! \param forGpuProgram [in]。
	virtual void ApplyObliqueDepthProjection(UGMatrix4d& matrix, const UGPlane& plane, 
            UGbool forGpuProgram);	
	//! \brief 生成投影矩阵。
	//! \param fovy 角度[in]。
	//! \param aspect 宽高比[in]。
	//! \param nearPlane 近平面z值[in]。
	//! \param farPlane 远平面[in]。
	//! \return 投影矩阵。
	// modified by luofx 07.12.5
//	virtual UGMatrix4d SetProjectionMatrix(UGReal fovy, UGReal aspect, UGReal nearPlane, 
//		                                   UGReal farPlane);	
	//! \brief 生成视图矩阵。
	//! \param cameraPosition 相机位置[in]。
	//! \param cameraTarget 相机焦点[in]。
	//! \param cameraUpVector 相机向上方向[in]。
	//! \param Tilt [in]。
	//! \param Bank [in]。
	//! \param Heading 航向[in]。
	//! \param dDistance 距离[in]。
	//! \return 视图矩阵。
	// modified by luofx 07.12.5
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
	//! \brief 设置视口。
	//! \param *pViewport 视口对象指针[in]。
	virtual void SetViewport(UGViewport *pViewport);	

	
	//! \brief 设置纹理。
	//! \param unit 纹理通道索引[in]。
	//! \param enabled true为启动,false为取消[in]。
	//! \param &texname 纹理名称[in]。
	virtual void SetTexture(UGuint unit, UGbool enabled, const UGString &texname);	
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
	

	//! \brief 设置绘制渲染细节模式。
	//! \param renderDetail 绘制模式[in]。
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
//	//! \brief 设置雾状态。
//	//! \param bEnable TRUE为启动，FALSE为关闭[in]。
//	virtual void SetFogEnable(UGbool bEnable);	
//	//! \brief 获取雾状态。
//	//! \return TRUE为打开，FALSE为关闭。
//	virtual UGbool GetFogEnable();	
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
	virtual void RenderSpritePoint(UGReal* pVertex,UGint nVertexCount,UGbool bDistChange,UGfloat* pQuadratic);	
	
	
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
	virtual void RenderSimplePoint(UGReal* pVertex,UGint nVertexCount,UGbool bPointSmooth=FALSE);	
	
	
	//! \brief 设置点线颜色。
	//! \param colorValue 颜色值[in]。
	virtual void  SetSingleColor(const UGColorValue& colorValue);	
	
	//! \brief 设置点大小。
	//! \param fSize 大小值[in]。
	virtual void SetPointSize(UGReal fSize);	
	
	//! \brief 设置线宽。
	//! \param fSize 线宽值[in]。
	virtual void SetLineWidth(UGReal fSize);	

protected:
	
	//! \brief 设置D3D常量新值。
	//! \param state 常量类型[in]。
	//! \param value 新值[in]。
	HRESULT SetRenderState(D3DRENDERSTATETYPE state, DWORD value);
	
	//! \brief 设置顶点声明。
	//! \param &ro 绘制操作对象[in]。
	HRESULT SetVertexDeclaration(const UGRenderOperation &ro);	
	
	//! \brief 设置缓存数据。
	//! \param &ro 绘制对象[in]。
	HRESULT SetBufferData(const UGRenderOperation &ro);	

	//! \brief 创建顶点缓冲。
	HRESULT CreateVertexBuffer();	
	
	//! \brief 创建索引缓冲。
	HRESULT CreateIndexBuffer();	
	
	//! \brief 创建纹理缓冲。
	HRESULT CreateTextureBuffer();	
	
	//! \brief 获取顶点声明个数。
	//! \param &ro 绘制操作对象[in]。
	UGushort GetVertexElementCount(const UGRenderOperation &ro);	

	//! \brief 填充顶点声明。
	//! \param &ro 绘制操作对象[in]。
	//! \param *pDwDecl 顶点声明[in]。
	HRESULT FillVertexElement(const UGRenderOperation &ro, 
										  D3DVERTEXELEMENT9 *pDwDecl);	

	//! \brief 判断是否有顶点数据。
	//! \param &ro 绘制操作对象[in]。
	//! \return true为有顶点数据，false为没有顶点数据。
	UGbool HasVertexData(const UGRenderOperation &ro);	
	
	//! \brief 判断是否有索引数据。
	//! \param &ro 绘制操作对象[in]。
	//! \return true为有索引顶点数据，false为没有顶点数据。
	UGbool HasIndexData(const UGRenderOperation &ro);

	//! \brief 测试设备状态。
	void TestDeviceState();	
	
	//! \brief 重新设置D3D状态。
	HRESULT ResetD3D();	
	
	//! \brief 清理缓冲区。
	HRESULT InvalidateBuffer();	

	//! \brief 获取D3D设备列表。
	//! \return D3D设备类表。
	UGD3D9DriverList* GetDirect3DDrivers(void);	

	//! \brief 刷新D3D设置。
	void RefreshD3DSettings(void);	
	
	//! \brief 刷新FSAA参数。
	void RefreshFSAAOptions(void);	
	//! \brief 释放设备。
	void FreeDevice(void);	

	//! \brief 检测多重采样质量。
	//! \param type 多重采样类型[in]。
	//! \param *outQuality 质量级别[out]。
	//! \param format 格式[in]。
	//! \param adapterNum 适配器数量[in]。
	//! \param deviceType 设备类别[in]。
	//! \param fullScreen true为全屏，false为非全屏[in]。
	UGbool CheckMultiSampleQuality(D3DMULTISAMPLE_TYPE type, 
								   DWORD *outQuality, D3DFORMAT format, UINT adapterNum, 
								   D3DDEVTYPE deviceType, UGbool fullScreen);	

	//! \brief 设置FSAA。
	//! \param type 多重采样类型[in]。
	//! \param qualityLevel 质量级别[in]。
	void SetFSAA(D3DMULTISAMPLE_TYPE type, DWORD qualityLevel);	
    
	
	//! \brief 初始化配置参数。
	void InitConfigOptions(void);	
	
	//! \brief 释放配置参数。
	void ReleaseConfigOptions();	

	//! \brief 设置光照。
	//! \param index 灯索引[in]。
	//! \param lt 光对象指针[in]。
	void SetD3D9Light( size_t index, UGLight* lt );	
	
	//! \brief 设置D3D状态参数
	//! \param state 状态类型。
	//! \param value 状态值为浮点数。
	HRESULT SetFloatRenderState(D3DRENDERSTATETYPE state, UGReal value);	
	
	//! \brief 设置纹理寻址属性。
	//! \param stage 纹理通道[in]。
	//! \param type 寻址类型[in]。
	//! \param value 属性值[in]。
	HRESULT SetTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value);	
	
	//! \brief 设置纹理过滤器。
	//! \param sampler 纹理通道[in]。
	//! \param type 过滤器类型[in]。
	//! \param value 属性值[in]。
	HRESULT SetSamplerState(DWORD sampler, D3DSAMPLERSTATETYPE type, DWORD value);	
	
	//! \brief 获取当前各向性值。
	//! \param unit 纹理通道索引[in]。
	DWORD GetCurrentAnisotropy(size_t unit);	

	//! \brief 初始化D3D。
	void InitD3D();

	//! \brief 输出二维文字。
	//! \param strText 输出文字内容[in]。
	//! \param rect 位置[in]。
	//! \param color 颜色[in]。
	//! \param DT_LEFT 格式[in]。
	//! \remarks 该输出方式采用ID3DFont模式。
	void TextOut2DText(UGString strText, UGRect2D rect, D3DCOLOR color, UGuint format = DT_TOP | DT_LEFT);
	

	//! \brief 输出三维文字。
	//! \param strText 文字内容[in]。
	void TextOut3DText(UGString strText);

	virtual void DrawBoundingBox(const UGBoundingBox& boundingBox){};
	virtual void DrawRadia(const UGVector3R& vecStart, const UGVector3R& vecEnd, const UGVector3R& vecIntersect){};
	
	// 临时使用光照函数
	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled){};
	virtual UGbool GetLightEnabled(UGint nLightID){return false;}
	virtual void MakePickRadial(const UGint x, const UGint y, UGVector3R& nPos, UGVector3R& fPos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO){};
	virtual UGMatrix4d& GetWorldMatrix(){return (UGMatrix4d)UGMatrix4d::ZERO;}
	virtual UGMatrix4d& GetViewMatrix(){return (UGMatrix4d)UGMatrix4d::ZERO;};
	virtual UGMatrix4d& GetProjectionMatrix(){return (UGMatrix4d)UGMatrix4d::ZERO;};
	virtual void RenderSimplePoint(UGReal* pVertex,UGint nVertexCount,UGbool bPointSmooth=FALSE, UGint selectedPointIndex = -1){};

	
private:		
	
	//! \brief 释放所有纹理。
	void ReleaseAllTexture();	
	
	//! \brief 现实帧频统计。
	void ShowFrameStat();	

private:
	
	//! \brief D3D对象。
	LPDIRECT3D9 m_pD3D;
	
	//! \brief D3D设备对象。
	LPDIRECT3DDEVICE9 m_pD3DDevice;		

	//! \brief 设备对象。
	UGD3D9Driver *m_pActiveD3DDriver;
	
	//! \brief 设备对象列表。
	UGD3D9DriverList* m_pDriverList;

	//! \brief 配置参数对象。
	UGConfigOptionMap m_Options;

	//! \brief 成员的简要说明。
	UGbool m_bUseNVPerfHUD;

	//! \brief 多重采样类型。
	D3DMULTISAMPLE_TYPE m_FSAAType;

	//! \brief 多重采用质量级别。
	DWORD m_FSAAQuality;	
	
	//! \brief 宽度。
	unsigned int m_nWidth;

	//! \brief 高度。
	unsigned int m_nHeight;
    //! \brief 颜色深度。
	unsigned int m_nColourDepth;
	
	//! \brief 设备状态。
	HRESULT m_hDeviceState;

	//! \brief 顶点数目。
	UGuint m_unLastVertexSourceCount;

	//! \brief 目前光源数。
	unsigned short m_nCurrentLights;

	//! \brief 视图矩阵。
	UGMatrix4d m_ViewMatrix;

	//! \brief 手动融合颜色数组
	UGColorValue m_ManualBlendColours[MAX_TEXTURE_NUM][2];	
	//! \brief 顶点声明对象。
	LPDIRECT3DVERTEXDECLARATION9 m_pDecl;
	//! \brief 顶点数目。
	UGuint m_unVBUsedVertexCount;	
	//! \brief 索引树木。
	UGuint m_unIBUsedVertexCount;
	//! \brief 顶点缓存。
	LPDIRECT3DVERTEXBUFFER9 m_pVB;	
	//! \brief 索引缓存。
	LPDIRECT3DINDEXBUFFER9  m_pIB;
	//! \brief 纹理缓存。
	LPDIRECT3DVERTEXBUFFER9 m_pTB;
//	LPDIRECT3DTEXTURE9 m_pTB;
	//! \brief 纹理数组。
	LPDIRECT3DTEXTURE9 m_pTexture[MAX_TEXTURE_NUM];		
	//! \brief 设备性能对象。
	D3DCAPS9 m_Caps;

	//! \brief 成员的简要说明。
	UGbool m_bPerStageConstantSupport;

	


	//! structure holding texture unit settings for every stage
	struct D3DTextureStageDesc
	{
		/// the type of the texture
		UGD3D9Mappings::eD3DTexType texType;
		/// wich texCoordIndex to use
		size_t coordIndex;
		/// type of auto tex. calc. used
		TexCoordCalcMethod autoTexCoordType;
        /// Frustum, used if the above is projection
        const UGFrustum *frustum;
		/// texture 
		IDirect3DBaseTexture9 *pTex;
	} m_TexStageDesc[MAX_TEXTURE_NUM];
	
	//! \brief 顶点格式。
	struct D3DVertexFormat
	{
		UGfloat x, y, z;
		UGfloat u, v;
	};

};
extern "C" D3DRENDERSYS_API UGRenderSys* CreateRenderSys();
}

#endif // !defined(AFX_UGD3DRENDERSYS_H__6736EEA2_1529_43BA_87AF_CE7A52A398E3__INCLUDED_)
