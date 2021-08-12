#include"orderFile.h"


OrderFile::OrderFile()
{
	ifstream ifs(ORDER_FILE, ios::in);

	string level;
	string direction;
	string stuId;
	string stuName;
	string roomID;
	string status;

	this->m_Size = 0;
	while (ifs >> level && ifs >> direction && ifs >> stuId && ifs >> stuName && ifs >> roomID && ifs >> status)
	{
		/*cout << date << endl;
		cout << time << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		cout << endl;*/

		//date ：1
		string key;
		string value;
		map<string, string>m;

		int pos = level.find(":");//4
		if (pos != -1)
		{
			key = level.substr(0, pos);
			value = level.substr(pos + 1, level.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取字符串
		pos = direction.find(":");//4
		if (pos != -1)
		{
			key = direction.substr(0, pos);
			value = direction.substr(pos + 1, direction.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");//4
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");//4
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = roomID.find(":");//4
		if (pos != -1)
		{
			key = roomID.substr(0, pos);
			value = roomID.substr(pos + 1, roomID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");//4
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;

	}
	ifs.close();
}
//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "level" << this->m_orderData[i]["level"] << " ";
		ofs << "direction" << this->m_orderData[i]["direction"] << " ";
		ofs << "stuId" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomID" << this->m_orderData[i]["roomID"] << " ";
		ofs << "status" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}