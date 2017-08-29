/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:35:43 by achiu-au          #+#    #+#             */
/*   Updated: 2017/08/13 20:00:28 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>

# define SIZE 9

typedef char	t_cell;
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_check_possible(char grid[SIZE][SIZE], char nb, int x, int y);
int		ft_browse_solutions(int cur, t_cell grid[SIZE][SIZE],
							t_cell first_solution[SIZE][SIZE], int *nbsol);
#endif
