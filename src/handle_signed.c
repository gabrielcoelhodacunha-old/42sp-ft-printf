/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 10:14:01 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_signed(char **str, size_t *flags)
{
	char	*old_str;

	if (!flags[SIGNED] || **str == '-')
		return ;
	old_str = *str;
	*str = ft_strjoin("+", old_str);
	free(old_str);
}
