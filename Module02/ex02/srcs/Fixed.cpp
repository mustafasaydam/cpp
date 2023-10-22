#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fixedInteger = 0;
}

//copy constructor
Fixed::Fixed(Fixed const &src){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

//constructor surcharge
Fixed::Fixed(const int int_value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedInteger = int_value * (1 << _bits);
}

Fixed::Fixed(const float float_value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedInteger = roundf((float)float_value * (1 << _bits));
}


Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

//Methodes classes
int Fixed::getRawBits(void) const{
	// std::cout << "getRawBits member function called" << std::endl;
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
	return (this->_fixedInteger >> _bits);
}

//operator copy assignement
Fixed	&Fixed::operator=(Fixed const &src){
	// std::cout << "Copy assignement operator called" << std::endl;
	this->_fixedInteger = src.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &src){
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &src){
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &src){
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &src){
	return (Fixed(this->toFloat() / src.toFloat()));
}

bool	Fixed::operator<(Fixed const &src) const{
	if (this->toFloat() < src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &src) const{
	if (this->toFloat() <= src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>(Fixed const &src) const{
	if (this->toFloat() > src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &src) const{
	if (this->toFloat() >= src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &src) const{
	if (this->toFloat() == src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &src){
	if (this->toFloat() != src.toFloat())
		return (true);
	return (false);
}

Fixed	Fixed::operator++(int){
	Fixed tmp = *this;
	this->_fixedInteger++;
	return (tmp);
}

Fixed	&Fixed::operator++(void){
	this->_fixedInteger++;
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed tmp = *this;
	this->_fixedInteger -= (1 << _bits);
	return (tmp);
}

Fixed	&Fixed::operator--(void){
	this->_fixedInteger -= (1 << _bits);
	return (*this);
}

Fixed const	&Fixed::min(Fixed const &v1, Fixed const &v2){
	if (v1 < v2)
		return (v1);
	return (v2);
}

Fixed	&Fixed::min(Fixed &v1, Fixed &v2){
	if (v1 < v2)
		return (v1);
	return (v2);
}

Fixed const	&Fixed::max(Fixed const &v1, Fixed const &v2){
	if (v1 > v2)
		return (v1);
	return (v2);
}

Fixed	&Fixed::max(Fixed &v1, Fixed &v2){
	if (v1 > v2)
		return (v1);
	return (v2);
}

//operateur de surcharge
std::ostream	&operator<<(std::ostream &o, Fixed const &fix){
	o << fix.toFloat();
	return (o);
}