/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:39:46 by marvin            #+#    #+#             */
/*   Updated: 2021/02/08 11:49:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!*needle)
		return ((char *)hay);
	while (hay[a] != '\0' && a < len)
	{
		b = 0;
		while (hay[a + b] != '\0' && hay[a + b] == needle[b] && (a + \
b) < len && needle[b] != '\0')
		{
			if (needle[b + 1] == '\0')
				return ((char *)&(hay[a]));
			b++;
		}
		a++;
	}
	return (0);
}
