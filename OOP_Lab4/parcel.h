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
public : void get_information()
	{
		//��������� ��������������� 8-�������� ������ ������� (ID)
		while (cin.get() != '\n');	//������� ������ �����
		generate_id();
		system("cls");
		cout << "���� ���������� � ����� �������\n\n���������� ����� ������� (id): " << this->id;

		cout << "\n\n������� ����� �����������: ";	
		getline(cin, town_sender);
		
		string town[5] = { "�������", "������", "�����������", "�����������", "������ ��������" };
		int num_town;
		do
		{
			cout << "\n\n1) �������\n2) ������\n3) �����������\n4) �����������\n5) ������ ��������";
			cout << "\n\n�������� ����� ����������: ";
			num_town = _getch();
		} while (num_town < 49 || num_town > 55);
		town_recipient = town[num_town - 49];
		cout << num_town - 48;

		cout << "\n\n������� ������: ";
		//cin >> shirina;

		cout << "\n\n������� ������: ";
		//cin >> visota;

		cout << "\n\n������� �����: ";
		//cin >> dlina;

		cout << "\n\n������� ��� (��.): ";
		//cin >> weight;
			
	}

	public : virtual void move(container * cont1)		//�� ��������
	{
		cont1->get_parcel(id);
	}

};

