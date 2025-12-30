#ifndef EASYFIND
#define EASYFIND

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
void easyfind(const T &container, int occurance){
	auto it = std::find(container.begin(), container.end(), occurance);
	if (it != container.end()){
		std::cout << occurance << " found in the container!\n";
		return ;
	}
	throw std::out_of_range("ERROR: number not found!");
	return ;
}

#endif