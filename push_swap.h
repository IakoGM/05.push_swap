/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:52:51 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/09 13:06:11 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
}					t_stack;

void	ft_free(char **ptr);
void	ft_error(char **ptr);

#endif