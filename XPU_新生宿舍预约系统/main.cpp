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
		if (select == 1)//�鿴����ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2)//���ԤԼ
		{
			tea->checkOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
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
		//�������ָ����ָ��
		Student *stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//�������Ա�Ӳ˵�
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		//������ָ��תΪ����ָ�� �������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		
		if (select == 1)
		{
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select==3)
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			//cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else//ע��
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼
void LoginIn(string fileName, int type)
{
	Identity *person = NULL;//����ָ�룬ָ���������

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())//����ļ������ھ��˳�
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����:" << endl;
		cin >> id;
	}

	cout << "�������û���: " << endl;
	cin >> name;

	cout << "����������: " << endl;
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
				cout << "ѧ����¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				//����ѧ���Ӳ˵�
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
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
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
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�����
				managerMenu(person);
				return;
			}
		}
	}
    cout << "��֤��¼ʧ��!!!" << endl;
	system("pause");
	system("cls");
	return;
	
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "=============��ӭ����XPU��������ԤԼϵͳ==========="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------------\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|              1��ѧ    ��            |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|              2����    ʦ            |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|              3���� �� Ա            |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|              0���˳�ϵͳ            |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|----------------�汾v1.1-------------|\n";
		cout << "\t\t|-------------������Ա:HanPu----------|\n";
		cout << "\t\t|-------------------------------------|\n";
		cout << "����������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ���´�ʹ��!" << endl;
			cout << "�����˳�..." << endl;
			Sleep(300);
			exit(0);
			break;
		default://��������
			cout << "����������������������!" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	
	system("pause");
	return 0;

}