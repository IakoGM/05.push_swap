/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:20:27 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 10:08:20 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_sorted(t_node *stack)
{
	t_node	*curr;

	curr = stack;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static int	ft_binary_digits(int num)
{
	int	cont;

	cont = 0;
	if (num == 0)
		return (0);
	while (num > 0)
	{
		num /= 2;
		cont++;
	}
	return (cont);
}

static int	ft_max_digits(t_node *head)
{
	t_node	*aux;
	int		max;

	aux = head;
	max = 0;
	while (aux)
	{
		if (ft_binary_digits(aux->index) > max)
			max = ft_binary_digits(aux->index);
		aux = aux->next;
	}
	return (max);
}

void	ft_sort_radix(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;
	int		size;
	int		i;
	int		max;

	i = 0;
	max = ft_max_digits(*stack_a);
	while (i < max)
	{
		size = ft_stack_size(*stack_a);
		while (size > 0)
		{
			aux = *stack_a;
			if (((aux->index >> i) & 1) == 1)
				ft_rotate(stack_a, 'a');
			else
				ft_pb(stack_a, stack_b);
			size--;
		}
		while (ft_stack_size(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		if (ft_stack_sorted(*stack_a) && ft_stack_size(*stack_b) == 0)
			break ;
		i++;
	}
}
