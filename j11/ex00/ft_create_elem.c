/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:40:30 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/22 13:41:35 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*new_chain;

	new_chain = malloc(sizeof(t_list));
	if (new_chain)
	{
		new_chain->data = data;
		new_chain->next = NULL;
	}
	return (new_chain);
}
