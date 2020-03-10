#include<iostream>
#include"conio.h" 
#include<iomanip> 
#include"stdio.h" 
#include"string.h" 
#include"stdlib.h" 
#include<fstream> 
#include<conio.h> // _getch

using namespace std;

class student //����ѧ���� 
{
private://����ѧ�����˽�г�Ա
	char name[20]; //����
	char sex[5]; //�Ա�
	int number; //ѧ��
	int score[5]; //����
	int total; //�ܷ�
	int average; //ƽ����
public: //���г�Ա
	student(); //ѧ�����캯��������ѧ�����ݵĳ�ʼ��������ѧ������
	void add(); //����ѧ����Ϣ����
	void output(); //���ѧ����Ϣ����
	void find(); //����ѧ�����ݺ���
	void ModifyItem(); //�޸�ѧ����Ϣ����
	void RemoveItemd(); //ɾ��ѧ����Ϣ����
	void sort(); //������
	void save(); //����ѧ����Ϣ��д���ļ�����
	void load(); //��д��ѧ����Ϣ���ļ��ĺ���
	student& operator=(student& T); //���ء�=������
	friend istream& operator >> (istream& scin, student& s1); //���ء�>>������
	friend ostream& operator << (ostream& scout, student& s2); //���ء�>>������
};
student stu[100];
int n = 0;
void student::add() //���Ӻ��� 
{
	char flag = 'Y';
	while (toupper(flag) == 'Y')
	{
		cin >> stu[n];
		n++;
		cout << " Ҫ����������(y/n)";
		cin >> flag;
		if (toupper(flag) != 'Y')
		{
			if (toupper(flag) == 'N')
			{
				break;
			}
			else
			{
				cout << "���������䣺";
				cin >> flag;
			}
		}
	}
}
void student::output() //������� 
{
	if (n != 0)
	{
		cout << " ---------------------------------------------------------------------------\n";
		cout << " number   name  sex    math    C++     English 	physics	 computer	total	average\n";
		cout << " --------------------------------------------------------------------------- \n";
		for (int t = 0; t < n; t++)
		{
			cout << stu[t];
		}
	}
	_getch();
}
void student::find() //���Һ��� 
{
	int f3 = 0;
	char n1[20];
	student temp;
	cout << " ������Ҫ���ҵ��˵�����: ";
	cin >> n1;
	for (int j = 0; j < n; j++)
	{
		if (strcmp(stu[j].name, n1) == 0)
		{
			temp = stu[j];
			f3 = 1;
		}
	}
	if (f3 == 0)
		cout << "�Բ���û����Ҫ���ҵ�ѧ���ɼ�" << endl;

	else
	{
		cout << " ---------------------------------------------------------------------------\n";
		cout << " name number sex math C++ English  physics computer average total\n";
		cout << " --------------------------------------------------------------------------- \n";
		cout << " " << temp.name << " " << temp.number << " " << temp.sex << " " << temp.score[0]
			<< " " << temp.score[1] << " " << temp.score[2] << " " << temp.score[3] << " " << temp.score[4] << " " << temp.total << " " << temp.average << endl;
	}
	_getch();
}
void student::ModifyItem() //�޸ĺ��� 
{
	int f4 = 0;
	int t;
	char n2[50];
	cout << " ������Ҫ�޸ĵ��˵�����:";
	cin >> n2;
	for (int j = 0; j < n; j++)
	{
		if (strcmp(stu[j].name, n2) == 0)
		{
			t = j;
			f4 = 1;
		}
	}
	if (f4 == 0)
		cout << "�Բ���û����Ҫ�޸ĵ�ѧ���ɼ�" << endl;
	else
	{
		cout << " ����: ";
		cin >> stu[t].name;
		cout << "������ѧ��: ";
		cin >> stu[t].number;
		cout << " �Ա� : ";
		cin >> stu[t].sex;
		cout << " ��ѧ�ɼ�: ";
		cin >> stu[t].score[0];
		cout << " C++�ɼ�: ";
		cin >> stu[t].score[1];
		cout << " Ӣ��ɼ�: ";
		cin >> stu[t].score[2];
		cout << " �����ɼ�: ";
		cin >> stu[t].score[3];
		cout << " ��������۳ɼ�: ";
		cin >> stu[t].score[4];
		stu[t].total = stu[t].score[0] + stu[t].score[1] + stu[t].score[2] + stu[t].score[3] + stu[t].score[4];
		stu[t].average = stu[t].total / 3;
		cout << " �޸ĳɹ� !" << endl;
	}
	_getch();
}
void student::RemoveItemd() //ɾ������ 
{
	char n3[20];
	bool f5 = 0;
	char c;
	do {
		cout << "��������Ҫɾ����ѧ��������";
		cin >> n3;
		for (int i = 0; i < n; i++)
		{
			if (strcmp(n3, stu[i].name) == 0)
			{
				f5 = 1;
				n--;
				do {
					stu[i] = stu[i + 1];
					i++;
				} while (i <= n);
			}
		}
		if (f5 == 0)
			cout << "��Ҫ��ɾ���Ķ������Ͳ����ڣ�";
		cout << "Ҫ����ɾ����(y/n)" << endl;
		cin >> c;
		if (toupper(c) != 'Y' && toupper(c) != 'N')
		{
			cout << "����ָ���������������Y��N��" << endl;
			cin >> c;
		}
	} while (toupper(c) == 'Y');
	_getch();
}
void student::sort() //������ 
{
	int i, j, k;
	student s3;
	for (i = 0; i < (n - 1); i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (stu[j].average > stu[i].average)
				k = j;
		if (k != i)
		{
			s3 = stu[i];
			stu[i] = stu[k];
			stu[k] = s3;
		}
	}
	cout << "\n\n����ɹ�!\n\n";

}

void student::save() //���溯�� 
{
	char filename1[20];
	cout << "�������ļ���: ";
	cin >> filename1;
	ofstream fout(filename1, ios::app);
	if (!fout)cout << "�ļ����ܴ�!" << endl;
	else
	{
		for (int i = 0; i < n; i++)
			fout << ' ' << stu[i].name << ' ' << stu[i].number << ' ' << stu[i].sex  << ' '
			<< stu[i].score[0] << ' ' << stu[i].score[1] << ' ' << stu[i].score[2] << ' ' << stu[i].score[3] << ' ' << stu[i].score[4] << ' ' << stu[i].total << ' ' << stu[i].average << ' ';
		cout << "����ɹ�!" << endl;
	}
	fout.close();
	_getch();
}
void student::load() //��ȡ���� 
{
	char filename2[20];
	cout << "��������Ҫ��ȡ���ļ���: ";
	cin >> filename2;
	ifstream fin(filename2, ios::in);
	if (!fin)cout << "�ļ��򲻿� !" << endl;
	else
	{
		for (int i = 0;; i++, n = i - 1)
		{
			if (fin.eof())break;
			fin >> stu[i].name >> stu[i].sex >> stu[i].number
				>> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3] >> stu[i].score[4] >> stu[i].total >> stu[i].average;
		}
		cout << "�ļ��Ѷ�ȡ�ɹ�!" << endl;
	}
	fin.close();
	_getch();
}
student& student::operator=(student& T) //����= 
{
	strcpy_s(name, T.name);
	strcpy_s(sex, T.sex);
	number = T.number;
	for (int i = 0; i < 5; i++)score[i] = T.score[i];
	total = T.total;
	average = T.average;
	return (*this);
}
ostream& operator << (ostream& scout, student& s2) //����<< 
{
	cout << setw(6) << s2.number << setw(10) << s2.name << setw(8) << s2.sex << setw(8) << s2.score[0]
		<< setw(8) << s2.score[1] << setw(10) << s2.score[2] << setw(10) << s2.score[3] << setw(10) << s2.score[4] << setw(10) << s2.total << setw(8) << s2.average << endl;
	return scout;
}
istream& operator >> (istream& scin, student& s1) //����>> 
{
	cout << " \t����:";
	scin >> s1.name;
	cout << " \tѧ��:";
	scin >> s1.number;
	cout << " \t�Ա� :";
	scin >> s1.sex;
	cout << " \t��ѧ�ɼ�:";
	scin >> s1.score[0];
	cout << " \tC++�ɼ�:";
	scin >> s1.score[1];
	cout << " \tӢ��ɼ�:";
	scin >> s1.score[2];
	cout << " \t�����ɼ�:";
	scin >> s1.score[3];
	cout << " \t��������۳ɼ�:";
	scin >> s1.score[4];
	s1.total = s1.score[0] + s1.score[1] + s1.score[2] + s1.score[3] + s1.score[4];
	s1.average = s1.total / 5;
	return scin;
}
student::student() //���캯�� 
{
	strcpy_s(name, " ");
	strcpy_s(sex, " ");
	number = 0;
	for (int i = 0; i < 5; i++)score[i] = 0;
	total = 0;
	average = 0;
}
void menu() //�˵����� 
{
	cout << "\n\n\nѧ���ɼ�����ϵͳ���˵� " << endl;
	cout << "\n\n\n1.����ѧ����Ϣ " << endl;
	cout << "2.���ѧ����Ϣ " << endl;
	cout << "3.����ѧ����Ϣ " << endl;
	cout << "4.�޸�ѧ����Ϣ " << endl;
	cout << "5.ɾ��ѧ����Ϣ " << endl;
	cout << "6.ѧ����Ϣ���� " << endl;
	cout << "7.�������� " << endl;
	cout << "8.�������� " << endl;
	cout << "9.�˳�ϵͳ " << endl;
	cout << "\n\n��ѡ��(1~9)�����س���ȷ��:";
}
int main() //������
{
	int choose;
	student s;
	do {
		menu();
		cin >> choose;
		switch (choose)
		{
		case 1: s.add(); break;
		case 2: s.output(); break;
		case 3: s.find(); break;
		case 4: s.ModifyItem(); break;
		case 5: s.RemoveItemd(); break;
		case 6: s.sort(); break;
		case 7: s.save(); break;
		case 8: s.load(); break;
		default: break;
		}
	} while (choose != 0);
}