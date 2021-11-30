/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 14:55:24 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_str_len(char *str, size_t *flags, char format);
static char		*get_padding(size_t padding_len, size_t *flags);
static int		check_if_is_negative(char *str, size_t *flags, char format);
static char		*get_padded_str(char **old_str, char *padding,
					int is_negative, size_t *flags);

void	handle_width(char **str, size_t *flags, char format)
{
	char	*old_str;
	char	*padding;
	size_t	str_len;
	int		is_negative;

	str_len = get_str_len(*str, flags, format);
	if (flags[FIELD_WIDTH] <= str_len)
		return ;
	old_str = *str;
	padding = get_padding(flags[FIELD_WIDTH] - str_len, flags);
	is_negative = check_if_is_negative(*str, flags, format);
	*str = get_padded_str(&old_str, padding, is_negative, flags);
	free(padding);
	free(old_str);
}

static char	*get_padded_str(char **old_str, char *padding,
				int is_negative, size_t *flags)
{
	char	*padded_str;

	if (flags[NEGATIVE_WIDTH])
		padded_str = ft_strjoin(*old_str, padding);
	else
		padded_str = ft_strjoin(padding, *old_str + is_negative);
	if (is_negative)
	{
		free(*old_str);
		*old_str = padded_str;
		padded_str = ft_strjoin("-", *old_str);
	}
	return (padded_str);
}

static int	check_if_is_negative(char *str, size_t *flags, char format)
{
	if (ft_strchr("di", format) && *str == '-' && flags[ZERO_PADDING])
		return (1);
	return (0);
}

static char	*get_padding(size_t padding_len, size_t *flags)
{
	char	c;
	char	*padding;

	padding = ft_calloc(padding_len + 1, 1);
	if (!padding)
		return (NULL);
	if (flags[ZERO_PADDING])
		c = '0';
	else
		c = ' ';
	ft_memset(padding, c, padding_len);
	return (padding);
}

static size_t	get_str_len(char *str, size_t *flags, char format)
{
	size_t	len;

	len = ft_strlen(str);
	if (format == 'c' && !len)
		len = 1;
	if (flags[PRECISION] && ft_strchr("di", format)
		&& *str == '-' && flags[ZERO_PADDING])
		len--;
	return (len);
}
