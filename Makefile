NAME	= libftprintf.a
LIBFTP	= ./libft
LIBFT	= $(LIBFTP)/libft.a
CC	= clang
CFLAGS	= -Wall -Wextra -Werror
UP	= ./utils
USRC	= $(UP)/ft_printf_utils.c \
	  $(UP)/print_char.c \
	  $(UP)/print_string.c
SRC	= $(USRC) ft_printf.c
INCLUDE = ft_printf.h
OBJS	= $(SRC:.c=.o)
AR	= ar rcs
RM	= rm -f

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(LIBFT) $(NAME)

$(LIBFT):	$(LIBFTP)/Makefile
		$(MAKE) -C $(LIBFTP) -s all
		$(MAKE) -C $(LIBFTP) -s clean

$(NAME):	$(LIBFT) $(OBJS) $(INCLUDE)
		cp $(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(LIBFT)
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
