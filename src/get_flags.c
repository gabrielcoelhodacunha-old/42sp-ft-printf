#include "../include/ft_printf.h"

static int	is_flag(char c);
static void	increase_width(int *flags, char number);

void	get_flags(const char **format, int *flags)
{
	char	*flag;

	while (is_flag(**format))
	{
		flag = ft_strchr(FLAGS, **format);
		if (**format == '0'
			&& !flags[PRECISION_WIDTH]
			&& !flags[FIELD_WIDTH])
			flags[ZERO_PADDING]++;
		else if (ft_isdigit(**format))
			increase_width(flags, **format);
		else if (flag)
			flags[flag - FLAGS]++;	
		(*format)++;
	}
}

static void	increase_width(int *flags, char number)
{
	int	flag;

	if (flags[PRECISION])
		flag = PRECISION_WIDTH;
	else
		flag = FIELD_WIDTH;
	flags[flag] *= 10;
	flags[flag] += number - '0';
}

static int	is_flag(char c)
{
	return (ft_isdigit(c) || ft_strchr(FLAGS, c));
}