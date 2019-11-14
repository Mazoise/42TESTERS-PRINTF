PREFIXE		= ./

LIBPATH		= ../../

SRCS		= $(addprefix ${PREFIXE}, main_tester.c)

OBJS		= ${SRCS:.c=.o}

NAME		= tester.out

CC			= gcc

CFLAGS		= -w -Wall -Werror -Wextra -D PRINT="ft_printf" -g3 -fsanitize=address

RM			= rm -f

AR			= ar rc

LIB			= -L${LIBPATH} -lftprintf

PRINTF_MAKE	= ${MAKE} -C ${LIBPATH}

$(NAME):	${OBJS} printmake
			${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

printmake:	
			${PRINTF_MAKE}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${PRINTF_MAKE} clean

fclean:		clean
			${RM} ${NAME}
			${PRINTF_MAKE} fclean

re:			fclean all

.PHONY:		all clean fclean re
