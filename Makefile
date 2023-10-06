.SILENT:

NAME    = push_swap

SRCS    = ft_sort.c ft_sort_five.c pushswap.c operations.c \
			ft_split.c  manager.c manager_2.c\
			ft_list_1.c ft_list_2.c ft_list_3.c

OBJS    = ${SRCS:.c=.o}


CFLAGS	= -Wall -Wextra -Werror
CL = ar -rcs
CC = cc

${NAME}:	${OBJS}
	${CL}	${NAME}	${OBJS}
	${CC}	${CFLAGS} -o $@ $^ -Iincludes/

all: ${NAME}
	printf "Compilation \033[0;32m [OK]\n\033[0m"

clean:
	${RM} ${OBJS}
	printf "clean\033[0;32m  [OK]\n\033[0m"

fclean:	clean
	${RM}	${NAME}
	printf "fclean\033[0;32m [OK]\n\033[0m"

re: fclean all

author:
		@printf "rboia-pe\n"

.PHONY: clean fclean norm all bonus re author
