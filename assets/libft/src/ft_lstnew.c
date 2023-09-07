/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:00:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/06 16:51:32 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int num, int fin_ind)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->n = num;
	new_list->fin_ind = fin_ind;
	new_list->pos = 0;
	new_list->target_pos = 0;
	new_list->cost_a = 0;
	new_list->cost_b = 0;
	new_list->next = NULL;
	return (new_list);
}
