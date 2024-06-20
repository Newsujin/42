#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& rhs) { *this = rhs; }

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs) {
		_N = rhs._N;
		_numbers = rhs._numbers;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (_numbers.size() == _N)
		throw std::logic_error("error: Span is full");

	_numbers.insert(num);
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error("error: Not enough elements to find a span");

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	std::multiset<int>::iterator start = _numbers.begin();
	std::multiset<int>::iterator end = std::next(start);

	while (end != _numbers.end()) {
		unsigned int span = static_cast<unsigned int>(std::abs(*end - *start));
		if (span < minSpan)
			minSpan = span;
		++start;
		++end;
	}
	return (minSpan);
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error("error: Not enough elements to find a span");

	return (*std::prev(_numbers.end()) - *_numbers.begin());
}