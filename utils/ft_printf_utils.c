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
	print_string(str_without_format);
	(*format) += len;
	free(str_without_format);
	return (len);
}

int	check_flags(const char **format, int flags[])
{
	while (**format
		&& (ft_strchr("-0.# +", **format) || ft_isdigit(**format)))
		(*format)++;
	return (0);
}

int	print_format(char format, va_list args)
{
	if (format == 'c')
		return (print_char(va_arg(args, int)));
	else if (format == 's')
		return (print_string(va_arg(args, char *)));
	else if (format == 'p')
		;
	else if (format == 'd' || format == 'i')
		;
	else if (format == 'u')
		;
	else if (format == 'x')
		;
	else if (format == 'X')
		;
	else if (format == '%')
		;
	return (-1);
}

int	print_formated(const char **format, va_list args)
{
	int	flags[NUMBER_OF_FLAGS];

	(*format)++;
	if (check_flags(format, flags))
		return (-1);
	return (print_format(*(*format)++, args));
}
