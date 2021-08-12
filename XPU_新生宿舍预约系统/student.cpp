#include"student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_Name = name;
	m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs>>c.m_ComId && ifs>>c.m_MaxNum)
	{
		//将读取的信息放在容器中
		vCom.push_back(c);
	}
	ifs.close();

}

void Student::operMenu()
{
	cout << "\t\t=========欢迎学生"<<this->m_Name<<"登录系统========"
		<< endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              1、申请预约宿舍        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              2、查看我的预约        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              3、查看所有预约        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              4、取消自身预约        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              0、注 销 登 录         |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "请输入您的选择：";
}

void Student::applyOrder()
{
	//cout << "机房开放时间为周一至周五!" << endl;
	cout << "宿舍一共有六层,其中" << endl;
	cout << "3-4层为1500元/年" << endl;
	cout << "1-2层为1200元/年" << endl;
	cout << "5-6层为1000元/年" << endl;
	cout << "请您选择将要预约的楼层: " << endl;
	cout << "1、3-4层" << endl;
	cout << "2、1-2层" << endl;
	cout << "3、5-6层" << endl;

	int level = 0;
	while (true)
	{
		cin >> level;
		if (level >= 1 && level <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请您选择具体的宿舍：" << endl;
	cout << "1号宿舍容量为：" << vCom[0].m_MaxNum << endl;
	cout << "2号宿舍容量为：" << vCom[1].m_MaxNum << endl;
	cout << "3号宿舍容量为：" << vCom[2].m_MaxNum << endl;

	int room = 0;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请您输入要申请床铺的位置：" << endl;
	cout << "1、上铺" << endl;
	cout << "2、下铺" << endl;

	int direction = 0;
	while (true)
	{
		cin >> direction;
		if (direction >= 1 && direction <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "level:" << level << " ";
	ofs << "direction:" << direction << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomID:" << room << " ";
	ofs << "status:" << 1 << " ";
	ofs << endl;

	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile order;
	if (order.m_Size==0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < order.m_Size; i++)
	{
		if (this->m_id == atoi(order.m_orderData[i]["stuId"].c_str()))//找到了自身的预约
		{
			cout << "预约楼层：" << order.m_orderData[i]["level"]<<"层";
			cout << " 宿舍位置：" << (order.m_orderData[i]["direction"] == "1" ? "上铺" : "下铺");
			cout << " 宿舍：" << order.m_orderData[i]["roomID"]<<"号宿舍";//m_orderData[i]["roomId"]
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
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile order;
	if (order.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < order.m_Size; i++)
	{
		cout << i + 1 << "、";
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

void Student::cancelOrder()
{
	OrderFile order;
	if (order.m_Size==0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录是可以取消的,请输入取消的记录." << endl;
	vector<int>v;//存放在最大容器中的下标编号
	int index = 1;
	for (int i = 0; i < order.m_Size; i++)
	{
		if (this->m_id == atoi(order.m_orderData[i]["stuId"].c_str()))
		{
			//再筛选状态
			if (order.m_orderData[i]["status"] == "1" || order.m_orderData[i]["status"] =="2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约楼层：" << order.m_orderData[i]["level"] << "层";
				cout << " 宿舍位置：" << (order.m_orderData[i]["direction"] == "1" ? "上铺" : "下铺");
				cout << " 宿舍：" << order.m_orderData[i]["roomID"] << "号宿舍";

				string status = " 状态: ";
				if (order.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (order.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录,0代表返回:" << endl;
	int select = 0;
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
				order.m_orderData[v[select - 1]]["status"] = "0";
				order.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误,请重新输入" << endl;
	}
	system("pause");
	system("cls");
}

