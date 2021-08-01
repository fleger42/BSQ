NAME		= do-op

all: ${NAME}

CFLAGS		= -Wall -Wextra -Werror

SRCS_PATH	= ./srcs/

GCC 		= cc

RM 			= rm -f

HEAD 		= includes
 
SRCS = ${SRCS_PATH}ecrire_solution.c ${SRCS_PATH}ft_atoi.c ${SRCS_PATH}lire_ecrire.c ${SRCS_PATH}main.c

OBJS = ${SRCS_PATH}ecrire_solution.o ${SRCS_PATH}ft_atoi.o ${SRCS_PATH}lire_ecrire.o ${SRCS_PATH}main.o

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}
.c.o:
		${GCC} ${CFLAGS} -c $< -I ${HEAD} -o ${<:.c=.o}
clean:
		${RM} ${OBJS}

re:			fclean all

fclean:			clean
		${RM} ${NAME}

.PHONY: re clean fclean all
