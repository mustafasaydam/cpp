#include "../includes/Span.hpp"

int main(){

	try{
		Span test(5);
		std::cout << "-------------Test Error shortSpan------------" << std::endl;
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "-------------Test all Work------------" << std::endl;
		Span test2(5);
		test2.addNumber(3);
		test2.addNumber(0);
		test2.addNumber(25);
		test2.addNumber(24);
		test2.addNumber(5);
		test2.addNumber(21);
		std::cout << test2.longestSpan() << std::endl;
		std::cout << test2.shortestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "-------------Test Error Range addNumber range------------" << std::endl;
		Span test3(10000);

		test3.addNumberRange(10000, 10000);
		std::cout << test3.longestSpan() << std::endl;
		std::cout << test3.shortestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "-------------Test Error Range addNumber range------------" << std::endl;
		Span test3(100000);

		test3.addNumberRange(0, 100000);
		std::cout << test3.longestSpan() << std::endl;
		std::cout << test3.shortestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}