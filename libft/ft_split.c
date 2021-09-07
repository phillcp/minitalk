/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:31:46 by marvin            #+#    #+#             */
/*   Updated: 2021/02/25 19:22:08 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numstring(char const *s1, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			b = 0;
		else if (b == 0)
		{
			b = 1;
			a++;
		}
		s1++;
	}
	return (a);
}

static int	ft_numchar(char const *s2, char c, int i)
{
	int	a;

	a = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		a++;
		i++;
	}
	return (a);
}

static char	**ft_free(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**ft_affect(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = malloc((ft_numchar(s, c, i) + 1) * sizeof(char));
		if (!dst[j])
			return (NULL);
		if (dst[j] == NULL)
			return (ft_free((char const **)dst, j));
		while (s[i] != '\0' && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (s == NULL)
		return (NULL);
	l = ft_numstring(s, c);
	dst = malloc((l + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	if (dst == NULL)
		return (NULL);
	return (ft_affect(s, dst, c, l));
}
