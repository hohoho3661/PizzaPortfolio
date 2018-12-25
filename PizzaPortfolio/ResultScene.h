#pragma once

class UI;

class ResultScene : public GameNode
{
	Image*	resultImg;

	RECT	okeyButton;

	UI*		userInterface;

	int		totalRevenue;	// ��ü����
	int		tip;			// ��
	int		rent;			// �Ӵ��
	int		refund;			// ȯ��
	int		toppingCost;	// ��� ��ᰪ
	int		netIncome;		// ������

public:
	ResultScene();
	~ResultScene();

	virtual bool	Init();
	virtual void	Release();
	virtual void	Update();
	virtual void	Render(HDC hdc);
};

