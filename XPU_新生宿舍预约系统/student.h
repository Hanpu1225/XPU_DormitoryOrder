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
	
	Student();//Ĭ�Ϲ��캯��
	
	Student(int id, string name, string pwd);//�вι��캯��
	
	virtual void operMenu();//�˵�����

	void applyOrder();	//����ԤԼ
	
	void showMyOrder();//�鿴����ԤԼ


	void showAllOrder();//�鿴����ԤԼ
	
	void cancelOrder();//ȡ��ԤԼ

	int m_id;//ѧ��
	vector<ComputerRoom>vCom;
};
