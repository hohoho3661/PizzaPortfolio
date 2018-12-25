#pragma once



class Guest
{
	Image*	guestImg;
	Image*	textBox;


	RECT	textBoxRC;

	RECT	okeyButton;
	RECT	repeatButton;


	OrderList	selectedOrder;
	int			orderIndex;	// ��������Ʈ�߿� ������� ������ �������� ���� ����

	OrderList	order1;
	OrderList	order2;
	OrderList	order3;
	OrderList	order4;
	OrderList	order5;


	int		guestIndex; // �մ��̹������� �����ϱ����� �������� ���� ����
	short	guestAlphaIndex;

	bool	isComplete; // ���Ϸ����� ���θ� Restaurant������ �޾ƿ� ����
	bool	isRepeat; // [��?]��ư�� �������� Ȯ�ο�
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


	void SetSelectOrderStr(string _SelectOrderStr) { selectedOrder.str = _SelectOrderStr; } // ���ڸ� �ް��� �մ��� �Ҹ�

	OrderList GetSelectedOrder() { return selectedOrder; }
};

