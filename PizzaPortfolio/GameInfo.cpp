#include "stdafx.h"
#include "GameInfo.h"
#include "UI.h"


GameInfo::GameInfo()
{
	isPizza = false;

	// �Ľ��� ������ �ֱ�
	for (int i = 0; i < HOW_MANY_ORDER; i++)
	{
		order[i] = OrderListParsing(i+1);
	}

	// ����Info �ʱ� ����
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

	// ���â
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

	// ���� ����
	std::ifstream inFile(TEXT("OrderListTextFile.txt"));	

	queue<string> q_data;
	string sBuffer;
	string textString;

	int iIndex = 0;

	// �̹̿����ִ��� Ȯ���ϰ�
	if (!inFile.is_open())
	{
		std::cout << "File is Not Read" << std::endl;
	}

	// �����о����
	while (getline(inFile, sBuffer))
	{
		q_data.push(sBuffer); // ť���ֱ�
	}

	// ���ϴݰ�
	inFile.close();


	// ==================================================
	string sRecord;
	string token;


	// ť ������ pop
	q_data.pop();

	int a = 1;

	while (!(q_data.empty()) && a <= _index) // ����ִ��� Ȯ���ϰ� �ݺ�������
	{
		// ť�� ���ִ� ù��° string�� 
		sRecord = q_data.front().substr(0, q_data.front().size()); // substr : ���ڿ��� �Ϻκ��� ���ڿ��� ��ȯ ( ������ġ (0����), ���� )
		
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

		// �ҽ�����
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isSauce = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// ġ���
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isCheese = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// ���۷δϿ���
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isPepperoni = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// �Ҽ�������
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isSausage = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// ��������
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isMushroom = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// �ø��꿩��
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isOlive = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// ���Ŀ���
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isOnion = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// �Ǹ�����
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.isPiment = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		
		// �ҽ���
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.sauceWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// ġ�
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.cheeseWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// ���۷δϷ�
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.pepperoniWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// �Ҽ�����
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.sausageWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// ������
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.mushroomWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// �ø��귮
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.oliveWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// ���ķ�
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.oliveWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// �Ǹ���
		iIndex = sRecord.find(";");
		textString = sRecord.substr(0, iIndex);
		orderList.primentWantAmount = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		// ���ڰ���
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
