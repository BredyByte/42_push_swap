/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:31:34 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/10 19:54:05 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_alg_two(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->n > tmp->next->n)
		ft_swap(stack_a, NULL, 'a');
}

void	ft_alg_three(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->n > tmp->next->n && tmp->n < tmp->next->next->n)
		ft_swap(stack_a, NULL, 'a');
	else if (tmp->n > tmp->next->n
		&& tmp->next->n > tmp->next->next->n
		&& tmp->n > tmp->next->next->n)
	{
		ft_swap(stack_a, NULL, 'a');
		ft_rev_rotate(stack_a, NULL, 'a');
	}
	else if (tmp->n > tmp->next->n
		&& tmp->next->n < tmp->next->next->n
		&& tmp->n > tmp->next->next->n)
		ft_rotate(stack_a, NULL, 'a');
	else if (tmp->next->next->n > tmp->n && tmp->next->n > tmp->next->next->n)
	{
		ft_swap(stack_a, NULL, 'a');
		ft_rotate(stack_a, NULL, 'a');
	}
	else if (tmp->n > tmp->next->next->n && tmp->next->n > tmp->n)
		ft_rev_rotate(stack_a, NULL, 'a');
}

static void	ft_push_all(t_list **stack_a, t_list **stack_b, int maxfin_ind)
{
	while (ft_lstsize(*stack_a) > (maxfin_ind / 2 + 1)
		&& ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->fin_ind <= maxfin_ind / 2)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, stack_b, 'a');
	}
	while (ft_lstsize(*stack_a) > 3)
		ft_push(stack_a, stack_b, 'b');
}

void	ft_alg_three_plus(t_list **stack_a, t_list **stack_b, int len)
{
	ft_push_all(stack_a, stack_b, len);
	ft_fill_stats(stack_a, stack_b);
	if (!ft_is_sorted(stack_a))
		ft_alg_three(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		ft_fill_stats(stack_a, stack_b);
		ft_move_cheapest_element_to_a(stack_a, stack_b);
	}
}
