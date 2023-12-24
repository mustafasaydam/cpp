#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "./Form.hpp"
#include <fstream>
#include <cstring>

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();
		virtual void	execute(Bureaucrat const &executor)const;
		class	ShrubberyError : public std::exception{
			public:
				const char*	what() const throw ();
		};
	private:
		std::string _target;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
	return;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {

	Form::operator=(src);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

const char*	ShrubberyCreationForm::ShrubberyError::what() const throw(){
	return "Couldn't Create file _shrubbery";
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	std::ofstream	outfile;

	if (!(this->getIsSign()))
		throw IsNotSigned();
	else if (this->getGradeForExec() < executor.getGrade())
		throw GradeTooLowForExec();
	else{
		outfile.open((this->_target + "_shrubbery").c_str(), std::ofstream::out);
		if (outfile){
			outfile << "           *****           " << std::endl;
			outfile << "          *******          " << std::endl;
			outfile << "         *********         " << std::endl;
			outfile << "        ***********        " << std::endl;
			outfile << "       *************       " << std::endl;
			outfile << "      ***************      " << std::endl;
			outfile << "             *             " << std::endl;
			outfile << "             *             " << std::endl;
			outfile << "             *             " << std::endl;
			outfile << "             *             " << std::endl;
			outfile.close();
		}
		else
			throw ShrubberyError();
	}
}

#endif