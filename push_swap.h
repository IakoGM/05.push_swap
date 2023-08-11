/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:52:51 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/10 16:04:02 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
}					t_stack;

void	ft_free(char **ptr);
void	ft_error_free_dp(char **ptr);
void	ft_error(void);


// ------- LISTAS ------- //
void	ft_lstadd_front(t_stack **lst, t_stack *new);
// void	ft_lstadd_back(t_stack **lst, t_stack *new)
t_stack	*ft_lstnew(int *content);


#endif