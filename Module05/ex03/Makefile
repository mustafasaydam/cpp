NAME = ex03

SRCS = srcs/main.cpp\
		srcs/Bureaucrat.cpp\
		srcs/Form.cpp

INCLUDES = includes/Bureaucrat.hpp\
			includes/Form.hpp\
			includes/PresidentialPardonForm.hpp\
			includes/ShrubberyCreationForm.hpp\
			includes/RobotomyRequestForm.hpp\
			includes/Intern.hpp


COMPILER = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
		${COMPILER} ${FLAGS} ${OBJS} -I includes -o ${NAME}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${OBJS} ${NAME}

re: fclean all

.PHONY: all clean fclean re