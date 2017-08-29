/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 22:01:49 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/20 16:18:43 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle02.h"

void	ft_set_g_to_zero(void)
{
	int i;

	i = -1;
	while (++i < NB_COLLE)
		g_is_colle[i] = 0;
}

void	ft_test_edge_line(char *str, int line_len)
{
	int		i;
	int		j;
	char	*char_edge;

	char_edge = (char *)malloc(NB_COLLE);
	if (!char_edge)
		return ;
	char_edge = "-*BBB";
	i = 0;
	while (++i < line_len - 1)
	{
		j = -1;
		while (++j < NB_COLLE)
		{
			if (g_is_colle[j] && str[i] != char_edge[j])
				g_is_colle[j] = 0;
		}
	}
}

void	ft_test_body_line(char *str, int line_len)
{
	int		i;
	char	*char_body;

	char_body = (char *)malloc(NB_COLLE);
	if (!char_body)
		return ;
	char_body = "|*BBB";
	i = -1;
	while (++i < NB_COLLE)
		if (g_is_colle[i] && str[0] != char_body[i])
			g_is_colle[0] = 0;
	i = 0;
	while (++i < line_len - 2)
		if (str[i] != ' ')
			ft_set_g_to_zero();
	i = -1;
	while (++i < NB_COLLE)
		if (g_is_colle[i] && str[line_len - 1] != char_body[i])
			g_is_colle[i] = 0;
}

void	ft_test_line(char *str, int line_len, int line_nbr)
{
	int i;

	ft_test_edge_line(str, line_len);
	i = 0;
	while (++i < line_nbr - 1)
		ft_test_body_line(str + i * (line_len + 1), line_len);
	if (line_nbr > 1)
		ft_test_edge_line(str + i * (line_len + 1), line_len);
}
