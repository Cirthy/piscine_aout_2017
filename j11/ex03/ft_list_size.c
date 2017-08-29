/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:09:46 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/21 21:40:30 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
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
