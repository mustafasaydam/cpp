#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int					_fixedInteger;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(Fixed const &src);
		~Fixed();
		Fixed    &operator=(Fixed const &src);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif