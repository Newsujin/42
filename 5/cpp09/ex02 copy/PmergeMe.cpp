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
		vec = rhs.vec;
		deq = rhs.deq;
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

size_t PmergeMe::jacobsthalNum(size_t n) {
    return ((pow(2, n) - pow(-1, n)) / 3);
}

/* vector */
void PmergeMe::fordJohnsonVec() {
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

void PmergeMe::insertVec(std::vector<Pair>& top, std::vector<Pair>& bot, int iter) { // iter == depth
	std::vector<Pair> sorting = top;
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

void PmergeMe::printVec(int state) {
	if (state == BEFORE_SORT)
		std::cout << "Before: ";
	else if (state == AFTER_SORT)
		std::cout << "After: ";

	for (size_t i = 0; i < vec.size() - 1; i++)
		std::cout << vec[i] << " ";
	std::cout << vec[vec.size() - 1] << std::endl;
}

/* deque */
void PmergeMe::fordJohnsonDeq() {
	int mergeSize = deq.size() / 2;
	Pair odd = std::make_pair(-1, -1);

	if (deq.size() % 2 == 1)
		odd = std::make_pair(deq[deq.size() - 1], -1);

	std::deque<Pair> top;
	std::deque<Pair> bot;
	int i = 0;
	int idx = 0;

	while (mergeSize--) {
		top.push_back(std::make_pair(deq[i + !(deq[i] > deq[i + 1])], idx++));
		bot.push_back(std::make_pair(deq[i + (deq[i] > deq[i + 1])], -1));
		i += 2;
	}
	mergeDeq(top, 1);
	insertDeq(top, bot, 0);

	if (odd.first != -1)
		insertDeqOdd(top, odd);

	for (size_t j = 0; j < top.size(); j++)
		deq[j] = top[j].first;
}

void PmergeMe::mergeDeq(std::deque<Pair>& before, int iter) {
    if (before.size() == 1)
        return;

    int merge_size = before.size() / 2;
    Pair odd = std::make_pair(-1, -1);

    if (before.size() % 2 == 1)
        odd = before[before.size() - 1];

    std::deque<Pair> top;
    std::deque<Pair> bot;
    int i = 0;
    while (merge_size--) {
        top.push_back(before[i + !(before[i].first > before[i + 1].first)]);
        bot.push_back(before[i + (before[i].first > before[i + 1].first)]);
        i += 2;
    }

    mergeDeq(top, iter + 1);
    insertDeq(top, bot, iter);

    if (odd.first > -1)
        insertDeqOdd(top, odd);

    before = top;
}

void PmergeMe::insertDeq(std::deque<Pair>& top, std::deque<Pair>& bot, int iter) {
	std::deque<Pair> sorting = top;
	sorting.insert(sorting.begin(), bot[top[0].second/static_cast<int>(pow(2, iter))]);
	size_t k = 1;
	std::deque<size_t> jacobsthalArr;
	for (size_t i = 1; jacobsthalNum(i) < top.size(); i++)
		jacobsthalArr.push_back(jacobsthalNum(i + 1));

	for (size_t j = 1; j < jacobsthalArr.size(); j++) {
		for (size_t i = jacobsthalArr[j]; i > jacobsthalArr[j - 1]; i--) {
			if (i > top.size())
				i = top.size();
			Pair value = bot[top[i - 1].second/static_cast<int>(pow(2, iter))];
			int st = 0;
			int en = i + k - 2;

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
}

void PmergeMe::insertDeqOdd(std::deque<Pair>& top, Pair& odd) {
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

void PmergeMe::printDeq(int state) {
	if (state == BEFORE_SORT)
		std::cout << "Before: ";
	else if (state == AFTER_SORT)
		std::cout << "After: ";

	for (size_t i = 0; i < deq.size() - 1; i++)
		std::cout << deq[i] << " ";
	std::cout << deq[deq.size() - 1] << std::endl;
}
