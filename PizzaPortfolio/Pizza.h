#pragma once

class UI;

enum Topping
{
	Sauce,
	Cheese,
	Pepperoni,
	Sausage,
	Mushroom,
	Olive,
	Onion, // 양파
	Piment, // 피망
	NONE,
};

class Pizza
{	
	//
	Image*			pizzaImg;
	Animation*		pizzaAni;

	RECT			pizzaRC;
	Image*			bakeImg;

	POINT			pizzaCenter;

	bool			isPizzaMove;
	bool			cuttingState;

	// 토핑
	Topping			topping;

	Image*			SauceImg;
	Image*			CheeseImg;
	Image*			PepperoniImg;
	Image*			SausageImg;
	Image*			MushroomImg;
	Image*			OliveImg;
	Image*			OnionImg; // 양파;
	Image*			PimentImg;// 피망;

	// 피자커팅
	POINT			cuttingStartPos[5], cuttingEndPos[5];


	//
	float			x, y;

	// 피자 오븐에 들어가면 색갈바끼는것
	int				pizzaAlpha;

	list<POINT> Saucelist;
	list<POINT>::iterator SauceIter = Saucelist.begin();

	list<POINT> Cheeselist;
	list<POINT>::iterator CheeseIter = Cheeselist.begin();

	list<POINT> Pepperonilist;
	list<POINT>::iterator PepperoniIter = Pepperonilist.begin();

	list<POINT> Sausagelist;
	list<POINT>::iterator SausageIter = Sausagelist.begin();

	list<POINT> Mushroomlist;
	list<POINT>::iterator MushroomIter = Mushroomlist.begin();

	list<POINT> Olivelist;
	list<POINT>::iterator OliveIter = Olivelist.begin();

	list<POINT> Onionlist;
	list<POINT>::iterator OnionIter = Onionlist.begin();

	list<POINT> Pimentlist;
	list<POINT>::iterator PimentIter = Pimentlist.begin();
	



	//pizzaInfo
	bool	isSauce;
	bool	isCheese;
	bool	isPepperoni;
	bool	isSausage;
	bool	isMushroom;
	bool	isOlive;
	bool	isOnion;
	bool	isPiment;

	short	sauceHaveAmount;
	short	cheeseHaveAmount;
	short	pepperoniHaveAmount;
	short	sausageHaveAmount;
	short	mushroomHaveAmount;
	short	oliveHaveAmount;
	short	onionHaveAmount;
	short	primentHaveAmount;

	//
	UI*		userInterface;
public:
	Pizza();
	~Pizza();

	bool Init();
	void Update(bool _cuttingState);
	void Render(HDC hdc);



	void MakePizza();

	float GetPizzaCenterX() { return pizzaCenter.x; }
	float GetPizzaCenterY() { return pizzaCenter.y; }
	POINT GetpizzaCenter() { return pizzaCenter; }

	void SetPizzaCenterX(float _pizzaCenterX) { pizzaCenter.x = _pizzaCenterX; }
	void SetPizzaCenterY(float _pizzaCenterY) { pizzaCenter.y = _pizzaCenterY; }

	void SetpizzaCenter(POINT _pizzaCenter) { pizzaCenter = _pizzaCenter; }

	int GetPizzaAlpha() { return pizzaAlpha; }
	void SetPizzaAlpha(int _pizzaAlpha) { pizzaAlpha = _pizzaAlpha; }

	// 토핑
	void			ToppingUpdate();
	void			ToppingPosition(Topping topping, float _x, float _y);	
	void			SetTopping(Topping _topping) { topping = _topping; }
	void			ToppingRender(HDC hdc);



	// 피자정보 get,set 함수
	bool	getIsSauce() { return isSauce; }
	bool	getIsCheese() { return isCheese; }
	bool	getIsPepperoni() { return isPepperoni; }
	bool	getIsSausage() { return isSausage; }
	bool	getIsMushroom() { return isMushroom; }
	bool	getIsOlive() { return isOlive; }
	bool	getIsOnion() { return isOnion; }
	bool	getIsPiment() { return isPiment; }
	short	getSauceHaveAmount() { return sauceHaveAmount; }
	short	getCheeseHaveAmount() { return cheeseHaveAmount; }
	short	getPepperoniHaveAmount() { return pepperoniHaveAmount; }
	short	getSausageHaveAmount() { return sausageHaveAmount; }
	short	getMushroomHaveAmount() { return mushroomHaveAmount; }
	short	getOliveHaveAmount() { return oliveHaveAmount; }
	short	getOnionHaveAmount() { return onionHaveAmount; }
	short	getPrimentHaveAmount() { return primentHaveAmount; }

	void	setIsSauce(bool _isSauce) { isSauce = _isSauce; }
	void	setIsCheese(bool _isCheese) { isCheese = _isCheese; }
	void	setIsPepperoni(bool _isPepperoni) { isPepperoni = _isPepperoni; }
	void	setIsSausage(bool _isSausage) { isSausage = _isSausage; }
	void	setIsMushroom(bool _isMushroom) { isMushroom = _isMushroom; }
	void	setIsOlive(bool _isOlive) { isOlive = _isOlive; }
	void	setIsOnion(bool _isOnion) { isOnion = _isOnion; }
	void	setIsPiment(bool _isPiment) { isPiment = _isPiment; }
	void	setSauceHaveAmount(short _sauceHaveAmount) { sauceHaveAmount = _sauceHaveAmount; }
	void	setCheeseHaveAmount(short _cheeseHaveAmount) { cheeseHaveAmount = _cheeseHaveAmount; }
	void	setPepperoniHaveAmount(short _pepperoniHaveAmount) { pepperoniHaveAmount = _pepperoniHaveAmount; }
	void	setSausageHaveAmount(short _sausageHaveAmount) { sausageHaveAmount = _sausageHaveAmount; }
	void	setMushroomHaveAmount(short _mushroomHaveAmount) { mushroomHaveAmount = _mushroomHaveAmount; }
	void	setOliveHaveAmount(short _oliveHaveAmount) { oliveHaveAmount = _oliveHaveAmount; }
	void	setOnionHaveAmount(short _onionHaveAmount) { onionHaveAmount = _onionHaveAmount; }
	void	setPrimentHaveAmount(short _primentHaveAmount) { primentHaveAmount = _primentHaveAmount; }


	void	setCuttingStartPos(POINT _point) { cuttingStartPos[0] = _point; }
	void	setCuttingEndPos(POINT _point) { cuttingEndPos[0] = _point; }
	void	setCuttingStartPos1(POINT _point) { cuttingStartPos[1] = _point; }
	void	setCuttingEndPos1(POINT _point) { cuttingEndPos[1] = _point; }
	void	setCuttingStartPos2(POINT _point) { cuttingStartPos[2] = _point; }
	void	setCuttingEndPos2(POINT _point) { cuttingEndPos[2] = _point; }
	void	setCuttingStartPos3(POINT _point) { cuttingStartPos[3] = _point; }
	void	setCuttingEndPos3(POINT _point) { cuttingEndPos[3] = _point; }
	void	setCuttingStartPos4(POINT _point) { cuttingStartPos[4] = _point; }
	void	setCuttingEndPos4(POINT _point) { cuttingEndPos[4] = _point; }
};

