/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:16:19 by jakgonza          #+#    #+#             */
/*   Updated: 2022/09/19 11:58:09 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*newlst;

	if (!lst && !f && !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		newlst = ft_lstnew(f(lst->content));
		ft_lstadd_back(&head, newlst);
		lst = lst->next;
	}
	return (head);
}
