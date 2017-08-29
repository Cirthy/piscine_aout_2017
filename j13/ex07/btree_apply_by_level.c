/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:12:31 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/24 13:19:10 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * (ft_recursive_power(nb, power - 1)));
}

int		btree_level_count(t_btree *root)
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

t_param	ft_set_param(t_btree *node, int current_level)
{
	t_param	set;

	set.node = node;
	set.current_level = current_level;
	return (set);
}

void	ft_apply_f(t_btree *root, void (*applyf)(), t_param *file)
{
	int		i;
	int		append;
	int		current_level;
	int		is_first_elem;

	file[0] = ft_set_param(root, 0);
	i = 0;
	append = 1;
	current_level = -1;
	while ((file + i)->node != NULL)
	{
		is_first_elem = (file + i)->current_level == current_level ? 0 : 1;
		current_level = (file + i)->current_level;
		(*applyf)((file + i)->node->item, current_level, is_first_elem);
		if ((file + i)->node->left)
			file[append++] = ft_set_param((file + i)->node->left,
										(file + i)->current_level + 1);
		if ((file + i)->node->right)
			file[append++] = ft_set_param((file + i)->node->right,
										(file + i)->current_level + 1);
		i++;
	}
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_param		*file;
	int			max_width;
	int			i;

	if (!root)
		return ;
	max_width = ft_recursive_power(2, btree_level_count(root) - 1);
	file = malloc(sizeof(*file) * max_width * (max_width + 1) / 2);
	i = -1;
	while (++i < max_width * (max_width + 1) / 2)
		file[i] = ft_set_param(NULL, 0);
	ft_apply_f(root, applyf, file);
}
