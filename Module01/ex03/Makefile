NAME = Unnecessary_violence

SRCS = srcs/HumanA.cpp\
		srcs/HumanB.cpp\
		srcs/Weapon.cpp\
		srcs/main.cpp

INCLUDES = includes/HumanA.hpp\
		includes/HumanB.hpp\
		includes/Weapon.hpp

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