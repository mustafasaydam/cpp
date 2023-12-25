#include "../includes/Scalar.hpp"

int	main(int argc, char **argv){
	if (argc == 1 || argc > 2)
		std::cout << "./ex00 <char, int, float or double>" << std::endl;
	else
	{
		Scalar	test(argv[1]);
		test.printChar();
		test.printInt();
		test.printFloat();
		test.printDouble();
	}
}