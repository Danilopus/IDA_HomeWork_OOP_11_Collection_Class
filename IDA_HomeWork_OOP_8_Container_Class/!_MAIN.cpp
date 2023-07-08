// HomeWork template project v 5.0 // 22.06.2023 //

/**

\brief Основы ООП на языке С++. Шаблонные классы

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
#include <fstream>
//#include <array>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"
#include "Collection.h"
#include "Collection_UnitTest.h"



// Homework OOP 11 ----------------------------------------------------	

/**
Запускает тестирование задания 1
\param std::string name_of_task - название задание
*/

//Task 1 Container class demo with overloaded operators: []
void Task_1(std::string name_of_task)
{	
	do	
	{		
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";
	//*
	{
		Collection<int> Collection_obj;
		std::cout << Collection_UnitTest::main_test(Collection_obj);

		
		std::cout << "\n\nRanged for loop testing:\n";	
		for (Collection<int>::iterator it = Collection_obj.begin(); it != Collection_obj.end(); ++it)
		{
			const auto& el = *it;
			std::cout << el << " | ";

		}
		for (auto it = Collection_obj.begin(); it != Collection_obj.end(); ++it)
		{
			std::cout << *it << " | ";
		}
		
		//Error(active)	E0350	more than one operator "!=" matches these operands
		/* 
		for (const auto& el : Collection_obj)
		//for (auto el : Collection_obj)
		{
			std::cout << el << " | ";
		}/*/
	}
	{
		Collection<double> Collection_obj;
		std::cout << Collection_UnitTest::main_test(Collection_obj);
	}//*/
	
	{
		Collection<int*> Collection_obj;
		// не работает - нет перегрузок тестовой функции на работу с vector
		// 
		//Local tests 
		int M;
		int* int_ptr = &M;

		std::cout << "\n\nArgument: " << typeid(Collection_obj[0]).name() << " sub test\n";
		

		std::cout << "\nCollection_obj.size() -> " << Collection_obj.size();
		Collection_obj.pushback(int_ptr).pushback(int_ptr).ShowValues();
		std::cout << "\nCollection_obj.size() -> " << Collection_obj.size();
		Collection_obj.pushfront(int_ptr).pushfront(int_ptr).ShowValues();
		std::cout << "\nCollection_obj.size() -> " << Collection_obj.size();

		std::cout << "\ntypeid(Collection_obj[0]).name() -> " << typeid(Collection_obj[0]).name();

		std::cout << "\n\nRanged for loop testing:\n";
		for (Collection<int*>::iterator it = Collection_obj.begin(); it != Collection_obj.end(); ++it)

		{
			const auto& el = *it;
			std::cout << el << " | ";

		}
		for (auto it = Collection_obj.begin(); it != Collection_obj.end(); ++it)
		{
			std::cout << *it << " | ";
		}

		//Error(active)	E0350	more than one operator "!=" matches these operands
		/*
		for (const auto& el : Collection_obj)
		//for (auto el : Collection_obj)
		{
			std::cout << el << " | ";
		}/*/


	}//*/
	
	//* STL vector test block
	{
		Collection<std::vector<float>> Collection_obj;
		//std::cout << Collection_UnitTest::main_test(Collection_obj); // не работает - нет перегрузок тестовой функции на работу с vector

		//Local tests
		std::vector<float> test_vec{ 1,2,3 };
		std::cout << "\n\nArgument: " << typeid(Collection_obj[0]).name() << " sub test\n";


		Collection_obj.pushback(test_vec).pushback(test_vec).pushback(test_vec).pushback(test_vec);

		// Error	C2679	binary '<<': no operator found which takes a right - hand operand of type 'any' (or there is no acceptable conversion)
		//Collection_obj.ShowValues();

		std::cout << "\nsize " << Collection_obj.size();
		std::cout << "\ntypeid(Collection_obj[0]).name() -> " << typeid(Collection_obj[0]).name();
	}

		std::cout << "\n\nEsc - exit | any key to continue";	
	} while (_getch() != 27);
}

//Task 2 
void Task_2(std::string name_of_task) {}

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
	MainMenu.AddElement("OOP Home Work 11: Templated classes. Universal Container class");	
	MainMenu.AddElement("Container class demo with overloaded operators: []");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

