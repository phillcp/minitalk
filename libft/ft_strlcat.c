/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 02:30:47 by marvin            #+#    #+#             */
/*   Updated: 2021/02/19 17:55:44 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;

	c = 0;
	a = ft_strlen(dest);
	b = ft_strlen(src);
	if (size < a + 1)
		return (size + b);
	if (size > a + 1)
	{
		while (src[c] != '\0' && a + 1 + c < size)
		{
			dest[a + c] = src[c];
			c++;
		}
	}
	dest[a + c] = '\0';
	return (a + b);
}
