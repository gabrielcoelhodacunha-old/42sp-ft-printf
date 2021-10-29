/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 10:14:01 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_width(char **str, size_t *flags, char format)
{
	char	*old_str;
	char	*width_adjustment;
	size_t	width;
	size_t	len;
	int	is_negative;

	len = ft_strlen(*str);
	if (format == 'c' && !len)
		len = 1;
	if (flags[PRECISION] && ft_strchr("di", format)
		&& ft_strchr(*str, '-') && flags[ZERO_PADDING])
		len--;
	if (flags[FIELD_WIDTH] <= len)
		return ;
	old_str = *str;
	width = flags[FIELD_WIDTH] - len;
	width_adjustment = ft_calloc(width + 1, 1);
	if (!width_adjustment)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	if (flags[ZERO_PADDING])
		ft_memset(width_adjustment, '0', width);
	else
		ft_memset(width_adjustment, ' ', width);
	if (ft_strchr("di", format) && ft_strchr(*str, '-')
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
