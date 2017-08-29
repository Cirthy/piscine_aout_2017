/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:34:44 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/22 13:22:24 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_chain;
	t_list	*current;
	int		inserted;

	new_chain = ft_create_elem(data);
	inserted = 0;
	if (!(*begin_list) || cmp(data, (*begin_list)->data) < 0)
	{
		new_chain->next = *begin_list;
		*begin_list = new_chain;
		return ;
	}
	current = *begin_list;
	while (!inserted && current->next)
	{
		if (cmp(data, current->next->data) < 0)
		{
			new_chain->next = current->next;
			current->next = new_chain;
			inserted = 1;
		}
		current = current->next;
	}
	if (!inserted)
		current->next = new_chain;
}
