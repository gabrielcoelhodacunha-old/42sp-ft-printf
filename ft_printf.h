#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"
# define NUMBER_OF_FLAGS 7

int		ft_printf(const char *format, ...);

char	*get_format_specifier(const char *format);
int		print_without_format(const char **format, char *format_specifier);
int		check_flags(const char **format, int flags[]);
int		print_format(char format, va_list args);
int		print_formated(const char **format, va_list args);

int		print_char(char c);
int		print_string(char *string);

#endif
