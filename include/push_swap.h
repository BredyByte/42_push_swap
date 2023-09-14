/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/14 12:27:09 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../assets/libft/include/libft.h"

// ft_create_stack.c
t_list	**ft_create_stack(char **values, t_list **stack_a);

// fn_errors.c
void	ft_arg_error(void);
size_t	ft_memory_error(t_list **stack_a, t_list **stack_b);

// ft_arg_check.c
void	ft_arg_check(int argc, char **argv);

// fn_utils.c
void	ft_free_all(t_list **stack_a, t_list **stack_b, char **values,
			int v_case);
void	ft_fill_ind_fin(t_list **stack_a);
int		max_fin_ind(t_list **stack_a);
int		ft_is_sorted(t_list **stack);

// fn_actions.c
void	ft_swap(t_list **stack_a, t_list **stack_b, int oper);
void	ft_push(t_list **stack_a, t_list **stack_b, int oper);
void	ft_rotate(t_list **stack_a, t_list **stack_b, int oper);
void	ft_rev_rotate(t_list **stack_a, t_list **stack_b, int oper);

// push_swap.c
void	push_swap(t_list **stack_a, t_list **stack_b, int len);

// fn_algorithms.c
void	ft_alg_two(t_list **stack_a);
void	ft_alg_three(t_list **stack_a);
void	ft_alg_three_plus(t_list **stack_a, t_list **stack_b, int len);

// void	ft_move_cheapest.c
void	ft_move_cheapest_element_to_a(t_list **stack_a, t_list **stack_b);

// ft_fill_stats.c
void	ft_fill_stats(t_list **stack_a, t_list **stack_b);

// fn_algorithms.c
void	ft_alg_two(t_list **stack_a);
void	ft_alg_three(t_list **stack_a);
void	ft_alg_three_plus(t_list **stack_a, t_list **stack_b, int len);

#endif
