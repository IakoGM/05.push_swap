/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:25:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/21 14:33:02 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(Node **stack_a, Node **stack_b)
{
	Node	*aux;

	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_b, aux);
	// Eliminar desde aqui hacia abajo
	printf("Stack A\n");
	ft_print_stack(*stack_a);
	printf("Stack B\n");
	ft_print_stack(*stack_b);
}

void	ft_pa(Node **stack_a, Node **stack_b)
{
	Node	*aux;

	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_a, aux);
	// Eliminar desde aqui hacia abajo
	printf("Stack A\n");
	ft_print_stack(*stack_a);
	printf("Stack B\n");
	ft_print_stack(*stack_b);
}

void	ft_swap(Node **head)
{
	Node	*aux1;
	Node	*aux2;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("La lista NO tiene al menos dos elementos para intercambiar\n");
		return ;
	}
	aux1 = *head;
	aux2 = (*head)->next;
	aux1->next = aux2->next;
	aux2->next = aux1;
	*head = aux2;
}

void	ft_swap_ss(Node **stack_a, Node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
