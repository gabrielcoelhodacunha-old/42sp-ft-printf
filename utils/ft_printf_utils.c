#include "../ft_printf.h"

char	*get_format_specifier(const char *format)
{
	return (ft_strchr(format, '%'));
}

int	print_without_format(const char **format, char *format_specifier)
{
	char	*str_without_format;
	size_t	len;

	len = format_specifier - *format;
	if (!format_specifier)
		len = ft_strlen(*format);
	str_without_format = ft_substr(*format, 0, len);
	if (!str_without_format)
		return (-1);
	print_string(str_without_format, NULL);
	(*format) += len;
	free(str_without_format);
	return (len);
}

int	check_flags(const char **format, int *flags)
{
	flags[0] = 1;
	while (**format
		&& (ft_strchr("-0.# +", **format) || ft_isdigit(**format)))
		(*format)++;
	return (0);
}

int	print_format(char format, va_list args, int *flags)
{
	if (ft_strchr("c%", format))
		return (print_char(va_arg(args, int), flags));
	else if (ft_strchr("s", format))
		return (print_string(va_arg(args, char *), flags));
	else if (ft_strchr("p", format))
		return (print_pointer(va_arg(args, void *), flags));
	else if (ft_strchr("di", format))
		return (print_signed_decimal(va_arg(args, int), flags));
	else if (ft_strchr("u", format))
		return (print_unsigned_decimal(va_arg(args, int), flags));
	else if (ft_strchr("xX", format))
		return (print_hexadecimal(va_arg(args, int), flags, format));
	return (-1);
}

int	print_formated(const char **format, va_list args)
{
	int	flags[NUMBER_OF_FLAGS];

	(*format)++;
	if (check_flags(format, flags))
		return (-1);
	return (print_format(*(*format)++, args, flags));
}
