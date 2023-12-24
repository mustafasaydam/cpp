#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "./Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string	_name;
		bool				_isSign;
		int					_gradeForSign;
		int					_gradeForExec;
	public:
		Form();
		Form&	operator=(const Form& src);
		Form(const Form &src);
		Form(std::string name, int gradeForSign, int gradeForExec);
		~Form();

		void	beSigned(Bureaucrat &emp);
		std::string	getName()const;
		int			getGradeForSign()const;
		int			getGradeForExec()const;
		bool		getIsSign()const;
		virtual void		execute(Bureaucrat const &executor)const = 0;
		class	GradeTooHighException : public std::exception{
			public:
				const char*	what() const throw ();
		};
		class	GradeTooLowException : public std::exception{
			public:
				const char*	what() const throw ();
		};
		class	GradeTooLowForExec : public std::exception{
			public:
				const char*	what() const throw ();
		};
		class	IsNotSigned : public std::exception{
			public:
				const char*	what() const throw ();
		};
};
std::ostream&	operator<<(std::ostream& os, const Form& Formulaire);

#endif