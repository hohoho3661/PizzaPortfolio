#include "stdafx.h"
#include "Pizza.h"

#include "UI.h"



Pizza::Pizza()
{
	pizzaImg = IMAGEMANAGER->findImage(TEXT("도우"));
	pizzaAni = ANIMANAGER->FindAni(TEXT("도우애니메이션"));

	bakeImg = IMAGEMANAGER->findImage(TEXT("Bake"));

	SauceImg = IMAGEMANAGER->findImage(TEXT("소스"));
	CheeseImg = IMAGEMANAGER->findImage(TEXT("치즈"));
	PepperoniImg = IMAGEMANAGER->findImage(TEXT("페퍼로니"));
	SausageImg = IMAGEMANAGER->findImage(TEXT("소세지"));
	MushroomImg = IMAGEMANAGER->findImage(TEXT("버섯"));
	OliveImg = IMAGEMANAGER->findImage(TEXT("올리브"));
	OnionImg = IMAGEMANAGER->findImage(TEXT("양파"));
	PimentImg = IMAGEMANAGER->findImage(TEXT("피망"));

	isSauce = false;
	isCheese = false;
	isPepperoni = false;
	isSausage = false;
	isMushroom = false;
	isOlive = false;
	isOnion = false;
	isPiment = false;

	sauceHaveAmount = 0;
	cheeseHaveAmount = 0;
	pepperoniHaveAmount = 0;
	sausageHaveAmount = 0;
	mushroomHaveAmount = 0;
	oliveHaveAmount = 0;
	onionHaveAmount = 0;
	primentHaveAmount = 0;

	userInterface = GAMEINFO->getUI();


}


Pizza::~Pizza()
{
}

bool Pizza::Init()
{
	pizzaCenter.x = STARTPIZZAPOSITIONX;
	pizzaCenter.y = STARTPIZZAPOSITIONY;

	pizzaRC = RectMakeCenter(pizzaCenter.x, pizzaCenter.y, PIZZA_SIZE, PIZZA_SIZE);
	bakeImg->SetCenter(pizzaCenter.x, pizzaCenter.y);
	
	isPizzaMove = false;

	// 토핑
	topping = NONE;

	
	pizzaAlpha = 0;



	//// 커팅
	//cuttingStartPos.x = pizzaCenter.x + (cosf(5) * PIZZA_SIZE / 2);
	//cuttingStartPos.y = pizzaCenter.y + (-sinf(5) * PIZZA_SIZE / 2);
	//cuttingEndPos.x = pizzaCenter.x + (cosf(5 + PI) * PIZZA_SIZE / 2);
	//cuttingEndPos.y = pizzaCenter.y + (-sinf(5 + PI) * PIZZA_SIZE / 2);


	return true;
}

void Pizza::Update(bool _cuttingState)
{
	cuttingState = _cuttingState;

	GetCursorPos(&_ptMouse);
	ScreenToClient(_hWnd, &_ptMouse);
		

//	pizzaCenter.x -= CAMERA->getPosition()->x;
//	pizzaCenter.y -= CAMERA->getPosition()->y;
	pizzaRC = RectMakeCenter(pizzaCenter.x, pizzaCenter.y, PIZZA_SIZE, PIZZA_SIZE);
	bakeImg->SetCenter(pizzaCenter.x, pizzaCenter.y);


	// 토핑
	ToppingUpdate();

	//// 커팅
	//cuttingStartPos.x = pizzaCenter.x + (cosf(5) * PIZZA_SIZE);
	//cuttingStartPos.y = pizzaCenter.y + (-sinf(7) * PIZZA_SIZE);
	//cuttingEndPos.x = pizzaCenter.x + (cosf(5 + PI) * PIZZA_SIZE);
	//cuttingEndPos.y = pizzaCenter.y + (-sinf(7+PI) * PIZZA_SIZE);

}

void Pizza::Render(HDC hdc)
{
	//EllipseMakeCenter(hdc, pizzaCenter.x, pizzaCenter.y, PIZZA_SIZE, PIZZA_SIZE);
	//DrawObject(hdc, pizzaRC, 1, RGB(102, 51, 51), ELLIPSE);

	pizzaImg->AniRenderCenter(hdc, pizzaCenter.x, pizzaCenter.y , pizzaAni);

	ToppingRender(hdc);

	bakeImg->AlphaRender(hdc, pizzaAlpha);

	
	// 커팅
	//lineMake(hdc, cuttingStartPos.x, cuttingStartPos.y, cuttingEndPos.x, cuttingEndPos.y);
	for (int i = 0; i < 5; i++)
	{
		lineMake(hdc, pizzaCenter.x + cuttingStartPos[i].x - 600,
			pizzaCenter.y + cuttingStartPos[i].y - 370,
			pizzaCenter.x + cuttingEndPos[i].x - 600,
			pizzaCenter.y + cuttingEndPos[i].y - 370,
			2, RGB(165,42,42),PS_SOLID); 
	}
}





//===========================================================================================================================






void Pizza::MakePizza()
{
	pizzaAni->start();
}


void Pizza::ToppingUpdate() // 토핑올리는 작업을 넣어보자
{
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		topping = NONE;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&pizzaRC, _ptMouse) && topping == NONE)
		{
			isPizzaMove = true;
		}
		if (CollisionCircleAndCircle(PIZZA_SIZE / 2 - 25, pizzaCenter.x, pizzaCenter.y,
			1, _ptMouse.x, _ptMouse.y) && topping == Pepperoni)
		{
			ToppingPosition(Pepperoni, _ptMouse.x, _ptMouse.y);
		}
		if (CollisionCircleAndCircle(PIZZA_SIZE / 2 - 25, pizzaCenter.x, pizzaCenter.y,
			1, _ptMouse.x, _ptMouse.y) && topping == Sausage)
		{
			ToppingPosition(Sausage, _ptMouse.x, _ptMouse.y);
		}
		if (CollisionCircleAndCircle(PIZZA_SIZE / 2 - 25, pizzaCenter.x, pizzaCenter.y,
			1, _ptMouse.x, _ptMouse.y) && topping == Mushroom)
		{
			ToppingPosition(Mushroom, _ptMouse.x, _ptMouse.y);
		}
		if (CollisionCircleAndCircle(PIZZA_SIZE / 2 - 25, pizzaCenter.x, pizzaCenter.y,
			1, _ptMouse.x, _ptMouse.y) && topping == Olive)
		{
			ToppingPosition(Olive, _ptMouse.x, _ptMouse.y);
		}
		if (CollisionCircleAndCircle(PIZZA_SIZE / 2 - 25, pizzaCenter.x, pizzaCenter.y,
			1, _ptMouse.x, _ptMouse.y) && topping == Onion)
		{
			ToppingPosition(Onion, _ptMouse.x, _ptMouse.y);
		}
		if (CollisionCircleAndCircle(PIZZA_SIZE / 2 - 25, pizzaCenter.x, pizzaCenter.y,
			1, _ptMouse.x, _ptMouse.y) && topping == Piment)
		{
			ToppingPosition(Piment, _ptMouse.x, _ptMouse.y);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		// 소스랑 치즈는 StayKeyDown으로
		if (CollisionCircleAndCircle(PIZZA_SIZE / 2 - 25, pizzaCenter.x, pizzaCenter.y,
			1, _ptMouse.x, _ptMouse.y) && topping == Sauce)
		{
			ToppingPosition(Sauce, _ptMouse.x, _ptMouse.y);
		}
		if (CollisionCircleAndCircle(PIZZA_SIZE / 2 - 25, pizzaCenter.x, pizzaCenter.y,
			1, _ptMouse.x, _ptMouse.y) && topping == Cheese)
		{
			ToppingPosition(Cheese, _ptMouse.x, _ptMouse.y);
		}

		// 피자를 (피자센터를 마우스위치로) 옴기는 부분
		if (PtInRect(&pizzaRC, _ptMouse) && topping == NONE && isPizzaMove == true && cuttingState == false)
		{
			pizzaCenter = _ptMouse;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		//	pizzaCenter = _ptMouse;
		isPizzaMove = false;
	}
}

void Pizza::ToppingPosition(Topping topping, float _x, float _y)
{
	switch (topping)
	{
	case Sauce:
		//SauceImg->SetX(pizzaCenter.x - (pizzaCenter.x - _x));
		//SauceImg->SetY(pizzaCenter.y - (pizzaCenter.y - _y));
		Saucelist.push_back(PointMake(_x, _y));
		isSauce = true;
		sauceHaveAmount++;
		userInterface->SetMoney(userInterface->GetMoney() - SAUCE_COST);
		GAMEINFO->setToppingCost(GAMEINFO->getToppingCost() + SAUCE_COST);
		break;
	case Cheese:
		//CheeseImg->SetX(pizzaCenter.x - (pizzaCenter.x - _x));
		//CheeseImg->SetY(pizzaCenter.y - (pizzaCenter.y - _y));
		Cheeselist.push_back(PointMake(_x, _y));
		isCheese = true;
		cheeseHaveAmount++;
		userInterface->SetMoney(userInterface->GetMoney() - CHEESE_COST);
		GAMEINFO->setToppingCost(GAMEINFO->getToppingCost() + CHEESE_COST);
		break;
	case Pepperoni:
		//PepperoniImg->SetX(pizzaCenter.x - (pizzaCenter.x - _x));
		//PepperoniImg->SetY(pizzaCenter.y - (pizzaCenter.y - _y));
		Pepperonilist.push_back(PointMake(_x, _y));
		isPepperoni = true;
		pepperoniHaveAmount++;
		userInterface->SetMoney(userInterface->GetMoney() - PEPPERONI_COST);
		GAMEINFO->setToppingCost(GAMEINFO->getToppingCost() + PEPPERONI_COST);
		break;
	case Sausage:
		//SausageImg->SetX(pizzaCenter.x - (pizzaCenter.x - _x));
		//SausageImg->SetY(pizzaCenter.y - (pizzaCenter.y - _y));
		Sausagelist.push_back(PointMake(_x, _y));
		isSausage = true;
		sausageHaveAmount++;
		userInterface->SetMoney(userInterface->GetMoney() - SAUSAGE_COST);
		GAMEINFO->setToppingCost(GAMEINFO->getToppingCost() + SAUSAGE_COST);
		break;
	case Mushroom:
		//MushroomImg->SetX(pizzaCenter.x - (pizzaCenter.x - _x));
		//MushroomImg->SetY(pizzaCenter.y - (pizzaCenter.y - _y));
		Mushroomlist.push_back(PointMake(_x, _y));
		isMushroom = true;
		mushroomHaveAmount++;
		userInterface->SetMoney(userInterface->GetMoney() - MUSHROOM_COST);
		GAMEINFO->setToppingCost(GAMEINFO->getToppingCost() + MUSHROOM_COST);
		break;
	case Olive:
		//OliveImg->SetX(pizzaCenter.x - (pizzaCenter.x - _x));
		//OliveImg->SetY(pizzaCenter.y - (pizzaCenter.y - _y));
		Olivelist.push_back(PointMake(_x, _y));
		isOlive = true;
		oliveHaveAmount++;
		userInterface->SetMoney(userInterface->GetMoney() - OLIVE_COST);
		GAMEINFO->setToppingCost(GAMEINFO->getToppingCost() + OLIVE_COST);
		break;
	case Onion:
		//OnionImg->SetX(pizzaCenter.x - (pizzaCenter.x - _x));
		//OnionImg->SetY(pizzaCenter.y - (pizzaCenter.y - _y));
		Onionlist.push_back(PointMake(_x, _y));
		isOnion = true;
		onionHaveAmount++;
		userInterface->SetMoney(userInterface->GetMoney() - ONION_COST);
		GAMEINFO->setToppingCost(GAMEINFO->getToppingCost() + ONION_COST);
		break;
	case Piment:
		//PimentImg->SetX(pizzaCenter.x - (pizzaCenter.x - _x));
		//PimentImg->SetY(pizzaCenter.y - (pizzaCenter.y - _y));
		Pimentlist.push_back(PointMake(_x, _y));
		isPiment = true;
		primentHaveAmount++;
		userInterface->SetMoney(userInterface->GetMoney() - PIMENT_COST);
		GAMEINFO->setToppingCost(GAMEINFO->getToppingCost() + PIMENT_COST);
		break;
	}

}

void Pizza::ToppingRender(HDC hdc)
{
	// 토핑 그리기 ( 피자센터를 기준으로 그림,,, 왜냐면 피자센터가 움직임에 따라 그려진 토핑도 따라서 이동하도록 )
	int sauceIndex = 1;
	int cheeseIndex = 1;
	int PepperoniIndex = 1;
	int SausageIndex = 1;
	int MushroomIndex = 1;
	int OliveIndex = 1;
	int OnionIndex = 1;
	int PimentIndex = 1;

	for (SauceIter = Saucelist.begin(); SauceIter != Saucelist.end(); SauceIter++, sauceIndex++)
	{
		SauceImg->FrameRenderCenterPoint(hdc, PointMake(pizzaCenter.x + (*SauceIter).x - STARTPIZZAPOSITIONX,
			pizzaCenter.y + (*SauceIter).y - STARTPIZZAPOSITIONY), sauceIndex % 4);
	}
	for (CheeseIter = Cheeselist.begin(); CheeseIter != Cheeselist.end(); CheeseIter++, cheeseIndex++)
	{
		CheeseImg->FrameRenderCenterPoint(hdc, PointMake(pizzaCenter.x + (*CheeseIter).x - STARTPIZZAPOSITIONX,
			pizzaCenter.y + (*CheeseIter).y - STARTPIZZAPOSITIONY), cheeseIndex % 4);
	}
	for (PepperoniIter = Pepperonilist.begin(); PepperoniIter != Pepperonilist.end(); PepperoniIter++, PepperoniIndex++)
	{
		PepperoniImg->FrameRenderCenterPoint(hdc, PointMake(pizzaCenter.x + (*PepperoniIter).x - STARTPIZZAPOSITIONX,
			pizzaCenter.y + (*PepperoniIter).y - STARTPIZZAPOSITIONY), PepperoniIndex % 9);
	}
	for (SausageIter = Sausagelist.begin(); SausageIter != Sausagelist.end(); SausageIter++, SausageIndex++)
	{
		SausageImg->FrameRenderCenterPoint(hdc, PointMake(pizzaCenter.x + (*SausageIter).x - STARTPIZZAPOSITIONX,
			pizzaCenter.y + (*SausageIter).y - STARTPIZZAPOSITIONY), SausageIndex % 9);
	}
	for (MushroomIter = Mushroomlist.begin(); MushroomIter != Mushroomlist.end(); MushroomIter++, MushroomIndex++)
	{
		MushroomImg->FrameRenderCenterPoint(hdc, PointMake(pizzaCenter.x + (*MushroomIter).x - STARTPIZZAPOSITIONX,
			pizzaCenter.y + (*MushroomIter).y - STARTPIZZAPOSITIONY), MushroomIndex % 9);
	}
	for (OliveIter = Olivelist.begin(); OliveIter != Olivelist.end(); OliveIter++, OliveIndex++)
	{
		OliveImg->FrameRenderCenterPoint(hdc, PointMake(pizzaCenter.x + (*OliveIter).x - STARTPIZZAPOSITIONX,
			pizzaCenter.y + (*OliveIter).y - STARTPIZZAPOSITIONY), OliveIndex % 9);
	}
	for (OnionIter = Onionlist.begin(); OnionIter != Onionlist.end(); OnionIter++, OnionIndex++)
	{
		OnionImg->FrameRenderCenterPoint(hdc, PointMake(pizzaCenter.x + (*OnionIter).x - STARTPIZZAPOSITIONX,
			pizzaCenter.y + (*OnionIter).y - STARTPIZZAPOSITIONY), OnionIndex % 9);
	}
	for (PimentIter = Pimentlist.begin(); PimentIter != Pimentlist.end(); PimentIter++, PimentIndex++)
	{
		PimentImg->FrameRenderCenterPoint(hdc, PointMake(pizzaCenter.x + (*PimentIter).x - STARTPIZZAPOSITIONX,
			pizzaCenter.y + (*PimentIter).y - STARTPIZZAPOSITIONY), PimentIndex % 9);
	}
	

	// 마우스 포지션에 선택된 토핑이 표시되게	
	switch (topping)
	{
	case Sauce:
		SauceImg->FrameRenderCenterPoint(hdc, _ptMouse, sauceIndex % 4);
		break;
	case Cheese:
		CheeseImg->FrameRenderCenterPoint(hdc, _ptMouse, cheeseIndex % 4);
		break;
	case Pepperoni:
		PepperoniImg->FrameRenderCenterPoint(hdc, _ptMouse, PepperoniIndex % 9);
		break;
	case Sausage:
		SausageImg->FrameRenderCenterPoint(hdc, _ptMouse, SausageIndex % 9);
		break;
	case Mushroom:
		MushroomImg->FrameRenderCenterPoint(hdc, _ptMouse, MushroomIndex % 9);
		break;
	case Olive:
		OliveImg->FrameRenderCenterPoint(hdc, _ptMouse, OliveIndex % 9);
		break;
	case Onion:
		OnionImg->FrameRenderCenterPoint(hdc, _ptMouse, OnionIndex % 9);
		break;
	case Piment:
		PimentImg->FrameRenderCenterPoint(hdc, _ptMouse, PimentIndex % 9);
		break;
	}
}