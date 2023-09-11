/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:43:13 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/11 15:23:24 by dbredykh         ###   ########.fr       */
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

static void	ft_reset_a(t_list **stack_a)
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

static int	fill_target(t_list **stack_a, int index)
{
	t_list	*node;
	int		dif;
	int		found;

	dif = 1;
	found = 0;
	if (index > max_fin_ind(stack_a))
		index = 0;
	while (found == 0)
	{
		node = *stack_a;
		while (node && found == 0)
		{
			if (node->fin_ind - dif == index)
				found = 1;
			else
				node = node->next;
		}
		dif++;
	}
	return (node->pos);
}

static int	fill_cost(int pos, int size)
{
	int	half;

	if (size % 2 == 0)
		half = size / 2;
	else
		half = (size / 2) + 1;
	if (pos <= half)
		return (pos - 1);
	else
		return (pos - size - 1);
}

void	ft_fill_stats(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	ft_calc_pos(stack_a);
	ft_calc_pos(stack_b);
	ft_reset_a(stack_a);
	node = *stack_b;
	while (node)
	{
		node->target_pos = fill_target(stack_a, node->fin_ind);
		node->cost_a = fill_cost(node->target_pos, size_a);
		node->cost_b = fill_cost(node->pos, size_b);
		node = node->next;
	}
}
