#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::cout << "==== TEST WITH std::vector ====" << std::endl;
	try
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);

		easyfind(vec, 30);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n==== TEST WITH std::list ====" << std::endl;
	try
	{
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);

		easyfind(lst, 1);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n==== TEST WITH EMPTY CONTAINER ====" << std::endl;
	try
	{
		std::vector<int> empty;
		easyfind(empty, 1);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
