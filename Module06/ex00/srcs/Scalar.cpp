#include "../includes/Scalar.hpp"

Scalar::Scalar()
{
    std::cout << "Default constructor is called!" << std::endl;
}

Scalar::Scalar(const char *argv)
{
    std::cout << "Constructor with parameter is called!" << std::endl;
}

Scalar::~Scalar()
{
    std::cout << "Destructor is called!" << std::endl;
}

Scalar::Scalar(const Scalar &src)
{
    std::cout << "Copy Constructor is called!" << std::endl;
    *this = src;
}

Scalar&  Scalar::operator=(const Scalar& src){
    std::cout << "Assigment operator is called!" << std::endl;
    *this = src;
    return (*this);
}

bool Scalar::is_char(const char *str)
{
    if (str[0] && !str[1] && !isdigit(str[0]))
        return true;
    return false;
}

bool Scalar::is_int(const char *str)
{
    long value;
    char *endptr;

    value = strtol(str, &endptr, 10);
    if (!(*endptr) && value >= INT_MIN && value <= INT_MAX)
        return true;
    return false;
}

bool Scalar::is_float(const char *str)
{
    float value;
    char *endptr;

    value = strtof(str, &endptr);
    if (*(endptr) == 'f')
        return true;
    return false;
}

bool Scalar::is_double(const char *str)
{
    double value;
    char *endptr;

    value = strtod(str, &endptr);
    if (!*(endptr))
        return true;
    return false;
}

void Scalar::convert(const char *str)
{
    if (is_char(str))
    {
        std::cout << "char: "
                  << "'" << str[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) <<static_cast<float>(str[0])<< "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
    }
    else if (is_int(str))
    {
        long value;
        char *endptr;
        value = strtol(str, &endptr, 10);
        char c_value = static_cast<char>(value);
        if (value < CHAR_MIN || value > CHAR_MAX)
            std::cout << "char: imposible" << std::endl;
        else if (!isprint(c_value))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << c_value << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) <<static_cast<float>(value)<< "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    }
    else if (is_float(str))
    {
        float value;
        char *endptr;

        value = strtof(str, &endptr);
        char c_value = static_cast<char>(value);
        if (value < CHAR_MIN || value > CHAR_MAX)
            std::cout << "char: imposible" << std::endl;
        else if (!isprint(c_value))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << c_value << "'" << std::endl;
        if ((value < INT_MIN || value > INT_MAX) || std::isnan(value))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value)<< "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    }
    else if (is_double(str))
    {
        double value;
        char *endptr;

        value = strtod(str, &endptr);
        char c_value = static_cast<char>(value);
        if (value < CHAR_MIN || value > CHAR_MAX  || std::isnan(value))
            std::cout << "char: imposible" << std::endl;
        else if (!isprint(c_value))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << c_value << "'" << std::endl;
        if ((value < INT_MIN || value > INT_MAX) || std::isnan(value))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) <<static_cast<float>(value)<< "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}