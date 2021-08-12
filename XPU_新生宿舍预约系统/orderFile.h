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

	void updateOrder();//更新预约记录

	int m_Size;//读取预约记录的条数

	map<int, map<string, string>>m_orderData;//条数 键值对
};
