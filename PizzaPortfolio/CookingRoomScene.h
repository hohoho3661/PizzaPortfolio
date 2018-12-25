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
	// 기본 카메라 설정
	RECT			rcWorldSize;	// 전체 크기
	RECT			rcClientSize;	// 클라이언트 크기
	POINT			pt;			// 이 값을 기준으로 카메라 이동

	// 배경
	Image*			backGround; // 화면 배경
	
	// 오븐(+레일)
	Image*			ovenImg;
	Image*			ovenRailImg;
	float			railX;		// 오븐레일의 시작 X값
	RECT			rcOvenRail;
	float			ovenRailStartX; // 오븐이 제자리에서 돌게 해주는 기준값
	bool			isRail; // 오븐위에 피자가있는지 확인용 bool
	RECT			ovenRC; // 알파값을 줄 부분
	int				alphaIndex;

	// 피자 박스에 담는부분
	RECT			pizzaBoxRC;
	int				BoxIndex;

	// 피자
	bool			isPizza; // 제작중인 피자가 현재 있는지 없는지 확인용

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

	//주문확인서
	ImageAndRect	orderCheck;
	RECT			orderCheckMiniRect;
	Image*			blackBlendImg;

	// 소스, 치즈, 페퍼로니는 기본으로 주는거라서 따로 이미지를 안뺌 (전체이미지에 속해있는 이미지),,,, 렉트만 있으면 오케이
	RECT			sauceBox;
	RECT			cheeseBox;
	RECT			pepperoniBox;

	Pizza*			pizza;

	//
	ImageAndRect	cuttingKnife; // 커팅칼
	float			cuttingKnifePosX; // 커팅칼 위치

	RECT			cuttingPositionBox; // 커팅할 위치
	float			cuttingPositionBoxX, cuttingPositionBoxY;

	POINT			cuttingPos, cuttingPosEnd; // 자를선 시작과 끝
	float			cuttingAngle;
	int				cuttingIndex;

	//	
	UI*				userInterface;
	int				happinessIndex;


	// 카메라 설정 ( 타겟 )
	POINT			targetCenterPoint;

		
public:
	CookingRoomScene();
	~CookingRoomScene();

	virtual bool	Init();
	virtual void	Release();
	virtual void	Update();
	virtual void	Render(HDC hdc);

	// 카메라 리펙토링
	bool			CameraInit(); 
	void			CameraMove();

	// 행복도 떨어지는것
	void PizzaCuttingUpdate();
	void HappinessDecrease();
	void RectSetting();
	void MakeDough();
	void ToppingSetting();
};