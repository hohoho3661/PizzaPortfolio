#include "stdafx.h"
#include "UI.h"



UI::UI()
{
	ui = IMAGEMANAGER->findImage(TEXT("UI"));
	assert(ui != NULL);
	
	whatDay = 1;
	whatTime = 12;

	whatTime = 0;

	whatMinute = 0;

	timeIndex = 0;


	happiness = 100;

	money = 50000;
}


UI::~UI()
{
}

bool UI::Init()
{
	return true;
}

void UI::Update()
{
	// 영업시간은 12시부터 8시까지 (PM)

	//whatTime++;
	if (whatTime < 8)
	{
		timeIndex++;
		if (timeIndex % 200 == 190)
		{
			whatMinute += 15;
		}
		if (whatMinute == 60)
		{
			whatMinute = 0;
			whatTime += 1;
		}

	//	whatTime %= 12;
	}



}

void UI::Render(HDC hdc)
{
	ui->Render(hdc, 0, 0);

	SetBkMode(hdc, TRANSPARENT); // 글자 배경색 없애기
	
	if (whatTime == 8)
	{
		SetTextColor(hdc, RGB(220, 20, 60));
		TextOutPutInt(hdc, 58, 25, 15, whatTime);
		TextOutPutInt(hdc, 82, 25, 15, whatMinute);
	}
	else
	{
		SetTextColor(hdc, RGB(255, 187, 0));
		TextOutPutInt(hdc, 58, 25, 15, whatTime);
		TextOutPutInt(hdc, 82, 25, 15, whatMinute);
	}

	SetTextColor(hdc, RGB(255, 187, 0)); // 글자 색깔 정하기

	TextOutPutInt(hdc, 60, 5, 15, whatDay);

	//
	TextOutPutInt(hdc, 240, 18, 15, happiness);

	//
	SetTextColor(hdc, RGB(255, 87, 100)); // 글자 색깔 정하기
	TextOutPutInt(hdc, 900, 18, 15, money);
}


//==============================================================================================================
//==============================================================================================================
//==============================================================================================================