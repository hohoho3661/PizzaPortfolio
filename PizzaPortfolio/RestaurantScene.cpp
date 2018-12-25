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
	restaurantImg = IMAGEMANAGER->findImage(TEXT("레스토랑"));
	restaurantOutsideImg = IMAGEMANAGER->findImage(TEXT("레스토랑외부"));
	
	nightImg = IMAGEMANAGER->findImage(TEXT("밤"));	
	morningImg = IMAGEMANAGER->findImage(TEXT("아침"));
	morningIndex = 255;

	restaurantOutsideIndexRC = RectMake(260, 20, 690, 320);

	restaurantAlphaIndex = 0;
	restaurantOutsideAlphaIndex = 255;

	counterImg = IMAGEMANAGER->findImage(TEXT("카운터"));
	pizzaBoxImg = IMAGEMANAGER->findImage(TEXT("피자박스"));
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

	// 밤이 되는 효과 (임시) - UI클래스에서 시간을 받아와서 시간에 따라 외부 이미지에 인덱스를 적용.
	if (userInterface->GetTime() >= 4 && userInterface->GetTime() < 8)
	{
		restaurantOutsideAlphaIndex = 255 - userInterface->GetTime() * 15;
		//restaurantOutsideAlphaIndex -= userInterface->GetTime() % 10;
	}

	// 밤이되면 결과창 ( 8:00 PM )
	if (userInterface->GetTime() == 8 && isGuest == false)
	{
		restaurantAlphaIndex++;

		if (restaurantAlphaIndex == 230)
		{
			SCENEMANAGER->ChangeScene(TEXT("Result"));

			// 하루가 끝났으니 임대료 지불
			userInterface->SetMoney(userInterface->GetMoney() - RENT_COST);
		}
	}

	// 손님 나오게 하기 (임시)
	if (KEYMANAGER->isOnceKeyDown('1') && isGuest == false)
	{

		userInterface->SetHappiness(100);
		isRepeatIndex = false;
		isGuestPizzaComplete = false;
		disapperGuestIndex = 255;
		guestIndex = 150; // 계산완료후 손님이 사라질때까지의 시간

		guestRC = RectMakeCenter(200, 400, 150, 200);

		isGuest = true;

		//
		guest = new Guest;
		guest->Init(disapperGuestIndex, isGuestPizzaComplete);
	}

	// 계산이 완료되면 손님이 사라지게
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
	
	// pizzaBox 손님에게 주기
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

				// 맞는지 검사하는 부분이 들어감
				// 피자랑 손님이 가진 정보를 비교,,,,,
				if (PtInRect(&guestRC, _ptMouse))
				{
					GAMEINFO->setIsPizza(false);

					// 피자값 측정
					tip = 0;
					howMuchPizzaCost = guest->GetSelectedOrder().howMuchPizza;
					GAMEINFO->setTotalRevenue(GAMEINFO->getTotalRevenue() + howMuchPizzaCost);

					userInterface->SetMoney(userInterface->GetMoney() + howMuchPizzaCost);



					// 만족도에 따라 대사 변경하자
					//string str = "happiness에 따라 나오는 대사!";

					string str;
					int strIndex = RAND->getInt(5);
					switch (strIndex)
					{
					case 0:
						str = "굳! 감사합니다";
						break;
					case 1:
						str = "피자~ 피자~";
						break;
					case 2:
						str = "오 제가 주문한 피자네요";
						break;
					case 3:
						str = "잘먹겠습니다";
						break;
					case 4:
						str = "피자에 대한 책을 쓰셔도 될것 같아요!";
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
						str = "이게 뭔가요!\n제가 주문한 피자는 이런게 아니예요";
						GAMEINFO->setRefund(GAMEINFO->getRefund() + howMuchPizzaCost);
						userInterface->SetMoney(userInterface->GetMoney() - howMuchPizzaCost);
						howMuchPizzaCost = 0;
					}

					else if (GAMEINFO->getSauceHaveAmount() < guest->GetSelectedOrder().sauceWantAmount)
					{
						userInterface->SetHappiness(0);
						str = "소스가 부족해요!";
					}

					else if (GAMEINFO->getCheeseHaveAmount() < guest->GetSelectedOrder().cheeseWantAmount)
					{
						userInterface->SetHappiness(0);
						str = "치즈가 부족해요!";
					}

					guest->SetSelectOrderStr(str);

					
					// 팁
					if (userInterface->GetHappiness() > 50)
					{
						tip = userInterface->GetHappiness() * 100;
						GAMEINFO->setTip(GAMEINFO->getTip() + tip);
						userInterface->SetMoney(userInterface->GetMoney() + tip);
					}


					// 대사를 하고나서는 손님은 잠시후에 사라지게 
					isGuestPizzaComplete = true;
				}

			}
		}
	}

	



	// 손님이있을때 ------ pizzaBox 손님에게 주는거 이후에 해줘야 정상작동됨
	if (isGuest == true)
	{
		guest->Update(disapperGuestIndex, isGuestPizzaComplete);

		// [네?]버튼을 눌렀는지 확인하고 눌렀으면 happiness를 10 깍는다.
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
	// 식당 전체 이미지
	// 식당
	DrawObject(hdc, restaurantOutsideIndexRC, 1, RGB(0, 0, 0), RECTANGLE);

	restaurantImg->Render(hdc);

	// 식당외부 - 알파값을 줘서 밤이되는 효과를 만들어보자
	restaurantOutsideImg->AlphaRender(hdc, restaurantOutsideAlphaIndex);

	if (isGuest == true)
	{
		guest->Render(hdc);
//		Rectangle(hdc, guestRC.left, guestRC.top, guestRC.right, guestRC.bottom);
	}

	// 카운터(주문받는곳) 이미지
	counterImg->Render(hdc);


	if (GAMEINFO->getIsPizza() == true)
	{
	//	Rectangle(hdc, pizzaBoxRC.left, pizzaBoxRC.top, pizzaBoxRC.right, pizzaBoxRC.bottom);
		pizzaBoxImg->Render(hdc);
	}


	// 거래완료후 돈 보여주자
	if (isGuestPizzaComplete)
	{
		SetTextColor(hdc, RGB(55, 87, 200)); // 글자 색깔 정하기

		TCHAR howMuchPizzaCostText[100] = { 0, };
		_stprintf_s(howMuchPizzaCostText, sizeof(howMuchPizzaCostText), TEXT("받은돈 : %d"), howMuchPizzaCost);
		TextOut(hdc, 160, 500, TEXT(howMuchPizzaCostText), _tcslen(TEXT(howMuchPizzaCostText)));

		TCHAR tipText[100] = { 0, };
		_stprintf_s(tipText, sizeof(tipText), TEXT("팁 : %d"), tip);
		TextOut(hdc, 160, 530, TEXT(tipText), _tcslen(TEXT(tipText)));
	}

	// 밤
	nightImg->AlphaRender(hdc, restaurantAlphaIndex);

	// 아침
	if (userInterface->GetTime() == 0)
	{
		morningImg->AlphaRender(hdc, morningIndex);
	}

	// UI (인퍼페이스 출력)
	userInterface->Render(hdc);
}
