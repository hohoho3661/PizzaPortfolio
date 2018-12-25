#pragma once

class UI;

class ResultScene : public GameNode
{
	Image*	resultImg;

	RECT	okeyButton;

	UI*		userInterface;

	int		totalRevenue;	// 전체수익
	int		tip;			// 팁
	int		rent;			// 임대료
	int		refund;			// 환불
	int		toppingCost;	// 사용 재료값
	int		netIncome;		// 순수익

public:
	ResultScene();
	~ResultScene();

	virtual bool	Init();
	virtual void	Release();
	virtual void	Update();
	virtual void	Render(HDC hdc);
};

