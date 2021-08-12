#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"title.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"


class Manager :public Identity
{
public:
	Manager();

	Manager(string name ,string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerson();//�鿴�˺�

	void showComputer();

	void clearFile();//���ԤԼ��¼

	//��ʼ������
	void initVector();

	//����ظ� ��ѧ�Ż���ְ���� ����2 �������
	bool checkRepeat(int id,int type);

	vector<Student>vStu;
	vector<Teacher>vTea;

	vector<ComputerRoom>vCom;//������Ϣ����
};