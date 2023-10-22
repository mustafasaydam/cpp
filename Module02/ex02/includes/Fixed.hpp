#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedInteger;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const int int_value);
		Fixed(const float float_value);
		Fixed(Fixed const &src);
		~Fixed();
		Fixed			&operator=(Fixed const &src);
		Fixed			operator+(Fixed const &src);
		Fixed			operator-(Fixed const &src);
		Fixed			operator*(Fixed const &src);
		Fixed			operator/(Fixed const &src);
		bool			operator<(Fixed const &src) const;
		bool			operator<=(Fixed const &src) const;
		bool			operator>(Fixed const &src) const;
		bool			operator>=(Fixed const &src) const;
		bool			operator==(Fixed const &src) const;
		bool			operator!=(Fixed const &src);
		Fixed			operator++(int);
		Fixed			&operator++(void);
		Fixed			operator--(int);
		Fixed			&operator--(void);
		static Fixed const		&min(Fixed const &v1, Fixed const &v2);
		static Fixed			&min(Fixed &v1, Fixed &v2);
		static Fixed const		&max(Fixed const &v1, Fixed const &v2);
		static Fixed			&max(Fixed &v1, Fixed &v2);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fix);

#endif