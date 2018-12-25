#pragma once



class Guest
{
	Image*	guestImg;
	Image*	textBox;


	RECT	textBoxRC;

	RECT	okeyButton;
	RECT	repeatButton;


	OrderList	selectedOrder;
	int			orderIndex;	// 오더리스트중에 어느것을 받을지 랜덤값을 받을 변수

	OrderList	order1;
	OrderList	order2;
	OrderList	order3;
	OrderList	order4;
	OrderList	order5;


	int		guestIndex; // 손님이미지값을 설정하기위한 랜덤값을 받을 변수
	short	guestAlphaIndex;

	bool	isComplete; // 계산완료인지 여부를 Restaurant씬에서 받아올 변수
	bool	isRepeat; // [네?]버튼을 눌렀는지 확인용
public:
	Guest();
	~Guest();
	
	void DisapperGuest();

	bool Init(short _alphaIndex, bool _isComplete);
	void Release();
	void Update(short _alphaIndex, bool _isComplete);
	void Render(HDC hdc);

	void OrderSetting();

	bool GetIsRepeat() { return isRepeat; }
	void SetIsRepeat(bool _isRepeat) { isRepeat = _isRepeat; }


	void SetSelectOrderStr(string _SelectOrderStr) { selectedOrder.str = _SelectOrderStr; } // 피자를 받고나서 손님이 할말

	OrderList GetSelectedOrder() { return selectedOrder; }
};

