/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdata_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:39:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 09:52:53 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_return_data(int *array, int *cont)
{
	char	**res;
	int		len;
	int		i;

	i = 0;
	len = *cont;
	res = (char **) malloc ((len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
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
		j = i + 1;
		while (j < *cont)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
