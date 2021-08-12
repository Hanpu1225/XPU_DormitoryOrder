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
	cout << "=============��ӭ��ʦ"<<this->m_Name<<"��¼ϵͳ============"
		<< endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|              1���鿴����ԤԼ        |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              2���������ԤԼ         |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|              0��ע �� �� ¼          |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "����������ѡ��";
}

void Teacher::showAllOrder()
{
	OrderFile order;
	if (order.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < order.m_Size; i++)
	{
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
//�������ԤԼ
void Teacher::checkOrder()
{
	OrderFile order;
	if (order.m_Size == 0)//ԤԼ������
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 0;
	cout << "����˵�ԤԼ��¼���£�" << endl;
	for (int i = 0; i < order.m_Size; i++)
	{
		if (order.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ¥�㣺" << order.m_orderData[i]["level"] << "��";
			cout << " ���᣺" << order.m_orderData[i]["roomID"] << "������";
			cout << " ����λ�ã�" << (order.m_orderData[i]["direction"] == "1" ? "����" : "����");
			cout << " ѧ�ţ�" << order.m_orderData[i]["stuId"];
			cout << " ������" << order.m_orderData[i]["stuName"];
			string status = " ״̬: ";
			status += "�����";
			cout << status << endl;
		}
	}

	cout << "��������˵�ԤԼ��¼,0������" << endl;
	int select = 0;//�����û�ѡ���ԤԼ��¼
	int ret = 0;//����ԤԼ�����¼

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
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					order.m_orderData[v[select - 1]]["status"] = "2";//ͨ��
				}
				else
				{
					order.m_orderData[v[select - 1]]["status"] = "-1";//��ͨ��
				}
				order.updateOrder();
				cout << "������Ŷ" << endl;;
				break;
			}
		}
		cout << "��Ч����,����������";
	}
	system("pause");
	system("cls");
}