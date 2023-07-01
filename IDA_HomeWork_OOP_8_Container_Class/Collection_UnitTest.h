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
		//std::string test_report = "\n\n*** Tests status\n" << typeid(test_obj[0]).name() << "\n";
		std::cout << typeid(test_obj[0]).name();
		
		std::string test_report = "\n\n*** Tests status\n";// +typeid(test_obj[0]).name();
		// 
		// 
		//Collection<any> test_obj;
	

		test_report += "\nData manage methods test_1: ";
		test_report += Collection_test_methods_1(test_obj) ? "Ok" : "failed";
		test_report += "\nData manage methods test_2: ";
		test_report += Collection_test_methods_2(test_obj) ? "Ok" : "failed";
		test_report += "\nPointers test: ";
		//test_report += Collection_test_pointers(test_obj) ? "Ok" : "failed";
		test_report += "\nClear test: ";
		test_report += Collection_test_4(test_obj) ? "Ok" : "failed";
		test_report += "\nOperator test: ";
		test_report += Collection_test_5(test_obj) ? "Ok" : "failed";
		test_report += "\nOperator << cin test: ";
		test_report += Collection_test_6(test_obj) ? "Ok" : "failed";
		
		return test_report;
	}
	//template <typename any>
	static bool Collection_test_methods_1(Collection<int>& test_obj)
	{
		std::cout << "\nData manage methods test_1\ntest_obj.pushback(3).pushback(5).pushfront(2).pushfront(1).insert(3, 4).ShowValues()\n";
		test_obj.pushback(3).pushback(5).pushfront(2).pushfront(1).insert(3, 4).ShowValues();

		//if (Summ(test_obj) == 15) { return true; }
		return false;
	}		
	static bool Collection_test_methods_1(Collection<double>& test_obj)
	{
		std::cout << "\nData manage methods test_1\ntest_obj.pushback(3).pushback(5).pushfront(2).pushfront(1).insert(3, 4).ShowValues()\n";
		test_obj.pushback(3).pushback(5).pushfront(2).pushfront(1).insert(3, 4).ShowValues();

		//if (Summ(test_obj) == 15) { return true; }
		return false;
	}


	template <typename any>
	static bool Collection_test_methods_2(Collection<double>& test_obj)
	{
		std::cout << "\n" << "\nData manage methods test_2\ntest_obj.popback().popfront()\n";
		//std::cout << test_obj.popback().popfront();
		test_obj.popback().popfront().ShowValues();

		//if (Summ(test_obj) == 9) { return true; }
		return false;
	}	

	
	template <typename any>
	static bool Collection_test_methods_2(Collection<any>& test_obj)
	{
		std::cout << "\n" << "\nData manage methods test_2\ntest_obj.popback().popfront()\n";
		//std::cout << test_obj.popback().popfront();
		test_obj.popback().popfront().ShowValues();
		//if (Summ(test_obj) == 9) { return true; }
		return false;
	}

	/*
	template <typename any>
	static bool Collection_test_pointers(Collection<any>& test_obj)
	{
		bool result=1;
		std::cout << "\n\nPointers test:" << "\n*test_obj.begin() == test_obj[0]";
		if (test_obj.begin() == &test_obj[0]) std::cout << " true";
		else { std::cout << " false"; result = 0; }

		std::cout << "\n" << "*test_obj.end() == test_obj[test_obj.size()-1])";
		if (test_obj.end() == &test_obj[test_obj.size() - 1]) std::cout << " true";
		else { std::cout << " false"; result = 0; }

		return result;
	}
	*/

	template <typename any>
	static bool Collection_test_4(Collection<any>& test_obj)
	{
		std::cout << "\n\nClear test" << "\n" << "test_obj.clear().ShowValues()\n";
		test_obj.clear().ShowValues();

		if (test_obj.size() == 0) { return true; }
		return false;
	}
	template <typename any>
	static bool Collection_test_5(Collection<any>& test_obj)
	{
		Collection<any> test_obj_2, test_obj_3;
		std::cout << "\n\nOperator test" << "\n" << "test_obj.pushfront(3).pushfront(2).pushfront(1)\ntest_obj_3 = test_obj_2 = test_obj\ntest_obj_3.ShowValues()\n";
		test_obj.pushfront(3).pushfront(2).pushfront(1);
		test_obj_3 = test_obj_2 = test_obj;
		test_obj_3.ShowValues();

		std::cout << "\n " << "\n" << "test_obj_2.insert(0, 555)\ntest_obj_3 = test_obj + test_obj_2\ntest_obj_3.ShowValues()\n";
		test_obj_2.insert(0, 555);
		//test_obj_3 = test_obj + test_obj_2;
		test_obj_3.ShowValues();

		//if (Summ(test_obj_3) == 567) { return true; }
		return false;
	}
	template <typename any>
	static bool Collection_test_6(Collection<any>& test_obj)
	{
		std::cout << "\n\nOperator << cin test" << "\n" 
			<< "std::cin >> test_obj\n";
		//std::cin >> test_obj;
		
		std::cout << "\n " << "test_obj.ShowValues()\n";
		test_obj.ShowValues();
		
		if (test_obj.size()) { return true; }
		return false;
	}

	template <typename any>
	static any Summ(Collection<any> Collection_obj)
	{
		any Summ{};
		for (size_t i = 0; i < Collection_obj.size(); i++)
			Summ += Collection_obj[i];
		return Summ;
	}
};





