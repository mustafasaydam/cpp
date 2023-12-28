#ifndef SCALAR_HPP
# define SCALAR_HPP
#include <iostream>
#include <limits.h>
#include <cmath>
#include <iomanip>
class Scalar {
    private:
        Scalar();
        Scalar(const char* argv);
        ~Scalar();
        Scalar(const Scalar& src);
        Scalar& operator=(const Scalar& src);
    public:
        static void convert(const char* str);
        static bool is_char(const char* str);
        static bool is_int(const char* str);
        static bool is_float(const char* str);
        static bool is_double(const char* str);
};

#endif