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

		template<typename T>
		void merge(T& before, int iter) {
			if (before.size() == 1)
				return;

			int merge_size = before.size() / 2;
			Pair odd = std::make_pair(-1, -1);

			if (before.size() % 2 == 1)
				odd = before[before.size() - 1];

			T top;
			T bot;
			int i = 0;
			while (merge_size--) {
				top.push_back(before[i + !(before[i].first > before[i + 1].first)]);
				bot.push_back(before[i + (before[i].first > before[i + 1].first)]);
				i += 2;
    		}

			merge(top, iter + 1);
			insert(top, bot, iter);

			if (odd.first > -1)
				insertOdd(top, odd);

			before = top;
		}

		template<typename T>
		void insert(T& top, T& bot, int iter) { // iter == depth
			std::cout << "insert start " << iter << std::endl;
			T sorting = top;
			// 야콥스탈 수 1은 맨 앞이기 때문에 바로 삽입
			sorting.insert(sorting.begin(), bot[top[0].second/static_cast<int>(pow(2, iter))]);
			size_t k = 1; // 배열에 넣은 숫자 개수
			std::vector<size_t> jacobsthalArr;
			// 야콥스탈 수 배열 생성 : 1 3 5 11 ...
			for (size_t i = 1; jacobsthalNum(i) < top.size(); i++)
				jacobsthalArr.push_back(jacobsthalNum(i + 1));
 				// i + 1 삽입 이유 : 야콥 스탈 수가 0 1 1 3 5 .. 인데 2번째 1부터 삽입하기 위하여

			// 야콥스탈 수 1은 위에서 바로 sorting에 넣었기 때문에 j = 1부터 시작
			for (size_t j = 1; j < jacobsthalArr.size(); j++) {
				for (size_t i = jacobsthalArr[j]; i > jacobsthalArr[j - 1]; i--) {
					if (i > top.size())
						i = top.size();
					Pair value = bot[top[i - 1].second/static_cast<int>(pow(2, iter))];
					int st = 0;
					int en = i + k - 2; // 식 도출 방법

					while (st < en) {
						int mid = (st + en) / 2;
						if (sorting[mid].first > value.first)
							en = mid - 1;
						else
							st = mid + 1;
					}
					if (sorting[st].first > value.first)
						sorting.insert(sorting.begin() + st, value);
					else
						sorting.insert(sorting.begin() + st + 1, value);
					k++;
				}
			}
			top = sorting;
			std::cout << "insert end" << std::endl;
		}

		template<typename T>
		void insertOdd(T& top, Pair& odd) {
			int st = 0;
			int en = top.size() - 1;
			while (st < en) {
				int mid = (st + en) / 2;
				if (top[mid].first > odd.first)
					en = mid - 1;
				else
					st = mid + 1;
			}
			if (top[st].first > odd.first)
				top.insert(top.begin() + st, odd);
			else
				top.insert(top.begin() + st + 1, odd);
		}

	public:
		PmergeMe(int ac, char** av);
		~PmergeMe();

		void printInput(int state);
		void mergeInsertVec();
		void mergeInsertDeq();
};

#endif