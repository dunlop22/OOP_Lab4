#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "container.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class parcel
{
public:
	int danger;
private: 
	int id;
	string town_sender;
	string town_recipient;
	double shirina;
	double visota;
	double dlina;
	double weight;
	
	//int num_is_container;
	//public virtaul void move

public: int get_id()
{
	return (this->id);
}

public: void print_information()
{
	cout << this->id << " : " << this->town_sender << "-->" << this->town_recipient << "  (" << this->shirina << "x" << this->dlina << "x" << this->visota << ") " << this->weight << "��.\n";
}
public: void generate_id()
{
	//��������� ���������� 8-�� �������� ������ id
	this->id = 10000000 + rand() % 90000000;
	//�������� ���������������� ������� ������ (���???)
}
public: string get_town()
{
	return (this->town_recipient);
}

public: void set_information()
	{
		//��������� ��������������� 8-�������� ������ ������� (ID)
		while (cin.get() != '\n');	//������� ������ �����
		generate_id();
		system("cls");
		cout << "���� ���������� � ����� �������\n\n���������� ����� ������� (id): " << this->id;

		cout << "\n\n������� ����� �����������: ";	
		getline(cin, this->town_sender);
		
		string town[5] = { "�������", "������", "�����������", "�����������", "������ ��������" };
		int num_town;
		do
		{
			cout << "\n\n1) �������\n2) ������\n3) �����������\n4) �����������\n5) ������ ��������";
			cout << "\n\n�������� ����� ����������: ";
			num_town = _getch();
		} while (num_town < 49 || num_town > 55);
		this->town_recipient = town[num_town - 49];
		cout << num_town - 48 << " (" << this->town_recipient << ")";
		
		cout << "\n\n������� ������: ";
		//cin >> this->shirina;

		cout << "\n\n������� ������: ";
		//cin >> this->visota;

		cout << "\n\n������� �����: ";
		//cin >> this->dlina;

		cout << "\n\n������� ��� (��.): ";
		//cin >> this->weight;
		do
		{
			cout << "\n\n������� �������? (1 - ��, 2 - ���)";
			this->danger = _getch();
		} while (this->danger != 49 && this->danger != 50);
		this->danger = this->danger - 48;
		cout << "\n\n����� ������� ��� �������������";
		_getch();
	}

	public: virtual void move(container * cont1)		//�� ��������
	{
		cont1->get_parcel(id);
	}

};

