/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:52:51 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/28 10:09:18 by jakgonza         ###   ########.fr       */
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
}					t_node;

// ------- UTILS ------- //
void	ft_free(char **ptr);
void	ft_error_free_dp(char **ptr);
void	ft_error(void);
int		ft_stack_sorted(t_node *stack);
int		ft_stack_size(t_node *stack);
void	ft_push_swap(t_node **stack_a, t_node **stack_b);
int		*ft_checkdata(int argc, char const **argv, int *cont, int *numbers);
int		*ft_fill_numbers(char **str, int *size);
char	**ft_return_data(int *array, int *cont);
int		ft_compare(char **str, char **nums_str);
int		ft_check_duplicates(int *numbers, int *cont);

// ------- LISTAS ------- //
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstnew(int *content);
void	ft_clear_stack(t_node **head);
int		ft_stack_size(t_node *stack);

// ------- MOVIMIENTOS ------- //
void	ft_pa(t_node **stack_a, t_node **stack_b);
void	ft_pb(t_node **stack_a, t_node **stack_b);
void	ft_swap(t_node **stack, char c);
void	ft_swap_ss(t_node **stack_a, t_node **stack_b);
void	ft_rotate(t_node **head, char c);
void	ft_rotate_rr(t_node **stack_a, t_node **stack_b);
void	ft_reverse_rotate(t_node **head, char c);
void	ft_reverse_rotate_rrr(t_node **stack_a, t_node **stack_b);

// ------- ORDENAMIENTO ------- //
void	ft_sort_three(t_node **head);
void	ft_sort_five(t_node **stack_a, t_node **stack_b);
void	ft_sort_radix(t_node **stack_a, t_node **stack_b);

#endif