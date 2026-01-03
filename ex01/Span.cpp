#include "Span.hpp"
#include <exception>
#include <iostream>
#include <algorithm>

Span::Span(unsigned int max_len) : _max_length(max_len)
{}
Span::Span(const Span &src) : _max_length(src._max_length), _numbers(src._numbers)
{}
Span Span::operator=(const Span &src){
	if (&src != this){
		_max_length = src._max_length;
		_numbers = src._numbers;
	}
	return *this;
}
Span::~Span(){}

void Span::addNumber(int number){
	if(_numbers.size() == _max_length){
		throw std::overflow_error("ERROR: span is full, you can not add anymore number!");
	}
	_numbers.push_back(number);
}
int Span::shortestSpan() const{
	if (_numbers.size() < 2){
		throw std::out_of_range("ERROR: shortest span is not possible, not enough elements!");
	}
	std::vector<int> copy(_numbers);
	std::sort(copy.begin(), copy.end());

	int shortest = copy[1] - copy[0];
	for(size_t i = 0; i < copy.size() - 1; i++){
		int d = copy [i + 1] - copy[i];
		if(d < shortest) {shortest = d;}
	}
	return shortest;
}
int Span::longestSpan() const{
	if (_numbers.size() < 2){
		throw std::out_of_range("ERROR: longest span is not possible, not enough elements!");
	}
	return (*std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end()));
}