/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabwat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 19:46:23 by msabwat           #+#    #+#             */
/*   Updated: 2017/08/13 21:43:13 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_not_inline(t_cell grid[SIZE][SIZE], t_cell nb, int i)
{
	int j;

	j = -1;
	while (++j < SIZE)
		if (grid[i][j] == nb)
			return (0);
	return (1);
}

int		ft_not_incolumn(t_cell grid[SIZE][SIZE], t_cell nb, int j)
{
	int i;

	i = -1;
	while (++i < SIZE)
		if (grid[i][j] == nb)
			return (0);
	return (1);
}

int		ft_not_inblock(t_cell grid[SIZE][SIZE], t_cell nb, int i, int j)
{
	int first_i_block;
	int first_j_block;

	first_i_block = i - (i % 3);
	first_j_block = j - (j % 3);
	i = first_i_block - 1;
	while (++i < first_i_block + 3)
	{
		j = first_j_block - 1;
		while (++j < first_j_block + 3)
			if (grid[i][j] == nb)
				return (0);
	}
	return (1);
}

int		ft_check_possible(t_cell grid[SIZE][SIZE], t_cell nb, int i, int j)
{
	return (ft_not_inline(grid, nb, i) &&
			ft_not_incolumn(grid, nb, j) &&
			ft_not_inblock(grid, nb, i, j));
}
