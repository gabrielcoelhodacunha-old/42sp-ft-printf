#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"
# define FLAGS "-.# +"
# define NUMBER_OF_FLAGS 8

enum {
	NEGATIVE_WIDTH,
	PRECISION,
	ALTERNATE_FORM,
	BLANK,
	SIGNED,
	ZERO_PADDING,
	FIELD_WIDTH,
	PRECISION_WIDTH
} e_flags;

typedef long long t_ll;
typedef unsigned long long t_ull;

typedef struct	s_uitoa_base
{
	char	*str;
	size_t	base_len;
}	t_uitoa_base;

int		ft_printf(const char *format, ...);

int		print_without_format(const char **format, char *format_specifier);
void	get_flags(const char **format, int *flags);
void	set_flags(char format, int *flags);
int		print_formated(const char **format, va_list args);

int		print_char(char c, int *flags);
int		print_string(char *string, int *flags, char format);
int		print_pointer(void *pointer, int *flags);
int		print_signed_decimal(t_ll decimal, int *flags);
int		print_unsigned_decimal(t_ull decimal, int *flags);
int		print_hexadecimal(t_ull decimal, int *flags, char format);

char	*ft_uitoa_base(t_ull un, char *base);

void	handle_flags(char **str, int *flags, char format);
void	handle_alternate_form(char **str, char form);

#endif
