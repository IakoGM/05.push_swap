/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:52:51 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/26 08:54:15 by jakgonza         ###   ########.fr       */
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

// ------- UTILS ------- //
void	ft_free(char **ptr);
void	ft_error_free_dp(char **ptr);
void	ft_error(void);
int		ft_stack_sorted(Node *stack);
void	ft_update(Node *head, int *s, int *m, int *e);
int		ft_stack_size(Node *stack);
int		*ft_list_to_array(Node *head, int *arr_size);
void	ft_sort_array(int *a, int *arr_size);
void	ft_stack_indexing(Node **stack_a, int *a, int *arr_size);


// ------- LISTAS ------- //
void	ft_lstadd_front(Node **lst, Node *new);
void	ft_lstadd_back(Node **lst, Node *new);
Node	*ft_lstnew(int *content);
void	ft_clear_stack(Node **head);
int		ft_stack_size(Node *stack);
int		ft_find_last(Node *head);

// ------- MOVIMIENTOS ------- //
void	ft_pa(Node **stack_a, Node **stack_b);
void	ft_pb(Node **stack_a, Node **stack_b);
void	ft_swap(Node **stack, char c);
void	ft_swap_ss(Node **stack_a, Node **stack_b);
void	ft_rotate(Node **head, char c);
void	ft_rotate_rr(Node **stack_a, Node **stack_b);
void	ft_reverse_rotate(Node **head, char c);
void	ft_reverse_rotate_rrr(Node **stack_a, Node **stack_b);

// ------- ORDENAMIENTO ------- //
void	ft_sort_three(Node **head);
void	ft_sort_five(Node **stack_a, Node **stack_b);
void	ft_sort_radix(Node **stack_a, Node **stack_b);

// ------- Funciones para eliminar ------- //
void	ft_print_stack(Node *stack);
int		ft_array_size(int *a);

#endif