#ifndef UTILS_H
# define UTILS_H
# include "../ft_printf.h"
# define NUMBER_OF_FLAGS 8

int		print_char(char c, int *flags);
int		print_string(char *string, int *flags);
int		print_pointer(void *pointer, int *flags);
int		print_signed_decimal(int decimal, int *flags);
int		print_unsigned_decimal(int decimal, int *flags);
int		print_hexadecimal(int decimal, int *flags, char format);

char	*ft_itoa_hexadecimal(int n);

#endif
