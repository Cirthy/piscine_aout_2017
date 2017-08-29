/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:47:10 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/21 21:36:02 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_chain;
	t_list	*current;

	new_chain = ft_create_elem(data);
	if (!*begin_list)
	{
		*begin_list = new_chain;
		return ;
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = new_chain;
}
