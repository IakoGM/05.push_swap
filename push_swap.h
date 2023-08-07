/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:52:51 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/07 11:49:18 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				index;
	int				content;
	struct s_node	*next;
}					t_node;

void	ft_free(char **ptr);
void	ft_error(char **ptr);

#endif