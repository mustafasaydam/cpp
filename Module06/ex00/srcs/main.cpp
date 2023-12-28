#include "../includes/Scalar.hpp"

int main(int argc, char *argv[]){
    if(argc != 2)
        std::cout << "true usage: ./ex00 <char, int, float, double>" << std::endl;
    else
        Scalar::convert(argv[1]);
    return 0;
}