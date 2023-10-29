#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include "./AAnimal.hpp"
#include "./Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
		Dog&	operator=(const Dog &src);
		Brain*	getBrain()const;
		void	makeSound()const;
};



#endif