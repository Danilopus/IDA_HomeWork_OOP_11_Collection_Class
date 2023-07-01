// HomeWork template project v 5.0 // 22.06.2023 //

/*

Задание 1
Реализовать класс-коллекцию для зранения элементов. в публичном интерфейсе этого
класса должны содержаться методы для работы с коллекуией и обязательно реализуйте
операторы для доступа к элементам.

*
Предусмотреть что если элемент коллекции сам является коллекцией то метод возвращающий
количество элементов должен возвращать количество учитывающее вложеные элементы.
Например: если в коллекции 10 элементов 2 из которых коллекции содержащие по 3
элемента в себе, то вернуться должно число 16 а не 10.

Задание 2
Изучите какие структуры данных помимо линейного массива и списка существуют и
составьте их описание на тему для чего они используются в программировании.

*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//#include <array>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"
#include "Collection.h"
#include "Collection_UnitTest.h"



// Homework OOP 8 ----------------------------------------------------	

/*
После уточнения на уроке по заданию вроде как получилось, что надо было сделать класс коллекцию, который содержит элементы самого себя
Потратив некоторое время пытаясь сделать задание в таком ключе я обнаружил, что получаются какие-то вырожденные структуры в виде массивов, каждый элемент которого тоже массив и так до бесконечности
Поэтому взял на себя смелость и изменил задание так, чтобы класс-коллекция принимал любые типы данных, в том числе другие коллекции, и возращал кол-во элементов с учетом вложенных коллекций

*/

//Task 1 Container class demo with overloaded operators: + | = | << | >> 
void Task_1(std::string name_of_task)
{	
	do
	{
		
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";
	{
		Collection<int> Collection_obj;
		//std::cout << Collection_UnitTest::main_test(Collection<int> Collection_obj);
		std::cout << Collection_UnitTest::main_test(Collection_obj);
	}
	{
		Collection<double> Collection_obj;
		std::cout << Collection_UnitTest::main_test(Collection_obj);
	}
	//{	
	//	//Collection<int[] {1, 2, 3} > Collection_obj;
	//	Collection<int[]> Collection_obj;
	//	std::cout << Collection_UnitTest::main_test(Collection_obj);
	//}
	//{
	//	//Collection<int[] {1, 2, 3} > Collection_obj;
	//	Collection<std::vector<float>> Collection_obj;
	//	std::cout << Collection_UnitTest::main_test(Collection_obj);
	//}


		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
}

//Task 2
void Task_2() {}

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
	MainMenu.AddElement("OOP Home Work 08: Universal Container class");	
	MainMenu.AddElement("Container class demo with overloaded operators: + | = | << | >> ");
	//MainMenu.AddElement("XXX");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

