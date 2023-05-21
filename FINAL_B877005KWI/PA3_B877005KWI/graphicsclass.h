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
	};//�ۼ��� ����ü

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
	XMMATRIX ConvertWorldMatrix(SetMatrix);//�ۼ��� �Լ�
	


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
obj0: ������
obj1: �ٴ�
obj2: �ǹ�
obj3: �踮��
obj4: ��
obj5: ��
obj6:�ǹٳ�������
obj7: �Ǹ�
obj8: ����
obj9: ���
obj10: ����
obj11: �Ĺ�
obj12: �ɸ����ν�
obj13: ���ĵ�
obj14: 
*/
#endif