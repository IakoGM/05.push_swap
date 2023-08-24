/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:35:17 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/24 12:20:02 by jakgonza         ###   ########.fr       */
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

int	ft_find_last(Node *head)
{
	int		num;
	Node	*aux;

	aux = head;
	while (aux->next)
		aux = aux->next;
	num = aux->content;
	return (num);
}

void	ft_sort_three(Node **head)
{
	int	start;
	int	middle;
	int	end;

	ft_update(*head, &start, &middle, &end);
	while (!ft_stack_sorted(*head))
	{
		if (start > middle && start > end)
		{
			ft_rotate(head, 'a');
			ft_update(*head, &start, &middle, &end);
		}
		else if ((start > middle || start < middle) && start < end)
		{
			ft_swap(head, 'a');
			ft_update(*head, &start, &middle, &end);
		}
		else if (start < middle && start > end)
		{
			ft_rotate(head, 'a');
			ft_update(*head, &start, &middle, &end);
		}
	}
}

void	ft_sort_five(Node **stack_a, Node **stack_b)
{
	int	size;
	int	min;
	int	i;

	size = ft_stack_size(*stack_a);
	if (size == 4)
		i = 1;
	if (size == 5)
		i = 0;
	while (i != 2)
	{
		min = ft_find_min(*stack_a);
		if (ft_find_last(*stack_a) == min)
			ft_reverse_rotate(stack_a, 'a');
		while (min != (*stack_a)->content)
			ft_rotate(stack_a, 'a');
		ft_pb(stack_a, stack_b);
		i++;
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}
