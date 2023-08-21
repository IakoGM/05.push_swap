/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:41:56 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/21 15:07:44 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(Node **head)
{
	Node	*aux;

	aux = *head;
	*head = (*head)->next;
	aux->next = NULL;
	ft_lstadd_back(head, aux);
}

void	ft_rotate_rr(Node **stack_a, Node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_reverse_rotate(Node **head)
{
	Node	*curr;
	Node	*aux;

	curr = *head;
	while (curr->next->next)
		curr = curr->next;
	aux = curr->next;
	ft_lstadd_front(head, aux);
	curr->next = NULL;
}

void	ft_reverse_rotate_rrr(Node **stack_a, Node **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
