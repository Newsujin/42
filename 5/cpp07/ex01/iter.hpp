#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void iter(T* array, int len, F func) {
    for (int i = 0; i < len; i++)
        func(array[i]);
}

template <typename T>
void square(T& val) {
    val *= val;
}

template <typename T>
void print(const T& val) {
    std::cout << val << std::endl;
}

#endif