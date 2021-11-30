/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_alternate_form.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 13:23:03 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_alternate_form(char **str, size_t *flags, char format)
{
	char	*old_str;

	if (!flags[ALTERNATE_FORM]
		|| (ft_strchr("xX", format) && **str == '0'))
		return ;
	old_str = *str;
	if (ft_strchr("px", format))
		*str = ft_strjoin("0x", old_str);
	else if (format == 'X')
		*str = ft_strjoin("0X", old_str);
	free(old_str);
}
