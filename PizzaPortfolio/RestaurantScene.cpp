#include "stdafx.h"
#include "RestaurantScene.h"

#include "Guest.h"
#include "UI.h"

RestaurantScene::RestaurantScene()
{
	isGuest = false;
}


RestaurantScene::~RestaurantScene()
{
}

bool RestaurantScene::Init()
{
	restaurantImg = IMAGEMANAGER->findImage(TEXT("�������"));
	restaurantOutsideImg = IMAGEMANAGER->findImage(TEXT("��������ܺ�"));
	
	nightImg = IMAGEMANAGER->findImage(TEXT("��"));	
	morningImg = IMAGEMANAGER->findImage(TEXT("��ħ"));
	morningIndex = 255;

	restaurantOutsideIndexRC = RectMake(260, 20, 690, 320);

	restaurantAlphaIndex = 0;
	restaurantOutsideAlphaIndex = 255;

	counterImg = IMAGEMANAGER->findImage(TEXT("ī����"));
	pizzaBoxImg = IMAGEMANAGER->findImage(TEXT("���ڹڽ�"));
	pizzaBoxImg->SetX(220);
	pizzaBoxImg->SetY(580);

	pizzaBoxRC = RectMake(pizzaBoxImg->GetX(), pizzaBoxImg->GetY(), pizzaBoxImg->GetWidth(), pizzaBoxImg->GetHeight());
	isPizzaBoxMoving = false;





	//
	userInterface = GAMEINFO->getUI();
	


	return true;
}

void RestaurantScene::Release()
{
}

void RestaurantScene::Update()
{	
	if (morningIndex >= 3)
	{
		morningIndex -= 3;
	}

	// ���� �Ǵ� ȿ�� (�ӽ�) - UIŬ�������� �ð��� �޾ƿͼ� �ð��� ���� �ܺ� �̹����� �ε����� ����.
	if (userInterface->GetTime() >= 4 && userInterface->GetTime() < 8)
	{
		restaurantOutsideAlphaIndex = 255 - userInterface->GetTime() * 15;
		//restaurantOutsideAlphaIndex -= userInterface->GetTime() % 10;
	}

	// ���̵Ǹ� ���â ( 8:00 PM )
	if (userInterface->GetTime() == 8 && isGuest == false)
	{
		restaurantAlphaIndex++;

		if (restaurantAlphaIndex == 230)
		{
			SCENEMANAGER->ChangeScene(TEXT("Result"));

			// �Ϸ簡 �������� �Ӵ�� ����
			userInterface->SetMoney(userInterface->GetMoney() - RENT_COST);
		}
	}

	// �մ� ������ �ϱ� (�ӽ�)
	if (KEYMANAGER->isOnceKeyDown('1') && isGuest == false)
	{

		userInterface->SetHappiness(100);
		isRepeatIndex = false;
		isGuestPizzaComplete = false;
		disapperGuestIndex = 255;
		guestIndex = 150; // ���Ϸ��� �մ��� ������������� �ð�

		guestRC = RectMakeCenter(200, 400, 150, 200);

		isGuest = true;

		//
		guest = new Guest;
		guest->Init(disapperGuestIndex, isGuestPizzaComplete);
	}

	// ����� �Ϸ�Ǹ� �մ��� �������
	if (isGuestPizzaComplete == true)
	{
		guestIndex--;
		if (guestIndex <= 0)
		{
			disapperGuestIndex -= 5;
			if (disapperGuestIndex <= 0)
			{
				//
				isGuest = false;
				isGuestPizzaComplete = false;
			}
		}
	}
	
	// pizzaBox �մԿ��� �ֱ�
	if (GAMEINFO->getIsPizza() == true)
	{
		if (PtInRect(&pizzaBoxRC, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				isPizzaBoxMoving = true;
			}
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && (isPizzaBoxMoving == true))
			{
				pizzaBoxImg->SetCenter(_ptMouse.x, _ptMouse.y);
			}
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				isPizzaBoxMoving = false;

				// �´��� �˻��ϴ� �κ��� ��
				// ���ڶ� �մ��� ���� ������ ��,,,,,
				if (PtInRect(&guestRC, _ptMouse))
				{
					GAMEINFO->setIsPizza(false);

					// ���ڰ� ����
					tip = 0;
					howMuchPizzaCost = guest->GetSelectedOrder().howMuchPizza;
					GAMEINFO->setTotalRevenue(GAMEINFO->getTotalRevenue() + howMuchPizzaCost);

					userInterface->SetMoney(userInterface->GetMoney() + howMuchPizzaCost);



					// �������� ���� ��� ��������
					//string str = "happiness�� ���� ������ ���!";

					string str;
					int strIndex = RAND->getInt(5);
					switch (strIndex)
					{
					case 0:
						str = "��! �����մϴ�";
						break;
					case 1:
						str = "����~ ����~";
						break;
					case 2:
						str = "�� ���� �ֹ��� ���ڳ׿�";
						break;
					case 3:
						str = "�߸԰ڽ��ϴ�";
						break;
					case 4:
						str = "���ڿ� ���� å�� ���ŵ� �ɰ� ���ƿ�!";
						break;
					}


					if (GAMEINFO->getPepperoniHaveAmount() < guest->GetSelectedOrder().pepperoniWantAmount
						|| GAMEINFO->getSausageHaveAmount() < guest->GetSelectedOrder().sausageWantAmount
						|| GAMEINFO->getMushroomHaveAmount() < guest->GetSelectedOrder().mushroomWantAmount
						|| GAMEINFO->getOliveHaveAmount() < guest->GetSelectedOrder().oliveWantAmount
						|| GAMEINFO->getOnionHaveAmount() < guest->GetSelectedOrder().onionWantAmount
						|| GAMEINFO->getPrimentHaveAmount() < guest->GetSelectedOrder().primentWantAmount)
					{
						userInterface->SetHappiness(0);
						str = "�̰� ������!\n���� �ֹ��� ���ڴ� �̷��� �ƴϿ���";
						GAMEINFO->setRefund(GAMEINFO->getRefund() + howMuchPizzaCost);
						userInterface->SetMoney(userInterface->GetMoney() - howMuchPizzaCost);
						howMuchPizzaCost = 0;
					}

					else if (GAMEINFO->getSauceHaveAmount() < guest->GetSelectedOrder().sauceWantAmount)
					{
						userInterface->SetHappiness(0);
						str = "�ҽ��� �����ؿ�!";
					}

					else if (GAMEINFO->getCheeseHaveAmount() < guest->GetSelectedOrder().cheeseWantAmount)
					{
						userInterface->SetHappiness(0);
						str = "ġ� �����ؿ�!";
					}

					guest->SetSelectOrderStr(str);

					
					// ��
					if (userInterface->GetHappiness() > 50)
					{
						tip = userInterface->GetHappiness() * 100;
						GAMEINFO->setTip(GAMEINFO->getTip() + tip);
						userInterface->SetMoney(userInterface->GetMoney() + tip);
					}


					// ��縦 �ϰ����� �մ��� ����Ŀ� ������� 
					isGuestPizzaComplete = true;
				}

			}
		}
	}

	



	// �մ��������� ------ pizzaBox �մԿ��� �ִ°� ���Ŀ� ����� �����۵���
	if (isGuest == true)
	{
		guest->Update(disapperGuestIndex, isGuestPizzaComplete);

		// [��?]��ư�� �������� Ȯ���ϰ� �������� happiness�� 10 ��´�.
		if (guest->GetIsRepeat() == true && isRepeatIndex == false)
		{
			userInterface->SetHappiness(userInterface->GetHappiness() - 10);
			isRepeatIndex = true;
		}
	}

	pizzaBoxRC = RectMake(pizzaBoxImg->GetX(), pizzaBoxImg->GetY(), pizzaBoxImg->GetWidth(), pizzaBoxImg->GetHeight());

	userInterface->Update();

}

void RestaurantScene::Render(HDC hdc)
{
	// �Ĵ� ��ü �̹���
	// �Ĵ�
	DrawObject(hdc, restaurantOutsideIndexRC, 1, RGB(0, 0, 0), RECTANGLE);

	restaurantImg->Render(hdc);

	// �Ĵ�ܺ� - ���İ��� �༭ ���̵Ǵ� ȿ���� ������
	restaurantOutsideImg->AlphaRender(hdc, restaurantOutsideAlphaIndex);

	if (isGuest == true)
	{
		guest->Render(hdc);
//		Rectangle(hdc, guestRC.left, guestRC.top, guestRC.right, guestRC.bottom);
	}

	// ī����(�ֹ��޴°�) �̹���
	counterImg->Render(hdc);


	if (GAMEINFO->getIsPizza() == true)
	{
	//	Rectangle(hdc, pizzaBoxRC.left, pizzaBoxRC.top, pizzaBoxRC.right, pizzaBoxRC.bottom);
		pizzaBoxImg->Render(hdc);
	}


	// �ŷ��Ϸ��� �� ��������
	if (isGuestPizzaComplete)
	{
		SetTextColor(hdc, RGB(55, 87, 200)); // ���� ���� ���ϱ�

		TCHAR howMuchPizzaCostText[100] = { 0, };
		_stprintf_s(howMuchPizzaCostText, sizeof(howMuchPizzaCostText), TEXT("������ : %d"), howMuchPizzaCost);
		TextOut(hdc, 160, 500, TEXT(howMuchPizzaCostText), _tcslen(TEXT(howMuchPizzaCostText)));

		TCHAR tipText[100] = { 0, };
		_stprintf_s(tipText, sizeof(tipText), TEXT("�� : %d"), tip);
		TextOut(hdc, 160, 530, TEXT(tipText), _tcslen(TEXT(tipText)));
	}

	// ��
	nightImg->AlphaRender(hdc, restaurantAlphaIndex);

	// ��ħ
	if (userInterface->GetTime() == 0)
	{
		morningImg->AlphaRender(hdc, morningIndex);
	}

	// UI (�������̽� ���)
	userInterface->Render(hdc);
}
