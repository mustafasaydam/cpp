NAME = ex02

SRCS = srcs/main.cpp\
		srcs/ScavTrap.cpp\
		srcs/ClapTrap.cpp\
		srcs/FragTrap.cpp

INCLUDES = includes/ScavTrap.hpp\
			includes/ClapTrap.hpp\
			includes/FragTrap.hpp

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

%.o: %.cpp
	${COMPILER} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY: all clean fclean re