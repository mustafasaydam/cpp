#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* Wa = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << Wa->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	Wa->makeSound();
	delete meta;
	delete j;
	delete i;
	delete Wa;
	return 0;
}