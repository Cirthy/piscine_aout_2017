/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:41:27 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/07 15:38:22 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_init_pos(int *pos)
{
	int i;

	i = 0;
	while (i++ < 8)
		pos[i - 1] = -10;
}

int		ft_abs(int i)
{
	if (i > 0)
		return (i);
	return (-i);
}

int		ft_is_free(int ligne, int colonne, int *pos)
{
	int l;
	int c;
	int free;

	l = 0;
	free = 1;
	while (free && l <= ligne)
	{
		c = pos[l];
		free = (colonne != c) && (ligne - l != ft_abs(colonne - c));
		l++;
	}
	return (free);
}

void	ft_browse_tree(int ligne, int *pos, int *count)
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
				ft_browse_tree(ligne + 1, pos, count);
				pos[ligne] = -10;
			}
			colonne++;
		}
	}
	else
		(*count)++;
}

int		ft_eight_queens_puzzle(void)
{
	int count;
	int pos[8];

	count = 0;
	ft_init_pos(pos);
	ft_browse_tree(0, pos, &count);
	return (count);
}
