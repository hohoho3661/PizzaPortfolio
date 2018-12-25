#pragma once

class UI;
class Pizza;

struct ImageAndRect
{
	Image*	img;
	bool	isExist;
	RECT	rect;
};


class CookingRoomScene : public GameNode
{
	// �⺻ ī�޶� ����
	RECT			rcWorldSize;	// ��ü ũ��
	RECT			rcClientSize;	// Ŭ���̾�Ʈ ũ��
	POINT			pt;			// �� ���� �������� ī�޶� �̵�

	// ���
	Image*			backGround; // ȭ�� ���
	
	// ����(+����)
	Image*			ovenImg;
	Image*			ovenRailImg;
	float			railX;		// ���췹���� ���� X��
	RECT			rcOvenRail;
	float			ovenRailStartX; // ������ ���ڸ����� ���� ���ִ� ���ذ�
	bool			isRail; // �������� ���ڰ��ִ��� Ȯ�ο� bool
	RECT			ovenRC; // ���İ��� �� �κ�
	int				alphaIndex;

	// ���� �ڽ��� ��ºκ�
	RECT			pizzaBoxRC;
	int				BoxIndex;

	// ����
	bool			isPizza; // �������� ���ڰ� ���� �ִ��� ������ Ȯ�ο�

	float			doughStartPosX, doughStartPosY;
	ImageAndRect	dough1;
	ImageAndRect	dough2;
	ImageAndRect	dough3;
	ImageAndRect	dough4;
	ImageAndRect	dough5;
	ImageAndRect	dough6;
	ImageAndRect	dough7;
	ImageAndRect	dough8;

	float			toppingBoxStartPosX, toppingBoxStartPosY;
	ImageAndRect	sausageBox;
	ImageAndRect	mushroomBox;
	ImageAndRect	oliveBox;
	ImageAndRect	onionBox;
	ImageAndRect	pimentBox;

	//�ֹ�Ȯ�μ�
	ImageAndRect	orderCheck;
	RECT			orderCheckMiniRect;
	Image*			blackBlendImg;

	// �ҽ�, ġ��, ���۷δϴ� �⺻���� �ִ°Ŷ� ���� �̹����� �Ȼ� (��ü�̹����� �����ִ� �̹���),,,, ��Ʈ�� ������ ������
	RECT			sauceBox;
	RECT			cheeseBox;
	RECT			pepperoniBox;

	Pizza*			pizza;

	//
	ImageAndRect	cuttingKnife; // Ŀ��Į
	float			cuttingKnifePosX; // Ŀ��Į ��ġ

	RECT			cuttingPositionBox; // Ŀ���� ��ġ
	float			cuttingPositionBoxX, cuttingPositionBoxY;

	POINT			cuttingPos, cuttingPosEnd; // �ڸ��� ���۰� ��
	float			cuttingAngle;
	int				cuttingIndex;

	//	
	UI*				userInterface;
	int				happinessIndex;


	// ī�޶� ���� ( Ÿ�� )
	POINT			targetCenterPoint;

		
public:
	CookingRoomScene();
	~CookingRoomScene();

	virtual bool	Init();
	virtual void	Release();
	virtual void	Update();
	virtual void	Render(HDC hdc);

	// ī�޶� �����丵
	bool			CameraInit(); 
	void			CameraMove();

	// �ູ�� �������°�
	void PizzaCuttingUpdate();
	void HappinessDecrease();
	void RectSetting();
	void MakeDough();
	void ToppingSetting();
};