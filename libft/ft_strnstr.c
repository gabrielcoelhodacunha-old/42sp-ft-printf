/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:35:13 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/09/10 18:35:13 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (!l_len)
		return ((char *) big);
	while (*big && len > l_len && ft_strncmp(big, little, l_len))
	{
		len--;
		big++;
	}
	if (len >= l_len && !ft_strncmp(big, little, l_len))
		return ((char *) big);
	return (NULL);
}
