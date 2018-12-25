#pragma once
#include "GameNode.h"

class Guest;
class UI;

class RestaurantScene :
	public GameNode
{
	Image*		restaurantImg;	// 레스토랑 이미지
	Image*		nightImg;	// 밤이 되는 효과
	short		restaurantAlphaIndex;	// 레스토랑 전체이미지 알파값 ( 결과창으로 넘어갈때 어두워지는 효과 )

	Image*		morningImg;
	int			morningIndex;

	Image*		restaurantOutsideImg;	// 레스토랑 외부 이미지 ( 밤이되는 효과를 만들기 위해 따로 분리함 )
	RECT		restaurantOutsideIndexRC;	// 레스토랑 외부 이미지의 렉트값
	int			restaurantOutsideAlphaIndex;	// 레스토랑 외부 이미지의 알파값

	Image*		counterImg;
	Image*		pizzaBoxImg;

	RECT		pizzaBoxRC;
	bool		isPizzaBoxMoving;

	Guest*		guest;
	RECT		guestRC;	// 피자를 만들고나서 손님에게 건넬때 충돌처리 할 부분

	
	bool		isGuest;	// 지금 손님이 있는지 없는지 확인용
	bool		isGuestPizzaComplete;	// 완료했는지 체크
	short		disapperGuestIndex;	// 손님사라지게 하기
	short		guestIndex;

	bool		isRepeatIndex;	// guest에서 repeat버튼을 누를때 happiness가 10 감소하는데,, 여러번 누르는걸 방지하기위해 선언한 변수

	int			tip;
	//
	UI*			userInterface;

	int			howMuchPizzaCost;	// 피자값
public:
	RestaurantScene();
	~RestaurantScene();

	virtual bool	Init();
	virtual void	Release();
	virtual void	Update();
	virtual void	Render(HDC hdc);
};

