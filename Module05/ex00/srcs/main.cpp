#include "../includes/Bureaucrat.hpp"

int	main(){
	try
	{
		std::cout << "----------------Create Employe with a bad grade----------------" << std::endl;
		Bureaucrat Probleme("Probleme",6666);
		std::cout << Probleme << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "----------------Create BOSS----------------" << std::endl;
		Bureaucrat Patron("Boss", 1);
		std::cout << Patron << std::endl;
		Patron.getPromoted();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try {
		std::cout << "----------------Create Employe----------------" << std::endl;
		Bureaucrat Manager("SubBoss", 25);
		std::cout << Manager << std::endl;
		for (int i=0; i < 24; i++){
			Manager.getPromoted();
		}
		std::cout << Manager << std::endl;
	}
	catch(const std::exception &src)
	{
		std::cout << src.what() <<std::endl;
	}
	try
	{
		std::cout << "----------------Create Intern----------------" << std::endl;
		Bureaucrat Intern;
		Intern.getRetrograded();
		std::cout << Intern << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}