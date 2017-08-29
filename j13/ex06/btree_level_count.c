/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:04:59 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/23 20:16:09 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left_depth;
	int	right_depth;

	if (!root)
		return (0);
	left_depth = 1 + btree_level_count(root->left);
	right_depth = 1 + btree_level_count(root->right);
	if (left_depth > right_depth)
		return (left_depth);
	return (right_depth);
}
