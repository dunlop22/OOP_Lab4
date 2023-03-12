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
	cout << this->id << " : " << this->town_sender << "-->" << this->town_recipient << "  (" << this->shirina << "x" << this->dlina << "x" << this->visota << ") " << this->weight << "кг.\n";
}
public: void generate_id()
{
	//генерация случайного 8-ми значного номера id
	this->id = 10000000 + rand() % 90000000;
	//проверка индивидуальности данного номера (как???)
}
public : void get_information()
	{
		//генерация индивидуального 8-значного номера посылки (ID)
		while (cin.get() != '\n');	//очистка потока ввода
		generate_id();
		system("cls");
		cout << "Ввод информации о новой посылке\n\nУникальный номер посылки (id): " << this->id;

		cout << "\n\nВведите город отправителя: ";	
		getline(cin, town_sender);
		
		string town[5] = { "Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород" };
		int num_town;
		do
		{
			cout << "\n\n1) Барнаул\n2) Москва\n3) Новосибирск\n4) Владивосток\n5) Нижний Новгород";
			cout << "\n\nВыберите город получателя: ";
			num_town = _getch();
		} while (num_town < 49 || num_town > 55);
		town_recipient = town[num_town - 49];
		cout << num_town - 48;

		cout << "\n\nВведите ширину: ";
		//cin >> shirina;

		cout << "\n\nВведите высоту: ";
		//cin >> visota;

		cout << "\n\nВведите длину: ";
		//cin >> dlina;

		cout << "\n\nВведите вес (кг.): ";
		//cin >> weight;
			
	}

	public : virtual void move(container * cont1)		//от решателя
	{
		cont1->get_parcel(id);
	}

};

