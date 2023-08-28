/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:26:43 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 10:13:05 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_list_to_array(t_node *head, int *arr_size)
{
	t_node	*aux;
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

static void	ft_sort_array(int *a, int *arr_size)
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

static void	ft_stack_indexing(t_node **stack_a, int *a, int *arr_size)
{
	t_node	*aux;
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

void	ft_push_swap(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	*arr;
	int	*arr_size;

	*stack_b = NULL;
	size = ft_stack_size(*stack_a);
	if (*stack_b == NULL && (ft_stack_sorted(*stack_a) || size <= 1))
		return ;
	if (size == 2 && !ft_stack_sorted(*stack_a))
		ft_swap(stack_a, 'a');
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size <= 5)
		ft_sort_five(stack_a, stack_b);
	else if (size > 5)
	{
		arr_size = (int *) malloc (1 * sizeof(int));
		arr = ft_list_to_array(*stack_a, arr_size);
		ft_sort_array(arr, arr_size);
		ft_stack_indexing(stack_a, arr, arr_size);
		free(arr);
		free(arr_size);
		ft_sort_radix(stack_a, stack_b);
	}
}
