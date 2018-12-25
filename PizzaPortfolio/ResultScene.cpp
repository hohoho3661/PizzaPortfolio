#include "stdafx.h"
#include "ResultScene.h"
#include "UI.h"

ResultScene::ResultScene()
{
	resultImg = IMAGEMANAGER->findImage(TEXT("결과창"));
	okeyButton = RectMake(935, 595, 230, 70);

	userInterface = GAMEINFO->getUI();
}

ResultScene::~ResultScene()
{
}

bool ResultScene::Init()
{
	// 결과창 세팅
	totalRevenue = GAMEINFO->getTotalRevenue();
	tip = GAMEINFO->getTip();
	rent = RENT_COST;
	refund = GAMEINFO->getRefund();
	toppingCost = GAMEINFO->getToppingCost();
	netIncome = (totalRevenue+tip)-(rent+refund+toppingCost);

	return true;
}

void ResultScene::Release()
{
}

void ResultScene::Update()
{
	GetCursorPos(&_ptMouse);
	ScreenToClient(_hWnd, &_ptMouse);
	if (PtInRect(&okeyButton, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			SCENEMANAGER->ChangeScene(TEXT("Shop"));
		}
	}
}

void ResultScene::Render(HDC hdc)
{
	resultImg->Render(hdc);
//	Rectangle(hdc, okeyButton.left, okeyButton.top, okeyButton.right, okeyButton.bottom);

	//
	SetBkMode(hdc, TRANSPARENT); // 글자 배경색 없애기
	SetTextColor(hdc, RGB(255, 187, 0));

	// 날짜
	TextOutPutInt(hdc, 90, 5, 15, userInterface->GetDay());

	SetTextColor(hdc, RGB(55, 57, 100));
	TextOutPutInt(hdc, WINSIZEX/2 - 40, 78, 30, userInterface->GetDay());
		
	// 돈
	SetTextColor(hdc, RGB(255, 87, 100));
	TextOutPutInt(hdc, 1020, 18, 15, userInterface->GetMoney());






	// 전체수익
	SetTextColor(hdc, RGB(93, 117, 84));
	TextOutPutInt(hdc, 750, 130, 25, totalRevenue);
	// 팁
	TextOutPutInt(hdc, 750, 170, 25, tip);


	// 임대료
	SetTextColor(hdc, RGB(184, 64, 94));
	TextOutPutInt(hdc, 750, 245, 25, rent);
	// 환불
	TextOutPutInt(hdc, 750, 285, 25, refund);
	// 사용 재료값
	TextOutPutInt(hdc, 750, 335, 25, toppingCost);


	// 순수익
	if (netIncome < 0)
	{
		SetTextColor(hdc, RGB(184, 64, 94));
	}
	else if (netIncome >= 0)
	{
		SetTextColor(hdc, RGB(93, 117, 84));
	}
	TextOutPutInt(hdc, 750, 440, 30, netIncome);

}
