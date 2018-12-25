#include "stdafx.h"
#include "MainGame.h"
#include "StartScene.h"
#include "CookingRoomScene.h"
#include "RestaurantScene.h"
#include "ResultScene.h"
#include "ShopScene.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

bool MainGame::Init() // �ʱ�ȭ
{
	GameNode::Init(true);
	
	//===================================

	// ���⼭ �̹��� �޴����� �ʱ�ȭ ����.
	IMAGEMANAGER->Init();

	// ���Ŵ����� �ʱ�ȭ �ϰ� ... Scene�� �߰�
	SCENEMANAGER->Init();


	// StartScene
	IMAGEMANAGER->AddImage(TEXT("StartImage"), TEXT("Image/Pizza/����ȭ��.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("StartButton"), TEXT("Image/Pizza/���۹�ư.bmp"),0,0, 231, 222, 1, 2, true, COLOR_M);

	// InGame
	IMAGEMANAGER->AddImage(TEXT("�������"), TEXT("Image/Pizza/���ڰ���/���ڰ���.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("��������ܺ�"), TEXT("Image/Pizza/���ڰ���/���ڰ��Թ�.bmp"), 1200, 675, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("ī����"), TEXT("Image/Pizza/���ڰ���/ī����.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("���ڹڽ�"), TEXT("Image/Pizza/���ڰ���/���ڹڽ�.bmp"), 287, 122, true, COLOR_M);


	IMAGEMANAGER->AddImage(TEXT("��ħ"), TEXT("Image/Pizza/���ڰ���/��ħ.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("��"), TEXT("Image/Pizza/���ڰ���/��.bmp"), 1200, 675, true, COLOR_M);

	// Guest
	IMAGEMANAGER->AddImage(TEXT("�մ�1"), TEXT("Image/Pizza/�մ�/�մ�1.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("�մ�2"), TEXT("Image/Pizza/�մ�/�մ�2.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("�մ�3"), TEXT("Image/Pizza/�մ�/�մ�3.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("�մ�4"), TEXT("Image/Pizza/�մ�/�մ�4.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("�մ�5"), TEXT("Image/Pizza/�մ�/�մ�5.bmp"), 1200, 675, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("��ǳ��"), TEXT("Image/Pizza/�մ�/��ǳ����ư.bmp"), 1200, 675, true, COLOR_M);


	// CookingRoom
	IMAGEMANAGER->AddImage(TEXT("�丮��"), TEXT("Image/Pizza/�丮��/�丮�ǳ���.bmp"), 3160, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("����"), TEXT("Image/Pizza/�丮��/����Ѳ�.bmp"), 3160, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("���췹��"), TEXT("Image/Pizza/�丮��/���췹��.bmp"), 1140, 378, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("�ֹ�Ȯ��"), TEXT("Image/Pizza/�丮��/�ֹ�Ȯ��.bmp"), 1200, 675, true, COLOR_M);
	
	IMAGEMANAGER->AddImage(TEXT("Ŀ��Į"), TEXT("Image/Pizza/�丮��/Ŀ��Į.bmp"), 160, 109, true, COLOR_M);



	IMAGEMANAGER->AddImage(TEXT("�Ҽ����ڽ�"), TEXT("Image/Pizza/�丮��/���ڽ�/�Ҽ����ڽ�.bmp"), 182, 174, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("�����ڽ�"), TEXT("Image/Pizza/�丮��/���ڽ�/�����ڽ�.bmp"), 182, 174, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("�ø���ڽ�"), TEXT("Image/Pizza/�丮��/���ڽ�/�ø���ڽ�.bmp"), 182, 174, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("���Ĺڽ�"), TEXT("Image/Pizza/�丮��/���ڽ�/���Ĺڽ�.bmp"), 182, 174, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("�Ǹ��ڽ�"), TEXT("Image/Pizza/�丮��/���ڽ�/�Ǹ��ڽ�.bmp"), 182, 174, true, COLOR_M);




	//���
	IMAGEMANAGER->AddFrameImage(TEXT("����"), TEXT("Image/Pizza/���/����.bmp"), 2415, 330, 7, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("�ҽ�"), TEXT("Image/Pizza/���/�ҽ�.bmp"), 320, 80, 4, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("ġ��"), TEXT("Image/Pizza/���/ġ��.bmp"), 320, 80, 4, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("���۷δ�"), TEXT("Image/Pizza/���/���۷δ�.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("�Ҽ���"), TEXT("Image/Pizza/���/�Ҽ���.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("����"), TEXT("Image/Pizza/���/����.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("�ø���"), TEXT("Image/Pizza/���/�ø���.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("����"), TEXT("Image/Pizza/���/����.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("�Ǹ�"), TEXT("Image/Pizza/���/�Ǹ�.bmp"), 450, 50, 9, 1, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("����1"), TEXT("Image/Pizza/���/���ڵ���/����1.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("����2"), TEXT("Image/Pizza/���/���ڵ���/����2.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("����3"), TEXT("Image/Pizza/���/���ڵ���/����3.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("����4"), TEXT("Image/Pizza/���/���ڵ���/����4.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("����5"), TEXT("Image/Pizza/���/���ڵ���/����5.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("����6"), TEXT("Image/Pizza/���/���ڵ���/����6.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("����7"), TEXT("Image/Pizza/���/���ڵ���/����7.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("����8"), TEXT("Image/Pizza/���/���ڵ���/����8.bmp"), 97, 66, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("Bake"), TEXT("Image/Pizza/���/���ڵ���/Bake.bmp"), 280, 280, true, COLOR_M);




	

	ANIMANAGER->AddCoordAni(TEXT("����ִϸ��̼�"), TEXT("����"), 0, 7, 10, false);
	
	// UI
	IMAGEMANAGER->AddImage(TEXT("UI"), TEXT("Image/Pizza/UI/���UI.bmp"), 1200, 675, true, COLOR_M);
//	IMAGEMANAGER->AddFrameImage(TEXT("Count"), TEXT("Image/Fortress/Count.bmp"), 47, 470, 1, 10, true, RGB(255, 40, 255));
	IMAGEMANAGER->AddImage(TEXT("�Ͻ�����"), TEXT("Image/Pizza/UI/�Ͻ�����.bmp"), 1200, 675, true, COLOR_M);


	// ResultScene
	IMAGEMANAGER->AddImage(TEXT("���â"), TEXT("Image/Pizza/UI/���â.bmp"), 1200, 675, true, COLOR_M);

	// ShopScene
	IMAGEMANAGER->AddImage(TEXT("����"), TEXT("Image/Pizza/����/����.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("üũ"), TEXT("Image/Pizza/����/üũ.bmp"), 69, 55, true, COLOR_M);



// ���������� ���Ѱ�
	GAMEINFO->getSingleton();

	// �� �߰�
	SCENEMANAGER->AddScene(TEXT("Start"), new StartScene);
	SCENEMANAGER->AddScene(TEXT("InGame1"), new RestaurantScene);
	SCENEMANAGER->AddScene(TEXT("InGame2"), new CookingRoomScene);
	SCENEMANAGER->AddScene(TEXT("Result"), new ResultScene);
	SCENEMANAGER->AddScene(TEXT("Shop"), new ShopScene);


	// ù �� ����
	SCENEMANAGER->ChangeScene(TEXT("Start"));
//	SCENEMANAGER->ChangeScene(TEXT("Shop"));
//	SCENEMANAGER->ChangeScene(TEXT("Result"));
//	SCENEMANAGER->ChangeScene(TEXT("InGame2"));


	
	//===================================
	pauseImg = IMAGEMANAGER->findImage(TEXT("�Ͻ�����"));
	pauseBlindImg = IMAGEMANAGER->findImage(TEXT("��"));
	pauseButton = RectMake(1145, 0, 55, 55);
	resumeButton = RectMake(470, 358, 257, 82);
	isPause = false;


	return true;
}

void MainGame::Release() // ����
{
	GameNode::Release();
	//==================================
	
	//IMAGEMANAGER->Release();
	//SCENEMANAGER->Release();

	//==================================
}

void MainGame::Update() // ����
{
	GameNode::Update();
	//==================================
	GetCursorPos(&_ptMouse);
	ScreenToClient(_hWnd, &_ptMouse);
	if (PtInRect(&pauseButton, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			isPause = true;
		}
	}
	
	if (isPause == true)
	{
		if (PtInRect(&resumeButton, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				isPause = false;
			}
		}
	}

	if (isPause == false)
	{
	//	CursorCase(); // ���콺Ŀ���� Ŭ���̾�Ʈ ������ ���δ� �Լ�.
		SCENEMANAGER->Update();
	}

	//==================================

}

void MainGame::Render(HDC hdc) // �׸��� ( ȭ�� ��� ) // �������۾��� ����ۿ� �����Ӵ����� 1/10�ʸ��� �ѹ��� ȭ�鿡 �ѷ���
{
	//GameNode::Render(hdc);

	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============================
	// ����۾��� ���� �ȿ��� �۾�.

	SCENEMANAGER->Render(backDC);
	if (isPause == true)
	{
		pauseBlindImg->AlphaRender(backDC, 150);
		pauseImg->Render(backDC);
		//Rectangle(backDC, resumeButton.left, resumeButton.top, resumeButton.right, resumeButton.bottom);
	}

	//============================
	this->GetBackBuffer()->Render(hdc, 0, 0);	
}






// ========================================================================================================================
// ========================================================================================================================
// ========================================================================================================================


void MainGame::CursorCase()
{
	// Ŭ���̾�Ʈ ũ�⸦ ��������
	GetClientRect(_hWnd, &clientRect);

	// Ŭ���̾�Ʈ ��ǥ�� �̸������� pt1, pt2���� ����
	p1.x = clientRect.left;
	p1.y = clientRect.top - 20; // 20�� �۾�ǥ���ٱ��� ������ �� ��.
	p2.x = clientRect.right;
	p2.y = clientRect.bottom;

	// Ŭ���̾�Ʈ ũ�⸦ ��ũ�� ũ��� ��ȯ
	ClientToScreen(_hWnd, &p1);
	ClientToScreen(_hWnd, &p2);

	clientRect.left = p1.x;
	clientRect.top = p1.y;
	clientRect.right = p2.x;
	clientRect.bottom = p2.y;

	// �� ��ǥ�� �������� Ŀ���� ������Ŵ
	ClipCursor(&clientRect);
}
