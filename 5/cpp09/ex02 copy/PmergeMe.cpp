#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char** av) {
    for (int i = 1; i < ac; i++) {
        std::string arg = av[i];
        if (!isNumber(arg))
            throw std::logic_error("Error: not a number: " + arg);

        long long number = std::atol(av[i]);
        if (number > 2147483647 || number < -2147483648)
            throw std::logic_error("Error: number out of int range: " + arg);

        vec.push_back(static_cast<int>(number));
        deq.push_back(static_cast<int>(number));
    }
}

PmergeMe::PmergeMe(const PmergeMe& rhs) { *this = rhs; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if (this != &rhs) {
		//
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isNumber(const std::string& number) const {
    for (size_t i = 0; i < number.size(); i++)
        if (!isdigit(number[i]))
            return (false);
    return (true);
}

void PmergeMe::printInput(int state) {
	if (state == BEFORE_SORT)
		std::cout << "before: ";
	else if (state == AFTER_SORT)
		std::cout << "after: ";

	for (size_t i = 0; i < vec.size() - 1; i++)
		std::cout << vec[i] << " ";
	std::cout << vec[vec.size() - 1] << std::endl;
}

void PmergeMe::mergeInsertVec() {
	int mergeSize = vec.size() / 2;
	Pair odd = std::make_pair(-1, -1);

	// 홀수면 마지막 수를 odd에 삽입
	if (vec.size() % 2 == 1)
		odd = std::make_pair(vec[vec.size() - 1], -1);

	std::vector<Pair> top;
	std::vector<Pair> bot;
	int i = 0;
	int idx = 0;

    // 상위 및 하위 벡터 생성
	while (mergeSize--) {
		top.push_back(std::make_pair(vec[i + !(vec[i] > vec[i + 1])], idx++));
		bot.push_back(std::make_pair(vec[i + (vec[i] > vec[i + 1])], -1));
		i += 2;
	}
	// 상위 벡터를 재귀적으로 병합 정렬
	merge(top, 1);
	// 하위 벡터의 요소들을 상위 벡터에 삽입
	insert(top, bot, 0);

	// 홀수인 경우 마지막 요소 삽입
	if (odd.first != -1)
		insertOdd(top, odd);

	// vec에 정렬된 숫자 저장
	for (size_t j = 0; j < top.size(); j++)
		vec[j] = top[j].first;
}

void PmergeMe::mergeInsertDeq() {
	int mergeSize = deq.size() / 2;
	Pair odd = std::make_pair(-1, -1);

	if (deq.size() % 2 == 1)
		odd = std::make_pair(deq[deq.size() - 1], -1);

	std::deque<Pair> top;
	std::deque<Pair> bot;
	int i = 0;
	int idx = 0;

    // 상위 및 하위 벡터 생성
	while (mergeSize--) {
		top.push_back(std::make_pair(deq[i + !(deq[i] > deq[i + 1])], idx++));
		bot.push_back(std::make_pair(deq[i + (deq[i] > deq[i + 1])], -1));
		i += 2;
	}
	// 상위 벡터를 재귀적으로 병합 정렬
	merge(top, 1);
	// 하위 벡터의 요소들을 상위 벡터에 삽입
	insert(top, bot, 0);

	// 홀수인 경우 마지막 요소 삽입
	if (odd.first != -1)
		insertOdd(top, odd);

	// vec에 정렬된 숫자 저장
	for (size_t j = 0; j < top.size(); j++)
		deq[j] = top[j].first;
}

size_t PmergeMe::jacobsthalNum(size_t n) {
    return ((pow(2, n) - pow(-1, n)) / 3);
}
