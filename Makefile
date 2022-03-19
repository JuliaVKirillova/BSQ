NAME = bsq

SRCS = bsq.c checks.c finds.c free.c ft_split.c \
main.c map.c read_map.c standard.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -c

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re