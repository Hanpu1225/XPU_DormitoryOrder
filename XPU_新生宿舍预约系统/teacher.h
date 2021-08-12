#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include"orderFile.h"
#include<vector>

class Teacher:public Identity
{
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void checkOrder();

	int m_EmpId;
};