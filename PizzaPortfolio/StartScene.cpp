#include "stdafx.h"
#include "StartScene.h"
#include "Button.h"



StartScene::StartScene()
{
}


StartScene::~StartScene()
{
}

bool StartScene::Init()
{
	startBackImg = IMAGEMANAGER->findImage(TEXT("StartImage"));

	pButton = new Button;
	assert(pButton != NULL);

	pButton->Init(TEXT("StartButton"), WINSIZEX / 2, WINSIZEY - 100,
		PointMake(0, 1), PointMake(0, 0), cbSceneChange);
	
	//
	indexBlend = 150;
	nCount = 200;
	colorTurnIndex = 1;


	//
	SOUNDMANAGER->Play(TEXT("StartSound"), 0.5f);



	return true;
}

void StartScene::Release()
{
	SAFE_DELETE(pButton);
}

void StartScene::Update()
{
	// �������Դٰ� �����������
	if (nCount == 254 || nCount == 150) // �ִ�, �ּҰ�
		colorTurnIndex *= -1;

	if (colorTurnIndex == 1)
		nCount++;
	if (colorTurnIndex == -1)
		nCount--;

	indexBlend = nCount;
	

	pButton->Update();
}

void StartScene::Render(HDC hdc)
{
	startBackImg->AlphaRender(hdc, indexBlend);
	pButton->Render(hdc);
}

void StartScene::cbSceneChange()
{
	SCENEMANAGER->ChangeScene(TEXT("InGame1"));
}


// ��ư�� ,,, �����ϱ����� �������� ������ x

// �Լ������͸� �����ϵ��ϸ�

// ���⼭�� cbSceneChange()�̴�.