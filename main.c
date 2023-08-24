/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:01:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/24 13:39:41 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_double_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_insert_data(char const **argv)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = NULL;
	while (argv[i])
		i++;
	str = (char **) malloc (i * sizeof(char *));
	if (!str)
		return (NULL);
	i--;
	while (i > j)
	{
		str[j] = ft_strdup(argv[j + 1]);
		j++;
	}
	str[j] = NULL;
	return (str);
}

int	*ft_fill_numbers(char **str, int *size)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = (int *) malloc (ft_double_strlen(str) * sizeof(int));
	while (str[i])
	{
		numbers[i] = ft_atoi(str[i]);
		i++;
	}
	*size = i;
	return (numbers);
}

char	**ft_return_data(int *array, int *cont)
{
	char	**res;
	int		len;
	int		i;

	i = 0;
	len = *cont;
	res = (char **) malloc ((len + 1) * sizeof(char *));
	while (i < len)
	{
		res[i] = ft_itoa(array[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	ft_compare(char **str, char **nums_str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && nums_str[i])
	{
		j = 0;
		while (str[i][j] || nums_str[i][j])
		{
			if ((str[i][j] != nums_str[i][j]) \
				|| (!str[i][j] && nums_str[i][j]) \
					|| (!nums_str[i][j] && str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicates(int *numbers, int *cont)
{
	int	i;
	int	j;

	i = 0;
	while (i < *cont)
	{
		j = 0;
		while (j < *cont)
		{
			if (numbers[i] == numbers[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_checkdata(int argc, char const **argv, int *cont, int *numbers)
{
	char	**str;
	char	**nums_str;

	str = NULL;
	nums_str = NULL;
	if (argc == 2)
		str = ft_split(argv[1], 32);
	else
		str = ft_insert_data(argv);
	numbers = ft_fill_numbers(str, cont);
	nums_str = ft_return_data(numbers, cont);
	if (ft_compare(str, nums_str))
	{
		if (!ft_check_duplicates(numbers, cont))
		{
			ft_free(str);
			ft_free(nums_str);
			return (numbers);
		}
	}
	ft_free(nums_str);
	free(numbers);
	ft_error_free_dp(str);
	return (numbers);
}

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

void	ft_fill_stack(Node **stack_a, int *numbers, int *cont)
{
	int		i;
	Node	*aux;

	i = 0;
	while (i < *cont)
	{
		aux = ft_lstnew(&numbers[i]);
		ft_lstadd_back(stack_a, aux);
		i++;
	}
	free(numbers);
}

void	ft_print_stack(Node *stack)
{
	Node	*curr;
	
	curr = stack;
	while (curr)
	{
		printf("El contenido del stack es: %d\n", curr->content);
		curr = curr->next;
	}
}

int	ft_stack_sorted(Node *stack)
{
	Node	*curr;

	curr = stack;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	ft_push_swap(Node **stack_a, Node **stack_b)
{
	int	size;
	*stack_b = NULL;

	size = ft_stack_size(*stack_a);
	if (*stack_b == NULL && (ft_stack_sorted(*stack_a) || size <= 1))
		return ;
	if (size == 2 && *stack_a > (*stack_a)->next)
			ft_swap(stack_a, 'a');
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size <= 5)
		ft_sort_five(stack_a, stack_b);
	else if (size > 5)
	{
		ft_sort_radix(stack_a, stack_b);
	}
}

int	main(int argc, char const *argv[])
{
	Node	*stack_a;
	Node	*stack_b;
	int	*numbers;
	int	cont[1];

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
	// ft_print_stack(stack_a);
	ft_push_swap(&stack_a, &stack_b);
	// printf("STACK A - Final\n");
	// ft_print_stack(stack_a);
	// printf("STACK B - Final\n");
	// ft_print_stack(stack_b);
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	// printf("Salida limpia!!\n");
	return (0);
}
