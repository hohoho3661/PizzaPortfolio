#pragma once

// 매크로

#define PI				3.141592
#define PI2				PI*2
#define COLOR_M			RGB(255,0,255)

#define CAMERA_SPEED	10 // 인게임 화면에서 마우스 커서가 클라이언트 가장자리로 갔을때,, 카메라가 움직이는 속도

#define STARTPIZZAPOSITIONX	490
#define STARTPIZZAPOSITIONY	410
#define PIZZA_SIZE			280

// 초기세팅
#define START_MONEY			50000
#define SAUCE_COST			10
#define CHEESE_COST			20
#define PEPPERONI_COST		300
#define SAUSAGE_COST		300
#define MUSHROOM_COST		500
#define OLIVE_COST			300
#define ONION_COST			100
#define PIMENT_COST			200

#define DOUGH_COST			5000

#define RENT_COST			10000




// ============== 두가지 문자셋을 안전하게 디파인? ( 유니코드, 멀티바이팅 ) =======================
#if defined(_UNICODE)
	typedef std::wstring	tstring;	//std::basic_string<wchar>
#else
	typedef std::string		tstring;	//std::basic_string<char>
#endif // #if defined(_UNICODE)




// 메모리 해제 매크로
// Backbuffer
#define SAFE_DELETE(p)	{if(p) {delete(p);(p) = NULL;}}
#define SAFE_RELEASE(p)	{if(p) {(p)->Release(); (p) = NULL;}}

// 윈도우 사이즈 관련 매크로
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define WINSIZEX	1200
#define WINSIZEY	675
#define WINSTARTX	0
#define WINSTARTY	0

// 싱글턴 객체 매크로
#define RAND			RandomFunction::getSingleton()
#define CAMERA			Camera::getSingleton()

#define IMAGEMANAGER	ImageManager::getSingleton()
#define KEYMANAGER		KeyManager::getSingleton()
#define TIMEMANAGER		TimeManager::getSingleton()
#define EFFECTMANAGER	EffectManager::getSingleton()
#define SCENEMANAGER	SceneManager::getSingleton()
#define SOUNDMANAGER	SoundManager::getSingleton()
#define TXTDATA			TextData::getSingleton()
#define ANIMANAGER		AniManager::getSingleton()

//
#define GAMEINFO		GameInfo::getSingleton()