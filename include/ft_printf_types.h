/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:48:08 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 10:48:08 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

typedef long long			t_ll;
typedef unsigned long long	t_ull;

typedef struct s_uitoa_base
{
	char	*str;
	size_t	base_len;
}	t_uitoa_base;

#endif
