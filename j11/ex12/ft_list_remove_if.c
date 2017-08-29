/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:33:07 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/22 09:55:10 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*current;

	if (!(*begin_list))
		return ;
	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		tmp = (*begin_list)->next;
		free((*begin_list));
		*begin_list = tmp;
	}
	current = *begin_list;
	while (current && current->next)
	{
		if (!cmp(current->next->data, data_ref))
		{
			tmp = current->next->next;
			free(current->next);
			current->next = tmp;
		}
		else
			current = current->next;
	}
}
