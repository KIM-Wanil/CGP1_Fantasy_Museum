////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	struct SetMatrix
	{
		float scaleX, scaleY, scaleZ;
		float rotateX, rotateY, rotateZ;
		float transX, transY, transZ;
	};//작성한 구조체

	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
	void OnOffAmbientLight();
	void OnOffDiffuseLight();
	void OnOffSpecularLight();
	float GetCamYaw();
	float GetCamPitch();
	void SetMoveLeftRight(float);
	void SetMoveBackForward(float);
	void SetMoveUpDown(float);
	void SetYawPitch(float,float);

private:
	bool Render(float,float,float);
	XMMATRIX ConvertWorldMatrix(SetMatrix);//작성한 함수
	


private:
	D3DClass* m_D3D;
	CameraClass* m_Camera;
	ModelClass* m_Model[15];
	int modelCount;
	LightShaderClass* m_LightShader;
	LightClass* m_Light;
	LightClass* m_Light1, * m_Light2, * m_Light3, * m_Light4;

	SetMatrix m_SetMatrix[15];
};
/*
obj0: 데스윙
obj1: 바닥
obj2: 건물
obj3: 배리어
obj4: 골렘
obj5: 둠
obj6:실바나스석상
obj7: 악마
obj8: 사자
obj9: 기사
obj10: 지옥
obj11: 식물
obj12: 케르베로스
obj13: 스탠드
obj14: 
*/
#endif