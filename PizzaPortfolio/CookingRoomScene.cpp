#include "stdafx.h"
#include "CookingRoomScene.h"
#include "UI.h"
#include "Pizza.h"



//===================================================== �ٲﳻ�� 361 ����




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
	// �̹��� �ҷ�����
	backGround = IMAGEMANAGER->findImage(TEXT("�丮��"));
	ovenImg = IMAGEMANAGER->findImage(TEXT("����"));
	ovenRailImg = IMAGEMANAGER->findImage(TEXT("���췹��"));

	dough1.img = IMAGEMANAGER->findImage(TEXT("����1"));
	dough2.img = IMAGEMANAGER->findImage(TEXT("����2"));
	dough3.img = IMAGEMANAGER->findImage(TEXT("����3"));
	dough4.img = IMAGEMANAGER->findImage(TEXT("����4"));
	dough5.img = IMAGEMANAGER->findImage(TEXT("����5"));
	dough6.img = IMAGEMANAGER->findImage(TEXT("����6"));
	dough7.img = IMAGEMANAGER->findImage(TEXT("����7"));
	dough8.img = IMAGEMANAGER->findImage(TEXT("����8"));

	//
	sausageBox.img = IMAGEMANAGER->findImage(TEXT("�Ҽ����ڽ�"));
	mushroomBox.img = IMAGEMANAGER->findImage(TEXT("�����ڽ�"));
	oliveBox.img = IMAGEMANAGER->findImage(TEXT("�ø���ڽ�"));
	onionBox.img = IMAGEMANAGER->findImage(TEXT("���Ĺڽ�"));
	pimentBox.img = IMAGEMANAGER->findImage(TEXT("�Ǹ��ڽ�"));

	//
	orderCheckMiniRect = RectMake(330, 0, 54, 52);

	orderCheck.img = IMAGEMANAGER->findImage(TEXT("�ֹ�Ȯ��"));
	orderCheck.rect = RectMake(370, 65, 455, 250);
	orderCheck.isExist = false;
	blackBlendImg = IMAGEMANAGER->findImage(TEXT("��"));

	// Ŀ��Į
	cuttingKnife.isExist = false;
	cuttingKnife.img = IMAGEMANAGER->findImage(TEXT("Ŀ��Į"));
	cuttingKnifePosX = 2700;
	cuttingKnife.img->SetCenter(cuttingKnifePosX, 260);
	cuttingKnife.rect = RectMake(cuttingKnife.img->GetX(), cuttingKnife.img->GetY(), cuttingKnife.img->GetWidth(), cuttingKnife.img->GetHeight());
	cuttingPositionBoxX = 2470;
	cuttingPositionBoxY = 270;
	cuttingPositionBox = RectMake(cuttingPositionBoxX, cuttingPositionBoxY, 200, 200);
	cuttingPos = { cuttingKnife.rect.left + 38, cuttingKnife.rect.top + 35 };
	cuttingIndex = 0;

	// ���� ����
	doughStartPosX = 75;
	doughStartPosY = 280;

	// ���� �ڽ�
	toppingBoxStartPosX = 670;
	toppingBoxStartPosY = 60;
	
	// ����, ���ΰ��� ��Ʈ�� �� ���⼭ ó��
	RectSetting();


	isPizza = false;
	

	// ����
	railX = 1091;
	rcOvenRail = RectMake(railX, 165, ovenImg->GetWidth(), ovenImg->GetHeight());
	isRail = false;
	ovenRailStartX = railX;
	ovenRC = RectMake(railX + 400, 165, 400, 378);
	alphaIndex = 0;

	// ���� �ڽ��� ��ºκ�
	BoxIndex = 2600+361;
	pizzaBoxRC = RectMake(BoxIndex, 320, 80,50);


	// ī�޶�
	CameraInit();


	// �������̽�
	userInterface = GAMEINFO->getUI();	// ������ ���۵ɶ� MainGame���� ���۽�Ų GameInfo�� �������̽�(UI)�� new�� ���� ,,, �װ� �ҷ���
	
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
	// ī�޶�
	CameraMove();


	// �����̵�
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

	// ���� ���� �����̵�
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

	// ���� Ư���κ� �������� ���İ� ���� ( �������°� ���� ȿ���� ������ )
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

	// ���� �ڽ��� ��ºκ�
	pizzaBoxRC = RectMake(BoxIndex, 320, 80, 50);

	if (PtInRect(&pizzaBoxRC, pizza->GetpizzaCenter()))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			GAMEINFO->setIsPizza(true);

			// ������� ������� ���������� gameInfo���� �����س��� �ѱ���
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

	// ���츸���
	MakeDough();

	// ���� ����
	ToppingSetting();


	



	// �⺻ �������̽� â
	userInterface->Update();

	// �ֹ����� Ȯ��
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


	// Ŀ��
	PizzaCuttingUpdate();


	// �丮�ǿ��� �ð��� �������� happiness����
	HappinessDecrease();

	// DoughRC(���� ������ Ŭ���κ��� ������ ��) �����ϴºκ�
	RectSetting();

	// ���� ������Ʈ ( �̵��̶� ���οø��°� ���⼭ ó�� )
	pizza->Update(cuttingKnife.isExist);

	ANIMANAGER->Update();
}

void CookingRoomScene::Render(HDC hdc)
{
	// ���
	backGround->Render(hdc, 0, 0, CAMERA->getPosition()->x, CAMERA->getPosition()->y,
		WINSIZEX, WINSIZEY);

	// ���췹�� (���ں��� ������ ����)
	ovenRailImg->Render(hdc, railX, 165);

	// ����
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
	
	// ���� ���� ����
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
		

	// ���� (���ں��� ���߿� ����)
	ovenImg->Render(hdc, 0, 0, CAMERA->getPosition()->x, CAMERA->getPosition()->y,
		WINSIZEX, WINSIZEY);

	// Ŀ��Į
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


	// �������̽�
	userInterface->Render(hdc);


	// �ֹ�Ȯ��
	if (orderCheck.isExist == true)
	{
		blackBlendImg->AlphaRender(hdc, 150);
		orderCheck.img->Render(hdc);

		//
		HFONT hFont;
		HFONT OldFont;

		string str = GAMEINFO->GetOrderCheckString();

		SetBkMode(hdc, TRANSPARENT); // ���� ���� ���ֱ�
		SetTextColor(hdc, RGB(85, 49, 40)); // ���� ���� ���ϱ�

		hFont = CreateFont(35, 0, NULL, NULL, FW_HEAVY, 0, 0, 0, HANGUL_CHARSET, NULL, NULL, NULL, NULL, TEXT("����ü"));
		OldFont = (HFONT)SelectObject(hdc, hFont);

		DrawText(hdc, str.c_str(), str.size(), &orderCheck.rect, DT_WORDBREAK);

		SelectObject(hdc, OldFont);
		DeleteObject(hFont);
	}
}


//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================


bool CookingRoomScene::CameraInit() 	// ī�޶� ����
{
	// �̸� ������ ������ ���� �־�ΰ�
	rcClientSize = { 0,0,WINSIZEX,WINSIZEY }; 
	rcWorldSize = { 0,0,3160,675 };
	
	//GetCursorPos(&_ptMouse);
	//ClientToScreen(_hWnd, &_ptMouse);

	//pt = ptMouse;
	pt.x = WINSIZEX / 2;
	pt.y = WINSIZEY / 2;

	CAMERA->Init(&_ptMouse, rcClientSize, rcWorldSize);
	if (CAMERA->Init(&pt, rcClientSize, rcWorldSize) == false) // &pt���� ��ȭ�� ȭ���� ������ ����.
	{
		return false;
	}

	return true;
}

void CookingRoomScene::CameraMove()
{
	GetCursorPos(&_ptMouse);
	//ClientToScreen(_hWnd, &ptMouse);												// ToScreen�� ���� ����ͻ��� ��ǥ
	ScreenToClient(_hWnd, &_ptMouse); // ScreenToClient, ClientToScreen �Լ�����,,,	// ToClient�� ������ ��ü�ӿ� �����ϴ� ��ǥ,,
	
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
	// ��ġ ����
	cuttingKnife.rect = RectMake(cuttingKnife.img->GetX(), cuttingKnife.img->GetY(), cuttingKnife.img->GetWidth(), cuttingKnife.img->GetHeight());
	cuttingPositionBox = RectMake(cuttingPositionBoxX, cuttingPositionBoxY, 200, 200);
	cuttingPos = { cuttingKnife.rect.left + 38, cuttingKnife.rect.top + 35 };

	// Ŀ�� (�ڸ���) ����
	cuttingAngle = UTIL::getAngle(pizza->GetPizzaCenterX(), pizza->GetPizzaCenterY(), cuttingPos.x, cuttingPos.y);
	cuttingPosEnd.x = pizza->GetPizzaCenterX() + (cosf(cuttingAngle + PI) * PIZZA_SIZE / 2);
	cuttingPosEnd.y = pizza->GetPizzaCenterY() + (-sinf(cuttingAngle + PI) * PIZZA_SIZE / 2);

	cuttingPos.x = pizza->GetPizzaCenterX() + (cosf(cuttingAngle) * PIZZA_SIZE / 2);
	cuttingPos.y = pizza->GetPizzaCenterY() + (-sinf(cuttingAngle) * PIZZA_SIZE / 2);


	// Ŀ��Į ��ġ ������Ʈ
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
			// Ŀ��Į �巡���� ���콺 ���Ҷ�,, ��ġ������ ����Ŭ������ �Ѱܼ�,,, �߶����� ������ ������
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

	// ���ڼ��Ͱ� ��������ġ(���ڸ� Ŀ���Ұ�)������ ������,, �̸� ������ ��ġ�� ���� ����
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
	// 8�� ���츦 �� ����ϸ� ���̱��̸鼭 8���� ����
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

	// �� ���츦 Ŭ���ϸ� �ش� ���찡 �������鼭 ���ڰ� �������
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
	// �⺻���
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

	// ���� �߰����
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
