/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 14:32:41 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	get_str_len(char **str, size_t *flags, char format);
static char		*get_padding(size_t padding_len, size_t *flags);

void	handle_width(char **str, size_t *flags, char format)
{
	char	*old_str;
	char	*padding;
	size_t	padding_len;
	size_t	str_len;
	int		is_negative;

	str_len = get_str_len(str, flags, format);
	if (flags[FIELD_WIDTH] <= str_len)
		return ;
	old_str = *str;
	padding_len = flags[FIELD_WIDTH] - str_len;
	padding = get_padding(padding_len, flags);
	if (ft_strchr("di", format) && (*str, '-')
		&& flags[ZERO_PADDING])
		is_negative = 1;
	else
		is_negative = 0;
	if (flags[NEGATIVE_WIDTH])
		*str = ft_strjoin(old_str, width_adjustment);
	else
		*str = ft_strjoin(width_adjustment, old_str + is_negative);
	if (is_negative)
	{
		free(old_str);
		old_str = *str;
		*str = ft_strjoin("-", old_str);
	}
	free(width_adjustment);
	free(old_str);
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

static size_t	get_str_len(char **str, size_t *flags, char format)
{
	size_t	len;

	len = ft_strlen(*str);
	if (format == 'c' && !len)
		len = 1;
	if (flags[PRECISION] && ft_strchr("di", format)
		&& **str == '-' && flags[ZERO_PADDING])
		len--;
	return (len);
}
