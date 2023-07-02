
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q9 сравнение указателей дает ошибку С2446: почему-то в шаблоне указтель на any не превращается в указатель на конкретный тип данных???

/*template <typename any>
static bool Collection_pointers_test(Collection<any>& test_obj)
{
	bool result = 1;
	std::cout << "\n\nPointers test:" << "\n*test_obj.begin() == test_obj[0]";
	if (test_obj.begin() == &test_obj[0]) std::cout << " true";
	else { std::cout << " false"; result = 0; }

	std::cout << "\n" << "*test_obj.end() == test_obj[test_obj.size()-1])";
	if (test_obj.end() == &test_obj[test_obj.size() - 1]) std::cout << " true";
	else { std::cout << " false"; result = 0; }

	return result;
}*/
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
