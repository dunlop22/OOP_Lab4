#pragma once 
#include <string>
#include "transport.h"
#include "parcel.h"
using namespace std;

class container
{

	//маленький
	//большой
	//для опасных грузов

	int id;	//уникальный номер
	int* spisok;	//массив с уникальными номерами посылок
	string town;	//направление контейнера
	parcel* parc;

	public:
		int kol_vo_parcel;

	public: virtual void generate_id()
	{
		this->id = 10000 + rand() % 90000;
	}

	public: virtual void get_parcel(parcel parc)
	{
		//новое поле под посылку, заполняется идентификационным номером
		//копия старого списка посылок

		int* spisok_temp = spisok;       //создание временного массива для копии
		spisok = new int[_msize(spisok) / sizeof(int) + 1]; //создание динамического массива с новыми размерами
		for (int i = 0; i < _msize(spisok) / sizeof(int) - 1; i++)
		{
			spisok[i] = spisok_temp[i];
		}

		delete[] spisok_temp;    //очистка памяти

		spisok[_msize(spisok) / sizeof(int) - 1] = id;
	}



	public: virtual void go_to_transport(transport * transp1)
	{
		transp1->drive();
	}

	public: virtual void set_town(string town_)	//установка пункта назначения
	{
		this->town = town_;
	}

	public: virtual string get_town()	//установка пункта назначения
	{
		return (this->town);
	}

	public: virtual int check_parcel()	//проверка наличия свободного места
	{
		return kol_vo_parcel;
	}

	public: virtual void set_parcel_minus()	//проверка наличия свободного места
	{
		kol_vo_parcel = kol_vo_parcel - 1;
	}

};

class danger_cont : public container	//контейнер с опасным содержимым
{
public:
	danger_cont()
	{
		kol_vo_parcel = 1;	//в целях безопасности
	}
};


class small_cont : public container		//маленький контейнер
{
public:
	small_cont()
	{
		kol_vo_parcel = 3;
	}
};

class big_cont : public container	//большой контейнер
{
public:
	big_cont()
	{
		
		this->kol_vo_parcel = 5;
	}
};
//контейнер делегат транспортное средство

//при создании контейнера он конфигурируется под то транпортное средство, на котором он будет передвигаться