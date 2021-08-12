#pragma once

/*建立一个身份类，用于管理三种身份，
1、每个身份都需要有姓名和密码
2、每个身份都有有对应自己的菜单，在菜单中可以实现对应的功能，用纯虚函数实现
3、在子类中必须要重写纯虚函数，否则就不能实例化对象
*/
#include<iostream>
using namespace std;

class Identity
{
public:
	virtual void operMenu()=0;//操作的菜单
	//用户名
	string m_Name;
	string m_Pwd;

};