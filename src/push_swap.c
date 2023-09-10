/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:14:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/10 19:54:25 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_swap(t_list **stack_a, t_list **stack_b, int len)
{
	if (!ft_is_sorted(stack_a))
	{
		if (len == 2)
			ft_alg_two(stack_a);
		else if (len == 3)
			ft_alg_three(stack_a);
		else if (len > 3)
			ft_alg_three_plus(stack_a, stack_b, len);
		if (!ft_is_sorted(stack_a))
			ft_adjust_stack_a(stack_a);
	}
}
