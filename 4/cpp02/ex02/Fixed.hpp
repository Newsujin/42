#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	value;
		const static int bits = 8;
	public:
		Fixed();
		Fixed(const int rhs);
		Fixed(const float rhs);
		Fixed(const Fixed &rhs);
		Fixed &operator=(const Fixed &rhs);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

		bool operator>(Fixed const &rhs) const;
		bool operator<(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;

		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;

		Fixed &operator++(void);
		const Fixed operator++(int);
		Fixed &operator--(void);
		const Fixed operator--(int);

		static Fixed &min(Fixed &left, Fixed &right);
		static const Fixed &min(Fixed const &left, Fixed const &right);
		static Fixed &max(Fixed &left, Fixed &right);
		static const Fixed &max(Fixed const &left, Fixed const &right);
};

std::ostream& operator<<(std::ostream &out, const Fixed &rhs);

#endif