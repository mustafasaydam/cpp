#ifndef AANIMAL_HPP
# define AANIMAL_HPP
#include <iostream>
#include "./Brain.hpp"

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal();
		AAnimal(const AAnimal &src);
		AAnimal& operator=(const AAnimal &src);
		virtual ~AAnimal() = 0;
		
		const std::string	getType()const;
		virtual void	makeSound()const = 0;
		virtual Brain*	getBrain() const = 0;
};



#endif