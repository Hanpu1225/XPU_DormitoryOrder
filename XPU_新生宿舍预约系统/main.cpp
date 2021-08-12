#include<iostream>
#include<windows.h>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"title.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

void teacherMenu(Identity* &teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)//查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->checkOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

void studentMenu(Identity* &student)
{
	while (true)
	{
		student->operMenu();
		//子类对象指向父类指针
		Student *stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//进入管理员子菜单
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针转为子类指针 调用子类其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		
		if (select == 1)
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select==3)
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			//cout << "清空预约" << endl;
			man->clearFile();
		}
		else//注销
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录
void LoginIn(string fileName, int type)
{
	Identity *person = NULL;//父类指针，指向子类对象

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())//如果文件不存在就退出
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号:" << endl;
		cin >> id;
	}

	cout << "请输入用户名: " << endl;
	cin >> name;

	cout << "请输入密码: " << endl;
	cin >> pwd;

	if (type == 1)
	{
		int fId;
		string fName;
		string fPwd;

		while (ifs>>fId && ifs>>fName && ifs>>fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				//进入学生子菜单
				studentMenu(person);
				return;
				
			}
		}
	}
	else if (type==2)
	{
		int fempId;
		string fName;
		string fPwd;
		while (ifs >> fempId && ifs >> fName && ifs >> fPwd)
		{
			if (fempId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师子菜单
				teacherMenu(person);
				return;	
			}
		}
		
	}
	else if(type == 3)
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs>> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员子菜单界面
				managerMenu(person);
				return;
			}
		}
	}
    cout << "验证登录失败!!!" << endl;
	system("pause");
	system("cls");
	return;
	
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "=============欢迎来到XPU新生宿舍预约系统==========="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------------\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|              1、学    生            |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|              2、老    师            |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|              3、管 理 员            |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|              0、退出系统            |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|----------------版本v1.1-------------|\n";
		cout << "\t\t|-------------开发人员:HanPu----------|\n";
		cout << "\t\t|-------------------------------------|\n";
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 1://学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎您下次使用!" << endl;
			cout << "正在退出..." << endl;
			Sleep(300);
			exit(0);
			break;
		default://输入有误
			cout << "您的输入有误，请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	
	system("pause");
	return 0;

}