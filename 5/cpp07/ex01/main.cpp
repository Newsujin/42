#include "iter.hpp"

int main() {
    char arr1[] = "abc";
    int arr2[] = {1, 2, 3, 4, 5};

    iter(arr1, 4, print<char>);
    iter(arr2, 5, print<int>);
    std::cout << std::endl;

    iter(arr2, 5, square<int>);
    iter(arr2, 5, print<int>);

    return (0);
}