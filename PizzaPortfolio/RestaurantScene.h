#pragma once
#include "GameNode.h"

class Guest;
class UI;

class RestaurantScene :
	public GameNode
{
	Image*		restaurantImg;	// ������� �̹���
	Image*		nightImg;	// ���� �Ǵ� ȿ��
	short		restaurantAlphaIndex;	// ������� ��ü�̹��� ���İ� ( ���â���� �Ѿ�� ��ο����� ȿ�� )

	Image*		morningImg;
	int			morningIndex;

	Image*		restaurantOutsideImg;	// ������� �ܺ� �̹��� ( ���̵Ǵ� ȿ���� ����� ���� ���� �и��� )
	RECT		restaurantOutsideIndexRC;	// ������� �ܺ� �̹����� ��Ʈ��
	int			restaurantOutsideAlphaIndex;	// ������� �ܺ� �̹����� ���İ�

	Image*		counterImg;
	Image*		pizzaBoxImg;

	RECT		pizzaBoxRC;
	bool		isPizzaBoxMoving;

	Guest*		guest;
	RECT		guestRC;	// ���ڸ� ������� �մԿ��� �ǳڶ� �浹ó�� �� �κ�

	
	bool		isGuest;	// ���� �մ��� �ִ��� ������ Ȯ�ο�
	bool		isGuestPizzaComplete;	// �Ϸ��ߴ��� üũ
	short		disapperGuestIndex;	// �մԻ������ �ϱ�
	short		guestIndex;

	bool		isRepeatIndex;	// guest���� repeat��ư�� ������ happiness�� 10 �����ϴµ�,, ������ �����°� �����ϱ����� ������ ����

	int			tip;
	//
	UI*			userInterface;

	int			howMuchPizzaCost;	// ���ڰ�
public:
	RestaurantScene();
	~RestaurantScene();

	virtual bool	Init();
	virtual void	Release();
	virtual void	Update();
	virtual void	Render(HDC hdc);
};

