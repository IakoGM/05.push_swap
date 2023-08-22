/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:35:17 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/22 14:03:55 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update(Node *head, int *s, int *m, int *e)
{
	*s = head->content;
	*m = head->next->content;
	*e = head->next->next->content;
}

int	ft_find_min(Node *head)
{
	Node	*curr;
	int		min;
	
	curr = head;
	min = curr->content;
	while (curr)
	{
		if (curr->content < min)
			min = curr->content;
		curr = curr->next;
	}
	return (min);
}

void	ft_sort_three(Node **head)
{
	int	start;
	int	middle;
	int	end;
	int	counter = 0;

	ft_update(*head, &start, &middle, &end);
	printf("Los elementos start %d, middle %d y end %d\n", start, middle, end);
	while (!ft_stack_sorted(*head))
	{
		if (start > middle && start > end)
		{
			ft_rotate(head);
			ft_update(*head, &start, &middle, &end);
			counter++;
			printf("Los elementos start %d, middle %d y end %d\n", start, middle, end);
		}
		else if ((start > middle || start < middle) && start < end)
		{
			ft_swap(head);
			ft_update(*head, &start, &middle, &end);
			counter++;
			printf("Los elementos start %d, middle %d y end %d\n", start, middle, end);
		}
		else if (start < middle && start > end)
		{
			ft_rotate(head);
			ft_update(*head, &start, &middle, &end);
			counter++;
			printf("Los elementos start %d, middle %d y end %d\n", start, middle, end);
		}
	}
	printf("El contador de movimentos es: %d\n", counter);
}

void	ft_sort_five(Node **stack_a, Node **stack_b)
{
	int	size;
	int	min;
	int	i;
	int	cont = 0;

	size = ft_stack_size(*stack_a);
	if (size == 4)
		i = 1;
	if (size == 5)
		i = 0;
	while (i != 2)
	{
		min = ft_find_min(*stack_a);
		while (min != (*stack_a)->content)
		{
			ft_rotate(stack_a);
			cont++;
		}
		ft_pb(stack_a, stack_b);
		cont++;
		i++;
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_pa(stack_a, stack_b);
		cont++;
	}
	
	printf("El contador de movimentos es: %d\n", cont);
}
