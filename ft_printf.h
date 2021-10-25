#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"
# define NUMBER_OF_FLAGS 8

enum {
	NEGATIVE_WIDTH,
	ZERO_PADDING,
	PRECISION,
	PRECISION_WIDTH,
	FIELD_WIDTH,
	ALTERNATE_FORM,
	BLANK_PADDING,
	SIGNED
} e_flags;

int		ft_printf(const char *format, ...);

char	*get_format_specifier(const char *format);
int		print_without_format(const char **format, char *format_specifier);
int		check_flags(const char **format, int flags[]);
int		print_format(char format, va_list args, int *flags);
int		print_formated(const char **format, va_list args);

int		print_char(char c, int *flags);
int		print_string(char *string, int *flags);
int		print_pointer(void *pointer, int *flags);
int		print_signed_decimal(int decimal, int *flags);
int		print_unsigned_decimal(int decimal, int *flags);
int		print_hexadecimal(int decimal, int *flags, char format);

#endif
