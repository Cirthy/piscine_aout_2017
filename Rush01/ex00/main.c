/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:01:33 by achiu-au          #+#    #+#             */
/*   Updated: 2017/08/13 21:42:56 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_valid_param(int argc, char **argv)
{
	int		i;
	int		j;
	t_cell	c;

	if (argc != (SIZE + 1))
		return (0);
	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			c = argv[i + 1][j];
			if (!(c >= '1' && c <= '9') && !(c == '.') && !c)
				return (0);
		}
		if (argv[i + 1][j])
			return (0);
	}
	return (1);
}

int		ft_absurd_init(t_cell grid[SIZE][SIZE])
{
	int		i;
	int		j;
	t_cell	tmp;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			tmp = grid[i][j];
			grid[i][j] = 0;
			if (tmp != 0 && !ft_check_possible(grid, tmp, i, j))
			{
				grid[i][j] = tmp;
				return (0);
			}
			grid[i][j] = tmp;
		}
	}
	return (1);
}

int		ft_init(t_cell grid[SIZE][SIZE], int argc, char **argv)
{
	int		i;
	int		j;
	t_cell	c;

	if (!ft_valid_param(argc, argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			c = argv[i + 1][j];
			grid[i][j] = (c == '.') ? 0 : c - '0';
		}
	}
	if (!ft_absurd_init(grid))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

void	ft_displaysolution(t_cell grid[SIZE][SIZE])
{
	int i;
	int j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			ft_putchar(grid[i][j] + '0');
			if (j != SIZE - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	t_cell	grid[SIZE][SIZE];
	t_cell	first_solution[SIZE][SIZE];
	int		nbsol;

	nbsol = -1;
	if (ft_init(grid, argc, argv))
	{
		if (ft_browse_solutions(0, grid, first_solution, &nbsol))
			ft_putstr("Error\n");
		else
		{
			if (!nbsol)
				ft_displaysolution(first_solution);
			else
				ft_putstr("Error\n");
		}
	}
	return (0);
}
