#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

template <typename T>
class Array {
    private:
        T* _arr;
        unsigned int _size;

    public:
        Array() : _arr(NULL), _size(0) {}

        Array(unsigned int n) : _arr(new T[n]), _size(n) {}

        Array(const Array& rhs) : _arr(NULL), _size(0) { *this = rhs; }

        Array &operator=(const Array& rhs) {
            if (this != &rhs) {
				if (_arr)
                	delete[] _arr;
                _size = rhs._size;
				if (_size > 0)
					_arr = new T[_size];
				else
					_arr = NULL;
				for (unsigned int i = 0; i < _size; i++)
					_arr[i] = rhs._arr[i];
            }
            return (*this);
        }

        ~Array() { delete[] _arr; }

        T& operator[](unsigned int idx) {
            if (idx >= _size)
                throw std::out_of_range("Index out of bounds");
            return (_arr[idx]);
        }

        const T& operator[](unsigned int idx) const {
            if (idx >= _size)
                throw std::out_of_range("Index out of bounds");
            return (_arr[idx]);
        }

        unsigned int size() const { return (_size); }
};

#endif