#include "Span.hpp"
#include <list>
#include <vector>

int main() {
	// vector test
    try {
        Span sp = Span(5);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);

        std::vector<int> vecs;
        vecs.push_back(15);
        vecs.push_back(20);
        // vecs.push_back(30); //span full error
        sp.addNumbers(vecs);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

	// list test
    try {
        Span sp2 = Span(5);
        sp2.addNumber(10);
        sp2.addNumber(20);
        sp2.addNumber(30);

        std::list<int> lists;
        lists.push_back(40);
        lists.push_back(50);
        sp2.addNumbers(lists);

        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

	// 10000 elements test
    try {
        Span sp3 = Span(10000);
        std::vector<int> bigN(10000);
        for (int i = 0; i < 10000; ++i)
            bigN[i] = i;
        sp3.addNumbers(bigN);

        std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
