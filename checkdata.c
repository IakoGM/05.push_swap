/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:49:50 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 10:03:02 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_double_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*ft_fill_numbers(char **str, int *size)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = (int *) malloc (ft_double_strlen(str) * sizeof(int));
	if (!numbers)
		return (NULL);
	while (str[i])
	{
		numbers[i] = ft_atoi(str[i]);
		i++;
	}
	*size = i;
	return (numbers);
}

static char	**ft_insert_data(char const **argv)
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
