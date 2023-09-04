/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:11:33 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/04 18:08:46 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calc_pos(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	ft_calc_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr_b;
	t_list	*curr_a;
	int		position;

	curr_b = *stack_b;
	while (curr_b)
	{
		position = 0;
		curr_a = *stack_a;
		while (curr_a)
		{
			if (curr_a->n > curr_b->n)
			{
				curr_b->target_pos = position;
				break ;
			}
			position++;
			curr_a = curr_a->next;
		}
		if (!curr_a)
			curr_b->target_pos = position;
		curr_b = curr_b->next;
	}
}

int ft_calculate_cost_to_top(t_list **stack, int element_position)
{
    int size = ft_lstsize(*stack);
    int cost;

    if (element_position < size / 2)
        cost = element_position;
    else
        cost = -(size - element_position);

    return cost;
}

void ft_calculate_cost_b(t_list **stack_b)
{
    t_list *tmp = *stack_b;
    int pos = 0;

    while (tmp)
    {
        tmp->cost_b = ft_calculate_cost_to_top(stack_b, pos);
        tmp = tmp->next;
        pos++;
    }
}

int ft_calculate_cost_a(t_list **stack_a, int target_position)
{
    return (ft_calculate_cost_to_top(stack_a, target_position));
}
