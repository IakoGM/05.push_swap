/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:01:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/08 13:37:12 by jakgonza         ###   ########.fr       */
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

int *ft_fill_numbers(char **str, int *cont)
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
	*cont = i;
	// Eliminar hasta return
	int j = 0;
	while (i > j)
	{
		printf("Numbers %d -> %d\n", j, numbers[j]);
		j++;
	}
	return (numbers);
}

char	**ft_return_data(int *array, int *cont)
{
	char	**res;
	int		len;
	int 	i;

	i = 0;
	len = *cont;
	res = (char **) malloc ((len + 1) * sizeof(char));
	while (i < len)
	{
		res[i] = ft_itoa(array[i]);
		i++;
	}
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
		while (str[i][j] && nums[i][j])
		{
			if (str[i][j] != nums[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
	// FIXME:
		// - Al hacer el itoa parece que los numeros no se guardan bien
		// - Chequear tambien el atoi por si acaso
	numbers = ft_fill_numbers(str, cont);
	nums = ft_return_data(numbers, cont);
	if (ft_compare(str, nums))
	// TODO:
		// - liberar toda la memoria
	free(str);
}

int	main(int argc, char const *argv[])
{
	if (argc == 1)
		return (0);
	ft_checkdata(argc, argv); // Comprobar si argv y &*argv funcionan igual
	return (0);
}
