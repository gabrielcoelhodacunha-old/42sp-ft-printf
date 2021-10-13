NAME	= libft.a

CC	= clang

CFLAGS	= -Wall -Wextra -Werror

PART_1	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c

PART_2	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	  ft_lstmap.c

INCLUDE = libft.h

OBJS	= $(PART_1:.c=.o) $(PART_2:.c=.o)

BOBJS	= $(BONUS:.c=.o)

AR	= ar rcs

RM	= rm -f

.c.o:		$(PART_1) $(PART_2)
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
		$(AR) $(NAME) $(OBJS)

bonus:		$(BOBJS) $(INCLUDE)
		$(AR) $(NAME) $(BOBJS)

clean:
		$(RM) $(OBJS) $(BOBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
