#include "../inc/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Not the expected amount of arguments" << std::endl;
		std::cout << "Usage: ./RNP \"operation in Reverse Polish Notation\"" << std::endl;
		return (1);
	}

	RPN::rpn( av[1] );
}