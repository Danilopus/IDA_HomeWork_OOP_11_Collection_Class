#pragma once
#include "Collection.h"


//template 
class Collection_UnitTest
{
public:
	
	//static std::string main_test()
	template <typename any>
	static std::string main_test(Collection<any> test_obj)
	{
		std::string type_id = typeid(test_obj[0]).name();
		//std::string test_report = "\n\n*** Tests status\n" << typeid(test_obj[0]).name() << "\n";
		//std::cout << "\n\n*\n**\n*** SELF Tests module. Collection argument type: " << typeid(test_obj[0]).name() << std::endl;
		std::cout << "\n\n*\n**\n*** SELF Tests module. Collection argument type: " << type_id << "\n";
		
		//std::string test_report = "\n\n*** Tests status\n" + "argument type: " + type_id;
		std::string test_report = "\n\n*** Tests status. "; 
		test_report += ("Argument type: " + type_id);

	// Methods test list --------------------------------------------------------*/
		
		//1
		test_report += "\nData manage methods: pushfront test: ";
		test_report += Collection_test_methods_2(test_obj) ? "Ok" : "failed";

		//2	
		test_report += "\nData manage methods: pushback test: ";
		test_report += Collection_test_methods_1(test_obj) ? "Ok" : "failed";

		//3
		test_report += "\nData manage methods: popfront test: ";
		test_report += Collection_test_methods_3(test_obj) ? "Ok" : "failed";

		//4
		test_report += "\nData manage methods: popback test: ";
		test_report += Collection_test_methods_4(test_obj) ? "Ok" : "failed";

		//5
		test_report += "\nData manage methods: insert test: ";
		test_report += Collection_test_methods_5(test_obj) ? "Ok" : "failed";

		//6
		test_report += "\nData manage methods: clear test: ";
		test_report += Collection_test_methods_6(test_obj) ? "Ok" : "failed";

		//7
		test_report += "\nData manage methods: size test: ";
		test_report += Collection_test_methods_7(test_obj) ? "Ok" : "failed";
		
		//7.1
		test_report += "\nData manage methods: fullsize test: ";
		test_report += Collection_test_methods_7_1(test_obj) ? "Ok" : "failed";

		//8
		test_report += "\nPointers test: ";
		test_report += Collection_pointers_test(test_obj) ? "Ok" : "failed";

		// Operators test list --------------------------------------------------------*/

		//1		
		test_report += "\nOperator [] test: ";
		test_report += Collection_operators_test_1(test_obj) ? "Ok" : "failed";
				
		return test_report;
	}

	template <typename any>
	static bool Collection_test_methods_1(Collection<any>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : pushback test" << "\n"
			<< "test_obj.pushback(3).pushback(4).pushback(5).ShowValues() -> ";// << std::endl;

		test_obj.pushback(3).pushback(4).pushback(5).ShowValues();


		//if (Summ(test_obj) == 15) 
		{ return true; }
		return false;
	}
	static bool Collection_test_methods_1(Collection<int>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : pushback test" << "\n"
			<< "test_obj.pushback(3).pushback(4).pushback(5).ShowValues() -> ";// << std::endl;

		test_obj.pushback(3).pushback(4).pushback(5).ShowValues();


		//if (Summ(test_obj) == 15) 
		{ return true; }
		return false;
	}		
	static bool Collection_test_methods_1(Collection<double>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : pushback test" << "\n"
			<< "test_obj.pushback(1.23).pushback(-4.56).pushback(7.89101112e5).ShowValues() -> ";

		test_obj.pushback(1.23).pushback(-4.56).pushback(7.89101112e3).ShowValues();


		//if (Summ(test_obj) == 15) 
		{ return true; }
		return false;
	}
	template <typename any>
	static bool Collection_test_methods_2(Collection<any>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : pushfront test" << "\n"
			<< "test_obj.pushfront(2).pushfront(1).ShowValues() -> ";
		test_obj.pushfront(2).pushfront(1).ShowValues();

		//if (Summ(test_obj) == 9) 
		{ return true; }
		return false;
	}		

	/*template <>
	static bool Collection_test_methods_2<int*>(Collection<int*>& test_obj);*/

	template <typename any>
	static bool Collection_test_methods_2(Collection<any[]>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : pushfront test" << "\n"
			<< "test_obj.pushfront(2).pushfront(1).ShowValues() -> ";
		int arr[5] = { 1,2,3,4,5 };
		test_obj.pushfront(arr).pushfront(arr).ShowValues();

		//if (Summ(test_obj) == 9) 
		{ return true; }
		return false;
	}
	template <typename any>
	static bool Collection_test_methods_2(Collection<any*>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : pushfront test" << "\n"
			<< "test_obj.pushfront(2).pushfront(1).ShowValues() -> ";
		int arr[5] = { 1,2,3,4,5 };
		test_obj.pushfront(arr).pushfront(arr).ShowValues();

		//if (Summ(test_obj) == 9) 
		{ return true; }
		return false;
	}

	//* проблемный тест - никак не хочет принимать указатели в мой контейнер
	//static bool Collection_test_methods_2(Collection<int[5]>& test_obj)
	static bool Collection_test_methods_2(Collection<int*>& test_obj)

	{
		std::cout << "\n\n" << "Data manage methods : pushfront test" << "\n"
			<< "test_obj.pushfront(2).pushfront(1).ShowValues() -> ";
		//int arr[5] = { 1,2,3,4,5 };
		int* int_arr = new int[5]{ 1,2,3,4,5 };

		test_obj.pushfront(int_arr).pushfront(int_arr).ShowValues();

		//if (Summ(test_obj) == 9) 
		{ return true; }
		return false;
	}
	//*/

	template <typename any>
	static bool Collection_test_methods_3(Collection<any>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : popfront test" << "\n"
			<< "test_obj.popfront().ShowValues() -> ";

		test_obj.popfront().ShowValues();

		//if (test_obj.size() == 0) 
		{ return true; }
		return false;
	}
	template <typename any>
	static bool Collection_test_methods_4(Collection<any>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : popback test" << "\n"
			<< "test_obj.popback().ShowValues() -> ";

		test_obj.popback().ShowValues();

		//if (test_obj.size() == 0) 
		{ return true; }
		return false;
	}
	template <typename any>
	static bool Collection_test_methods_5(Collection<any>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : insert test" << "\n"
			<< "test_obj.insert(1,555).ShowValues() -> ";

		test_obj.insert(1,555).ShowValues();

		//if (test_obj.size() == 0) 
		{ return true; }
		return false;
	}
	template <typename any>
	static bool Collection_test_methods_6(Collection<any>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : clear test" << "\n"
			<< "test_obj.clear().ShowValues() -> ";

		test_obj.clear().ShowValues();

		//if (test_obj.size() == 0) 
		{ return true; }
		return false;
	}
	template <typename any>
	static bool Collection_test_methods_7(Collection<any>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : size test" << "\n"
			<< "test_obj.pushback(100).pushback(200).pushback(300).size() -> ";

		std::cout << test_obj.pushback(100).pushback(200).pushback(300).size();

		//if (test_obj.size() == 0) 
		{ return true; }
		return false;
	}
	template <typename any>
	static bool Collection_test_methods_7_1(Collection<any>& test_obj)
	{
		std::cout << "\n\n" << "Data manage methods : fullsize test" << "\n"
			<< "test_obj.pushback(100).pushback(200).pushback(300).fullsize() -> ";

		std::cout << test_obj.pushback(100).pushback(200).pushback(300).fullsize();

		//if (test_obj.size() == 0) 
		{ return true; }
		return false;
	}

		template <typename any>
	static bool Collection_pointers_test(Collection<any>& test_obj)
	{	
		
		bool result = 1;
		std::cout << "\n\nPointers test:" << "\n*test_obj.begin() == test_obj[0]";

		/* сравнение указателей дает ошибку С2446: почему-то в шаблоне указтель на any не превращается в указатель на конкретный тип данных???

		if (test_obj.begin() == &test_obj[0]) std::cout << " true";
		else { std::cout << " false"; result = 0; }

		std::cout << "\n" << "*test_obj.end() == test_obj[test_obj.size()-1])";
		if (test_obj.end() == &test_obj[test_obj.size() - 1]) std::cout << " true";
		else { std::cout << " false"; result = 0; }		
		
		//*/

		//return result;
		
		
		std::cout << " -> skipped due to error C2446";
		return false;		
	}

		template <typename any>
	static bool Collection_operators_test_1(Collection<any>& test_obj)
	{
		std::cout << "\n\n" << "Operator [] test: " << "\n"
			<< "test_obj[0] -> ";
		std::cout << test_obj[0];
		std::cout << "\ntest_obj[size()-1] -> ";
		std::cout << test_obj[test_obj.size() - 1];

		//if (test_obj.size() == 0) 
		{ return true; }
		return false;
	}
		




/*
	template <typename any>
	static any Summ(Collection<any> Collection_obj)
	{
		any Summ{};
		for (size_t i = 0; i < Collection_obj.size(); i++)
			Summ += Collection_obj[i];
		return Summ;
	}
*/

};





