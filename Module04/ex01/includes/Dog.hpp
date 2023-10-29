#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
		Dog&	operator=(const Dog &src);
		Animal&	operator=(const Animal &src);
		Brain*	getBrain()const;
		virtual void	makeSound()const;
};



#endif