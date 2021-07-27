/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 23:04:37 by aabet             #+#    #+#             */
/*   Updated: 2020/11/16 23:04:39 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*item;

	list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		item = ft_lstnew((*f)(lst->content));
		if (!item)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&list, item);
		lst = lst->next;
	}
	return (list);
}
