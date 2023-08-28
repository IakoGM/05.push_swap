/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:25:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 10:07:34 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;

	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_b, aux);
	write(1, "pb\n", 3);
}

void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;

	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_a, aux);
	write(1, "pa\n", 3);
}

void	ft_swap(t_node **head, char c)
{
	t_node	*aux1;
	t_node	*aux2;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	aux1 = *head;
	aux2 = (*head)->next;
	aux1->next = aux2->next;
	aux2->next = aux1;
	*head = aux2;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_swap_ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a, 'x');
	ft_swap(stack_b, 'x');
	write(1, "ss\n", 3);
}
