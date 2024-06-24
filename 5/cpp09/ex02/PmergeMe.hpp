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
		void mergeVec(std::vector<Pair>& before, int iter);
		void insertVec(std::vector<Pair>& top, std::vector<Pair>& bot, int iter);
		void insertVecOdd(std::vector<Pair>& top, Pair& odd);

	public:
		PmergeMe(int ac, char** av);
		~PmergeMe();

		void printInput(int state);
		void mergeInsertVec();
};

#endif