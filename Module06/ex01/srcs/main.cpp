#include <iostream>
#include <stdint.h>

struct Data{
	int c;
	std::string n;
};

uintptr_t	serialize(Data*	ptr){
	uintptr_t	value;

	value = reinterpret_cast<uintptr_t>(ptr);
	return (value);
}

Data*	deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}

int main(){
	Data Test;
	Data Result;

	std::cout << "-----------Init Data Test--------------" << std::endl;
	Test.c = 10;
	Test.n = "Test of serialize";

	std::cout << "Test: " << &Test << " " << Test.c << " " << Test.n << std::endl;
	std::cout << "Result: "<< &Result << " " << Result.c << " " << Result.n << std::endl;
	std::cout << "-----------Serialize Data Test--------------" << std::endl;
	uintptr_t raw = serialize(&Test);
	std::cout << raw << std::endl;
	std::cout << "-----------Deserialize Data Test In result --------------" << std::endl;
	Result = *deserialize(raw);
	std::cout << "Result: "<< &Result << " " << Result.c << " " << Result.n << std::endl;
	std::cout << "Test: " << &Test << " " << Test.c << " " << Test.n << std::endl;

}