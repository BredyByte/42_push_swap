/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_more_three_alg_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:30:02 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/05 14:09:23 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_determine_costs_for_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		target_pos;

	tmp = *stack_b;
	while (tmp)
	{
		target_pos = tmp->target_pos;
		tmp->cost_a = ft_calculate_cost_a(stack_a, target_pos);
		tmp = tmp->next;
	}
}

t_list	*ft_find_cheapest_element(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*cheapest_element;
	int		lowest_cost;
	int		tmp_cost;

	tmp = *stack_b;
	cheapest_element = NULL;
	lowest_cost = INT_MAX;
	while (tmp)
	{
		tmp_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		if (tmp_cost < lowest_cost)
		{
			lowest_cost = tmp_cost;
			cheapest_element = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest_element);
}

static void	ft_exec_act_aux(t_list **stack_a, t_list **stack_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		ft_rotate(stack_a, stack_b, 'r');
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		ft_rev_rotate(stack_a, stack_b, 'r');
		(*cost_a)++;
		(*cost_b)++;
	}
	while (*cost_a > 0)
	{
		ft_rotate(stack_a, NULL, 'a');
		(*cost_a)--;
	}
}

void	ft_execute_optimized_actions(t_list **stack_a, t_list **stack_b,
		int *cost_a, int *cost_b)
{
	ft_exec_act_aux(stack_a, stack_b, cost_a, cost_b);
	while (*cost_a < 0)
	{
		ft_rev_rotate(stack_a, NULL, 'a');
		(*cost_a)++;
	}
	while (*cost_b > 0)
	{
		ft_rotate(NULL, stack_b, 'b');
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		ft_rev_rotate(NULL, stack_b, 'b');
		(*cost_b)++;
	}
}

void	ft_move_cheapest_element_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = ft_find_cheapest_element(stack_b);
	ft_execute_optimized_actions(stack_a, stack_b, &(cheapest->cost_a),
		&(cheapest->cost_b));
	ft_push(stack_a, stack_b, 'a');
}
