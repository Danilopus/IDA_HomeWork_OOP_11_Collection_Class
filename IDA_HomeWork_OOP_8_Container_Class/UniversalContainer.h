#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>
#include <cassert>



class UniversalContainer
{
	size_t _size = 0;
	size_t _capacity = 0;
	
	//long long* _long_values = nullptr;

	void Add_capacity(size_t capacity_to_add = 0);
	void Shrink_capacity();

public:

	// Constructors // Initialisation // Destructors // Memory Manage -------
	UniversalContainer();
	UniversalContainer(const UniversalContainer& UniversalContainer_obj);

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q8 как сделать универсальныю инициализацию UniversalContainer_obj {5, 7, 9}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::		
	
	~UniversalContainer();

	// Setters // Getters --------------------------------------------------

	// Data manage ---------------------------------------------------------
	template <typename any> UniversalContainer& pushback(any new_value)
	{
		// if (_size!=0 && type_check) - проверка, если массив уже создан, то помещаем только элементы того типа что уже есть
				
		
		if (_size >= _capacity)
		{
			Add_capacity();

			any* new_item_container = new any[_capacity]; //???

			// Resize_container()		
			for (int i = 0; i < _size; i++)
				new_item_container[i] = old_item_container[i];
			delete[] old_item_container;
		}
		// как хранить new_item_container??? указатель может быть разным, умный указатель?


		//_long_values[_size] = new_value;
		any[_size] = new_value;		

		_size++;



		return *this;
	}

	
	
	UniversalContainer& pushfront(long long new_value);
	UniversalContainer& popfront();
	UniversalContainer& pushback(long long new_value);
	UniversalContainer& popback();
	UniversalContainer& insert(size_t pos, long long  new_value);

	size_t size() { return _size; }

	long long int* begin();
	long long int* end();

	UniversalContainer& clear();

	// Shows ---------------------------------------------------------------
	void ShowValues();

	//Overload operators - reference returned -----------------------------------------	
	
	UniversalContainer& operator + (const UniversalContainer& UniversalContainer_obj) const;
	UniversalContainer& operator = (const UniversalContainer& UniversalContainer_obj);

	long long& operator [ ] (size_t index);
	long long& operator [ ] (size_t index) const;

	friend std::ostream& operator << (std::ostream& out, UniversalContainer* UniversalContainer_obj);
	friend std::ostream& operator << (std::ostream& out, UniversalContainer& UniversalContainer_obj);
	friend std::istream& operator >> (std::istream& in, UniversalContainer& UniversalContainer_obj);

};
