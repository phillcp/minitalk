/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:00:33 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 16:57:18 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*reeeeeeeeeeeeeeeeeeeeeeeeeeeeee;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		reeeeeeeeeeeeeeeeeeeeeeeeeeeeee = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(reeeeeeeeeeeeeeeeeeeeeeeeeeeeee, del);
	}
}
