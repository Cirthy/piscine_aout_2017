/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:52:37 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/22 19:25:47 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list *a, t_list *b)
{
	char *tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

t_list	*ft_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i++ < nbr)
	{
		if (!begin_list)
			return (NULL);
		begin_list = begin_list->next;
	}
	return (begin_list);
}

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

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	t_list	*chain1;
	t_list	*chain2;

	if (!begin_list)
		return ;
	size = ft_list_size(begin_list);
	i = size / 2;
	while (--i >= 0)
	{
		chain1 = ft_at(begin_list, size - i - 1);
		chain2 = ft_at(begin_list, i);
		ft_swap(chain1, chain2);
	}
}
