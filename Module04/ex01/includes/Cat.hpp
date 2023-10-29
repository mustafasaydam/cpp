#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();
		Cat&	operator=(const Cat &src);
		Animal&	operator=(const Animal &src);
		Brain*	getBrain()const;
		virtual void	makeSound()const;
};

#endif