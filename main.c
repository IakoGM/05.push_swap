/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:01:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/09 14:02:09 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <string.h>

// int	ft_hasspace(char const *arg)
// {
// 	while (*arg)
// 	{
// 		if (*arg == 32)
// 			return (1);
// 		arg++;
// 	}
// 	return (0);
// }

int	ft_double_strlen(char **str)
{
	int i;

	i = 0;
	while(str[i])
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
	while(argv[i])
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

int *ft_fill_numbers(char **str, int *size)
{
	int	*numbers;
	int i;

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
	int 	i;

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

int	ft_compare(char **str, char **nums)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && nums[i])
	{
		while (str[i][j] || nums[i][j])
		{
			if ((str[i][j] != nums[i][j]) || !str[i][j] || !nums[i][j])
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

void	ft_checkdata(int argc, char const **argv)
{
	char	**str;
	char	**nums;
	int		*numbers;
	int		cont[1];
	int		i;

	i = 0;
	str = NULL;
	nums = NULL;
	cont[0] = 0;
	if (argc == 2)
		str = ft_split(argv[1], 32);
	else
		str = ft_insert_data(&*argv);
	// FIXME -> si va una letra sola, tanto en "y" como en argumento y el atoi() devuelve un 0...
	numbers = ft_fill_numbers(str, cont);
	while (i < *cont)
	{
		printf("Numbers int* %d es: %d\n", i, numbers[i]);
		i++;
	}
	nums = ft_return_data(numbers, cont);
	// i = 0;
	// while (nums[i])
	// {
	// 	printf("Nums char* %d es: %s\n", i, nums[i]);
	// 	i++;
	// }
	if (ft_compare(str, nums))
	{
		printf("Las cadenas son iguales\n");
		if (!ft_check_duplicates(numbers, cont))
		{
			printf("No hay numeros duplicados.\n");
			return ;
		}
	}
	ft_free(nums);
	free(numbers);	
	ft_error(str);	
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

// void	ft_fill_stack(t_stack a, int *numbers)
// {
	
// }

int	main(int argc, char const *argv[])
{
	// t_stack	a;
	// t_stack	b;
	// int	*numbers;

	if (argc == 1)
		return (0);
	if (ft_check_empty(argv))
	{
		write(2, "Error\n", 6);
		exit(2);
	}
	if (ft_only_spaces(argv))
	{
		write(2, "Error\n", 6);
		exit(2);
	}
	ft_checkdata(argc, argv);
	// ft_fill_stack(a, numbers);	
	return (0);
}
