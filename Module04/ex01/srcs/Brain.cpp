#include "../includes/Brain.hpp"

Brain::Brain(){
	std::cout << "Constructor Brain" << std::endl;
	for (int i = 0; i < 100; i++){
		this->ideas[i] = "No idea";
	}
}

Brain::~Brain(){
	std::cout << "Destructor Brain" << std::endl;
}

Brain::Brain(const Brain &src){
	*this = src;
	std::cout << "Copy Constructor Brain" << std::endl;
}

Brain&	Brain::operator=(const Brain &src){
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++){
		this->ideas[i] = src.ideas[i];
	}
	return (*this);
}