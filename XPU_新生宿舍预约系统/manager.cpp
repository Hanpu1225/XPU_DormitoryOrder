#include"manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs>>com.m_ComId && ifs>> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ: " << vCom.size() << endl;
}

void Manager::operMenu()
{
	cout << "\t\t=========��ӭ����Ա"<<this->m_Name<<"��¼ϵͳ========"
		<< endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              1����Ӳ�ͬ�˺�        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              2���鿴�����˺�        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              3���鿴�������        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              4���������ԤԼ        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              0��ע �� �� ¼         |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "����������ѡ��";
}

void Manager::addPerson()
{
	cout << "��������Ҫ����˺�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;//�����ļ���
	string errorTip;//������ʾ


	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
		errorTip = "ѧ���ظ�,����������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ�����:";
		errorTip = "ְ������ظ�,����������";
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

	cout << "����������:" << endl;
	cin >> name;

	cout << "����������:" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
	//���ó�ʼ�������Ľӿڣ����»�ȡ�ļ��е�����
	this->initVector();
}

void printStu(Student &s)
{
	cout << "ѧ��: " << s.m_id << " ����: " << s.m_Name << " ����: " << s.m_Pwd << endl;
}

void printTea(Teacher &t)
{
	cout << "ְ�����: " << t.m_EmpId << "����: " << t.m_Name << "����: " << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴������" << endl;
	cout << "1���鿴ѧ����Ϣ" << endl;
	cout << "2���鿴��ʦ��Ϣ" << endl;

	int select = 0;
	cin >> select;

	if (select==1)
	{
		cout << "����ѧ����Ϣ����:" << endl;
		for_each(vStu.begin(), vStu.end(),printStu);
	}
	else
	{
		cout << "������ʦ��Ϣ����:" << endl;
		for_each(vStu.begin(), vStu.end(), printStu);
	}

	system("pause");
	system("cls");

}
//�鿴¥����Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ����:" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it!=vCom.end(); it++)
	{
		cout << "����¥��: " << it->m_ComId << "  ��¥��Ŀǰʣ��Ϊ: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::clearFile()
{
	cout << "��ȷ��Ҫ������ԤԼ��¼����� ��" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
	int select = 0;
	
	while (true)
	{
	   cin >> select;
	   if (select != 1 && select != 2)
	   {
		   cout << "������������,����������!" << endl;
	   }
	   else
	   {
		   break;
	   }
	}
	
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}


void Manager::initVector()
{
	//��ȡ��Ϣ ѧ�� ��ʦ

	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs>>s.m_id && ifs>>s.m_Name && ifs>>s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ:"<< vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ����Ϣ

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs>>t.m_EmpId && ifs>>t.m_Name && ifs>>t.m_Pwd)
	{
		vTea.push_back(t);
	}

	cout << "��ǰ��ʦ������Ϊ:" << vTea.size() << endl;
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