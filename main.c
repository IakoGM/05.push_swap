/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:01:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/10 16:24:59 by jakgonza         ###   ########.fr       */
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
	// int		*numbers;

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
		printf("Las cadenas son iguales\n");
		if (!ft_check_duplicates(numbers, cont))
		{
			printf("No hay numeros duplicados.\n");
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

int	ft_check_empty(char const **argv)
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

int	ft_only_spaces(char const **argv)
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

t_stack	*ft_fill_stack(t_stack *stack_a, int *numbers, int *cont)
{
	int		i;
	t_stack *tmp;

	i = 1;
	stack_a = ft_lstnew(&numbers[0]);
	tmp = stack_a;
	printf("La direccion de memoria de tmp es: %p\n", tmp);
	printf("La direccion de memoria de stack_a es: %p\n", stack_a);
	stack_a = stack_a->next;
	while (i < *cont)
	{
		stack_a = ft_lstnew(&numbers[i]);
		printf("El contenido de stack_a en numbers[%d] es: %d\n", i, stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	while (tmp->content)
	{
		printf("El contenido de stack_a a traves de tmp[%d] es: %d", i, tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (stack_a);
}

int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	// t_stack	*stack_b;
	int	*numbers;
	int	cont[1];

	cont[0] = 0;
	numbers = NULL;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (ft_check_empty(argv) || ft_only_spaces(argv))
		ft_error();
	numbers = ft_checkdata(argc, argv, cont, numbers);
	int	i = 0;
	while (i < *cont)
	{
		printf("Numbers en el main contiene: %d\n", numbers[i]);
		i++;
	}
	printf("Su direccion de memoria es: %p\n", numbers);
	stack_a = ft_fill_stack(stack_a, numbers, cont);
	free(numbers);
	return (0);
}
