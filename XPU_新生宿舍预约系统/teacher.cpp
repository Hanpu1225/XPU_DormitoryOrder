#include"teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

void Teacher::operMenu()
{
	cout << "=============欢迎老师"<<this->m_Name<<"登录系统============"
		<< endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|              1、查看所有预约        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              2、审核所有预约         |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              0、注 销 登 录          |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "请输入您的选择：";
}

void Teacher::showAllOrder()
{
	OrderFile order;
	if (order.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < order.m_Size; i++)
	{
		cout << "预约楼层：" << order.m_orderData[i]["level"] << "层";
		cout << " 宿舍：" << order.m_orderData[i]["roomID"] << "号宿舍";
		cout << " 宿舍位置：" << (order.m_orderData[i]["direction"] == "1" ? "上铺" : "下铺");
		cout << " 学号：" << order.m_orderData[i]["stuId"];
		cout << " 姓名：" << order.m_orderData[i]["stuName"];
		
		string status = " 状态: ";
		if (order.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (order.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (order.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败,审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
}
//审核所有预约
void Teacher::checkOrder()
{
	OrderFile order;
	if (order.m_Size == 0)//预约的条数
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 0;
	cout << "待审核的预约记录如下：" << endl;
	for (int i = 0; i < order.m_Size; i++)
	{
		if (order.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约楼层：" << order.m_orderData[i]["level"] << "层";
			cout << " 宿舍：" << order.m_orderData[i]["roomID"] << "号宿舍";
			cout << " 宿舍位置：" << (order.m_orderData[i]["direction"] == "1" ? "上铺" : "下铺");
			cout << " 学号：" << order.m_orderData[i]["stuId"];
			cout << " 姓名：" << order.m_orderData[i]["stuName"];
			string status = " 状态: ";
			status += "审核中";
			cout << status << endl;
		}
	}

	cout << "请输入审核的预约记录,0代表返回" << endl;
	int select = 0;//接受用户选择的预约记录
	int ret = 0;//接受预约结果记录

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					order.m_orderData[v[select - 1]]["status"] = "2";//通过
				}
				else
				{
					order.m_orderData[v[select - 1]]["status"] = "-1";//不通过
				}
				order.updateOrder();
				cout << "审核完毕哦" << endl;;
				break;
			}
		}
		cout << "无效输入,请重新输入";
	}
	system("pause");
	system("cls");
}