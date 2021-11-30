/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 13:39:40 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_precision(char **str, size_t *flags, char format)
{
	char	*old_str;
	size_t	len;
	size_t	flags_aux[NUMBER_OF_FLAGS];

	if (!flags[PRECISION])
		return ;
	old_str = *str;
	len = ft_strlen(*str);
	if (format == 's' && len > flags[PRECISION_WIDTH])
		*str = ft_substr(old_str, 0, flags[PRECISION_WIDTH]);
	else if (ft_strchr("diuxX", format) && flags[PRECISION_WIDTH])
	{
		*str = ft_strdup(old_str);
		flags_aux[FIELD_WIDTH] = flags[PRECISION_WIDTH];
		flags_aux[PRECISION] = 1;
		flags_aux[ZERO_PADDING] = 1;
		flags_aux[NEGATIVE_WIDTH] = 0;
		handle_width(str, flags_aux, format);
	}
	else if (ft_strchr("diuxX", format) && *old_str == '0')
		*str = ft_strdup("");
	else
		*str = ft_strdup(old_str);
	free(old_str);
}
