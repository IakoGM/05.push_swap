/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:01:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/02 20:04:03 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "libft/libft.h"
#include <stdio.h>

int ft_atoi(const char *nptr)
{
	int num;

	num = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + *nptr - '0';
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9') && *nptr != '\0')
		return (-1);
	return (num);
}

int	ft_hasspace(char const *arg)
{
	while (*arg)
	{
		if (*arg == 32)
			return (1);
		arg++;
	}
	return (0);
}

void	ft_parsedata(int argc, char const **argv)
{
	int		i;
	char	**str;
	// t_node	*lst;

	i = 1;
	str = NULL;
	while (argc > i)
	{
		if (ft_hasspace(argv[i]))
		{
			str = ft_split(argv[i], 32); // WARNING: - devuelve un char** maloqueado
			while (*str)                 // Si tiene **str da segfault
			{
				if (ft_atoi(*str) == -1)
					ft_error(str);				
				// lst->content = *str;
				str++;
			}
		}
		else {
			if (ft_atoi(argv[i]) == -1)
				ft_error(argv[i]);
		}
		i++;
	}
	if (str != NULL)
		ft_free(str);
}

int	main(int argc, char const *argv[])
{
	if (argc == 1)
		return (0);
	ft_parsedata(argc, &*argv);
	return (0);
}
