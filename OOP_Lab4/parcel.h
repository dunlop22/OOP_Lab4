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
	cout << this->id << " : " << this->town_sender << "-->" << this->town_recipient << "  (" << this->shirina << "x" << this->dlina << "x" << this->visota << ") " << this->weight << "кг.\n";
}
public: void generate_id()
{
	//генерация случайного 8-ми значного номера id
	this->id = 10000000 + rand() % 90000000;
	//проверка индивидуальности данного номера (как???)
}
public: string get_town()
{
	return (this->town_recipient);
}

public: void set_information()
	{
		//генерация индивидуального 8-значного номера посылки (ID)
		while (cin.get() != '\n');	//очистка потока ввода
		generate_id();
		system("cls");
		cout << "Ввод информации о новой посылке\n\nУникальный номер посылки (id): " << this->id;

		cout << "\n\nВведите город отправителя: ";	
		getline(cin, this->town_sender);
		
		string town[5] = { "Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород" };
		int num_town;
		do
		{
			cout << "\n\n1) Барнаул\n2) Москва\n3) Новосибирск\n4) Владивосток\n5) Нижний Новгород";
			cout << "\n\nВыберите город получателя: ";
			num_town = _getch();
		} while (num_town < 49 || num_town > 55);
		this->town_recipient = town[num_town - 49];
		cout << num_town - 48 << " (" << this->town_recipient << ")";
		
		cout << "\n\nВведите ширину: ";
		//cin >> this->shirina;

		cout << "\n\nВведите высоту: ";
		//cin >> this->visota;

		cout << "\n\nВведите длину: ";
		//cin >> this->dlina;

		cout << "\n\nВведите вес (кг.): ";
		//cin >> this->weight;
		do
		{
			cout << "\n\nПосылка опасная? (1 - ДА, 2 - НЕТ)";
			this->danger = _getch();
		} while (this->danger != 49 && this->danger != 50);
		this->danger = this->danger - 48;
		cout << "\n\nЛюбая клавиша для подтверждения";
		_getch();
	}

	public: virtual void move(container * cont1)		//от решателя
	{
		cont1->get_parcel(id);
	}

};

