/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:52:51 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/21 12:30:13 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <string.h>

typedef struct Node
{
	int				index;
	int				content;
	struct Node		*next;
}					Node;

void	ft_free(char **ptr);
void	ft_error_free_dp(char **ptr);
void	ft_error(void);


// ------- LISTAS ------- //
void	ft_lstadd_front(Node **lst, Node *new);
void	ft_lstadd_back(Node **lst, Node *new);
Node	*ft_lstnew(int *content);
void	ft_clear_stack(Node **head);
int		ft_stack_size(Node *stack);

#endif