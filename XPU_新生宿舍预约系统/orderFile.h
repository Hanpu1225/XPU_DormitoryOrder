#pragma once
#include<iostream>
using namespace std;
#include"title.h"
#include<fstream>
#include<map>
#include<string>

class OrderFile
{
public:
	OrderFile();

	void updateOrder();//����ԤԼ��¼

	int m_Size;//��ȡԤԼ��¼������

	map<int, map<string, string>>m_orderData;//���� ��ֵ��
};
