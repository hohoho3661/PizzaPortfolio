#pragma once

// ����������� �� ���� ������ ��.

class Button;

class StartScene : public GameNode
{
	Image*	startBackImg;
	Button*	pButton;

	int		nCount;
	int		colorTurnIndex;
	int		indexBlend;

public:
	StartScene();
	~StartScene();

	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	static void cbSceneChange();
};