/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:40:07 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/24 09:38:32 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *))
{
	if (!root)
		return (0);
	if ((*cmpf)(root->item, data_ref) > 0)
	{
		if (root->left)
			return (btree_search_item(root->left, data_ref, cmpf));
		else
			return (0);
	}
	else if ((*cmpf)(root->item, data_ref) < 0)
	{
		if (root->right)
			return (btree_search_item(root->right, data_ref, cmpf));
		else
			return (0);
	}
	else
		return (data_ref);
}
