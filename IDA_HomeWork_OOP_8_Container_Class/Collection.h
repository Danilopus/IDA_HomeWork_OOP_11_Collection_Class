#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>
#include <cassert>


template <typename any>
class Collection
{
	size_t _size = 0;
	size_t _capacity = 0;
	any* _values_list = nullptr;	
	//Collection* _values_list = nullptr; какое значение/применение может быть у такого элемента?

	void Add_capacity(size_t capacity_to_add = 0)
	{		
			size_t new_capacity = _capacity + capacity_to_add;
			if (!capacity_to_add)
				new_capacity += (_capacity > 5 ? _capacity / 2 : 5);


			any* new_list = new any[new_capacity];

			for (int i = 0; i < _size; i++)
				new_list[i] = _values_list[i];

			delete[] _values_list;

			_values_list = new_list;
			_capacity = new_capacity;
			//return *this;
	}
	void Shrink_capacity()
	{
		size_t new_capacity = _size + _size / 2;
		any* new_list = new any[new_capacity];
		for (int i = 0; i < _size; i++)
			new_list[i] = _values_list[i];
		delete[] _values_list;
		_values_list = new_list;
		//return *this;
	}

public:

	// Constructors // Initialisation // Destructors // Memory Manage -------
	Collection()
	{
		_size = 0;
		_capacity = 0;
		_values_list = nullptr;
	}
	Collection(const Collection& Collection_obj) { *this = Collection_obj; }	
	~Collection()
	{
		delete[] _values_list;
	}

	// Setters // Getters --------------------------------------------------

	// Data manage ---------------------------------------------------------
	//Collection& pushback(any& new_value)
	Collection& pushback(any new_value)
	{
		if (_size >= _capacity) { Add_capacity(); }
		_values_list[_size] = new_value;
		_size++;
		return *this;
	}	
	Collection& pushfront(any new_value)
	{
		if (_size >= _capacity) Add_capacity();
		for (int i = _size; i > 0; i--)
			_values_list[i] = _values_list[i - 1];
		_values_list[0] = new_value;
		_size++;
		return *this;
	}
	Collection& popfront()
	{
		_size--;
		if (_size == 0) { clear(); return *this; }
		if (_size < _capacity / 2) Shrink_capacity();
		for (int i = 0; i < _size; i++)
			_values_list[i] = _values_list[i + 1];
		return *this;
	}
	Collection& popback()
	{
		_size--;
		if (_size == 0) { clear(); return  *this; }
		if (_size < _capacity / 2) Shrink_capacity();
		return *this;
	}
	Collection& insert(size_t pos, any new_value)
	{
		if (_size >= _capacity) Add_capacity();
		for (int i = _size; i > pos; i--)
			_values_list[i] = _values_list[i - 1];
		_values_list[pos] = new_value;
		_size++;
		return *this;
	}
	Collection& clear()
	{
		delete[] _values_list;
		_size = 0;
		_capacity = 0;
		_values_list = nullptr;
		return *this;
	}

	size_t size() { return _size; }

	Collection* begin() { return _values_list; }
	Collection* end() {	return _values_list + _size - 1; }

	// Shows ---------------------------------------------------------------
	void ShowValues() { std::cout << this; }

	//Overload operators - reference returned -----------------------------------------	
	
	/*
	Collection& operator + (const Collection& Collection_obj) const

	{
		Collection& new_container = *new Collection;
		for (size_t i = 0; i < _size; i++)
			new_container.pushback(_values_list[i]);

		for (size_t i = 0; i < Collection_obj._size; i++)
			new_container.pushback(Collection_obj._values_list[i]);

		return new_container;
	}
	*/
	/*
	//Collection<any>& operator = (const Collection<any>& Collection_obj)
	Collection& operator = (const Collection& Collection_obj)
	{
		if (_size >= Collection_obj._size)
		{
			for (size_t i = 0; i < Collection_obj._size; i++)
				_values_list[i] = Collection_obj[i];
			_size = Collection_obj._size;
			if (_size < _capacity / 2) Shrink_capacity();
		}
		else
		{
			any* new_list_for_copie = new any[Collection_obj._capacity];
			for (size_t i = 0; i < Collection_obj._size; i++)
				new_list_for_copie[i] = Collection_obj[i];
			delete[] _values_list;
			_values_list = new_list_for_copie;
			_size = Collection_obj._size;
			_capacity = Collection_obj._capacity;
		}
		return *this;
	}
	*/

	any& operator [ ] (size_t index) { return *(_values_list + index); }
	any& operator [ ] (size_t index) const { return *(_values_list + index); }


	/*
	friend std::ostream& operator << (std::ostream& out, Collection* Collection_obj)
	{
		if (Collection_obj->_values_list == nullptr)
			return out << "[no data]";

		out << "[ ";
		for (int i = 0; i < Collection_obj->_size; i++)
			//out << Collection_obj->_values_list[i] << " | ";
			out << (*Collection_obj)[i] << " | ";
		out << "\b\b]";
		return out;
	}
	friend std::ostream& operator << (std::ostream& out, Collection& Collection_obj)
	{
		if (Collection_obj._values_list == nullptr)
			return out << "[no data]";

		out << "[ ";
		for (int i = 0; i < Collection_obj._size; i++)
			//		out << Collection_obj._values_list[i] << " | ";
			out << Collection_obj[i] << " | ";
		out << "\b\b]";
		return out;
	}
	friend std::istream& operator >> (std::istream& in, Collection& Collection_obj) 
	{
		//Collection_obj.pushback(Get_LL_SA());
		return in;
	}
	*/
};

