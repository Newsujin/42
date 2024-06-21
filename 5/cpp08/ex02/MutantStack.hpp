#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T, typename F = std::deque<T> >
class MutantStack : public std::stack<T, F> {
	public:
		MutantStack() : std::stack<T, F>() {}
		MutantStack(const MutantStack& rhs) : std::stack<T, F> (rhs) {}
		MutantStack& operator=(const MutantStack& rhs) {
			if (this != &rhs)
				*this = rhs;
			return (*this);
		}
		~MutantStack() {}

		typedef typename F::iterator iterator;
        typedef typename F::const_iterator const_iterator;
        typedef typename F::reverse_iterator reverse_iterator;
        typedef typename F::const_reverse_iterator const_reverse_iterator;

		//default
		iterator begin() {
			return (this->c.begin());
		}
		iterator end() {
			return (this->c.end());
		}
		const_iterator begin() const {
			return (this->c.begin());
		}
		const_iterator end() const {
			return (this->c.end());
		}

		//reverse
		reverse_iterator rbegin() {
			return (this->c.rbegin());
		}
		reverse_iterator rend() {
			return (this->c.rend());
		}
		const_reverse_iterator rbegin() const {
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const {
			return (this->c.rend());
		}
};

#endif