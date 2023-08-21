/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:03:37 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/21 12:27:40 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Node	*ft_lstnew(int *content)
{
	Node	*new;

	new = (Node *) malloc (sizeof(Node));
	if (!new)
		return (NULL);
	new->index = 0;
	new->content = *content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(Node **head, Node *new)
{
	Node	*curr;

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

void	ft_lstadd_front(Node **head, Node *new)
{
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		*head = new;
	}
}

void	ft_clear_stack(Node **head)
{
	Node	*curr;
	Node	*aux;
	
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

int	ft_stack_size(Node *stack)
{
	Node	*curr;
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