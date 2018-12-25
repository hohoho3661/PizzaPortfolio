#include "stdafx.h"
#include "GameInfo.h"
#include "UI.h"


GameInfo::GameInfo()
{
	isPizza = false;

	// 파싱한 데이터 넣기
	for (int i = 0; i < HOW_MANY_ORDER; i++)
	{
		order[i] = OrderListParsing(i+1);
	}

	// 피자Info 초기 정보
	isSauce = false;
	isCheese = false;
	isPepperoni = false;
	isSausage = false;
	isMushroom = false;
	isOlive = false;
	isOnion = false;
	isPiment = false;

	sauceHaveAmount = 0;
	cheeseHaveAmount = 0;
	pepperoniHaveAmount = 0;
	sausageHaveAmount = 0;
	mushroomHaveAmount = 0;
	oliveHaveAmount = 0;
	onionHaveAmount = 0;
	primentHaveAmount = 0;
	howMuchPizza = 0;

	// 결과창
	totalRevenue = 0;
	tip = 0;
	refund = 0;
	toppingCost = 0;

	//
	userInterface = new UI;
	userInterface->Init();
}


GameInfo::~GameInfo()
{
}

OrderList GameInfo::OrderListParsing(int _index)
{
	OrderList orderList;

	// 파일 열고
	std::ifstream inFile(TEXT("OrderListTextFile.txt"));	

	queue<string> q_data;
	string sBuffer;
	string textString;

	int iIndex = 0;

	// 이미열려있는지 확인하고
	if (!inFile.is_open())
	{
		std::cout << "File is Not Read" << std::endl;
	}

	// 파일읽어오기
	while (getline(inFile, sBuffer))
	{
		q_data.push(sBuffer); // 큐에넣기
	}

	// 파일닫고
	inFile.close();


	// ==================================================
	string sRecord;
	string token;


	// 큐 데이터 pop
	q_data.pop();

	int a = 1;

	while (!(q_data.empty()) && a <= _index) // 비어있는지 확인하고 반복문돌림
	{
		// 큐에 들어가있는 첫번째 string을 
		sRecord = q_data.front().substr(0, q_data.front().size()); // substr : 문자열의 일부분을 문자열로 반환 ( 시작위치 (0부터), 개수 )
		
		// orderList.str
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.str = textString;
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		// orderList.strAgain
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.strAgain = textString;
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		// 소스여부
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isSauce = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 치즈여부
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isCheese = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 페퍼로니여부
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isPepperoni = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 소세지여부
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isSausage = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 버섯여부
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isMushroom = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 올리브여부
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isOlive = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 양파여부
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isOnion = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 피망여부
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isPiment = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		
		// 소스량
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.sauceWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 치즈량
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.cheeseWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 페퍼로니량
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.pepperoniWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 소세지량
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.sausageWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 버섯량
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.mushroomWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 올리브량
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.oliveWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 양파량
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.oliveWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 피망량
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.primentWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// 피자가격
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.howMuchPizza = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		//
		a++;
		q_data.pop();
	}

	return orderList;
}
