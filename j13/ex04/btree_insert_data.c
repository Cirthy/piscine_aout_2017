/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 18:16:38 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/24 09:24:37 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *))
{
	t_btree	*new_node;

	new_node = btree_create_node(item);
	if (!*root)
	{
		*root = new_node;
		return ;
	}
	if ((*cmpf)((*root)->item, item) > 0)
	{
		if (!(*root)->left)
			(*root)->left = new_node;
		else
			btree_insert_data(&((*root)->left), item, cmpf);
	}
	else
	{
		if (!(*root)->right)
			(*root)->right = new_node;
		else
			btree_insert_data(&((*root)->right), item, cmpf);
	}
}
