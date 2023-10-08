NAME = BraiiiiiiinnnzzzZ

SRCS = srcs/main.cpp\
		srcs/newZombie.cpp\
		srcs/Zombie.cpp\
		srcs/randomChump.cpp

INCLUDES = includes/Zombie.hpp

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