/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:16:41 by marvin            #+#    #+#             */
/*   Updated: 2021/02/15 14:17:42 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		a;
	int		size;

	size = 0;
	while (s1[size])
		++size;
	s2 = malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		s2[a] = s1[a];
		a++;
	}
	s2[a] = '\0';
	return (s2);
}
