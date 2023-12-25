#include "../includes/Base.hpp"

int main(){
	Base *test;

	test = generate();
	identify(test);
	identify(*test);
	delete test;
}