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

	void showPerson();//查看账号

	void showComputer();

	void clearFile();//清空预约记录

	//初始化容器
	void initVector();

	//检测重复 ，学号或者职工号 参数2 检测类型
	bool checkRepeat(int id,int type);

	vector<Student>vStu;
	vector<Teacher>vTea;

	vector<ComputerRoom>vCom;//机房信息容器
};