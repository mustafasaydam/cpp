#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main(){
	ShrubberyCreationForm shrubbery("Shrubbery Creation Form");
	RobotomyRequestForm robotomy("Robomoty Request Form");
	PresidentialPardonForm pardon("Presidential Pardon Form");
	try{
		std::cout << "-------------------Form error not sign--------------------" << std::endl;
		Bureaucrat patron("Boss",1);
		patron.executeForm(shrubbery);
		patron.executeForm(robotomy);
		patron.executeForm(pardon);

	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "-------------------Form error not graded enought--------------------" << std::endl;
		Bureaucrat patron("Boss",1);
		std::cout << "Boss Signed all Form" << std::endl;
		patron.signForm(shrubbery);
		patron.signForm(robotomy);
		patron.signForm(pardon);
		std::cout << "Create Intern" << std::endl;
		Bureaucrat intern("intern",150);
		intern.executeForm(shrubbery);
		intern.executeForm(robotomy);
		intern.executeForm(pardon);
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "-------------------Form Exec find--------------------" << std::endl;
		std::cout << "Create employe" << std::endl;
		Bureaucrat employe("employe",5);
		employe.executeForm(shrubbery);
		employe.executeForm(robotomy);
		employe.executeForm(pardon);
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}