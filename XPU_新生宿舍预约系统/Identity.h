#pragma once

/*����һ������࣬���ڹ���������ݣ�
1��ÿ����ݶ���Ҫ������������
2��ÿ����ݶ����ж�Ӧ�Լ��Ĳ˵����ڲ˵��п���ʵ�ֶ�Ӧ�Ĺ��ܣ��ô��麯��ʵ��
3���������б���Ҫ��д���麯��������Ͳ���ʵ��������
*/
#include<iostream>
using namespace std;

class Identity
{
public:
	virtual void operMenu()=0;//�����Ĳ˵�
	//�û���
	string m_Name;
	string m_Pwd;

};