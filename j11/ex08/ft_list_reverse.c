/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:52:37 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/22 13:47:31 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	if (!*begin_list)
		return ;
	current = *begin_list;
	next = current->next;
	current->next = NULL;
	prev = current;
	while (next)
	{
		current = next;
		next = current->next;
		current->next = prev;
		prev = current;
	}
	*begin_list = current;
}
