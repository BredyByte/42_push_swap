/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:14:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/04 18:08:59 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_alg_two(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->n > tmp->next->n)
		ft_swap(stack_a, NULL, 'a');
}

static	void	ft_alg_three(t_list **stack_a)
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

void determine_costs_for_stack_B(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp = *stack_b;

    while (tmp)
    {
        int target_pos = tmp->target_pos;
        tmp->cost_a = ft_calculate_cost_a(stack_a, target_pos);
        tmp = tmp->next;
    }
}

static void	ft_more_three(t_list **stack_a, t_list **stack_b, int len)
{
	int		i;
	int		pos;
	t_list	*tmp;

	i = len;
	pos = 0;
	tmp = *stack_b;
	while (i != 3)
	{
		ft_push(stack_a, stack_b, 'b');
		i--;
	}
	ft_alg_three(stack_a);
	ft_calc_pos(stack_a);
	ft_calc_pos(stack_b);
	ft_calc_target_pos(stack_a, stack_b);
	ft_calculate_cost_b(stack_b);
	determine_costs_for_stack_B(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b, int len)
{
	(void) stack_b;
	if (len == 2)
		ft_alg_two(stack_a);
	if (len == 3)
		ft_alg_three(stack_a);
	if (len > 3)
		ft_more_three(stack_a, stack_b, len);
}
