#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <windows.h>

#include "container.h"
#include "parcel.h"
#include "transport.h"
#include "solver.h"

using namespace std;

int main()
{
    parcel* parcel_spisok;
    parcel_spisok = new parcel[0];
    srand(time(NULL));  //для генерации случайных id
    setlocale(LC_ALL, "Russian");
    int num_parcel = 0;     //общее количество посылок
    int func;   //флаг для выбора пункта меню
    do
    {
        do           //главное меню
        {
            system("cls");
            cout << "1) Добавить несколько новых посылок\n2) Отправить посылки\n3) Просмотр информации об имеющихся посылках\nESC) Выход\n\nОбщее количество посылок на данный момент: " << num_parcel << "\n";
            func = _getch();
        } while (func != 49 && func != 50 && func != 51 && func != 27);

        if (func == 49)
        {
            int new_parcel; ///количество новых посылок
            do
            {
                system("cls");
                cout << "Введите количество новых посылок: ";
                cin >> new_parcel;
            } while (new_parcel < 0);

            parcel* parcel_spisok_temp = parcel_spisok;       //создание временного массива для копии
            parcel_spisok = new parcel[num_parcel + new_parcel]; //создание динамического массива с новыми размерами
            for (int i = 0; i < num_parcel; i++) 
            {
                parcel_spisok[i] = parcel_spisok_temp[i];
            }

            delete[] parcel_spisok_temp;    //очистка памяти
            for (int i = 0; i < new_parcel; i++)
            {
                parcel_spisok[num_parcel + i].set_information();
            }
            num_parcel = num_parcel + new_parcel;       //общее количество посылок (вместе с только что добавленными)
        }

        else if (func == 50)        //перемещение посылок
        {
            if (num_parcel > 0)         //имеются посылки для отправления
            {
                //распределение посылок по контейнерам
                for (int i = 0; i < num_parcel; i++)
                {
                    //solver
                    container** mass_container = new container * [0];
                    solver* solv = new solver;
                    int num_container = 0;
                    solv->parcel_to_container(mass_container, parcel_spisok, num_parcel, &num_container);
                    //big_cont* ty = new big_cont[10];
                    //parcel_spisok[i].move(  );
                }


                cout << "\n\nРаспредление закончено";
                _getch();
                string town[5] = { "Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород" };
                cout << "Перемещение посылок в города...\n";

                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        Sleep(500);
                        cout << "....";
                    }
                    cout << town[i] << "\n";
                }
                num_parcel = 0;
                //удаление массива с посылками
            }
            else        //посылок для отправления нет
            {
                system("cls");
                cout << "Нет посылок для отправления!\n\nДля продолжения нажмите любую клавишу";
                _getch();
            }
        }

        else if (func == 51)        //просмотр информации о существующих посылках
        {
            system("cls");

            if (num_parcel > 0)
            {
                                //вывод информации о посылках
                for (int i = 0; i < num_parcel; i++)
                {
                    parcel_spisok[i].print_information();
                }
            }
            else
            {
                cout << "Нет посылок для просмотра информации!";
            }
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
        }
    } while (func != 27);

    //drive...-> меню перемещения -> конечный пункт


}
