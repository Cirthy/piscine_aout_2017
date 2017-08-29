/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:17:07 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/08 11:41:03 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_init_pos(int *pos)
{
	int i;

	i = 0;
	while (i++ < 8)
		pos[i - 1] = -10;
}

void	ft_display_sol(int *pos)
{
	int i;

	i = 0;
	while (i++ < 8)
		ft_putchar(pos[i - 1] + '1');
	ft_putchar('\n');
}

int		ft_is_free(int ligne, int colonne, int *pos)
{
	int l;
	int c;
	int free;
	int bool_abs;

	l = 0;
	free = 1;
	while (free && l <= ligne)
	{
		c = pos[l];
		bool_abs = (ligne - l != colonne - c) && (ligne - l != c - colonne);
		free = (colonne != c) && bool_abs;
		l++;
	}
	return (free);
}

void	ft_browse_tree(int ligne, int *pos)
{
	int colonne;

	if (ligne < 8)
	{
		colonne = 0;
		while (colonne < 8)
		{
			if (ft_is_free(ligne, colonne, pos))
			{
				pos[ligne] = colonne;
				ft_browse_tree(ligne + 1, pos);
				pos[ligne] = -10;
			}
			colonne++;
		}
	}
	else
		ft_display_sol(pos);
}

void	ft_eight_queens_puzzle_2(void)
{
	int pos[8];

	ft_init_pos(pos);
	ft_browse_tree(0, pos);
}
