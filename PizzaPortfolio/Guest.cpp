#include "stdafx.h"
#include "Guest.h"

Guest::Guest()
{

}

Guest::~Guest()
{
}


bool Guest::Init(short _alphaIndex, bool _isComplete)
{
	guestAlphaIndex = _alphaIndex;
	isComplete = _isComplete;

	OrderSetting();

	guestIndex = RAND->getInt(5);
	switch (guestIndex)
	{
	case 0:
		guestImg = IMAGEMANAGER->findImage(TEXT("�մ�1"));
		break;
	case 1:
		guestImg = IMAGEMANAGER->findImage(TEXT("�մ�2"));
		break;
	case 2:
		guestImg = IMAGEMANAGER->findImage(TEXT("�մ�3"));
		break;
	case 3:
		guestImg = IMAGEMANAGER->findImage(TEXT("�մ�4"));
		break;
	case 4:
		guestImg = IMAGEMANAGER->findImage(TEXT("�մ�5"));
		break;
	}

	textBox = IMAGEMANAGER->findImage(TEXT("��ǳ��"));



	isRepeat = false;



	textBoxRC = RectMake(320, 120, 820, 100);

	okeyButton = RectMake(480, 270, 220, 70); // [������] ��ư
	repeatButton = RectMake(750, 270, 220, 70); // [��?] ��ư

	return true;
}

void Guest::Release()
{
	SAFE_DELETE(guestImg);
	SAFE_RELEASE(guestImg);
}

void Guest::DisapperGuest()
{
	//guestImg->SetX(guestImg->GetX() - 1);
	//if (guestImg->GetX() < 50)
	//{
	//	this->Release();
	//}
}

void Guest::Update(short _alphaIndex, bool _isComplete)
{
	guestAlphaIndex = _alphaIndex;
	isComplete = _isComplete;

	GetCursorPos(&_ptMouse);
	ScreenToClient(_hWnd, &_ptMouse);

	if (PtInRect(&okeyButton, _ptMouse) && isComplete == false)
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			SCENEMANAGER->ChangeScene(TEXT("InGame2"));
		}
	}
	if (PtInRect(&repeatButton, _ptMouse) && isComplete == false)
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			selectedOrder.str = selectedOrder.strAgain;
			GAMEINFO->SetOrderCheckString(selectedOrder.str);
			isRepeat = true;
		}
	}

}

void Guest::Render(HDC hdc)
{
	// �մ��̹���
	guestImg->AlphaRender(hdc, guestAlphaIndex);

	// ��ǳ�� �̹���
	textBox->AlphaRender(hdc, guestAlphaIndex);
 
	timeGetTime();


	//
	HFONT hFont;
	HFONT OldFont;

	string str = selectedOrder.str;
	GAMEINFO->SetOrderCheckString(selectedOrder.str);

	SetBkMode(hdc, TRANSPARENT); // ���� ���� ���ֱ�
	SetTextColor(hdc, RGB(85, 49, 40)); // ���� ���� ���ϱ�

	hFont = CreateFont(35, 0, NULL, NULL, FW_HEAVY, 0, 0, 0, HANGUL_CHARSET, NULL, NULL, NULL, NULL, TEXT("����ü"));
	OldFont = (HFONT)SelectObject(hdc, hFont);

	DrawText(hdc, str.c_str(), str.size(), &textBoxRC, DT_WORDBREAK);

	SelectObject(hdc, OldFont);
	DeleteObject(hFont);
}

void Guest::OrderSetting()
{
	order1 = GAMEINFO->GetOrderList(1);
	order2 = GAMEINFO->GetOrderList(2);

	order3 = GAMEINFO->GetOrderList(3);
	order4 = GAMEINFO->GetOrderList(4);
	order5 = GAMEINFO->GetOrderList(5);
	
	if (GAMEINFO->GetIsSausageBuy() == false && order3.isSausage == true
		|| GAMEINFO->GetIsMushroomBuy() == false && order3.isMushroom == true
		|| GAMEINFO->GetIsOliveBuy() == false && order3.isOlive == true
		|| GAMEINFO->GetIsOnionBuy() == false && order3.isOnion == true
		|| GAMEINFO->GetIsPimentBuy() == false && order3.isPiment == true)
	{
		order3 = GAMEINFO->GetOrderList(1);
	}
	if (GAMEINFO->GetIsSausageBuy() == false && order4.isSausage == true
		|| GAMEINFO->GetIsMushroomBuy() == false && order4.isMushroom == true
		|| GAMEINFO->GetIsOliveBuy() == false && order4.isOlive == true
		|| GAMEINFO->GetIsOnionBuy() == false && order4.isOnion == true
		|| GAMEINFO->GetIsPimentBuy() == false && order4.isPiment == true)
	{
		order4 = GAMEINFO->GetOrderList(1);
	}
	if (GAMEINFO->GetIsSausageBuy() == false && order5.isSausage == true
		|| GAMEINFO->GetIsMushroomBuy() == false && order5.isMushroom == true
		|| GAMEINFO->GetIsOliveBuy() == false && order5.isOlive == true
		|| GAMEINFO->GetIsOnionBuy() == false && order5.isOnion == true
		|| GAMEINFO->GetIsPimentBuy() == false && order5.isPiment == true)
	{
		order5 = GAMEINFO->GetOrderList(2);
	}




	// ���õ� order�� �������� �̾Ƽ� selectedOrder�� �ֱ�.
	orderIndex = RAND->getInt(HOW_MANY_ORDER);
	switch (orderIndex)
	{
	case 0:
		selectedOrder = order1;
		break;
	case 1:
		selectedOrder = order2;
		break;
	case 2:
		selectedOrder = order3;
		break;
	case 3:
		selectedOrder = order4;
		break;
	case 4:
		selectedOrder = order5;
		break;
	}
}
