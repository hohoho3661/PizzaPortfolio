#pragma once

// ����� ���� �ڷ���



//Extern
extern HWND			_hWnd;
extern HINSTANCE	_hInst;
extern POINT		_ptMouse;

enum OBJ_TYPE
{
	ELLIPSE = 0,
	RECTANGLE,

};

struct OrderList
{
	string	str;
	string	strAgain;
//	string	strAgainAgain;

	bool	isSauce;
	bool	isCheese;
	bool	isPepperoni;
	bool	isSausage;
	bool	isMushroom;
	bool	isOlive;
	bool	isOnion;
	bool	isPiment;

	short	sauceWantAmount;
	short	cheeseWantAmount;
	short	pepperoniWantAmount;
	short	sausageWantAmount;
	short	mushroomWantAmount;
	short	oliveWantAmount;
	short	onionWantAmount;
	short	primentWantAmount;

	int		howMuchPizza;

	short	degreeBaked; // ����������,,,   ������������ �ο��Ǵ� ���İ� �������� üũ�Ұ�
};

struct OrderListTest
{
	string	str;
	string	strAgain;

	int one;
	int two;
	int three;
};