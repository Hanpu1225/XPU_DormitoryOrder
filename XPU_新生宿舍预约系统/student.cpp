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
		//����ȡ����Ϣ����������
		vCom.push_back(c);
	}
	ifs.close();

}

void Student::operMenu()
{
	cout << "\t\t=========��ӭѧ��"<<this->m_Name<<"��¼ϵͳ========"
		<< endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              1������ԤԼ����        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              2���鿴�ҵ�ԤԼ        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              3���鿴����ԤԼ        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              4��ȡ������ԤԼ        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              0��ע �� �� ¼         |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "����������ѡ��";
}

void Student::applyOrder()
{
	//cout << "��������ʱ��Ϊ��һ������!" << endl;
	cout << "����һ��������,����" << endl;
	cout << "3-4��Ϊ1500Ԫ/��" << endl;
	cout << "1-2��Ϊ1200Ԫ/��" << endl;
	cout << "5-6��Ϊ1000Ԫ/��" << endl;
	cout << "����ѡ��ҪԤԼ��¥��: " << endl;
	cout << "1��3-4��" << endl;
	cout << "2��1-2��" << endl;
	cout << "3��5-6��" << endl;

	int level = 0;
	while (true)
	{
		cin >> level;
		if (level >= 1 && level <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "����ѡ���������᣺" << endl;
	cout << "1����������Ϊ��" << vCom[0].m_MaxNum << endl;
	cout << "2����������Ϊ��" << vCom[1].m_MaxNum << endl;
	cout << "3����������Ϊ��" << vCom[2].m_MaxNum << endl;

	int room = 0;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��������Ҫ���봲�̵�λ�ã�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	int direction = 0;
	while (true)
	{
		cin >> direction;
		if (direction >= 1 && direction <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;
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
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < order.m_Size; i++)
	{
		if (this->m_id == atoi(order.m_orderData[i]["stuId"].c_str()))//�ҵ��������ԤԼ
		{
			cout << "ԤԼ¥�㣺" << order.m_orderData[i]["level"]<<"��";
			cout << " ����λ�ã�" << (order.m_orderData[i]["direction"] == "1" ? "����" : "����");
			cout << " ���᣺" << order.m_orderData[i]["roomID"]<<"������";//m_orderData[i]["roomId"]
			string status = " ״̬: ";
			if (order.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (order.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (order.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��,���δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
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
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < order.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ¥�㣺" << order.m_orderData[i]["level"] << "��";
		cout << " ���᣺" << order.m_orderData[i]["roomID"] << "������";
		cout << " ����λ�ã�" << (order.m_orderData[i]["direction"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << order.m_orderData[i]["stuId"];
		cout << " ������" << order.m_orderData[i]["stuName"];

		string status = " ״̬: ";
		if (order.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (order.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (order.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��,���δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
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
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼�ǿ���ȡ����,������ȡ���ļ�¼." << endl;
	vector<int>v;//�������������е��±���
	int index = 1;
	for (int i = 0; i < order.m_Size; i++)
	{
		if (this->m_id == atoi(order.m_orderData[i]["stuId"].c_str()))
		{
			//��ɸѡ״̬
			if (order.m_orderData[i]["status"] == "1" || order.m_orderData[i]["status"] =="2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ¥�㣺" << order.m_orderData[i]["level"] << "��";
				cout << " ����λ�ã�" << (order.m_orderData[i]["direction"] == "1" ? "����" : "����");
				cout << " ���᣺" << order.m_orderData[i]["roomID"] << "������";

				string status = " ״̬: ";
				if (order.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (order.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼,0������:" << endl;
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
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "��������,����������" << endl;
	}
	system("pause");
	system("cls");
}

