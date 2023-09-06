/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:14:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/06 10:54:10 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// Функция для корректировки стека A
static void	ft_adjust_stack_a(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*smallest;

	tmp = *stack_a;
	smallest = tmp;
	while (tmp)
	{
		if (tmp->n < smallest->n)
			smallest = tmp;
		tmp = tmp->next;
	}
	while (*stack_a != smallest)
	{
		if (smallest->pos < (ft_lstsize(*stack_a) / 2))
			ft_rotate(stack_a, NULL, 'a');
		else
			ft_rev_rotate(stack_a, NULL, 'a');
	}
}

static void	ft_push_all_but_three_to_b(t_list **stack_a, t_list **stack_b,
		int len)
{
	int	i;

	i = len;
	while (i != 3)
	{
		ft_push(stack_a, stack_b, 'b');
		i--;
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 2)
		ft_alg_two(stack_a);
	if (len == 3)
		ft_alg_three(stack_a);
	if (len > 3)
	{
		ft_push_all_but_three_to_b(stack_a, stack_b, len);
		ft_alg_three(stack_a);
		while (ft_lstsize(*stack_b) > 0)
		{
			ft_calc_pos(stack_a);
			ft_calc_pos(stack_b);
			ft_calc_target_pos(stack_a, stack_b);
			ft_calculate_cost_b(stack_b);
			ft_determine_costs_for_stack_b(stack_a, stack_b);
			ft_move_cheapest_element_to_a(stack_a, stack_b);
		}
		if (!ft_is_sorted(stack_a))
			ft_adjust_stack_a(stack_a);
	}
}
