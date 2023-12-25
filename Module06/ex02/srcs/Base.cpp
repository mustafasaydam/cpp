#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base(){

}

Base*	generate(void){
	srand(time(NULL));
	int	choice = rand() % 3;
	Base	*ptr = NULL;

	switch (choice)
	{
	case 0:
		ptr = new A();
		break;
	case 1:
		ptr = new B();
		break;
	case 2:
		ptr = new C();
		break;	
	default:
		break;
	}
	return (ptr);
}

void	identify(Base *p){
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "Class A" << std::endl;
	else if (b)
		std::cout << "Class B" << std::endl;
	else if (c)
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p){
	try{
		A a = dynamic_cast<A &>(p); 
		std::cout << "Class A" << std::endl;
		return;
	}
	catch(std::exception& e){
	}
	try{
		B b = dynamic_cast<B &>(p); 
		std::cout << "Class B" << std::endl;
		return;
	}
	catch(std::exception& e){
	}
	try{
		C c = dynamic_cast<C &>(p); 
		std::cout << "Class C" << std::endl;
		return;
	}
	catch(std::exception& e){
	}
	std::cout << "Unknown" << std::endl;
}