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
	// �����ð��� 12�ú��� 8�ñ��� (PM)

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

	SetBkMode(hdc, TRANSPARENT); // ���� ���� ���ֱ�
	
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

	SetTextColor(hdc, RGB(255, 187, 0)); // ���� ���� ���ϱ�

	TextOutPutInt(hdc, 60, 5, 15, whatDay);

	//
	TextOutPutInt(hdc, 240, 18, 15, happiness);

	//
	SetTextColor(hdc, RGB(255, 87, 100)); // ���� ���� ���ϱ�
	TextOutPutInt(hdc, 900, 18, 15, money);
}


//==============================================================================================================
//==============================================================================================================
//==============================================================================================================