#include "ft_printf.h"

int	print_str(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
}

char	*get_format_specifier(const char *format)
{
	return ft_strchr(format, '%');
}

int	print_without_format(const char **format, char *format_specifier,
			int *char_count)
{
	char	*str_without_format;
	size_t	len;

	len = format_specifier - *format;
	if (!format_specifier)
		len = ft_strlen(*format);
	str_without_format = ft_substr(*format, 0, len);
	if (!str_without_format)
		return (-1);
	*char_count += print_str(str_without_format);
	*format += len;
	free(str_without_format);
	return (0);
}

int	check_flags(const char **format, size_t flags[])
{
	while (**format
	&& (ft_strchr("-0.# +", **format)
	|| ft_isdigit(**format)))
		(*format)++;
	return (0);
}

#define NUMBER_OF_FLAGS 7

int	print_formated(const char **format, va_list args, int *char_count)
{
	size_t	flags[NUMBER_OF_FLAGS];

	(*format)++;
	if (check_flags(format, flags))
		return (-1);
	switch(**format)
	{
		case 'c':
		case 's':
		case 'p':
		case 'd': case 'i':
		case 'u':
		case 'x':
		case 'X':
		case '%':
		default:
			return (0);
	}
	va_arg(args, int);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	char_count;
	char	*format_specifier;

	if (!format)
		return (-1);
	va_start(args, format);
	char_count = 0;
	while (*format)
	{
		format_specifier = get_format_specifier(format);
		if (print_without_format(&format, format_specifier,
				&char_count))
			return (-1);
		if (format_specifier
		&& print_formated(&format, args, &char_count))
			return (-1);
	}
	va_end(args);
	return (char_count);
}
