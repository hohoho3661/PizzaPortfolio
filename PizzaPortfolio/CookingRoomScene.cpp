#include "stdafx.h"
#include "CookingRoomScene.h"
#include "UI.h"
#include "Pizza.h"



//===================================================== 바뀐내부 361 차이




CookingRoomScene::CookingRoomScene()
{
	dough1.isExist = true;
	dough2.isExist = true;
	dough3.isExist = true;
	dough4.isExist = true;
	dough5.isExist = true;
	dough6.isExist = true;
	dough7.isExist = true;
	dough8.isExist = true;

	sausageBox.isExist = false;
	mushroomBox.isExist = false;
	oliveBox.isExist = false;
	onionBox.isExist = false;
	pimentBox.isExist = false;

}

CookingRoomScene::~CookingRoomScene()
{
}

bool CookingRoomScene::Init()
{	
	// 이미지 불러오기
	backGround = IMAGEMANAGER->findImage(TEXT("요리실"));
	ovenImg = IMAGEMANAGER->findImage(TEXT("오븐"));
	ovenRailImg = IMAGEMANAGER->findImage(TEXT("오븐레일"));

	dough1.img = IMAGEMANAGER->findImage(TEXT("도우1"));
	dough2.img = IMAGEMANAGER->findImage(TEXT("도우2"));
	dough3.img = IMAGEMANAGER->findImage(TEXT("도우3"));
	dough4.img = IMAGEMANAGER->findImage(TEXT("도우4"));
	dough5.img = IMAGEMANAGER->findImage(TEXT("도우5"));
	dough6.img = IMAGEMANAGER->findImage(TEXT("도우6"));
	dough7.img = IMAGEMANAGER->findImage(TEXT("도우7"));
	dough8.img = IMAGEMANAGER->findImage(TEXT("도우8"));

	//
	sausageBox.img = IMAGEMANAGER->findImage(TEXT("소세지박스"));
	mushroomBox.img = IMAGEMANAGER->findImage(TEXT("버섯박스"));
	oliveBox.img = IMAGEMANAGER->findImage(TEXT("올리브박스"));
	onionBox.img = IMAGEMANAGER->findImage(TEXT("양파박스"));
	pimentBox.img = IMAGEMANAGER->findImage(TEXT("피망박스"));

	//
	orderCheckMiniRect = RectMake(330, 0, 54, 52);

	orderCheck.img = IMAGEMANAGER->findImage(TEXT("주문확인"));
	orderCheck.rect = RectMake(370, 65, 455, 250);
	orderCheck.isExist = false;
	blackBlendImg = IMAGEMANAGER->findImage(TEXT("밤"));

	// 커팅칼
	cuttingKnife.isExist = false;
	cuttingKnife.img = IMAGEMANAGER->findImage(TEXT("커팅칼"));
	cuttingKnifePosX = 2700;
	cuttingKnife.img->SetCenter(cuttingKnifePosX, 260);
	cuttingKnife.rect = RectMake(cuttingKnife.img->GetX(), cuttingKnife.img->GetY(), cuttingKnife.img->GetWidth(), cuttingKnife.img->GetHeight());
	cuttingPositionBoxX = 2470;
	cuttingPositionBoxY = 270;
	cuttingPositionBox = RectMake(cuttingPositionBoxX, cuttingPositionBoxY, 200, 200);
	cuttingPos = { cuttingKnife.rect.left + 38, cuttingKnife.rect.top + 35 };
	cuttingIndex = 0;

	// 피자 도우
	doughStartPosX = 75;
	doughStartPosY = 280;

	// 토핑 박스
	toppingBoxStartPosX = 670;
	toppingBoxStartPosY = 60;
	
	// 피자, 토핑관련 렉트는 다 여기서 처리
	RectSetting();


	isPizza = false;
	

	// 레일
	railX = 1091;
	rcOvenRail = RectMake(railX, 165, ovenImg->GetWidth(), ovenImg->GetHeight());
	isRail = false;
	ovenRailStartX = railX;
	ovenRC = RectMake(railX + 400, 165, 400, 378);
	alphaIndex = 0;

	// 피자 박스에 담는부분
	BoxIndex = 2600+361;
	pizzaBoxRC = RectMake(BoxIndex, 320, 80,50);


	// 카메라
	CameraInit();


	// 인터페이스
	userInterface = GAMEINFO->getUI();	// 게임이 시작될때 MainGame에서 시작시킨 GameInfo에 인터페이스(UI)를 new로 만듬 ,,, 그걸 불러옴
	
	pizza = new Pizza;

	return true;
}

void CookingRoomScene::Release()
{
	//SAFE_DELETE(backGround);
	//SAFE_DELETE(userInterface);
}

void CookingRoomScene::Update()
{
	// 카메라
	CameraMove();


	// 레일이동
	if (ovenRailStartX <= 1111)
	{
		railX += 0.5f;
		ovenRailStartX += 0.5f;


		if (ovenRailStartX == 1111)
		{
			ovenRailStartX = 1091;
			railX = ovenRailStartX - CAMERA->getPosition()->x;
		}
	}

	rcOvenRail = RectMake(railX, 165, 1140, 378);
	ovenRC = RectMake(railX + 400, 165, 400, 378);

	// 레일 따라 피자이동
	if (PtInRect(&rcOvenRail, pizza->GetpizzaCenter()))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			isRail = true;
		}			
	}
	if (isRail == true)
	{
		pizza->SetPizzaCenterX(pizza->GetPizzaCenterX() + 1);

	}
	if (!PtInRect(&rcOvenRail, pizza->GetpizzaCenter()))
	{
		isRail = false;
	}

	// 레일 특정부분 지나갈때 알파값 적용 ( 구워지는거 같은 효과를 만들어보자 )
	if (PtInRect(&ovenRC, pizza->GetpizzaCenter()))
	{
		alphaIndex++;

		if (pizza->GetPizzaAlpha() < 50)
		{
			if (alphaIndex % 12 == 1)
			{
				pizza->SetPizzaAlpha(pizza->GetPizzaAlpha() + 1);
			}
		}
	}

	// 피자 박스에 담는부분
	pizzaBoxRC = RectMake(BoxIndex, 320, 80, 50);

	if (PtInRect(&pizzaBoxRC, pizza->GetpizzaCenter()))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			GAMEINFO->setIsPizza(true);

			// 여기까지 만들어진 피자정보를 gameInfo에서 저장해놓고 넘기자
			GAMEINFO->setIsSauce(pizza->getIsSauce());
			GAMEINFO->setIsCheese(pizza->getIsCheese());
			GAMEINFO->setIsPepperoni(pizza->getIsPepperoni());
			GAMEINFO->setIsSausage(pizza->getIsSausage());
			GAMEINFO->setIsMushroom(pizza->getIsMushroom());
			GAMEINFO->setIsOlive(pizza->getIsOlive());
			GAMEINFO->setIsOnion(pizza->getIsOnion());
			GAMEINFO->setIsPiment(pizza->getIsPiment());
			GAMEINFO->setSauceHaveAmount(pizza->getSauceHaveAmount());
			GAMEINFO->setCheeseHaveAmount(pizza->getCheeseHaveAmount());
			GAMEINFO->setPepperoniHaveAmount(pizza->getPepperoniHaveAmount());
			GAMEINFO->setSausageHaveAmount(pizza->getSausageHaveAmount());
			GAMEINFO->setMushroomHaveAmount(pizza->getMushroomHaveAmount());
			GAMEINFO->setOliveHaveAmount(pizza->getOliveHaveAmount());
			GAMEINFO->setOnionHaveAmount(pizza->getOnionHaveAmount());
			GAMEINFO->setPrimentHaveAmount(pizza->getPrimentHaveAmount());

			SCENEMANAGER->ChangeScene(TEXT("InGame1"));
		}
	}

	// 도우만들기
	MakeDough();

	// 토핑 세팅
	ToppingSetting();


	



	// 기본 인터페이스 창
	userInterface->Update();

	// 주문정보 확인
	if (PtInRect(&orderCheckMiniRect, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			orderCheck.isExist = true;
		}
	}
	if (orderCheck.isExist == true)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			orderCheck.isExist = false;
		}
	}


	// 커팅
	PizzaCuttingUpdate();


	// 요리실에서 시간이 지날수록 happiness감소
	HappinessDecrease();

	// DoughRC(각각 도우의 클릭부분을 지정한 곳) 세팅하는부분
	RectSetting();

	// 피자 업데이트 ( 이동이랑 토핑올리는걸 여기서 처리 )
	pizza->Update(cuttingKnife.isExist);

	ANIMANAGER->Update();
}

void CookingRoomScene::Render(HDC hdc)
{
	// 배경
	backGround->Render(hdc, 0, 0, CAMERA->getPosition()->x, CAMERA->getPosition()->y,
		WINSIZEX, WINSIZEY);

	// 오븐레일 (피자보다 이전에 랜더)
	ovenRailImg->Render(hdc, railX, 165);

	// 도우
	if (dough1.isExist)
		dough1.img->Render(hdc, dough1.rect.left, dough1.rect.top);
	if (dough2.isExist)
		dough2.img->Render(hdc, dough2.rect.left, dough2.rect.top);
	if (dough3.isExist)
		dough3.img->Render(hdc, dough3.rect.left, dough3.rect.top);
	if (dough4.isExist)
		dough4.img->Render(hdc, dough4.rect.left, dough4.rect.top);
	if (dough5.isExist)
		dough5.img->Render(hdc, dough5.rect.left, dough5.rect.top);
	if (dough6.isExist)
		dough6.img->Render(hdc, dough6.rect.left, dough6.rect.top);
	if (dough7.isExist)
		dough7.img->Render(hdc, dough7.rect.left, dough7.rect.top);
	if (dough8.isExist)
		dough8.img->Render(hdc, dough8.rect.left, dough8.rect.top);
	
	// 상점 구입 재료들
	if(sausageBox.isExist)
		sausageBox.img->Render(hdc, sausageBox.rect.left, sausageBox.rect.top);
	if (mushroomBox.isExist)
		mushroomBox.img->Render(hdc, mushroomBox.rect.left, mushroomBox.rect.top);
	if (oliveBox.isExist)
		oliveBox.img->Render(hdc, oliveBox.rect.left, oliveBox.rect.top);
	if (onionBox.isExist)
		onionBox.img->Render(hdc, onionBox.rect.left, onionBox.rect.top);
	if (pimentBox.isExist)
		pimentBox.img->Render(hdc, pimentBox.rect.left, pimentBox.rect.top);

	//Rectangle(hdc, pepperoniBox.left, pepperoniBox.top, pepperoniBox.right, pepperoniBox.bottom);
	//Rectangle(hdc, cheeseBox.left, cheeseBox.top, cheeseBox.right, cheeseBox.bottom);
	//Rectangle(hdc, sauceBox.left, sauceBox.top, sauceBox.right, sauceBox.bottom);

	if (isPizza == true)
	{
		pizza->Render(hdc);
	}
		

	// 오븐 (피자보다 나중에 렌더)
	ovenImg->Render(hdc, 0, 0, CAMERA->getPosition()->x, CAMERA->getPosition()->y,
		WINSIZEX, WINSIZEY);

	// 커팅칼
	//Rectangle(hdc, cuttingKnife.rect.left, cuttingKnife.rect.top, cuttingKnife.rect.right, cuttingKnife.rect.bottom);
	cuttingKnife.img->Render(hdc);

	//Rectangle(hdc, cuttingPositionBox.left, cuttingPositionBox.top, cuttingPositionBox.right, cuttingPositionBox.bottom);
	if (pizza->GetPizzaCenterX() == cuttingPositionBox.left + (cuttingPositionBox.right - cuttingPositionBox.left) / 2
		&& pizza->GetPizzaCenterY() == cuttingPositionBox.top + (cuttingPositionBox.bottom - cuttingPositionBox.top) / 2)
	{
		//lineMake(hdc, pizza->GetPizzaCenterX(), pizza->GetPizzaCenterY(), cuttingPos.x, cuttingPos.y);
		//lineMake(hdc, pizza->GetPizzaCenterX(), pizza->GetPizzaCenterY(), cuttingPosEnd.x, cuttingPosEnd.y);		

		lineMake(hdc, cuttingPos.x, cuttingPos.y, cuttingPosEnd.x, cuttingPosEnd.y, 1, RGB(255,255,255), PS_DASH);		

	}


	// 인터페이스
	userInterface->Render(hdc);


	// 주문확인
	if (orderCheck.isExist == true)
	{
		blackBlendImg->AlphaRender(hdc, 150);
		orderCheck.img->Render(hdc);

		//
		HFONT hFont;
		HFONT OldFont;

		string str = GAMEINFO->GetOrderCheckString();

		SetBkMode(hdc, TRANSPARENT); // 글자 배경색 없애기
		SetTextColor(hdc, RGB(85, 49, 40)); // 글자 색깔 정하기

		hFont = CreateFont(35, 0, NULL, NULL, FW_HEAVY, 0, 0, 0, HANGUL_CHARSET, NULL, NULL, NULL, NULL, TEXT("굴림체"));
		OldFont = (HFONT)SelectObject(hdc, hFont);

		DrawText(hdc, str.c_str(), str.size(), &orderCheck.rect, DT_WORDBREAK);

		SelectObject(hdc, OldFont);
		DeleteObject(hFont);
	}
}


//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================


bool CookingRoomScene::CameraInit() 	// 카메라 설정
{
	// 미리 선언한 변수에 값을 넣어두고
	rcClientSize = { 0,0,WINSIZEX,WINSIZEY }; 
	rcWorldSize = { 0,0,3160,675 };
	
	//GetCursorPos(&_ptMouse);
	//ClientToScreen(_hWnd, &_ptMouse);

	//pt = ptMouse;
	pt.x = WINSIZEX / 2;
	pt.y = WINSIZEY / 2;

	CAMERA->Init(&_ptMouse, rcClientSize, rcWorldSize);
	if (CAMERA->Init(&pt, rcClientSize, rcWorldSize) == false) // &pt값의 변화로 화면을 조정할 예정.
	{
		return false;
	}

	return true;
}

void CookingRoomScene::CameraMove()
{
	GetCursorPos(&_ptMouse);
	//ClientToScreen(_hWnd, &ptMouse);												// ToScreen은 실제 모니터상의 좌표
	ScreenToClient(_hWnd, &_ptMouse); // ScreenToClient, ClientToScreen 함수차이,,,	// ToClient는 윈도우 객체속에 존재하는 좌표,,
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !(pt.x < WINSIZEX/2 +CAMERA_SPEED))
	{
		CAMERA->setTargetPos(&pt);
		pt.x -= CAMERA_SPEED;

		pizza->SetPizzaCenterX(pizza->GetPizzaCenterX() + CAMERA_SPEED);
		railX += CAMERA_SPEED;
		BoxIndex += CAMERA_SPEED;
		doughStartPosX += CAMERA_SPEED;
		toppingBoxStartPosX += CAMERA_SPEED;
		cuttingKnifePosX += CAMERA_SPEED;
		cuttingPositionBoxX += CAMERA_SPEED;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !(pt.x > 3160 - (WINSIZEX / 2)))
	{
		CAMERA->setTargetPos(&pt);
		pt.x += CAMERA_SPEED;

		pizza->SetPizzaCenterX(pizza->GetPizzaCenterX() - CAMERA_SPEED);
		railX -= CAMERA_SPEED;
		BoxIndex -= CAMERA_SPEED;
		doughStartPosX -= CAMERA_SPEED;
		toppingBoxStartPosX -= CAMERA_SPEED;
		cuttingKnifePosX -= CAMERA_SPEED;
		cuttingPositionBoxX -= CAMERA_SPEED;
	}
	
	CAMERA->Update();
}

void CookingRoomScene::PizzaCuttingUpdate()
{
	// 위치 설정
	cuttingKnife.rect = RectMake(cuttingKnife.img->GetX(), cuttingKnife.img->GetY(), cuttingKnife.img->GetWidth(), cuttingKnife.img->GetHeight());
	cuttingPositionBox = RectMake(cuttingPositionBoxX, cuttingPositionBoxY, 200, 200);
	cuttingPos = { cuttingKnife.rect.left + 38, cuttingKnife.rect.top + 35 };

	// 커팅 (자를선) 설정
	cuttingAngle = UTIL::getAngle(pizza->GetPizzaCenterX(), pizza->GetPizzaCenterY(), cuttingPos.x, cuttingPos.y);
	cuttingPosEnd.x = pizza->GetPizzaCenterX() + (cosf(cuttingAngle + PI) * PIZZA_SIZE / 2);
	cuttingPosEnd.y = pizza->GetPizzaCenterY() + (-sinf(cuttingAngle + PI) * PIZZA_SIZE / 2);

	cuttingPos.x = pizza->GetPizzaCenterX() + (cosf(cuttingAngle) * PIZZA_SIZE / 2);
	cuttingPos.y = pizza->GetPizzaCenterY() + (-sinf(cuttingAngle) * PIZZA_SIZE / 2);


	// 커팅칼 위치 업데이트
	if (cuttingKnife.isExist == false)
	{
		cuttingKnife.img->SetCenter(cuttingKnifePosX, 260);
	}
	if (PtInRect(&cuttingKnife.rect, _ptMouse))
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			cuttingKnife.isExist = true;
			cuttingKnife.img->SetCenter(_ptMouse.x, _ptMouse.y);
		}
	}
	if (cuttingKnife.isExist == true)
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			// 커팅칼 드래그후 마우스 업할때,, 위치정보를 피자클래스로 넘겨서,,, 잘라지는 부위를 정해줌
			cuttingKnife.isExist = false;

			switch (cuttingIndex)
			{
			case 0:
				pizza->setCuttingStartPos(cuttingPos);
				pizza->setCuttingEndPos(cuttingPosEnd);
				break;
			case 1:
				pizza->setCuttingStartPos1(cuttingPos);
				pizza->setCuttingEndPos1(cuttingPosEnd);
				break;
			case 2:
				pizza->setCuttingStartPos2(cuttingPos);
				pizza->setCuttingEndPos2(cuttingPosEnd);
				break;
			case 3:
				pizza->setCuttingStartPos3(cuttingPos);
				pizza->setCuttingEndPos3(cuttingPosEnd);
				break;
			case 4:
				pizza->setCuttingStartPos4(cuttingPos);
				pizza->setCuttingEndPos4(cuttingPosEnd);
				break;
			}


			cuttingIndex++;
		}
	}

	// 피자센터가 정해진위치(피자를 커팅할곳)안으로 들어오면,, 미리 지정한 위치로 센터 설정
	if (PtInRect(&cuttingPositionBox, PointMake(pizza->GetPizzaCenterX(), pizza->GetPizzaCenterY())))
	{
		pizza->SetPizzaCenterX(cuttingPositionBox.left + (cuttingPositionBox.right - cuttingPositionBox.left) / 2);
		pizza->SetPizzaCenterY(cuttingPositionBox.top + (cuttingPositionBox.bottom - cuttingPositionBox.top) / 2);
	}
}

void CookingRoomScene::HappinessDecrease()
{
	happinessIndex++;
	if (happinessIndex % 150 == 149)
	{
		userInterface->SetHappiness(userInterface->GetHappiness() - 1);
	}
}

void CookingRoomScene::RectSetting()
{
	dough1.rect = RectMake(doughStartPosX, doughStartPosY, dough1.img->GetWidth(), dough1.img->GetHeight());
	dough2.rect = RectMake(doughStartPosX + dough1.img->GetWidth(), doughStartPosY, dough1.img->GetWidth(), dough1.img->GetHeight());
	dough3.rect = RectMake(doughStartPosX, doughStartPosY + dough1.img->GetHeight(), dough1.img->GetWidth(), dough1.img->GetHeight());
	dough4.rect = RectMake(doughStartPosX + dough1.img->GetWidth(), doughStartPosY + dough1.img->GetHeight(), dough1.img->GetWidth(), dough1.img->GetHeight());
	dough5.rect = RectMake(doughStartPosX, doughStartPosY + dough1.img->GetHeight() * 2, dough1.img->GetWidth(), dough1.img->GetHeight());
	dough6.rect = RectMake(doughStartPosX + dough1.img->GetWidth(), doughStartPosY + dough1.img->GetHeight() * 2, dough1.img->GetWidth(), dough1.img->GetHeight());
	dough7.rect = RectMake(doughStartPosX, doughStartPosY + dough1.img->GetHeight() * 3, dough1.img->GetWidth(), dough1.img->GetHeight());
	dough8.rect = RectMake(doughStartPosX + dough1.img->GetWidth(), doughStartPosY + dough1.img->GetHeight() * 3, dough1.img->GetWidth(), dough1.img->GetHeight());

	sausageBox.rect = RectMake(toppingBoxStartPosX, toppingBoxStartPosY, sausageBox.img->GetWidth(), sausageBox.img->GetHeight());
	mushroomBox.rect = RectMake(toppingBoxStartPosX, toppingBoxStartPosY + sausageBox.img->GetHeight(), mushroomBox.img->GetWidth(), mushroomBox.img->GetHeight());
	oliveBox.rect = RectMake(toppingBoxStartPosX + sausageBox.img->GetWidth(), toppingBoxStartPosY, oliveBox.img->GetWidth(), oliveBox.img->GetHeight());
	onionBox.rect = RectMake(toppingBoxStartPosX + sausageBox.img->GetWidth(), toppingBoxStartPosY + oliveBox.img->GetHeight(), onionBox.img->GetWidth(), onionBox.img->GetHeight());
	pimentBox.rect = RectMake(toppingBoxStartPosX + sausageBox.img->GetWidth(), toppingBoxStartPosY + oliveBox.img->GetHeight()*2, pimentBox.img->GetWidth(), pimentBox.img->GetHeight());


	sauceBox = RectMake(toppingBoxStartPosX - (sausageBox.img->GetWidth() * 3 + 70), toppingBoxStartPosY, sausageBox.img->GetWidth() + 60, sausageBox.img->GetHeight());
	cheeseBox = RectMake(toppingBoxStartPosX - (sausageBox.img->GetWidth()*2 + 5), toppingBoxStartPosY, sausageBox.img->GetWidth(), sausageBox.img->GetHeight());
	pepperoniBox = RectMake(toppingBoxStartPosX - sausageBox.img->GetWidth(), toppingBoxStartPosY, sausageBox.img->GetWidth(), sausageBox.img->GetHeight());
}

void CookingRoomScene::MakeDough()
{
	// 8개 도우를 다 사용하면 돈이깍이면서 8개가 리필
	if (dough1.isExist == false
		&& dough2.isExist == false
		&& dough3.isExist == false
		&& dough4.isExist == false
		&& dough5.isExist == false
		&& dough6.isExist == false
		&& dough7.isExist == false
		&& dough8.isExist == false)
	{
		userInterface->SetMoney(userInterface->GetMoney() - DOUGH_COST);
		GAMEINFO->setToppingCost(GAMEINFO->getToppingCost() + DOUGH_COST);
		dough1.isExist = true;
		dough2.isExist = true;
		dough3.isExist = true;
		dough4.isExist = true;
		dough5.isExist = true;
		dough6.isExist = true;
		dough7.isExist = true;
		dough8.isExist = true;
	}

	// 각 도우를 클릭하면 해당 도우가 없어지면서 피자가 만들어짐
	if (PtInRect(&dough1.rect, _ptMouse) && !isPizza)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->Init();
			pizza->MakePizza();
			isPizza = true;
			dough1.isExist = false;
		}
	}
	if (PtInRect(&dough2.rect, _ptMouse) && !isPizza)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->Init();
			pizza->MakePizza();
			isPizza = true;
			dough2.isExist = false;
		}
	}
	if (PtInRect(&dough3.rect, _ptMouse) && !isPizza)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->Init();
			pizza->MakePizza();
			isPizza = true;
			dough3.isExist = false;
		}
	}
	if (PtInRect(&dough4.rect, _ptMouse) && !isPizza)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->Init();
			pizza->MakePizza();
			isPizza = true;
			dough4.isExist = false;
		}
	}
	if (PtInRect(&dough5.rect, _ptMouse) && !isPizza)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->Init();
			pizza->MakePizza();
			isPizza = true;
			dough5.isExist = false;
		}
	}
	if (PtInRect(&dough6.rect, _ptMouse) && !isPizza)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->Init();
			pizza->MakePizza();
			isPizza = true;
			dough6.isExist = false;
		}
	}
	if (PtInRect(&dough7.rect, _ptMouse) && !isPizza)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->Init();
			pizza->MakePizza();
			isPizza = true;
			dough7.isExist = false;
		}
	}
	if (PtInRect(&dough8.rect, _ptMouse) && !isPizza)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->Init();
			pizza->MakePizza();
			isPizza = true;
			dough8.isExist = false;
		}
	}
}

void CookingRoomScene::ToppingSetting()
{
	// 기본재료
	if (PtInRect(&sauceBox, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->SetTopping(Sauce);
		}
	}
	if (PtInRect(&cheeseBox, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->SetTopping(Cheese);
		}
	}
	if (PtInRect(&pepperoniBox, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->SetTopping(Pepperoni);
		}
	}

	sausageBox.isExist = GAMEINFO->GetIsSausageBuy();
	mushroomBox.isExist = GAMEINFO->GetIsMushroomBuy();
	oliveBox.isExist = GAMEINFO->GetIsOliveBuy();
	onionBox.isExist = GAMEINFO->GetIsOnionBuy();
	pimentBox.isExist = GAMEINFO->GetIsPimentBuy();

	// 상점 추가재료
	if (PtInRect(&sausageBox.rect, _ptMouse) && sausageBox.isExist)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->SetTopping(Sausage);
		}
	}
	if (PtInRect(&mushroomBox.rect, _ptMouse) && mushroomBox.isExist)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->SetTopping(Mushroom);
		}
	}
	if (PtInRect(&oliveBox.rect, _ptMouse) && oliveBox.isExist)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->SetTopping(Olive);
		}
	}
	if (PtInRect(&onionBox.rect, _ptMouse) && onionBox.isExist)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->SetTopping(Onion);
		}
	}
	if (PtInRect(&pimentBox.rect, _ptMouse) && pimentBox.isExist)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			pizza->SetTopping(Piment);
		}
	}
}
