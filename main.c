/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:01:59 by jakgonza          #+#    #+#             */
/*   Updated: 2023/07/28 18:09:56 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	while (argc > i)
	{
		if (ft_hasspace(argv[i]))
		{
			printf("Yes, has espace.\n");
			str = ft_split(argv[i], 32); // WARNING: - devuelve un char** maloqueado
			while (*str)                 // Si tiene **str da segfault
			{
				if (!ft_isdigit((int) *str))
				{
					free(str);
					write(2, "Todos los datos introducidos han de ser numeros enteros.\n", 57);
					exit (2);
				}
				// lst->content = *str;
				printf("El argumento contiene -> %s\n", *str);
				str++;
			}
		}
		else
			printf("NO, it doesn't\n");
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	if (argc == 5) // Si NO hay argumentos devuelve el control al usuario
		return (0);
	ft_parsedata(argc, &*argv);
	// if (argv[1])
	// 	printf("%s", argv[1]);
	return (0);
}
