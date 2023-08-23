/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:41:56 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/23 17:32:20 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(Node **head, char c)
{
	Node	*aux;

	aux = *head;
	*head = (*head)->next;
	aux->next = NULL;
	ft_lstadd_back(head, aux);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rotate_rr(Node **stack_a, Node **stack_b)
{
	ft_rotate(stack_a, 'x');
	ft_rotate(stack_b, 'x');
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate(Node **head, char c)
{
	Node	*curr;
	Node	*aux;

	curr = *head;
	while (curr->next->next)
		curr = curr->next;
	aux = curr->next;
	ft_lstadd_front(head, aux);
	curr->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_rrr(Node **stack_a, Node **stack_b)
{
	ft_reverse_rotate(stack_a, 'x');
	ft_reverse_rotate(stack_b, 'x');
	write(1, "rrr\n", 4);
}
