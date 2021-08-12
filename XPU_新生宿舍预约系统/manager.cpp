#include"manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs>>com.m_ComId && ifs>> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为: " << vCom.size() << endl;
}

void Manager::operMenu()
{
	cout << "\t\t=========欢迎管理员"<<this->m_Name<<"登录系统========"
		<< endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              1、添加不同账号        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              2、查看所有账号        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              3、查看宿舍余额        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              4、清空所有预约        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              0、注 销 登 录         |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "请输入您的选择：";
}

void Manager::addPerson()
{
	cout << "请输入您要添加账号类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;//操作文件名
	string errorTip;//错误提示


	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号:";
		errorTip = "学号重复,请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号:";
		errorTip = "职工编号重复,请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret= checkRepeat(id, select);
		if (ret==true)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名:" << endl;
	cin >> name;

	cout << "请输入密码:" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
	//调用初始化容器的接口，重新获取文件中的数据
	this->initVector();
}

void printStu(Student &s)
{
	cout << "学号: " << s.m_id << " 姓名: " << s.m_Name << " 密码: " << s.m_Pwd << endl;
}

void printTea(Teacher &t)
{
	cout << "职工编号: " << t.m_EmpId << "姓名: " << t.m_Name << "密码: " << t.m_Pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看的内容" << endl;
	cout << "1、查看学生信息" << endl;
	cout << "2、查看老师信息" << endl;

	int select = 0;
	cin >> select;

	if (select==1)
	{
		cout << "所有学生信息如下:" << endl;
		for_each(vStu.begin(), vStu.end(),printStu);
	}
	else
	{
		cout << "所有老师信息如下:" << endl;
		for_each(vStu.begin(), vStu.end(), printStu);
	}

	system("pause");
	system("cls");

}
//查看楼层信息
void Manager::showComputer()
{
	cout << "宿舍信息如下:" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it!=vCom.end(); it++)
	{
		cout << "宿舍楼层: " << it->m_ComId << "  该楼层目前剩余为: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::clearFile()
{
	cout << "您确定要将所有预约记录清空吗 ？" << endl;
	cout << "1、确定" << endl;
	cout << "2、取消" << endl;
	int select = 0;
	
	while (true)
	{
	   cin >> select;
	   if (select != 1 && select != 2)
	   {
		   cout << "您的输入有误,请重新输入!" << endl;
	   }
	   else
	   {
		   break;
	   }
	}
	
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}


void Manager::initVector()
{
	//读取信息 学生 老师

	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs>>s.m_id && ifs>>s.m_Name && ifs>>s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生的数量为:"<< vStu.size() << endl;
	ifs.close();

	//读取老师的信息

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs>>t.m_EmpId && ifs>>t.m_Name && ifs>>t.m_Pwd)
	{
		vTea.push_back(t);
	}

	cout << "当前老师的数量为:" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type==1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}