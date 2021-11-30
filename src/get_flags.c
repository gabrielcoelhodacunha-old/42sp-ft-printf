/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 13:20:12 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(char c);
static void	increase_width(size_t *flags, char number);

void	get_flags(const char **format, size_t *flags)
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

static void	increase_width(size_t *flags, char number)
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
