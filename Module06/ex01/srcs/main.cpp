#include "../includes/Serializer.hpp"

int main(){
	Data Test;
	Data Result;

	std::cout << "-----------Init Data Test--------------" << std::endl;
	Test.c = 10;
	Test.n = "Test of serialize";

	std::cout << "Test: " << &Test << " " << Test.c << " " << Test.n << std::endl;
	std::cout << "Result: "<< &Result << " " << Result.c << " " << Result.n << std::endl;
	std::cout << "-----------Serialize Data Test--------------" << std::endl;
	uintptr_t raw = Serializer::serialize(&Test);
	std::cout << raw << std::endl;
	std::cout << "-----------Deserialize Data Test In result --------------" << std::endl;
	Result = *Serializer::deserialize(raw);
	std::cout << "Result: "<< &Result << " " << Result.c << " " << Result.n << std::endl;
	std::cout << "Test: " << &Test << " " << Test.c << " " << Test.n << std::endl;

}