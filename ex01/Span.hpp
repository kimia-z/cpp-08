#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <stdexcept>

class Span
{
private:
	unsigned int		_max_length;
	std::vector<int>	_numbers;

public:
	Span(unsigned int max_len);
	Span(const Span &src);
	Span operator=(const Span &src);
	~Span();

	template <typename IT>
	void addNumber(IT begin, IT end){
		if(_numbers.size() + std::distance(begin, end) > _max_length){
		throw std::overflow_error("ERROR: span is full, you can not add anymore number!");
		}
		_numbers.insert(_numbers.end(), begin, end);
	}

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
};

#endif