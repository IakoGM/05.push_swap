/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:01:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/07/26 18:16:20 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsedata(int argc, char **argv)
{
	int i;

	i = 1;
	while (argc > i)
	{
		if (ft_hasspace(argv[i]))
		{
			ft_split(argv[i]);
		}
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	if (argc == 1) // Si NO hay argumentos devuelve el control al usuario
		return (0);
	ft_parsedata(argc, &*argv);
	return (0);
}
