#pragma once

class UI;

class ShopScene : public GameNode
{
	Image*	shopImg;

	Image*	checkImg;

	RECT	dailyStatisticsButton;
	RECT	nextDayButton;


	RECT	sausageBuyBox;
	RECT	mushroomBuyBox;
	RECT	oliveBuyBox;
	RECT	onionBuyBox;
	RECT	pimentBuyBox;


	UI*			userInterface;
public:
	ShopScene();
	~ShopScene();

	virtual bool	Init();
	virtual void	Release();
	virtual void	Update();
	virtual void	Render(HDC hdc);
};

