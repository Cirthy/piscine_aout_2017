/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test-corners.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 21:02:33 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/22 15:38:03 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle02.h"

void	ft_test_top_left_corner(char tlc)
{
	if (tlc != 'o')
		g_is_colle[0] = 0;
	if (tlc != '/')
		g_is_colle[1] = 0;
	if (tlc != 'A')
	{
		g_is_colle[2] = 0;
		g_is_colle[3] = 0;
		g_is_colle[4] = 0;
	}
}

void	ft_test_top_right_corner(char trc)
{
	if (trc != 'o')
		g_is_colle[0] = 0;
	if (trc != 92)
		g_is_colle[1] = 0;
	if (trc != 'A')
		g_is_colle[2] = 0;
	if (trc != 'C')
	{
		g_is_colle[3] = 0;
		g_is_colle[4] = 0;
	}
}

void	ft_test_bottom_left_corner(char blc)
{
	if (blc != 'o')
		g_is_colle[0] = 0;
	if (blc != 92)
		g_is_colle[1] = 0;
	if (blc != 'C')
	{
		g_is_colle[2] = 0;
		g_is_colle[4] = 0;
	}
	if (blc != 'A')
		g_is_colle[3] = 0;
}

void	ft_test_bottom_right_corner(char brc)
{
	if (brc != 'o')
		g_is_colle[0] = 0;
	if (brc != '/')
		g_is_colle[1] = 0;
	if (brc != 'C')
	{
		g_is_colle[2] = 0;
		g_is_colle[3] = 0;
	}
	if (brc != 'A')
		g_is_colle[4] = 0;
}

void	ft_test_corners(char *str, int line_len, int line_nbr)
{
	int		i;
	int		current_line;

	ft_test_top_left_corner(str[0]);
	i = 0;
	current_line = 1;
	while (str[i])
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (line_len > 1)
			ft_test_top_right_corner(str[i - 1]);
		while (current_line != line_nbr)
		{
			if (str[i] == '\n')
				current_line++;
			i++;
		}
		if (line_nbr > 1)
			ft_test_bottom_left_corner(str[i]);
		while (str[i])
			i++;
		if (line_len > 1 && line_nbr > 1)
			ft_test_bottom_right_corner(str[i - 2]);
	}
}
