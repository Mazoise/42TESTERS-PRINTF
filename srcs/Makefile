PREFIXE		= ./

LIBPATH		= ../../

SRCS = $(addprefix ${PREFIXE}, main_tester.c)

OBJS		= ${SRCS:.c=.o}

INCLUDES	= ../includes

NAME		= tester.out

CC			= gcc

CFLAGS		= -I ${INCLUDES} -D PRINT="ft_printf" -D REAL_F=0 #-g3 -fsanitize=address

RM			= rm -f

AR			= ar rc

LIB			= -L${LIBPATH} -lftprintf

PRINTF_MAKE	= ${MAKE} -C ${LIBPATH}

$(NAME):	${OBJS}
			${PRINTF_MAKE}
			${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${PRINTF_MAKE} clean

fclean:		clean
			${RM} ${NAME}
			${PRINTF_MAKE} fclean

re:			fclean all

.PHONY:		all clean fclean re
