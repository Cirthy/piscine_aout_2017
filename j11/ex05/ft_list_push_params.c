/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:39:00 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/22 19:22:59 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_chain;

	new_chain = ft_create_elem(data);
	new_chain->next = *begin_list;
	*begin_list = new_chain;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*begin_list;

	i = -1;
	begin_list = NULL;
	while (++i < ac)
		ft_list_push_front(&begin_list, av[i]);
	return (begin_list);
}
