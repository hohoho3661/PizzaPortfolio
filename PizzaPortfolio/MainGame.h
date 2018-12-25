#pragma once
#include "GameNode.h"


class MainGame : public GameNode
{
private:
	RECT	clientRect;
	POINT	p1, p2;


	//
	Image*	pauseImg;
	Image*	pauseBlindImg;
	RECT	pauseButton;
	RECT	resumeButton;
	bool	isPause;
public:
	MainGame();
	virtual ~MainGame();
	//==========================================
	

	//==========================================
	virtual bool	Init();
	virtual void	Release();
	virtual void	Update();
	virtual void	Render(HDC hdc);

	void			CursorCase(); // 마우스 커서를 가둬보자
};