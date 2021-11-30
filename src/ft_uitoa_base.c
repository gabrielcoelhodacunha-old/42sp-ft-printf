/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 13:17:35 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	determine_len(t_ull un, size_t base_len);
static void		convert(t_ull un, char *str, size_t len,
					t_uitoa_base *args);

char	*ft_uitoa_base(t_ull un, char *base)
{
	t_uitoa_base	args;
	size_t			len;

	args.base_len = ft_strlen(base);
	len = determine_len(un, args.base_len);
	args.str = malloc(len + 1);
	if (!args.str)
		return (NULL);
	convert(un, base, len - 1, &args);
	args.str[len] = '\0';
	return (args.str);
}

static void	convert(t_ull un, char *base, size_t len, t_uitoa_base *args)
{
	if (un >= args->base_len)
		convert(un / args->base_len, base, len - 1, args);
	args->str[len] = base[un % args->base_len];
}

static size_t	determine_len(t_ull un, size_t base_len)
{
	size_t	len;

	len = 1;
	while (un >= base_len)
	{
		un /= base_len;
		len++;
	}
	return (len);
}
