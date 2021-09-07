/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:57:18 by marvin            #+#    #+#             */
/*   Updated: 2021/02/15 14:29:40 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	int				b;
	char			*str;

	if (!s || !f)
		return (NULL);
	b = ft_strlen(s);
	str = malloc(b + 1);
	if (!str)
		return (NULL);
	a = 0;
	while (s[a] != '\0')
	{
		str[a] = f(a, s[a]);
		++a;
	}
	str[a] = '\0';
	return (str);
}
