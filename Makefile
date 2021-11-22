SRCS	=	ft_printf.c parser.c print_d.c conversions.c print_s.c print_c.c print_others.c print_p.c utils_1.c utils_2.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a 

CC	= cc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

RM	= rm -f

$(NAME):	${OBJS} 
	make -C ./libft all
	cp ./libft/libft.a ./libftprintf.a
	ar -rcs ${NAME} ${OBJS}

all:	$(NAME) 

clean:
	${RM} ${OBJS}
	make -C ./libft clean

fclean:	clean
	${RM} ${NAME}
	make -C ./libft fclean

re:	fclean all

.PHONY: 	all clean fclean