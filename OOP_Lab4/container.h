#pragma once 
#include <string>
#include "transport.h"
#include "parcel.h"
using namespace std;

class container
{

	//���������
	//�������
	//��� ������� ������

	int id;	//���������� �����
	int* spisok;	//������ � ����������� �������� �������
	string town;	//����������� ����������
	parcel* parc;

	public:
		int kol_vo_parcel;

	public: virtual void generate_id()
	{
		this->id = 10000 + rand() % 90000;
	}

	public: virtual void get_parcel(parcel parc)
	{
		//����� ���� ��� �������, ����������� ����������������� �������
		//����� ������� ������ �������

		int* spisok_temp = spisok;       //�������� ���������� ������� ��� �����
		spisok = new int[_msize(spisok) / sizeof(int) + 1]; //�������� ������������� ������� � ������ ���������
		for (int i = 0; i < _msize(spisok) / sizeof(int) - 1; i++)
		{
			spisok[i] = spisok_temp[i];
		}

		delete[] spisok_temp;    //������� ������

		spisok[_msize(spisok) / sizeof(int) - 1] = id;
	}



	public: virtual void go_to_transport(transport * transp1)
	{
		transp1->drive();
	}

	public: virtual void set_town(string town_)	//��������� ������ ����������
	{
		this->town = town_;
	}

	public: virtual string get_town()	//��������� ������ ����������
	{
		return (this->town);
	}

	public: virtual int check_parcel()	//�������� ������� ���������� �����
	{
		return kol_vo_parcel;
	}

	public: virtual void set_parcel_minus()	//�������� ������� ���������� �����
	{
		kol_vo_parcel = kol_vo_parcel - 1;
	}

};

class danger_cont : public container	//��������� � ������� ����������
{
public:
	danger_cont()
	{
		kol_vo_parcel = 1;	//� ����� ������������
	}
};


class small_cont : public container		//��������� ���������
{
public:
	small_cont()
	{
		kol_vo_parcel = 3;
	}
};

class big_cont : public container	//������� ���������
{
public:
	big_cont()
	{
		
		this->kol_vo_parcel = 5;
	}
};
//��������� ������� ������������ ��������

//��� �������� ���������� �� ��������������� ��� �� ����������� ��������, �� ������� �� ����� �������������