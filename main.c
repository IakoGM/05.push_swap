/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:01:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 10:06:58 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_empty(char const **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_only_spaces(char const **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j] == 32 || argv[i][j] == 9)
			j++;
		if (argv[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_fill_stack(t_node **stack_a, int *numbers, int *cont)
{
	int		i;
	t_node	*aux;

	i = 0;
	while (i < *cont)
	{
		aux = ft_lstnew(&numbers[i]);
		ft_lstadd_back(stack_a, aux);
		i++;
	}
	free(numbers);
}

int	main(int argc, char const *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*numbers;
	int		cont[1];

	cont[0] = 0;
	numbers = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (ft_check_empty(argv) || ft_only_spaces(argv))
		ft_error();
	numbers = ft_checkdata(argc, argv, cont, numbers);
	ft_fill_stack(&stack_a, numbers, cont);
	ft_push_swap(&stack_a, &stack_b);
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}
