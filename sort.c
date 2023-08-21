/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:35:17 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/21 23:26:35 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update(Node *head, int *s, int *m, int *e)
{
	*s = head->content;
	*m = head->next->content;
	*e = head->next->next->content;
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
