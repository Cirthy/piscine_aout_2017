/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:17:28 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/20 16:20:36 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle02.h"

void	ft_init_globtab(void)
{
	int i;

	i = -1;
	while (++i < NB_COLLE)
		g_is_colle[i] = 1;
}

void	ft_display_result(int line_len, int line_nbr)
{
	int is_not_first;
	int i;
	int no_match;

	no_match = 1;
	is_not_first = 0;
	i = -1;
	while (++i < NB_COLLE)
		if (g_is_colle[i])
		{
			no_match = 0;
			if (is_not_first)
				ft_putstr(" || ");
			is_not_first = 1;
			ft_putstr("[colle-0");
			ft_putnbr(i);
			ft_putstr("] [");
			ft_putnbr(line_len);
			ft_putstr("] [");
			ft_putnbr(line_nbr);
			ft_putchar(']');
		}
	if (no_match)
		ft_putstr(NO_MATCH_MESSAGE);
}

int		main(void)
{
	char	enter[BUFFER_SIZE + 1];
	int		line_len;
	int		line_nbr;
	int		ret;

	ret = read(0, enter, BUFFER_SIZE);
	enter[ret] = '\0';
	line_len = ft_get_first_line_size(enter);
	ft_init_globtab();
	line_nbr = ft_get_nbr_line(enter);
	if (line_nbr == 0 || line_len == 0)
		ft_display_result(0, 0);
	else if (ft_not_same_len(enter, line_len))
	{
		ft_putstr(NO_MATCH_MESSAGE);
		return (0);
	}
	ft_test_corners(enter, line_len, line_nbr);
	ft_test_line(enter, line_len, line_nbr);
	if (line_len > 0 && line_nbr > 0)
		ft_display_result(line_len, line_nbr);
	ft_putchar('\n');
	return (0);
}
