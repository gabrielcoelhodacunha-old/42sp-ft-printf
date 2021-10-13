NAME	= libftprintf.a
LIBFTP	= ./libft
LIBFT	= $(LIBFTP)/libft.a
CC	= clang
CFLAGS	= -Wall -Wextra -Werror
SRC	= ft_printf.c
INCLUDE = ft_printf.h
OBJS	= $(SRC:.c=.o)
AR	= ar rcs
RM	= rm -f

.c.o:		$(SRC)
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(LIBFT) $(NAME)

$(LIBFT):	$(LIBFTP)/Makefile
		$(MAKE) -C $(LIBFTP) all
		$(MAKE) -C $(LIBFTP) clean

$(NAME):	$(LIBFT) $(OBJS) $(INCLUDE)
		$(AR) $(NAME) $(LIBFT) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(LIBFT)
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
