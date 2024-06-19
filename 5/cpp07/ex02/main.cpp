#include "Array.hpp"

int main() {
    try {
        // 정수형 배열 생성 및 초기화
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i * 2;

        // 정수형 배열 요소 출력
        std::cout << "intArray elements: ";
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        // 문자열 배열 생성 및 초기화
        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "world";
        strArray[2] = "!";

        // 문자열 배열 요소 출력
        std::cout << "strArray elements: ";
        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << strArray[i] << " ";
        std::cout << std::endl;

        // 복사 생성자 테스트
        Array<int> copyArray(intArray);
        std::cout << "copyArray elements after copy construction: ";
        for (unsigned int i = 0; i < copyArray.size(); i++)
            std::cout << copyArray[i] << " ";
        std::cout << std::endl;

        // 할당 연산자 테스트
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "assignedArray elements after assignment: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++)
            std::cout << assignedArray[i] << " ";
        std::cout << std::endl;

        // 예외 테스트: 범위를 벗어난 접근 시도
        std::cout << intArray[10] << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}