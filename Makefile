NAME	= libftprintf.a

SRCS	=  part_1.c part_2.c ft_printf.c 

OBJS	= $(SRCS:.c=.o)

BONUS_S	=  

BONUS_O	= $(BONUS_S:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

LIB		= ar -rcs

RM		=	rm -f


all:	$(NAME)

$(NAME):	$(OBJS)
		$(LIB) $(NAME) $(OBJS)

bonus:		$(NAME) $(BONUS_O)
		$(LIB) $(NAME) $(BONUS_O)

clean:
		$(RM) $(OBJS) $(BONUS_O)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re
