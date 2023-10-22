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
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fix);

#endif