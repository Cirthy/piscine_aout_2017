/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_solutions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 11:16:37 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/13 20:04:08 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	ft_fullgrid(t_cell grid[SIZE][SIZE],
			t_cell first_solution[SIZE][SIZE], int *nbsol)
{
	int i;
	int j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			first_solution[i][j] = grid[i][j];
	}
	(*nbsol)++;
	return (*nbsol);
}

int	ft_browse_solutions(int cur, t_cell grid[SIZE][SIZE],
						t_cell first_solution[SIZE][SIZE], int *nbsol)
{
	int		i;
	int		j;
	t_cell	c;

	if (cur == 81)
		return (ft_fullgrid(grid, first_solution, nbsol));
	i = cur / 9;
	j = cur % 9;
	if (grid[i][j] != 0)
		return (ft_browse_solutions(cur + 1, grid, first_solution, nbsol));
	c = 0;
	while (++c < 10)
	{
		if (ft_check_possible(grid, c, i, j))
		{
			grid[i][j] = c;
			if (ft_browse_solutions(cur + 1, grid, first_solution, nbsol))
				return (1);
			grid[i][j] = 0;
		}
	}
	return (0);
}
