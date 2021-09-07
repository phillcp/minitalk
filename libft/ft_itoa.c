/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:37:58 by marvin            #+#    #+#             */
/*   Updated: 2021/02/12 15:33:03 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_rec_s(int n, int i, int *s, int sign)
{
	char	*ret;

	if (n == 0)
	{
		ret = ft_malloc(i + 1);
		if (ret == NULL)
			return (NULL);
		*s = i - sign;
		ret[i] = '\0';
		return (ret);
	}
	ret = itoa_rec_s(n / 10, i + 1, s, sign);
	if (ret == NULL)
		return (NULL);
	ret[(*s) - i] = ft_abs(n % 10) + '0';
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		s;

	if (n == 0)
	{
		if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(2)))
			return (NULL);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	if (n < 0)
	{
		ret = itoa_rec_s(n, 1, &s, 0);
		if (ret == NULL)
			return (NULL);
		ret[0] = '-';
	}
	else
		ret = itoa_rec_s(n, 0, &s, 1);
	return (ret);
}
