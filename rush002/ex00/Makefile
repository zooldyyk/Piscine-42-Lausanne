SRCSDIR		= ./
SRCS		= main.c functions.c functions2.c manage_file.c print.c
SRCSPATH	= ${patsubst %,${SRCSDIR}%,${SRCS}}

OBJS		= ${SRCSPATH:.c=.o}

NAME		= rush-02

CC		= gcc
RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re

