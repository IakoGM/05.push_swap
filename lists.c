/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:03:37 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/10 16:14:31 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int *content)
{
	t_stack	*new;

	new = (t_stack *) malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new->index = 0;
	new->content = *content;
	new->next = NULL;
	return (new);
}

// void	ft_lstadd_back(t_stack **lst, t_stack *new)
// {
// 	t_stack	*tmp;

// 	if (*lst == NULL)
// 		*lst = new;
// 	else
// 	{
// 		tmp = *lst;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 	}
// }

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}