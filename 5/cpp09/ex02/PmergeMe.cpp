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
	mergeVec(top, 1);
	// 하위 벡터의 요소들을 상위 벡터에 삽입
	insertVec(top, bot, 0);

	// 홀수인 경우 마지막 요소 삽입
	if (odd.first != -1)
		insertVecOdd(top, odd);

	// vec에 정렬된 숫자 저장
	for (size_t j = 0; j < top.size(); j++)
		vec[j] = top[j].first;
}

void PmergeMe::mergeVec(std::vector<Pair>& before, int iter) {
    if (before.size() == 1)
        return;

    int merge_size = before.size() / 2;
    Pair odd = std::make_pair(-1, -1);

    if (before.size() % 2 == 1)
        odd = before[before.size() - 1];

    std::vector<Pair> top;
    std::vector<Pair> bot;
    int i = 0;
    while (merge_size--) {
        top.push_back(before[i + !(before[i].first > before[i + 1].first)]);
        bot.push_back(before[i + (before[i].first > before[i + 1].first)]);
        i += 2;
    }

    mergeVec(top, iter + 1);
    insertVec(top, bot, iter);

    if (odd.first > -1)
        insertVecOdd(top, odd);

    before = top;
}

void PmergeMe::insertVec(std::vector<Pair>& top, std::vector<Pair>& bot, int iter) {
    for (size_t i = 0; i < bot.size(); i++) {
        int check = top[i * 2].second / static_cast<int>(pow(2, iter));
        int st = 0;
        int en = i * 2;
        while (st < en) {
            int mid = (st + en) / 2;
            if (top[mid].first > bot[check].first)
                en = mid - 1;
            else
                st = mid + 1;
        }
        if (top[st].first > bot[check].first)
            top.insert(top.begin() + st, bot[check]);
        else
            top.insert(top.begin() + st + 1, bot[check]);
    }
}

void PmergeMe::insertVecOdd(std::vector<Pair>& top, Pair& odd) {
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