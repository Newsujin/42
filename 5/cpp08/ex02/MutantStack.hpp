#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T, typename F = std::deque<T>>
class MutantStack : public std::stack<T, F> {
	public:
		typedef typename std::deque<T>::iterator iter;
		typedef typename std::deque<T>::const_iterator const_iter;

};

#endif