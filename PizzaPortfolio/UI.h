#pragma once

// ~��°, ~pm(�ð�), ������(%), �ֹ���(�丮�ǿ����� Ŭ������ - Ŭ���ϸ� �ֹ�����������)
// ��


class UI
{
	Image*	ui;
	int		whatDay;
	int		whatTime;
	int		whatMinute;
	int		timeIndex;

	int		happiness;

	int		money;	
public:
	UI();
	~UI();

	bool Init();
	void Update();
	void Render(HDC hdc);

	int GetHappiness() { return happiness; }
	void SetHappiness(int _happiness) { happiness = _happiness; }

	int GetMoney() { return money; }
	void SetMoney(int _money) { money = _money; }

	int GetTime() { return whatTime; }
	void SetTime(int _whatTime) { whatTime = _whatTime; }

	int GetDay() { return whatDay; }
	void SetDay(int _whatDay) { whatDay = _whatDay; }
};

