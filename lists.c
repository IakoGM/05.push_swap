/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:03:37 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 10:06:41 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int *content)
{
	t_node	*new;

	new = (t_node *) malloc (sizeof(t_node));
	if (!new)
		return (NULL);
	new->index = 0;
	new->content = *content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_node **head, t_node *new)
{
	t_node	*curr;

	if (*head == NULL)
		*head = new;
	else
	{
		curr = *head;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

void	ft_lstadd_front(t_node **head, t_node *new)
{
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		*head = new;
	}
}

void	ft_clear_stack(t_node **head)
{
	t_node	*curr;
	t_node	*aux;

	if (*head == NULL)
		return ;
	curr = *head;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*head = NULL;
}

int	ft_stack_size(t_node *stack)
{
	t_node	*curr;
	int		cont;

	cont = 0;
	curr = stack;
	while (curr)
	{
		cont++;
		curr = curr->next;
	}
	return (cont);
}
