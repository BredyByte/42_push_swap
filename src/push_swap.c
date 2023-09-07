/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:14:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/07 16:27:09 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_calc_pos(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

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

void	ft_push_all(t_list **a, t_list **b, int maxfin_ind)
{
	while (ft_lstsize(*a) > (maxfin_ind / 2 + 1) && ft_lstsize(*a) > 3)
	{
		if ((*a)->fin_ind <= maxfin_ind / 2)
			ft_push(a, b, 'b');
		else
			ft_rotate(a, b, 'a');
	}
	while (ft_lstsize(*a) > 3)
		ft_push(a, b, 'b');
}

int	max_fin_ind(t_list **stack_a)
{
	t_list	*tmp;
	int		max;

	tmp = *stack_a;
	max = tmp->fin_ind;
	while (tmp)
	{
		if (tmp->fin_ind > max)
			max = tmp->fin_ind;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_get_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_b;
	int		dif;
	int		found;
	int		fin_ind;

	dif = 1;
	found = 0;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		fin_ind = tmp_b->fin_ind;
		if (fin_ind > max_fin_ind(stack_a))
			fin_ind = 0;
		while (found == 0)
		{
			tmp = *stack_a;
			while (tmp && found == 0)
			{
				if (tmp->fin_ind - dif == fin_ind)
					found = 1;
				else
					tmp = tmp->next;
			}
			dif++;
		}
		tmp_b->target_pos = tmp->pos;
		tmp_b = tmp_b->next;
	}
}

void	ft_reset_a(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		tmp->cost_a = 0;
		tmp->cost_b = 0;
		tmp->target_pos = 0;
		tmp = tmp->next;
	}
}

void	ft_get_costs(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		size_b;
	t_list	*tmp;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		int half_a, half_b;
		if (size_a % 2 == 0)
			half_a = size_a / 2;
		else
			half_a = (size_a / 2) + 1;
		if (size_b % 2 == 0)
			half_b = size_b / 2;
		else
			half_b = (size_b / 2) + 1;
		if (tmp->target_pos <= half_a)
			tmp->cost_a = tmp->target_pos - 1;
		else
			tmp->cost_a = tmp->target_pos - size_a - 1;
		if (tmp->pos <= half_b)
			tmp->cost_b = tmp->pos - 1;
		else
			tmp->cost_b = tmp->pos - size_b - 1;
		tmp = tmp->next;
	}
}

void	ft_fill_stats(t_list **stack_a, t_list **stack_b)
{
	ft_calc_pos(stack_a);
	ft_calc_pos(stack_b);
	ft_reset_a(stack_a);
	ft_get_target_pos(stack_a, stack_b);
	ft_get_costs(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b, int len)
{
	if (!ft_is_sorted(stack_a))
	{
		if (len == 2)
			ft_alg_two(stack_a);
		if (len == 3)
			ft_alg_three(stack_a);
		if (len > 3)
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
			if (!ft_is_sorted(stack_a))
				ft_adjust_stack_a(stack_a);
		}
	}
}
