/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/04 18:08:32 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../assets/libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

void	ft_arg_check(int argc, char **argv, int *values);

// fn_errors.c
void	ft_arg_error(int *values);
size_t	ft_memory_error(t_list **stack_a, t_list **stack_b);

// fn_utils.c
void	ft_free_all(t_list **stack_a, t_list **stack_b, int *values);

// ft_create_stack.c
t_list	**ft_create_stack(int *values, t_list **stack_a);

// fn_actions.c
void	ft_swap(t_list **stack_a, t_list **stack_b, int oper);
void	ft_push(t_list **stack_a, t_list **stack_b, int oper);
void	ft_rotate(t_list **stack_a, t_list **stack_b, int oper);
void	ft_rev_rotate(t_list **stack_a, t_list **stack_b, int oper);

// push_swap.c
void	push_swap(t_list **stack_a, t_list **stack_b, int len);

//push_swap_utils.c
void	ft_calc_pos(t_list **stack);
void	ft_calc_target_pos(t_list **stack_a, t_list **stack_b);
void 	ft_calculate_cost_b(t_list **stack_b);
int		ft_calculate_cost_a(t_list **stack_a, int target_position);

#endif
