#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> defaultArray;
    std::cout << "기본 배열 크기: " << defaultArray.size() << std::endl;
    try {
        std::cout << "기본 배열 첫 번째 요소: " << defaultArray[0] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;

    unsigned int n = 5;
    Array<int> paramArray(n);
    std::cout << "파라미터 배열 크기: " << paramArray.size() << std::endl;
    std::cout << "파라미터 배열 요소: ";
    for (unsigned int i = 0; i < paramArray.size(); i++) {
        std::cout << paramArray[i] << " ";
    }
    std::cout << std::endl;

	std::cout << std::endl;
    Array<int> copyArray(paramArray);
    std::cout << "복사된 배열 크기: " << copyArray.size() << std::endl;
    paramArray[0] = 42;
    std::cout << "원본 배열 수정 후 첫 번째 요소: " << paramArray[0] << std::endl;
    std::cout << "복사된 배열 첫 번째 요소 (깊은 복사 확인): " << copyArray[0] << std::endl;

	std::cout << std::endl;
    Array<int> assignArray = paramArray;
    std::cout << "대입된 배열 크기: " << assignArray.size() << std::endl;
    paramArray[1] = 100;
    std::cout << "원본 배열 수정 후 두 번째 요소: " << paramArray[1] << std::endl;
    std::cout << "대입된 배열 두 번째 요소 (깊은 복사 확인): " << assignArray[1] << std::endl;
	std::cout << std::endl;

    try {
        std::cout << "배열 범위 초과 접근: " << paramArray[10] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
