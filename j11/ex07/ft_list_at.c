/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:21:21 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/22 19:23:36 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = -1;
	while (++i < nbr)
	{
		if (!begin_list)
			return (NULL);
		begin_list = begin_list->next;
	}
	return (begin_list);
}
