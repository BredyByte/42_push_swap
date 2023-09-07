/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_more_three_alg_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:30:02 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/07 15:33:30 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_move_cheapest_element_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = ft_find_cheapest_element(stack_b);
	ft_push(stack_a, stack_b, 'a');
}
