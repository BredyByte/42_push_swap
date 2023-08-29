/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:57:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/29 16:04:42 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*curr;
	t_list	*prev;

	prev = (t_list *)*lst;
	while (prev)
	{
		curr = prev->next;
		ft_lstdelone(prev, del);
		prev = curr;
	}
	*lst = 0;
}
