#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>

class Span {
	private:
		unsigned int _N;
		std::multiset<int> _numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& rhs);
		Span& operator=(const Span& rhs);
		~Span();

		void addNumber(int num);
		template <typename T>
		void addNumbers(T& container) {
			if (_numbers.size() + container.size() > _N)
				throw std::logic_error("error: Span is full");

			typename T::iterator iter = container.begin();
			while (iter != container.end())
				_numbers.insert(*iter++);
		}
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif