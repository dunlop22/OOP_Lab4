#pragma once
#include "parcel.h"
#include "container.h"
#include <conio.h>
class solver
{

	//посылка, передвинься в контейнер
	public: void parcel_to_container(container** container_mass, parcel* parcel_mass, int num_parcel, int *num_container)
	{
		for (int i = 0;i < num_parcel; i++)
		{

			if (parcel_mass[i].danger == 1)
			{
				//обязательное создание нового контейнера, вне зависимости от заполнения остальных
				container** container_spisok_temp = container_mass;       //создание временного массива для копии
				container_mass = new container*[*num_container + 1]; //создание динамического массива с новыми размерами
				for (int i = 0; i < *num_container; i++)
				{
					container_mass[i] = container_spisok_temp[i];
				}

				delete[] container_spisok_temp;    //очистка памяти
				*num_container = *num_container + 1;
				container_mass[*num_container - 1] = new danger_cont();
				container_mass[*num_container - 1]->generate_id();	//присвоение индвидуального номера
				container_mass[*num_container - 1]->kol_vo_parcel = 1;
				cout << parcel_mass[i].danger;
				_getch();

			}
			else
			{
				//проверка наличия свободного места к существующих контейнерах
				for (int j = 0; j < *num_container; j++)
				{
					if (container_mass[j]->check_parcel() > 0)
					{
						//проверка города направления
						if (container_mass[j]->get_town() == parcel_mass[i].get_town())
						{
							container_mass[j]->set_parcel_minus();
							container_mass[j]->get_parcel(parcel_mass[i].get_id());	//добавление 


						}
					}
				}
			}
		}
	}

};



