/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:41:56 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 10:07:41 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **head, char c)
{
	t_node	*aux;

	aux = *head;
	*head = (*head)->next;
	aux->next = NULL;
	ft_lstadd_back(head, aux);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rotate_rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a, 'x');
	ft_rotate(stack_b, 'x');
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate(t_node **head, char c)
{
	t_node	*curr;
	t_node	*aux;

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

void	ft_reverse_rotate_rrr(t_node **stack_a, t_node **stack_b)
{
	ft_reverse_rotate(stack_a, 'x');
	ft_reverse_rotate(stack_b, 'x');
	write(1, "rrr\n", 4);
}
