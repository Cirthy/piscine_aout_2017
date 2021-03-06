/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:20:30 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/22 13:08:24 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int	size;

	if (!begin_list)
		return (0);
	size = 1;
	while (begin_list->next)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	ft_swap(t_list **begin_list, t_list *prev,
				t_list *chain1, t_list *chain2)
{
	if (prev)
		prev->next = chain2;
	else
		*begin_list = chain2;
	chain1->next = chain2->next;
	chain2->next = chain1;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		size;
	t_list	*prev;
	t_list	*current;

	size = ft_list_size(*begin_list);
	i = -1;
	while (++i < size)
	{
		current = *begin_list;
		prev = NULL;
		while (current->next)
		{
			if (cmp(current->data, current->next->data) > 0)
				ft_swap(begin_list, prev, current, current->next);
			else
				current = current->next;
			if (prev)
				prev = prev->next;
			else
				prev = *begin_list;
		}
	}
}
