#include "../include/ft_printf.h"

static void	initialize_flags(int *flags);
static int	print_format(char format, va_list args, int *flags);

int	print_formated(const char **format, va_list args)
{
	int	flags[NUMBER_OF_FLAGS];

	(*format)++;
	initialize_flags(flags);
	get_flags(format, flags);
	return (print_format(*(*format)++, args, flags));
}

static int	print_format(char format, va_list args, int *flags)
{
	if (ft_strchr("c%", format))
		return (print_char(va_arg(args, int), flags));
	else if (ft_strchr("s", format))
		return (print_string(va_arg(args, char *), flags, format));
	/*
	else if (ft_strchr("p", format))
		return (print_pointer(va_arg(args, void *), flags));
	else if (ft_strchr("di", format))
		return (print_signed_decimal(va_arg(args, int), flags));
	else if (ft_strchr("u", format))
		return (print_unsigned_decimal(va_arg(args, unsigned int),
				flags));
	*/
	else if (ft_strchr("xX", format))
		return (print_hexadecimal(va_arg(args, unsigned int),
				flags, format));
	return (-1);
}

static void	initialize_flags(int *flags)
{
	int	flag;

	flag = -1;
	while (++flag < NUMBER_OF_FLAGS)
		flags[flag] = 0;
}
