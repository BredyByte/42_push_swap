/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/07 15:13:37 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../assets/libft/include/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_arg_check(int argc, char **argv);

// fn_errors.c
void	ft_arg_error(void);
size_t	ft_memory_error(t_list **stack_a, t_list **stack_b);

// fn_utils.c
void	ft_free_all(t_list **stack_a, t_list **stack_b, char **values,
			int v_case);

// ft_create_stack.c
t_list	**ft_create_stack(char **values, t_list **stack_a);

// fn_actions.c
void	ft_swap(t_list **stack_a, t_list **stack_b, int oper);
void	ft_push(t_list **stack_a, t_list **stack_b, int oper);
void	ft_rotate(t_list **stack_a, t_list **stack_b, int oper);
void	ft_rev_rotate(t_list **stack_a, t_list **stack_b, int oper);

// push_swap.c
void	push_swap(t_list **stack_a, t_list **stack_b, int len);

// push_swap_utils.c

// fn_more_three_alg_utils.c
t_list	*ft_find_cheapest_element(t_list **stack_b);
void	ft_move_cheapest_element_to_a(t_list **stack_a, t_list **stack_b);

// fn_algorithms.c
void	ft_alg_two(t_list **stack_a);
void	ft_alg_three(t_list **stack_a);

#endif
