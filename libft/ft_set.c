/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:23:37 by fheaton-          #+#    #+#             */
/*   Updated: 2021/07/29 16:26:15 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_norm.h"

int8_t	ft_set8(int8_t *a, int8_t b)
{
	*a = b;
	return (b);
}

int16_t	ft_set16(int16_t *a, int16_t b)
{
	*a = b;
	return (b);
}

int32_t	ft_set32(int32_t *a, int32_t b)
{
	*a = b;
	return (b);
}

int64_t	ft_set64(int64_t *a, int64_t b)
{
	*a = b;
	return (b);
}
