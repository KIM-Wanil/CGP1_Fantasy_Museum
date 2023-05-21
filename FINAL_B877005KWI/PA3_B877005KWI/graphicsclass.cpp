////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;
	modelCount = 15;
	for (int i = 0; i < modelCount; i++)
	{
		m_Model[i] = 0;
	}
	m_LightShader = 0;
	m_Light = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;


	// Create the Direct3D object.
	m_D3D = new D3DClass;
	if(!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;
	if(!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(50.0f, 5.0f, 0.0f);	
	//m_Camera->SetPosition(0.0f, 0.0f, -20.0f);	

		
	// Create the model object.
	for (int i = 0; i < modelCount; i++) 
	{
		m_Model[i] = new ModelClass;
		if (!m_Model[i])
		{
			return false;
		}
	}

	// Initialize the model object.
	result = m_Model[0]->Initialize(m_D3D->GetDevice(), L"./data/deathwing.obj", L"./data/deathwing.dds", 0);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	//¶¥
	result = m_Model[1]->Initialize(m_D3D->GetDevice(), L"./data/ground.obj", L"./data/tile.dds", 1);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[2]->Initialize(m_D3D->GetDevice(), L"./data/hallmaxlast.obj", L"./data/hall.dds", 2);
	//result = m_Model[2]->Initialize(m_D3D->GetDevice(), L"./data/gallery.obj", L"./data/hall.dds", 2);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[3]->Initialize(m_D3D->GetDevice(), L"./data/barrier.obj", L"./data/hall.dds", 3);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[4]->Initialize(m_D3D->GetDevice(), L"./data/golem.obj", L"./data/golem.dds", 4);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[5]->Initialize(m_D3D->GetDevice(), L"./data/dragon.obj", L"./data/dragon.dds", 5);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[6]->Initialize(m_D3D->GetDevice(), L"./data/sylvanas.obj", L"./data/sylvanas.dds", 6);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[7]->Initialize(m_D3D->GetDevice(), L"./data/demon.obj", L"./data/demon.dds", 7);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[8]->Initialize(m_D3D->GetDevice(), L"./data/lion.obj", L"./data/lion.dds", 8);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[9]->Initialize(m_D3D->GetDevice(), L"./data/horseman.obj", L"./data/horseman.dds", 9);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[10]->Initialize(m_D3D->GetDevice(), L"./data/hell.obj", L"./data/hell.dds", 10);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[11]->Initialize(m_D3D->GetDevice(), L"./data/plant.obj", L"./data/plant.dds", 11);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[12]->Initialize(m_D3D->GetDevice(), L"./data/cerberus.obj", L"./data/cerberus.dds", 12);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[13]->Initialize(m_D3D->GetDevice(), L"./data/stand.obj", L"./data/deathwing.dds", 13);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	result = m_Model[14]->Initialize(m_D3D->GetDevice(), L"./data/phoenix3.obj", L"./data/phoenix.dds", 14);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	// Create the light shader object.
	m_LightShader = new LightShaderClass;
	if (!m_LightShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_LightShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the light object.
	m_Light = new LightClass;
	if (!m_Light)
	{
		return false;
	}

	// Initialize the light object.
	m_Light->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light->SetDiffuseColor(0.2f, 0.2f, 0.2f, 1.0f);
	m_Light->SetDirection(1.0f, -1.0f, 1.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(128.0f);
	

	m_Light1 = new LightClass;
	if (!m_Light1)
	{
		return false;
	}
	// Initialize the first light object.

	m_Light1->SetDiffuseColor(0.7f, 0.7f, 0.7f, 1.0f);
	m_Light1->SetPosition(60.0f, 10.0f, 50.0f);
	// Create the second light object.

	m_Light2 = new LightClass;
	if (!m_Light2)
	{
		return false;
	}
	// Initialize the second light object.

	m_Light2->SetDiffuseColor(0.7f, 0.7f, 0.7f, 1.0f);
	m_Light2->SetPosition(60.0f, 10.0f, -50.0f);


	// Create the third light object.
	m_Light3 = new LightClass;
	if (!m_Light3)
	{
		return false;
	}

	// Initialize the third light object.
	m_Light3->SetDiffuseColor(0.7f, 0.7f, 0.7f, 1.0f);
	m_Light3->SetPosition(-30.0f, 10.0f, 50.0f);

	// Create the fourth light object.
	m_Light4 = new LightClass;
	if (!m_Light4)
	{
		return false;
	}
	// Initialize the fourth light object.
	m_Light4->SetDiffuseColor(0.7f, 0.7f, 0.7f, 1.0f);
	m_Light4->SetPosition(-30.0f, 10.0f, -50.0f);
	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the model object.
	if(m_Model)
	{
		for (int i = 0; i < modelCount; i++)
		{
			m_Model[i]->Shutdown();
			delete m_Model[i];
			m_Model[i] = 0;
		}
	}


	// Release the camera object.
	if(m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the D3D object.
	if(m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	// Release the light object.
	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}
	if (m_Light1)
	{
		delete m_Light1;
		m_Light1 = 0;
	}

	if (m_Light2)
	{
		delete m_Light2;
		m_Light2 = 0;
	}

	if (m_Light3)
	{
		delete m_Light3;
		m_Light3 = 0;
	}

	if (m_Light4)
	{
		delete m_Light4;
		m_Light4 = 0;
	}
	// Release the light shader object.
	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}
	
	return;
}

bool GraphicsClass::Frame()
{
	bool result;

	static float rotation = 0.0f;
	static float trans1 = 0.0f;
	static int dir = 1;
	static float rot1 = -XM_PI * 0.5f;

	// Update the rotation variable each frame.
	rotation += XM_PI * 0.008f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	if (trans1 > 50.0f && dir == 1)
	{
		dir = 0;
		rot1 =  XM_PI * 0.5f;
	}
	if (trans1 < -50.0f && dir == 0)
	{
		dir = 1;
		rot1 = -XM_PI * 0.5f;
	}

	if (dir == 1)
	{
		trans1 += 0.1f;
	}
	else
	{
		trans1 -= 0.1f;
	}

	// Render the graphics scene.
	result = Render(rotation,trans1,rot1);
	if(!result)
	{
		return false;
	}

	return true;
}

bool GraphicsClass::Render(float rotation,float trans1,float rot1)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	bool result;


	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	//worldMatrix = XMMatrixRotationY(rotation);
	m_SetMatrix[0] = { 0.05f, 0.05f, 0.05f,//µ¥½ºÀ®
					   0.0f, rotation * 0.03f, 0.0f,
					   10.0f, 11.0f, 0.0f };

	m_SetMatrix[1] = { 10.0f, 10.0f, 1.0f,
					  0.5f * XM_PI, 0.0f, 0.0f,
					   0.0f, -3.0f, 0.0f };
	m_SetMatrix[2] = { 10.0f, 10.0f, 10.0f,
				      0.5f * XM_PI, 0.0f, 0.0f,
					   0.0f, -3.0f, 0.0f };
	m_SetMatrix[3] = { 0.2f, 0.1f, 0.1f,//barrier
					  0.0f, 0.0f, 0.0f,
					   0.0f, 0.0f, 0.0f };
	m_SetMatrix[4] = { 0.1f, 0.1f, 0.1f,//°ñ·½
					  0.0f, 0.0f, 0.0f,
					   -5.0f, 0.0f, 75.0f };
	m_SetMatrix[5] = { 7.0f, 7.0f, 7.0f,//µå·¡°ï
					  0.0f, 0.0f, 0.0f,
					   40.0f, 0.0f, 80.0f };
	m_SetMatrix[6] = { 3.0f, 3.0f, 3.0f,//½Ç¹Ù³ª½º¼®»ó
					  0.0f, -0.5f * XM_PI, 0.0f,
					   -200.0f, 27.0f, -5.0f };
	m_SetMatrix[7] = { 0.25f, 0.25f, 0.25f,//¾Ç¸¶
					  0.0f, 0.0f, 0.0f,
					   80.0f, 0.0f, 75.0f };
	m_SetMatrix[8] = { 7.0f, 7.0f, 7.0f,//»çÀÚ
					  0.0f, 1.0f * XM_PI, 0.0f,
					   40.0f, 3.0f, -80.0f };
	m_SetMatrix[9] = { 4.0f, 4.0f, 4.0f,//±â»ç
					  0.0f, 1.0f * XM_PI, 0.0f,
					   80.0f, 45.0f, -80.0f };
	m_SetMatrix[10] = { 0.07f, 0.07f, 0.07f,//Áö¿Á
					  0.0f, 0.0f, 0.0f,
					   -5.0f, -0.5f, -85.0f };
	m_SetMatrix[11] = { 0.1f, 0.1f, 0.1f,//½Ä¹°
					  0.0f, 0.0f, 0.0f,
					   -50.0f, 0.0f, -85.0f };
	m_SetMatrix[12] = { 0.8f, 0.8f, 0.8f,//ÄÉ¸£º£·Î½º
					  0.0f, 1.0f * XM_PI, 0.0f,
					   -55.0f, 0.0f, 90.0f };
	m_SetMatrix[13] = { 2.0f, 2.0f, 2.0f,//½ºÅÄµå
					  0.0f, 0.0f, 0.0f,
					   10.0f, 3.0f, 0.0f };
	m_SetMatrix[14] = { 1.0f, 1.0f, 1.0f,//ÇÇ´Ð½º
					  0.0f, rot1, 0.0f,
					   -50.0f, 120.0f, trans1 };

	XMFLOAT4 pointDiffusecolor[4];
	XMFLOAT4 lightPosition[4];

	/*pointDiffusecolor[0] = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
	pointDiffusecolor[1] = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
	pointDiffusecolor[2] = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
	pointDiffusecolor[3] = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);

	lightPosition[0] = XMFLOAT4(0.0f, 0.1f, 0.0f, 1.0f);
	lightPosition[1] = XMFLOAT4(-0.1f, 0.01f, 0.1f, 1.0f);
	lightPosition[2] = XMFLOAT4(1.0f, 1.0f, -1.0f, 1.0f);
	lightPosition[3] = XMFLOAT4(-1.0f, 1.0f, -1.0f, 1.0f);*/
	pointDiffusecolor[0] = m_Light1->GetDiffuseColor();
	pointDiffusecolor[1] = m_Light2->GetDiffuseColor();
	pointDiffusecolor[2] = m_Light3->GetDiffuseColor();
	pointDiffusecolor[3] = m_Light4->GetDiffuseColor();

	lightPosition[0] = m_Light1->GetPosition();
	lightPosition[1] = m_Light2->GetPosition();
	lightPosition[2] = m_Light3->GetPosition();
	lightPosition[3] = m_Light4->GetPosition();

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	for (int i = 0; i < modelCount; i++)
	{
		m_Model[i]->Render(m_D3D->GetDeviceContext());
		worldMatrix = ConvertWorldMatrix(m_SetMatrix[i]);
		// Render the model using the light shader.
		result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model[i]->GetIndexCount(),
			m_Model[i]->GetInstanceCount(i),
			worldMatrix, viewMatrix, projectionMatrix,
			m_Model[i]->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(), pointDiffusecolor, lightPosition);
		if (!result)
		{
			return false;
		}
	}
	
	

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}

XMMATRIX GraphicsClass::ConvertWorldMatrix(SetMatrix temp_matrix)
{
	XMMATRIX matTrans, matRotation, matScale, matFinal;

	matScale = XMMatrixScaling(temp_matrix.scaleX, temp_matrix.scaleY, temp_matrix.scaleZ);
	matRotation = XMMatrixRotationRollPitchYaw(temp_matrix.rotateX, temp_matrix.rotateY, temp_matrix.rotateZ);
	matTrans = XMMatrixTranslation(temp_matrix.transX, temp_matrix.transY, temp_matrix.transZ);
	matFinal = matScale * matRotation * matTrans;
	return matFinal;
}
void GraphicsClass::OnOffAmbientLight() { m_LightShader->OnOffAmbientLight(); };
void GraphicsClass::OnOffDiffuseLight() { m_LightShader->OnOffDiffuseLight(); };
void GraphicsClass::OnOffSpecularLight() { m_LightShader->OnOffSpecularLight(); };
//void GraphicsClass::OnOffSpecularColor() { m_Light->OnOffSpecularColor(); };

float GraphicsClass::GetCamYaw()
{
	return m_Camera->GetCamYaw();
}

float GraphicsClass::GetCamPitch()
{
	return m_Camera->GetCamPitch();
}

void GraphicsClass::SetMoveLeftRight(float speed)
{
	m_Camera->SetMoveLeftRight(speed);
}

void GraphicsClass::SetMoveBackForward(float speed)
{
	m_Camera->SetMoveBackForward(speed);
}
void GraphicsClass::SetMoveUpDown(float speed)
{
	m_Camera->SetMoveUpDown(speed);
}
void GraphicsClass::SetYawPitch(float yaw, float pitch)
{
	m_Camera->SetYawPitch(yaw, pitch);
}