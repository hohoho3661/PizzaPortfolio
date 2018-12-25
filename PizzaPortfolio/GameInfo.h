#pragma once
#include "SingleTon.h"

class UI;

class GameInfo : public SingletonBase<GameInfo>
{
	bool		isPizza;

	// 파싱한 데이터를 받을 변수 ( 주문 정보 )
#define HOW_MANY_ORDER 5 // 파싱할 데이터가 몇개인지 (나중에 지울꺼)
	OrderList	order[HOW_MANY_ORDER];
	string		orderStr;

	// 상점 관련 (상점에서 재료를 샀는지)
	bool		isSausageBuy;
	bool		isMushroomBuy;
	bool		isOliveBuy;
	bool		isOnionBuy;
	bool		isPimentBuy;
	

	//pizzaInfo
	bool		isSauce;
	bool		isCheese;
	bool		isPepperoni;
	bool		isSausage;
	bool		isMushroom;
	bool		isOlive;
	bool		isOnion;
	bool		isPiment;

	short		sauceHaveAmount;
	short		cheeseHaveAmount;
	short		pepperoniHaveAmount;
	short		sausageHaveAmount;
	short		mushroomHaveAmount;
	short		oliveHaveAmount;
	short		onionHaveAmount;
	short		primentHaveAmount;

	int			howMuchPizza; // 피자가 얼마인지

	// 결과창
	int		totalRevenue;	// 전체수익
	int		tip;			// 팁
	int		refund;			// 환불
	int		toppingCost;	// 사용 재료값

	// 인터페이스
	UI*		userInterface;


public:
	GameInfo();
	~GameInfo();

	// 파싱
	OrderList	OrderListParsing(int _index);
	OrderList	GetOrderList(int n) { return order[n-1]; }
	string		GetOrderCheckString() { return orderStr; }
	void		SetOrderCheckString(string _orderStr) { orderStr = _orderStr; }

	// 피자정보 관련 get, set함수들
	bool	getIsPizza() { return isPizza; }
	void	setIsPizza(bool _isPizza) { isPizza = _isPizza; }

	bool	getIsSauce		()			{ return isSauce; }
	bool	getIsCheese		()			{ return isCheese; }
	bool	getIsPepperoni	()			{ return isPepperoni; }
	bool	getIsSausage	()			{ return isSausage; }
	bool	getIsMushroom	()			{ return isMushroom; }
	bool	getIsOlive		()			{ return isOlive; }
	bool	getIsOnion		()			{ return isOnion; }
	bool	getIsPiment		()			{ return isPiment; }
	short	getSauceHaveAmount		()	{ return sauceHaveAmount;}
	short	getCheeseHaveAmount		()	{ return cheeseHaveAmount; }
	short	getPepperoniHaveAmount	()	{ return pepperoniHaveAmount; }
	short	getSausageHaveAmount	()	{ return sausageHaveAmount; }
	short	getMushroomHaveAmount	()	{ return mushroomHaveAmount; }
	short	getOliveHaveAmount		()	{ return oliveHaveAmount; }
	short	getOnionHaveAmount		()	{ return onionHaveAmount; }
	short	getPrimentHaveAmount	()	{ return primentHaveAmount; }
	int		getHowMuchPizza() { return howMuchPizza; }

	void	setIsSauce		(bool _isSauce)		{ isSauce = _isSauce; }
	void	setIsCheese		(bool _isCheese)	{ isCheese = _isCheese; }
	void	setIsPepperoni	(bool _isPepperoni) { isPepperoni = _isPepperoni; }
	void	setIsSausage	(bool _isSausage)	{ isSausage = _isSausage; }
	void	setIsMushroom	(bool _isMushroom)	{ isMushroom = _isMushroom; }
	void	setIsOlive		(bool _isOlive)		{ isOlive = _isOlive; }
	void	setIsOnion		(bool _isOnion)		{ isOnion = _isOnion; }
	void	setIsPiment		(bool _isPiment)	{ isPiment = _isPiment; }
	void	setSauceHaveAmount		(short _sauceHaveAmount) { sauceHaveAmount = _sauceHaveAmount; }
	void	setCheeseHaveAmount		(short _cheeseHaveAmount) { cheeseHaveAmount = _cheeseHaveAmount; }
	void	setPepperoniHaveAmount	(short _pepperoniHaveAmount) { pepperoniHaveAmount = _pepperoniHaveAmount; }
	void	setSausageHaveAmount	(short _sausageHaveAmount) { sausageHaveAmount = _sausageHaveAmount; }
	void	setMushroomHaveAmount	(short _mushroomHaveAmount) { mushroomHaveAmount = _mushroomHaveAmount; }
	void	setOliveHaveAmount		(short _oliveHaveAmount) { oliveHaveAmount = _oliveHaveAmount; }
	void	setOnionHaveAmount		(short _onionHaveAmount) { onionHaveAmount = _onionHaveAmount; }
	void	setPrimentHaveAmount	(short _primentHaveAmount) { primentHaveAmount = _primentHaveAmount; }
	void	setHowMuchPizza(int _howMuchPizza) { howMuchPizza = _howMuchPizza; }

	// 결과창
	int		getTotalRevenue() { return totalRevenue; }
	int		getTip() { return tip; }
	int		getRefund() { return refund; }
	int		getToppingCost() { return toppingCost; }

	void	setTotalRevenue(int _totalRevenue) { totalRevenue = _totalRevenue; }	// 전체수익
	void	setTip(int _tip) { tip = _tip; }			// 팁
	void	setRefund(int _refund) { refund = _refund; }			// 임대료
	void	setToppingCost(int _toppingCost) { toppingCost = _toppingCost; }	// 사용 재료값


	// 상점관련
	bool	GetIsSausageBuy() { return isSausageBuy; }
	bool	GetIsMushroomBuy() { return isMushroomBuy; }
	bool	GetIsOliveBuy() { return isOliveBuy; }
	bool	GetIsOnionBuy() { return isOnionBuy; }
	bool	GetIsPimentBuy() { return isPimentBuy; }

	void	SetIsSausageBuy(bool _isSausageBuy) { isSausageBuy = _isSausageBuy; }
	void	SetIsMushroomBuy(bool _isMushroomBuy) {	isMushroomBuy = _isMushroomBuy;	}
	void	SetIsOliveBuy(bool _isOliveBuy) { isOliveBuy = _isOliveBuy; }
	void	SetIsOnionBuy(bool _isOnionBuy) { isOnionBuy = _isOnionBuy; }
	void	SetIsPimentBuy(bool _isPimentBuy) { isPimentBuy = _isPimentBuy; }

	//
	UI*		getUI() { return userInterface; }
};

