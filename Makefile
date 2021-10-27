NAME	= libftprintf.a
LIBFTP	= ./libft
LIBFT	= $(LIBFTP)/libft.a
CC	= clang
CFLAGS	= -Wall -Wextra -Werror
SRC	= ft_printf.c print_without_format.c print_formated.c get_flags.c \
	  print_char.c print_string.c print_hexadecimal.c ft_uitoa_base.c
INCLUDE	= ft_printf.h
OBJP	= ./obj/
OBJS	= $(SRC:%.c=$(OBJP)%.o)
AR	= ar rcs
RM	= rm -fr
VPATH	= . ./src ./include $(OBJP)

$(OBJP)%.o:	%.c
		mkdir -p $(OBJP)
		$(CC) $(CFLAGS) -c $< -o $@

all:		$(LIBFT) $(NAME)

$(LIBFT):	$(LIBFTP)/Makefile
		$(MAKE) -C $(LIBFTP) -s

$(NAME):	$(LIBFT) $(OBJS) $(INCLUDE)
		cp $(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

clean:
		$(MAKE) -C $(LIBFTP) -s clean
		$(RM) $(OBJP)

fclean:		clean
		$(MAKE) -C $(LIBFTP) -s fclean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
