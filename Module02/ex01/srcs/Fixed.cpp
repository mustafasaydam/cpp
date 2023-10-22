#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedInteger = 0;
}

Fixed::Fixed(const int int_value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedInteger = int_value * (1 << _bits);
}

Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedInteger = roundf((float)float_value * (1 << _bits));
}

Fixed::Fixed(Fixed const &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &src){
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fixedInteger = src.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fix){
	o << fix.toFloat();
	return (o);
}

int Fixed::getRawBits(void) const{
	//std::cout << "getRawBits member function called" << std::endl;
	return(this->_fixedInteger);
}

void Fixed::setRawBits(int const raw){
	this->_fixedInteger = raw;
	return ;
}

float	Fixed::toFloat( void ) const{
	float num;
	num = (float)this->_fixedInteger / (1 << _bits);
	return (num);
}

int		Fixed::toInt( void ) const{
	return (this->_fixedInteger / (1 << _bits));
}