NAME	= libftprintf.a
LIBFTP	= ./libft
LIBFT	= $(LIBFTP)/libft.a
CC	= clang
CFLAGS	= -Wall -Wextra -Werror
SRC	= ft_printf.c
INCLUDE	= ft_printf.h
OBJP	= ./obj/
OBJS	= $(SRC:%.c=$(OBJP)%.o)
AR	= ar rcs
RM	= rm -f
VPATH	= . ./src ./include $(OBJP)

$(OBJP)%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

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
