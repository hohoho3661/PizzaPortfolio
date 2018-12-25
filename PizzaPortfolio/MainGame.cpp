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

bool MainGame::Init() // 초기화
{
	GameNode::Init(true);
	
	//===================================

	// 여기서 이미지 메니저를 초기화 하자.
	IMAGEMANAGER->Init();

	// 씬매니저를 초기화 하고 ... Scene을 추가
	SCENEMANAGER->Init();


	// StartScene
	IMAGEMANAGER->AddImage(TEXT("StartImage"), TEXT("Image/Pizza/시작화면.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("StartButton"), TEXT("Image/Pizza/시작버튼.bmp"),0,0, 231, 222, 1, 2, true, COLOR_M);

	// InGame
	IMAGEMANAGER->AddImage(TEXT("레스토랑"), TEXT("Image/Pizza/피자가게/피자가게.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("레스토랑외부"), TEXT("Image/Pizza/피자가게/피자가게밖.bmp"), 1200, 675, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("카운터"), TEXT("Image/Pizza/피자가게/카운터.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("피자박스"), TEXT("Image/Pizza/피자가게/피자박스.bmp"), 287, 122, true, COLOR_M);


	IMAGEMANAGER->AddImage(TEXT("아침"), TEXT("Image/Pizza/피자가게/아침.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("밤"), TEXT("Image/Pizza/피자가게/밤.bmp"), 1200, 675, true, COLOR_M);

	// Guest
	IMAGEMANAGER->AddImage(TEXT("손님1"), TEXT("Image/Pizza/손님/손님1.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("손님2"), TEXT("Image/Pizza/손님/손님2.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("손님3"), TEXT("Image/Pizza/손님/손님3.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("손님4"), TEXT("Image/Pizza/손님/손님4.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("손님5"), TEXT("Image/Pizza/손님/손님5.bmp"), 1200, 675, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("말풍선"), TEXT("Image/Pizza/손님/말풍선버튼.bmp"), 1200, 675, true, COLOR_M);


	// CookingRoom
	IMAGEMANAGER->AddImage(TEXT("요리실"), TEXT("Image/Pizza/요리실/요리실내부.bmp"), 3160, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("오븐"), TEXT("Image/Pizza/요리실/오븐뚜껑.bmp"), 3160, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("오븐레일"), TEXT("Image/Pizza/요리실/오븐레일.bmp"), 1140, 378, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("주문확인"), TEXT("Image/Pizza/요리실/주문확인.bmp"), 1200, 675, true, COLOR_M);
	
	IMAGEMANAGER->AddImage(TEXT("커팅칼"), TEXT("Image/Pizza/요리실/커팅칼.bmp"), 160, 109, true, COLOR_M);



	IMAGEMANAGER->AddImage(TEXT("소세지박스"), TEXT("Image/Pizza/요리실/재료박스/소세지박스.bmp"), 182, 174, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("버섯박스"), TEXT("Image/Pizza/요리실/재료박스/버섯박스.bmp"), 182, 174, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("올리브박스"), TEXT("Image/Pizza/요리실/재료박스/올리브박스.bmp"), 182, 174, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("양파박스"), TEXT("Image/Pizza/요리실/재료박스/양파박스.bmp"), 182, 174, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("피망박스"), TEXT("Image/Pizza/요리실/재료박스/피망박스.bmp"), 182, 174, true, COLOR_M);




	//재료
	IMAGEMANAGER->AddFrameImage(TEXT("도우"), TEXT("Image/Pizza/재료/도우.bmp"), 2415, 330, 7, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("소스"), TEXT("Image/Pizza/재료/소스.bmp"), 320, 80, 4, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("치즈"), TEXT("Image/Pizza/재료/치즈.bmp"), 320, 80, 4, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("페퍼로니"), TEXT("Image/Pizza/재료/페퍼로니.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("소세지"), TEXT("Image/Pizza/재료/소세지.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("버섯"), TEXT("Image/Pizza/재료/버섯.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("올리브"), TEXT("Image/Pizza/재료/올리브.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("양파"), TEXT("Image/Pizza/재료/양파.bmp"), 450, 50, 9, 1, true, COLOR_M);
	IMAGEMANAGER->AddFrameImage(TEXT("피망"), TEXT("Image/Pizza/재료/피망.bmp"), 450, 50, 9, 1, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("도우1"), TEXT("Image/Pizza/재료/피자도우/도우1.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("도우2"), TEXT("Image/Pizza/재료/피자도우/도우2.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("도우3"), TEXT("Image/Pizza/재료/피자도우/도우3.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("도우4"), TEXT("Image/Pizza/재료/피자도우/도우4.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("도우5"), TEXT("Image/Pizza/재료/피자도우/도우5.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("도우6"), TEXT("Image/Pizza/재료/피자도우/도우6.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("도우7"), TEXT("Image/Pizza/재료/피자도우/도우7.bmp"), 97, 66, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("도우8"), TEXT("Image/Pizza/재료/피자도우/도우8.bmp"), 97, 66, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("Bake"), TEXT("Image/Pizza/재료/피자도우/Bake.bmp"), 280, 280, true, COLOR_M);




	

	ANIMANAGER->AddCoordAni(TEXT("도우애니메이션"), TEXT("도우"), 0, 7, 10, false);
	
	// UI
	IMAGEMANAGER->AddImage(TEXT("UI"), TEXT("Image/Pizza/UI/상단UI.bmp"), 1200, 675, true, COLOR_M);
//	IMAGEMANAGER->AddFrameImage(TEXT("Count"), TEXT("Image/Fortress/Count.bmp"), 47, 470, 1, 10, true, RGB(255, 40, 255));
	IMAGEMANAGER->AddImage(TEXT("일시정지"), TEXT("Image/Pizza/UI/일시정지.bmp"), 1200, 675, true, COLOR_M);


	// ResultScene
	IMAGEMANAGER->AddImage(TEXT("결과창"), TEXT("Image/Pizza/UI/결과창.bmp"), 1200, 675, true, COLOR_M);

	// ShopScene
	IMAGEMANAGER->AddImage(TEXT("상점"), TEXT("Image/Pizza/상점/상점.bmp"), 1200, 675, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("체크"), TEXT("Image/Pizza/상점/체크.bmp"), 69, 55, true, COLOR_M);



// 게임정보에 대한것
	GAMEINFO->getSingleton();

	// 씬 추가
	SCENEMANAGER->AddScene(TEXT("Start"), new StartScene);
	SCENEMANAGER->AddScene(TEXT("InGame1"), new RestaurantScene);
	SCENEMANAGER->AddScene(TEXT("InGame2"), new CookingRoomScene);
	SCENEMANAGER->AddScene(TEXT("Result"), new ResultScene);
	SCENEMANAGER->AddScene(TEXT("Shop"), new ShopScene);


	// 첫 씬 설정
	SCENEMANAGER->ChangeScene(TEXT("Start"));
//	SCENEMANAGER->ChangeScene(TEXT("Shop"));
//	SCENEMANAGER->ChangeScene(TEXT("Result"));
//	SCENEMANAGER->ChangeScene(TEXT("InGame2"));


	
	//===================================
	pauseImg = IMAGEMANAGER->findImage(TEXT("일시정지"));
	pauseBlindImg = IMAGEMANAGER->findImage(TEXT("밤"));
	pauseButton = RectMake(1145, 0, 55, 55);
	resumeButton = RectMake(470, 358, 257, 82);
	isPause = false;


	return true;
}

void MainGame::Release() // 해제
{
	GameNode::Release();
	//==================================
	
	//IMAGEMANAGER->Release();
	//SCENEMANAGER->Release();

	//==================================
}

void MainGame::Update() // 변동
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
	//	CursorCase(); // 마우스커서를 클라이언트 영역에 가두는 함수.
		SCENEMANAGER->Update();
	}

	//==================================

}

void MainGame::Render(HDC hdc) // 그리기 ( 화면 출력 ) // 랜더링작업을 백버퍼에 프래임단위로 1/10초마다 한번씩 화면에 뿌려줌
{
	//GameNode::Render(hdc);

	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============================
	// 모든작업은 여기 안에서 작업.

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
	// 클라이언트 크기를 가져오고
	GetClientRect(_hWnd, &clientRect);

	// 클라이언트 좌표를 미리만들어둔 pt1, pt2값에 저장
	p1.x = clientRect.left;
	p1.y = clientRect.top - 20; // 20은 작업표시줄까지 여유를 둔 값.
	p2.x = clientRect.right;
	p2.y = clientRect.bottom;

	// 클라이언트 크기를 스크린 크기로 변환
	ClientToScreen(_hWnd, &p1);
	ClientToScreen(_hWnd, &p2);

	clientRect.left = p1.x;
	clientRect.top = p1.y;
	clientRect.right = p2.x;
	clientRect.bottom = p2.y;

	// 그 좌표를 기준으로 커서를 고정시킴
	ClipCursor(&clientRect);
}
