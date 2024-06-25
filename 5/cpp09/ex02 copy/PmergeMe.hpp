#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>

# define BEFORE_SORT 0
# define AFTER_SORT 1

class PmergeMe {
	private:
		typedef std::pair<int, int> Pair;
		std::vector<int> vec;
		std::deque<int> deq;

		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);

		bool isNumber(const std::string& number) const;
		size_t jacobsthalNum(size_t n);

		/* vector */
		void mergeVec(std::vector<Pair>& before, int iter);
		void insertVec(std::vector<Pair>& top, std::vector<Pair>& bot, int iter);
		void insertVecOdd(std::vector<Pair>& top, Pair& odd);

		/* deque */
		void mergeDeq(std::deque<Pair>& before, int iter);
		void insertDeq(std::deque<Pair>& top, std::deque<Pair>& bot, int iter);
		void insertDeqOdd(std::deque<Pair>& top, Pair& odd);

	public:
		PmergeMe(int ac, char** av);
		~PmergeMe();

		void fordJohnsonVec();
		void fordJohnsonDeq();
		void printVec(int state);
		void printDeq(int state);
};

#endif