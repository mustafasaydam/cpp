#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int	main(){
	try{
		Intern	Stajyer;
		Stajyer.makeForm("PresidentialPardonForm", "Manu");
		Stajyer.makeForm("RobotomyRequestForm", "Ethan");
		Stajyer.makeForm("ShrubberyCreationForm", "Eric");
		Stajyer.makeForm("rien", "Manu");
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}