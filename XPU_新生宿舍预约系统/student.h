#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"title.h"
#include"orderFile.h"


class Student:public Identity
{
public:
	
	Student();//默认构造函数
	
	Student(int id, string name, string pwd);//有参构造函数
	
	virtual void operMenu();//菜单界面

	void applyOrder();	//申请预约
	
	void showMyOrder();//查看自身预约


	void showAllOrder();//查看所有预约
	
	void cancelOrder();//取消预约

	int m_id;//学号
	vector<ComputerRoom>vCom;
};
