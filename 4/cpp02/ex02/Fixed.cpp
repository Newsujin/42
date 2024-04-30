#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int rhs) {
    value = rhs << bits;
}

Fixed::Fixed(const float rhs) {
    value = roundf(rhs * (1 << bits));
}

Fixed::Fixed(const Fixed &rhs) {
    *this = rhs;
}

Fixed&  Fixed::operator=(const Fixed &rhs) {
    if (&rhs == this)
        return (*this);
    value = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
    return (value);
}

void Fixed::setRawBits(int const raw) {
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

bool Fixed::operator>(Fixed const &rhs) const {
	return (getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const {
	return (getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return (getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return (getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const {
	return (getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return (getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++(void) {
	value++;
	return (*this);
}

const Fixed Fixed::operator++(int) {
	const Fixed fixed(*this);
	value++;
	return (fixed);
}

Fixed& Fixed::operator--(void) {
	value--;
	return (*this);
}

const Fixed Fixed::operator--(int) {
	const Fixed fixed(*this);
	value--;
	return (fixed);
}

Fixed &Fixed::min(Fixed &left, Fixed &right) {
	if (left <= right)
		return left;
	return right;
}

const Fixed &Fixed::min(Fixed const &left, Fixed const &right) {
	if (left <= right)
		return left;
	return right;
}

Fixed &Fixed::max(Fixed &left, Fixed &right) {
	if (left >= right)
		return left;
	return right;
}

const Fixed &Fixed::max(Fixed const &left, Fixed const &right) {
	if (left >= right)
		return left;
	return right;
}
