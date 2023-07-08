#pragma once
#include <vector>
#include <iterator>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>
#include <cassert>
//#include <initializer_list>


/****
\brief Самодельный контейнер по типу std::vector

\bug не смог заставить работать настоящий ranged for - ругается на перегузку !=. Ошибка E0350

\todo 
1) ranged for	
2) fullsize() via traits 
3) more doxigen comments

*/

template <typename any>
class Collection
{
	size_t _size = 0;
	size_t _capacity = 0;
	any* _values_list = nullptr;	

	void Add_capacity(size_t capacity_to_add = 0)
	{		
			size_t new_capacity = _capacity + capacity_to_add;
			if (!capacity_to_add)
				new_capacity += (_capacity > 5 ? _capacity / 2 : 5);


			any* new_list = new any[new_capacity];

			for (int i = 0; i < _size; i++)
				new_list[i] = _values_list[i];
				//*new_list[i] = *_values_list[i];

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
	Collection& pushfront(any new_value)
	{
		if (_size >= _capacity) Add_capacity();
		for (int i = _size; i > 0; i--)
			_values_list[i] = _values_list[i - 1];
		//*_values_list[i] = _values_list[i - 1];
		//*_values_list[i] = *_values_list[i - 1];

		_values_list[0] = new_value;
		//*_values_list[0] = new_value;
		//*_values_list[0] = *new_value;
		_size++;
		return *this;
	}
	Collection& pushback(any new_value)
	{
		if (_size >= _capacity) { Add_capacity(); }
		_values_list[_size] = new_value;
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

	size_t size()	{ return _size; }

	size_t fullsize() 
	{ 
		size_t inner_size = 0;
		for (int i = 0; i < _size; i++)
		{
			//inner_size += std::size(_values_list[i]);
		}
		return 	_size + inner_size;
	}


	//Collection* begin() { return _values_list; }
	//Collection* end() {	return _values_list + _size - 1; }

	// Shows ---------------------------------------------------------------
	void ShowValues() 
	{ 
		//std::cout << this; 

		if (_values_list == nullptr)
		{
			std::cout << "[no data]";
			return;
		}

		std::cout << "\n[ ";
		for (int i = 0; i < _size; i++)
			//out << Collection_obj->_values_list[i] << " | ";
			std::cout << _values_list[i] << " | ";
		std::cout << "\b\b]";

	}

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
	
	class iterator 
	{
	private:
		iterator() = delete;

		//iterator(const Collection&& position, any* place) : collection_(position), place_(place)	{	}
		
		iterator(any* place) : place_(place) {	}

		friend class Collection;
		//const Collection& collection_;
		any* place_;

	public:

		any* operator->()const	{ return place_; }
		any& operator*()const	{ return *place_; }
		operator any* ()const	{ return place_; };

		iterator& operator+(int i)const	
		{ 
			iterator result(*this); 
			result.place_ += i;
			return result;
		}
		iterator& operator+=(int i) 
		{
			place_ += i;
			return *this;
		}
		iterator& operator-(int i)const 
		{
			iterator result(*this);
			result.place_ -= i;
			return result;
		}
		iterator& operator-=(int i) 
		{
			place_ -= i;
			return *this;
		}
		iterator& operator--() 
		{
			place_ -= 1;
			return *this;
		}
		iterator& operator--(int) 
		{
			iterator tmp{ *this };
			place_ -= 1;
			return tmp;
		}
		iterator& operator++() 
		{
			place_ += 1;
			return *this;
		}
		iterator& operator++(int) {
			iterator tmp{ *this };
			place_ += 1;
			return tmp;
		}

		operator bool()const {
			return static_cast<bool>(place_);
		}

		bool operator==(const iterator&& other)const	{ return place_ == other.place_; }
		//bool operator!=(const iterator&& other)const	{	return !(*this == other); }
		bool operator!=(const iterator&& other)const	{	return !(place_ == other.place_); }
		bool operator<(const iterator&& other)const	{ return place_ < other.place_; }
		bool operator<=(const iterator&& other)const	{ return place_ <= other.place_; }
		bool operator>(const iterator&& other)const	{ return place_ > other.place_; }
		bool operator>=(const iterator&& other)const	{ return place_ >= other.place_; }
		
		any& operator[](int i)const	{ return place_[i]; }
		//const Collection const* from()const	{ return &collection_; }
	
	};

	iterator begin() { return _values_list; }
	iterator end() { return (_values_list + _size); }

	//iterator begin() {	return iterator(*this, _values_list);	}
	//iterator end() {return iterator(*this, _values_list + _size);	}
};

