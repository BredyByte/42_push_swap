/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:14:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/06 16:20:59 by dbredykh         ###   ########.fr       */
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

int	max_index(t_list **stack_a)
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

int	fill_cost(int pos, int size)
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

int	fill_target(t_list **stack_a, int index)
{
	t_list	*tmp;
	int		dif;
	int		found;

	dif = 1;
	found = 0;
	if (index > max_index(stack_a))
		index = 0;
	while (found == 0)
	{
		tmp = *stack_a;
		while (tmp && found == 0)
		{
			if (tmp->fin_ind - dif == index)
				found = 1;
			else
				tmp = tmp->next;
		}
		dif++;
	}
	return (tmp->pos);
}

void	fill_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		pos;

	pos = 1;
	tmp = *stack_a;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
	pos = 1;
	tmp = *stack_b;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}

void	ft_fill_stats(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	fill_pos(stack_a, stack_b);
	tmp = *stack_a;
	while (tmp)
	{
		tmp->target_pos = 0;
		tmp->cost_a = 0;
		tmp->cost_b = 0;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	while (tmp)
	{
		tmp->target_pos = fill_target(stack_a, tmp->fin_ind);
		printf ("target_pos : %d \n", tmp->target_pos);
		tmp->cost_a = fill_cost(tmp->target_pos, size_a);
		tmp->cost_b = fill_cost(tmp->pos, size_b);
		tmp = tmp->next;
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b, int len)
{
	t_list	*tmp;
	if (len == 2)
		ft_alg_two(stack_a);
	if (len == 3)
		ft_alg_three(stack_a);
	if (len > 3)
	{
		ft_push_all_but_three_to_b(stack_a, stack_b, len);
		ft_alg_three(stack_a);
		printf ("Stack_a\n");
		tmp = *stack_a;
		while (tmp)
		{
			printf("value: %d, ", tmp->n);
			printf("fin_index: %d, \n", tmp->fin_ind);
			tmp = tmp->next;
		}
		while (ft_lstsize(*stack_b) > 0)
		{
			ft_fill_stats(stack_a, stack_b);
			ft_calc_target_pos(stack_a, stack_b);
			/* ft_determine_costs_for_stack_b(stack_a, stack_b); */
			ft_move_cheapest_element_to_a(stack_a, stack_b);
		}
		printf ("Before: \n");
		tmp = *stack_a;
		while (tmp)
		{
			printf("value: %d, ", tmp->n);
			printf("fin_index: %d, ", tmp->fin_ind);
			printf("cost_b: %d, ", tmp->cost_b);
			printf("cost_a: %d, ", tmp->cost_a);
			printf("pos: %d, ", tmp->pos);
			printf("target_pos: %d, \n", tmp->target_pos);
			tmp = tmp->next;
		}
		if (!ft_is_sorted(stack_a))
			ft_adjust_stack_a(stack_a);
		printf ("After: \n");
		tmp = *stack_a;
		while (tmp)
		{
			printf("value: %d, ", tmp->n);
			printf("fin_index: %d, \n", tmp->fin_ind);
			tmp = tmp->next;
		}
	}
}
