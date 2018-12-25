#pragma once

// 사용자 정의 자료형



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

	short	degreeBaked; // 구워진정도,,,   오븐지나갈때 부여되는 알파값 기준으로 체크할거
};

struct OrderListTest
{
	string	str;
	string	strAgain;

	int one;
	int two;
	int three;
};