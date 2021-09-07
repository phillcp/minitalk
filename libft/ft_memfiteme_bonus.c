/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfiteme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 23:36:47 by marvin            #+#    #+#             */
/*   Updated: 2021/02/08 11:31:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memfiteme(void *coisa, size_t nmemb, size_t size)
{
	if (!coisa || !nmemb || !size)
		return (NULL);
	coisa = malloc(nmemb * size);
	if (!coisa)
		return (NULL);
	return (coisa);
}
