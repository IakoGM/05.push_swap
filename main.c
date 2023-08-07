/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:01:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/07 18:31:27 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

// void	ft_parsedata(int argc, char const **argv)
// {
// 	int		i;
// 	char	**str;

// 	i = 1;
// 	str = NULL;
// 	while (argc > i)
// 	{
// 		if (ft_hasspace(argv[i]))
// 		{
// 			str = ft_split(argv[i], 32); // WARNING: - devuelve un char** maloqueado
// 			while (*str)                 // Si tiene **str da segfault
// 			{
// 				if (ft_atoi(*str) == -1)
// 					ft_error(str);
// 				str++;
// 			}
// 		}
// 		else 
// 		{
// 			if (ft_atoi(argv[i]) == -1)
// 			{
// 				if (str != NULL)
// 					ft_free(str);
// 				write(2, "Error\n", 6);
// 			}
// 		}
// 		i++;
// 	}
// 	if (str != NULL)
// 		ft_free(str);
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

void	ft_checkdata(int argc, char const **argv)
{
	char	**str;
	int		*numbers;
	int		i;

	i = 0;
	str = NULL;
	if (argc == 2)
		str = ft_split(argv[1], 32);
	else
		str = ft_insert_data(&*argv);
	numbers = (int *) malloc (ft_double_strlen(str) * sizeof(int));
	while (str[i])
	{
		numbers[i] = ft_atoi(str[i]);
		i++;
	}
	// La i es 3
	int j = 0;
	while (i > j)
	{
		printf("Numbers %d -> %d\n", j, numbers[j]);
		j++;
	}
	
	// atoi
	// itoa
	// strcmp

	free(str);
}

int	main(int argc, char const *argv[])
{
	if (argc == 1)
		return (0);
	ft_checkdata(argc, argv); // Comprobar si argv y &*argv funcionan igual
	// ft_parsedata(argc, &*argv);
	return (0);
}
