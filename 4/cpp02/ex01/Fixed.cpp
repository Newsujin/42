#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int rhs) {
    std::cout << "Int constructor called" << std::endl;
    value = rhs << bits;
}

Fixed::Fixed(const float rhs) {
    std::cout << "Float constructor called" << std::endl;
    value = roundf(rhs * (1 << bits));
}

Fixed::Fixed(const Fixed &rhs) {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed&  Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (&rhs == this)
        return (*this);
    value = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    return (value);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

float Fixed::toFloat() const {
    return ((float)value / (1 << bits));
}

int Fixed::toInt() const {
    return (value >> bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &rhs)
{
    out << rhs.toFloat();
    return (out);
}
