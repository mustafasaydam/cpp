#include "../includes/Scalar.hpp"

Scalar::Scalar()
{
	std::cout << "Default constructor" << std::endl;
	this->all_impossible = true;
}

Scalar::Scalar(const char *arg){
	this->impossible_ch = false;
	this->impossible_int = false;
	this->all_impossible = false;
	detect_type(arg);
	if (this->db_value < INT_MIN || this->db_value > INT_MAX || isnan(this->db_value))
	{
		this->impossible_int = true;
		this->impossible_ch = true;
	}
	else if (this->db_value < CHAR_MIN || this->db_value > CHAR_MAX)
		this->impossible_ch = true;
}


Scalar::Scalar(const Scalar& src)
{
	std::cout << "Copy constructor" << std::endl;
	*this = src;
}

Scalar&	Scalar::operator=(const Scalar& src){
	this->impossible_ch = src.impossible_ch;
	this->impossible_int = src.impossible_ch;
	this->all_impossible = src.impossible_ch;
	this->db_value = src.db_value;
	this->int_value = src.int_value;
	this->fl_value = src.fl_value;
	this->ch_value = src.ch_value;
	return (*this);
}


bool	Scalar::check_is_char(const char *str){
	if (str[0] && !str[1] && !isdigit(str[0]))
	{
		this->ch_value = str[0];
		this->int_value = static_cast<int>(str[0]);
		this->fl_value = static_cast<float>(str[0]);
		this->db_value = static_cast<double>(str[0]);
		return (true);
	}
	return (false);
}

bool	Scalar::is_integer(const char *str){
	long value;
	char	*endptr;

	value = strtol(str, &endptr, 10);
	if (!(*endptr) && (value >= INT_MIN && value <= INT_MAX))
	{
		this->int_value = static_cast<int>(value);
		this->fl_value = static_cast<float>(value);
		this->db_value = static_cast<double>(value);
		this->ch_value = static_cast<char>(value);
		return (true);
	}
	return (false);
}

bool	Scalar::is_float(const char *str){
	float	value;
	char	*endptr;

	value = strtof(str, &endptr);
	if ((*endptr) == 'f')
	{
		this->fl_value = value;
		this->int_value = static_cast<int>(value);
		this->db_value = static_cast<double>(value);
		this->ch_value = static_cast<char>(value);
		return (true);
	}
	return (false);
}

bool	Scalar::is_double(const char *str){
	double	value;
	char	*endptr;

	value = strtod(str, &endptr);
	if (!(*endptr))
	{
		this->db_value = value;
		this->fl_value = static_cast<float>(value);
		this->int_value = static_cast<int>(value);
		this->ch_value = static_cast<char>(value);
		return (true);
	}
	return (false);
}

void	Scalar::printChar(){
	std::cout << "char: ";
	if (this->all_impossible || this->impossible_ch)
		std::cout << "impossible" << std::endl;
	else if (!isprint(this->ch_value))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(this->ch_value) << "'" << std::endl;
}

void	Scalar::printInt(){
	std::cout << "int: ";
	if (this->all_impossible || this->impossible_int)
		std::cout << "impossible" << std::endl;
	else
		std::cout <<  static_cast<int>(this->int_value) << std::endl;
}

void	Scalar::printDouble(){
	std::cout << "double: ";
	if (this->all_impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(this->db_value) << std::endl;
}

void	Scalar::printFloat(){
	std::cout << "float: ";
	if (this->all_impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) <<static_cast<float>(this->fl_value)<< "f" << std::endl;
}

void	Scalar::detect_type(const char *arg){
	if (check_is_char(arg))
		return;
	else if (is_integer(arg))
		return;
	else if (is_double(arg))
		return;
	else if (is_float(arg))
		return;
	this->all_impossible = true;
	return;
}

Scalar::~Scalar()
{
}
