/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:20:27 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/24 16:22:37 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_list_to_array(Node *head)
{
	Node	*aux;
	int		size;
	int		*a;
	int		i;

	aux = head;
	i = 0;
	size = ft_stack_size(head);
	a = (int *) malloc (size * sizeof(int));
	while (aux)
	{
		a[i] = aux->content;
		aux = aux->next;
		i++;
	}
	return (a);	
}

void	ft_sort_array(int *a)
{
	int	size;
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (a[i])
		i++;
	size = i;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
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

void	ft_stack_indexing(Node **stack_a, int *a)
{
	Node	*aux;
	int		i;

	i = 0;
	while (a[i])
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

void	ft_index_to_binary(Node **head)
{
	*head = NULL;
}

void	ft_sort_radix(Node **stack_a, Node **stack_b)
{
	// TODO: Desarrollar el algoritmo radix para el ordenamiento
	int	*arr;
	int i;
	Node *aux;

	i = 0;
	stack_b = NULL;
	arr = ft_list_to_array(*stack_a);
	ft_sort_array(arr);
	ft_stack_indexing(stack_a, arr);
	free(arr);
	ft_index_to_binary(stack_a);
	
	// Detele from this line
	while (arr[i])
	{
		printf("El valor del array en la posicion %d es: %d\n", i, arr[i]);
		i++;
	}
	aux = *stack_a;
	while (aux)
	{
		printf("El valor de indice es: %d\n", aux->index);
		aux = aux->next;
	}
}
