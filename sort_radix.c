/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:20:27 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/26 08:53:44 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_list_to_array(Node *head, int *arr_size)
{
	Node	*aux;
	int		size;
	int		*a;
	int		i;

	aux = head;
	i = 0;
	size = ft_stack_size(head);
	a = (int *) malloc (size * sizeof(int));
	if (!a)
		return (NULL);
	while (aux)
	{
		a[i] = aux->content;
		aux = aux->next;
		i++;
	}
	arr_size[0] = i;
	return (a);	
}

void	ft_sort_array(int *a, int *arr_size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < arr_size[0] - 1)
	{
		j = 0;
		while (j < arr_size[0] - 1)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_stack_indexing(Node **stack_a, int *a, int *arr_size)
{
	Node	*aux;
	int		i;

	i = 0;
	while (i < arr_size[0])
	{
		aux = *stack_a;
		while (aux)
		{
			if (aux->content == a[i])
				aux->index = i;
			aux = aux->next;
		}
		i++;
	}
}

int	ft_binary_digits(int num)
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

int	ft_max_digits(Node *head)
{
	Node	*aux;
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

void	ft_sort_radix(Node **stack_a, Node **stack_b)
{
	Node	*aux;
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
		if(ft_stack_sorted(*stack_a) && ft_stack_size(*stack_b) == 0)
			break ;
		i++;
	}
}
