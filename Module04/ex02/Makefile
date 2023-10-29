NAME = ex02

SRCS = srcs/main.cpp\
		srcs/AAnimal.cpp\
		srcs/Dog.cpp\
		srcs/Cat.cpp\
		srcs/Brain.cpp

INCLUDES = includes/AAnimal.hpp\
			includes/Dog.hpp\
			includes/Cat.hpp\
			includes/Brain.hpp

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