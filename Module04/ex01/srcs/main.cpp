#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

int main()
{
	Animal *animals[20];

	for (int i = 0; i < 20; i++){
		if (i < 10)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "----------Change ideas-----------" << std::endl;
	Brain *brain_test = animals[0]->getBrain();
	for (int k = 0; k < 100; k++){
		brain_test->ideas[k] = "hungry";
	}

	*(animals[1]) = *(animals[0]);
	std::cout << animals[0]->getBrain()->ideas[0] << std::endl;
	std::cout << animals[1]->getBrain()->ideas[0] << std::endl;

	brain_test->ideas[0] = "play";
	brain_test->ideas[1] = "sleep";
	std::cout << animals[0]->getBrain()->ideas[0] << std::endl;
	std::cout << animals[1]->getBrain()->ideas[0] << std::endl;

	std::cout << "----------Print ideas-----------" << std::endl;
	std::cout << brain_test->ideas[0] << std::endl;
	std::cout << brain_test->ideas[1] << std::endl;
	std::cout << brain_test->ideas[2] << std::endl;
	std::cout << brain_test->ideas[3] << std::endl;
	std::cout << brain_test->ideas[4] << std::endl;
	std::cout << brain_test->ideas[5] << std::endl;
	std::cout << brain_test->ideas[6] << std::endl;
	std::cout << brain_test->ideas[7] << std::endl;
	std::cout << brain_test->ideas[8] << std::endl;
	std::cout << brain_test->ideas[9] << std::endl;
	std::cout << brain_test->ideas[10] << std::endl;
	for (int j = 0; j < 20 ; j++){
		delete animals[j];
	}

	std::cout << "-----------------deep copy Dog and Cat------------------" << std::endl;
	Cat first;
	Cat second;
	Cat third(first);

	first.getBrain()->ideas[0] = "Hunnnnnnnnnnnnnnnnnnnnnnnnnnnngry";
	second = first;
	first.getBrain()->ideas[0] = "Sleepinnnnnnnnnnnnnnnnnnnng";
	std::cout << "first[0] : " << first.getBrain()->ideas[0] << std::endl;
	std::cout << "second[0] : " << second.getBrain()->ideas[0] << std::endl;
	std::cout << "third[0] : " << third.getBrain()->ideas[0] << std::endl;
	return 0;
}