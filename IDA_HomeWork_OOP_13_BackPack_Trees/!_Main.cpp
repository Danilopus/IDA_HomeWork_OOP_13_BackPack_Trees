// HomeWork template project v 6.0 // 27.06.2023 //

/*

Наследование - Интерфейсы

Задание на композицию

Для реализованных классов Локация и Рюкзак создать интерфейсы:
Локация:
Для игры - позволяет добавлять и удалять деревья с локации
Для игрока - позволяет просматривать деревья и собирать с них плоды
Рюкзак:
Для игрока - позволяет добавлять и удалять плоды из рюкзака
Для игры - только просматривать содержимое без изменений

Продемонстрировать различное поведение объектов класса при передаче их по разным
интерфейсам.

*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"
#include "Location.h"
#include "BackPack.h"



// Homework OOP 13 ----------------------------------------------------	


//Task 1 Location
void Task_1(std::string name_of_task)
{	
	//*
	do
	{		
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";					
	
		TreeLocation Location_1(3);
		BackPack main_back_pack;

		std::cout << "\nLocation_1.Info()";
		Location_1.Info();


		// Player interface
		std::cout << "\n\n\n// Player interface\n";
		Location_Player_Interface* Location_Player_Interface_ptr = &Location_1;

		std::cout << "\nShowTrees()";
		Location_Player_Interface_ptr->ShowTrees();
		Location_Player_Interface_ptr->Get_fruit(0, &main_back_pack);
		std::cout << "\n\nAfter harvesting Tree 1 -> ShowTrees()";
		Location_Player_Interface_ptr->ShowTrees();


		// TheGame interface
		std::cout << "\n\n\n// TheGame interface\n";
		Location_TheGame_Interface* Location_TheGame_Interface_ptr = &Location_1;

		std::cout << "\nAddNewTree() -> Info()";
		Location_TheGame_Interface_ptr->AddNewTree();
		Location_1.Info();
		std::cout << "\n\nDeleteTree() -> DeleteTree() -> Info()";
		Location_TheGame_Interface_ptr->DeleteTree();
		Location_TheGame_Interface_ptr->DeleteTree();
		Location_1.Info();


		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);//*/
}

//Task 2 BackPack
void Task_2(std::string name_of_task)

{
	//*
	do
	{
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";

		BackPack main_back_pack;
		TreeLocation Location_2(5);

		// Player interface
		std::cout << "\n\n\n// Player interface\n";
		BackPack_Player_Interface* BackPack_Player_Interface_ptr = &main_back_pack;

		std::cout << "\nEmpty BackPack -> Info()\n";
		BackPack_Player_Interface_ptr->Info();

		std::cout << "\n\nLocation_2.ShowTrees()";
		Location_2.ShowTrees();

		std::cout << "\n\n\nBackPack after harvesting Trees 1, 2 and 3 -> Info()";

		// почему так?
		// Error(active)	E3364	operator -> or ->*applied to "MotherPlant" instead of to a pointer type	 
		//BackPack_Player_Interface_ptr->AddItem((Location_2[0])->Get_fruit());

		BackPack_Player_Interface_ptr->AddItem(*Location_2[0].Get_fruit());
		BackPack_Player_Interface_ptr->AddItem(*Location_2[1].Get_fruit());
		BackPack_Player_Interface_ptr->AddItem(*Location_2[2].Get_fruit());
		BackPack_Player_Interface_ptr->Info();

		std::cout << "\n\n\nBackPack after deleting 1 item -> Info()";
		BackPack_Player_Interface_ptr->DeleteItem();
		BackPack_Player_Interface_ptr->Info();


		// TheGame interface
		std::cout << "\n\n\n// TheGame interface\nInfo() method only";
		BackPack_TheGame_Interface* BackPack_TheGame_Interface_ptr = &main_back_pack;

		BackPack_TheGame_Interface_ptr->Info();


		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);//*/
}

//Task 3 
void Task_3() {}

//Task 4
void Task_4() {}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 13: Interfaces");	// Homework name
	MainMenu.AddElement("Location class demo through differents interfaces:\nInterface 1: Player\nInterface 2: Game\n");
	MainMenu.AddElement("BackPack class demo through differents interfaces:\nInterface 1: Player\nInterface 2: Game");

	//MainMenu.AddElement("XXX");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

