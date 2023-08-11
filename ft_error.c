/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:38:27 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/10 12:49:59 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_free_dp(char **ptr)
{
	if (!ptr)
		exit(2);
	ft_free(ptr);
	write(2, "Error\n", 6);
	exit(2);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}
