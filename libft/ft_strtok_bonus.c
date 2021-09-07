/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:02:13 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 22:44:07 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok_bonus(char *str, const char *delim)
{
	static char	*s1 = NULL;
	char		*ret;

	if (((!s1 || !*s1) && !str) || !delim)
		return (0);
	s1 = ft_strdup(str);
	while (*s1 && ft_strchr(delim, *s1))
		s1++;
	ret = s1;
	while (*s1 && !ft_strchr(delim, *s1))
		s1++;
	if (*s1)
	{
		*s1 = '\0';
		s1++;
	}
	if (str)
		s1 = (str);
	else
		s1 = (0);
	if (*ret)
		return (ret);
	return (0);
}
