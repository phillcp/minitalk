/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:03:41 by fheaton-          #+#    #+#             */
/*   Updated: 2021/02/15 16:20:13 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*aux;

	if (!lst)
		return (NULL);
	ret = ft_lstnew(f(lst->content));
	aux = ret;
	while (ft_set64((int64_t *)&lst, (int64_t)lst->next) && aux)
	{
		aux->next = ft_lstnew(f(lst->content));
		aux = aux->next;
	}
	if (!aux)
	{
		ft_lstclear(&ret, del);
		ret = NULL;
	}
	return (ret);
}
