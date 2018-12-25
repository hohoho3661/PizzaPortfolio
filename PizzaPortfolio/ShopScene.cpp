#include "stdafx.h"
#include "ShopScene.h"

#include "UI.h"


ShopScene::ShopScene()
{
	shopImg = IMAGEMANAGER->findImage(TEXT("상점"));

	checkImg = IMAGEMANAGER->findImage(TEXT("체크"));
	
	
	dailyStatisticsButton = RectMake(33, 595, 230, 70);
	nextDayButton = RectMake(935, 595, 230, 70);

	sausageBuyBox = RectMake(265,105,220,130);
	mushroomBuyBox = RectMake(510, 105, 220, 130);
	oliveBuyBox = RectMake(755, 105, 220, 130);
	onionBuyBox = RectMake(265, 325, 220, 130);
	pimentBuyBox = RectMake(510, 325, 220, 130);

	userInterface = GAMEINFO->getUI();
}

ShopScene::~ShopScene()
{
}

bool ShopScene::Init()
{
	return true;
}

void ShopScene::Release()
{
}

void ShopScene::Update()
{
	GetCursorPos(&_ptMouse);
	ScreenToClient(_hWnd, &_ptMouse);
	if (PtInRect(&dailyStatisticsButton, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			SCENEMANAGER->ChangeScene(TEXT("Result"));
		}
	}
	if (PtInRect(&nextDayButton, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			// 다음날로 이동
			// 날짜 +1
			userInterface->SetDay(userInterface->GetDay() + 1);
			// 시간 초기화
			userInterface->SetTime(0);
			// 하루정산 초기화
			GAMEINFO->setTotalRevenue(0);
			GAMEINFO->setTip(0);
			GAMEINFO->setRefund(0);
			GAMEINFO->setToppingCost(0);

			
			SCENEMANAGER->ChangeScene(TEXT("InGame1"));			
		}
	}


	// 재료 구입
	if (PtInRect(&sausageBuyBox, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && GAMEINFO->GetIsSausageBuy() == false)
		{
			userInterface->SetMoney(userInterface->GetMoney() - 10000);
			GAMEINFO->SetIsSausageBuy(true);
		}
	}
	if (PtInRect(&mushroomBuyBox, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && GAMEINFO->GetIsMushroomBuy() == false)
		{
			userInterface->SetMoney(userInterface->GetMoney() - 10000);
			GAMEINFO->SetIsMushroomBuy(true);
		}
	}
	if (PtInRect(&oliveBuyBox, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && GAMEINFO->GetIsOliveBuy() == false)
		{
			userInterface->SetMoney(userInterface->GetMoney() - 10000);
			GAMEINFO->SetIsOliveBuy(true);
		}
	}
	if (PtInRect(&onionBuyBox, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && GAMEINFO->GetIsOnionBuy() == false)
		{
			userInterface->SetMoney(userInterface->GetMoney() - 10000);
			GAMEINFO->SetIsOnionBuy(true);
		}
	}
	if (PtInRect(&pimentBuyBox, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && GAMEINFO->GetIsPimentBuy() == false)
		{
			userInterface->SetMoney(userInterface->GetMoney() - 10000);
			GAMEINFO->SetIsPimentBuy(true);
		}
	}
}

void ShopScene::Render(HDC hdc)
{
	shopImg->Render(hdc);
//	Rectangle(hdc, dailyStatisticsButton.left, dailyStatisticsButton.top, dailyStatisticsButton.right, dailyStatisticsButton.bottom);
//	Rectangle(hdc, nextDayButton.left, nextDayButton.top, nextDayButton.right, nextDayButton.bottom);
	
	//Rectangle(hdc, sausageBuyBox.left, sausageBuyBox.top, sausageBuyBox.right, sausageBuyBox.bottom);
	//Rectangle(hdc, mushroomBuyBox.left, mushroomBuyBox.top, mushroomBuyBox.right, mushroomBuyBox.bottom);
	//Rectangle(hdc, oliveBuyBox.left, oliveBuyBox.top, oliveBuyBox.right, oliveBuyBox.bottom);
	//Rectangle(hdc, onionBuyBox.left, onionBuyBox.top, onionBuyBox.right, onionBuyBox.bottom);
	//Rectangle(hdc, pimentBuyBox.left, pimentBuyBox.top, pimentBuyBox.right, pimentBuyBox.bottom);




	// 구입하면 체크하는 거
	if (GAMEINFO->GetIsSausageBuy())
	{
		checkImg->Render(hdc, sausageBuyBox.left + (sausageBuyBox.right - sausageBuyBox.left) / 2 - checkImg->GetWidth() / 2,
			sausageBuyBox.top + (sausageBuyBox.bottom - sausageBuyBox.top) / 2 - checkImg->GetHeight() / 2);
	}
	if (GAMEINFO->GetIsMushroomBuy())
	{
		checkImg->Render(hdc, mushroomBuyBox.left + (mushroomBuyBox.right - mushroomBuyBox.left) / 2 - checkImg->GetWidth() / 2,
			mushroomBuyBox.top + (mushroomBuyBox.bottom - mushroomBuyBox.top) / 2 - checkImg->GetHeight() / 2);
	}
	if (GAMEINFO->GetIsOliveBuy())
	{
		checkImg->Render(hdc, oliveBuyBox.left + (oliveBuyBox.right - oliveBuyBox.left) / 2 - checkImg->GetWidth() / 2,
			oliveBuyBox.top + (oliveBuyBox.bottom - oliveBuyBox.top) / 2 - checkImg->GetHeight() / 2);
	}
	if (GAMEINFO->GetIsOnionBuy())
	{
		checkImg->Render(hdc, onionBuyBox.left + (onionBuyBox.right - onionBuyBox.left) / 2 - checkImg->GetWidth() / 2,
			onionBuyBox.top + (onionBuyBox.bottom - onionBuyBox.top) / 2 - checkImg->GetHeight() / 2);
	}
	if (GAMEINFO->GetIsPimentBuy())
	{
		checkImg->Render(hdc, pimentBuyBox.left + (pimentBuyBox.right - pimentBuyBox.left) / 2 - checkImg->GetWidth() / 2,
			pimentBuyBox.top + (pimentBuyBox.bottom - pimentBuyBox.top) / 2 - checkImg->GetHeight() / 2);
	}

	//
	SetBkMode(hdc, TRANSPARENT); // 글자 배경색 없애기
	SetTextColor(hdc, RGB(255, 187, 0)); // 글자 색깔 정하기

	// 날짜
	TextOutPutInt(hdc, 90, 5, 15, userInterface->GetDay());


	// 돈
	SetTextColor(hdc, RGB(255, 87, 100));
	TextOutPutInt(hdc, 1020, 18, 15, userInterface->GetMoney());	
}
