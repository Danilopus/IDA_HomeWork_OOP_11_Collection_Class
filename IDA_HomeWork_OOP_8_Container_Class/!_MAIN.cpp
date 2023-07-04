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
#include <fstream>
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
	}
	{
		Collection<double> Collection_obj;
		std::cout << Collection_UnitTest::main_test(Collection_obj);
	}//*/
	
	//* Pointers test block
	{
		//Collection<int[]> Collection_obj;
		//Collection<int[5]> Collection_obj;
		Collection<int*> Collection_obj;
		//std::cout << Collection_UnitTest::main_test(Collection_obj);

		//Local tests 
		int M;
		int* int_ptr = &M;
		std::cout << "\n\nLight local test\n";
		Collection_obj.pushback(int_ptr).pushback(int_ptr).ShowValues();
		std::cout << "\n";
		Collection_obj.pushfront(int_ptr).pushfront(int_ptr).ShowValues();


	}//*/
	
	//* STL vector test block
	{
		Collection<std::vector<float>> Collection_obj;
		//std::cout << Collection_UnitTest::main_test(Collection_obj);

				//Local tests
		std::vector<float> test_vec{ 1,2,3 };
		//std::vector<double> test_vec{ 1,2,3 };

		//std::cout << test_vec;

		//Collection_obj.pushback(test_vec).pushback(test_vec).ShowValues();
		std::cout << "\nsize " << Collection_obj.pushback(test_vec).pushback(test_vec).size();


	}//*/


		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
}

//Task 2 Standart template library container class info
void Task_2(std::string name_of_task)
{
	std::ifstream file_read_obj;
	do
	{
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";
		file_read_obj.open("Task_2.txt");
		if (file_read_obj.is_open())
		{
			std::string str_tmp;
			while (std::getline(file_read_obj, str_tmp))
				std::cout << str_tmp << '\n';
		}
		file_read_obj.close();

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
}

//Task 3 std::size inspection
template <typename any> void try_size(any& value)
//template <typename any> void try_size(any* value)
{
	std::cout << "\ntypeid(value) -> " << typeid(value).name();
	std::cout << "\ntypeid(*value) -> "  << typeid(*value).name();
	//std::cout << "\ntry_size -> " << std::size(value);
	std::cout << "\ntry_size* -> " << std::size(*value);
}
void Task_3() 
{
	std::vector<int> test_vector{ 1, 2, 3, 4, 5 };
	std::vector<int>* test_vector_dynamic = new std::vector<int>{ 10, 20, 30, 40, 50 };
	auto auto_pointer = new std::vector<int>{ 100, 200, 300, 400, 500 };


	int N = 111;
	auto ptr_N = &N;
	int* N_dynamic = new int{ 222 };
	int M[3]{ 11, 22, 33 };
	int* M_ptr = M;
	int* M_dynamic = new int[3]{ 222, 333, 444 };

	std::cout << "\nstd::size(test_vector) -> " << std::size(test_vector);
	std::cout << "\nstd::size(test_vector_dynamic) -> " << std::size(*test_vector_dynamic);
	std::cout << "\nstd::size(auto_pointer) -> " << std::size(*auto_pointer);
	try_size(auto_pointer);

	//std::cout << "\nstd::size(N);" << std::size(N);
	//std::cout << "\nstd::size(ptr_N);" << std::size(ptr_N);
	//std::cout << "\nstd::size(N_dynamic);" << std::size(N_dynamic);
	
	//try_size(N);
	//try_size(ptr_N);


	std::cout << "\nstd::size(M) -> " << std::size(M);
	//std::cout << "\nstd::size(M_ptr);" << std::size(*M_ptr);
	//std::cout << "\nstd::size(M_dynamic);" << std::size(M_dynamic);
	//try_size(M);
	//try_size(M_ptr);
	//try_size(M_dynamic);



	_getch();
};


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
	MainMenu.AddElement("Container class demo with overloaded operators: []");
	MainMenu.AddElement("Standart template library container class info");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

