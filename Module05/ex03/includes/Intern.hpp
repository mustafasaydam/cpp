#ifndef INTERN_HPP
# define INTERN_HPP
#include <iostream>
#include "./Form.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./Form.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"

class Form;
class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		Intern&	operator=(const Intern &src);
		Form*	makeForm(std::string name_form, std::string target_form);
		class FormNotFound : public std::exception{
			public:
				const char*	what() const throw ();
		};
		~Intern();
};

Intern::Intern(){
	return ;
}

Intern::Intern(const Intern &src){
	*this = src;
	return ;
}

Intern&	Intern::operator=(const Intern &src){
	if (this != &src)
		*this = src;
	return (*this);
}

Intern::~Intern(){
	return ;
}

const char*	Intern::FormNotFound::what() const throw(){
	return "Form : Not Found";
}

Form*	Intern::makeForm(std::string name_form, std::string target_form){
	std::string	form[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	int i = 0;
	for (; i < 3; i++){
		if(form[i] == name_form)
			break;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << name_form << std::endl;
			return (new ShrubberyCreationForm(target_form));
		case 1:
			std::cout << "Intern creates " << name_form << std::endl;
			return (new PresidentialPardonForm(target_form));
		case 2:
			std::cout << "Intern creates " << name_form << std::endl;
			return (new RobotomyRequestForm(target_form));
		default:
			throw FormNotFound();
	}
}

#endif