/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:18:37 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/19 16:21:40 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advanced_do_op.h"
#include "ft_opp.h"

int		ft_return_with_message(char *str)
{
	ft_putstr(str);
	return (0);
}

int		ft_usage(int a, int b)
{
	int i;

	a = 0;
	b = 0;
	i = -1;
	ft_putstr("error : only [ ");
	while (++i < NB_OPERATEURS)
	{
		ft_putstr((g_opptab + i)->operateur);
		ft_putchar(' ');
	}
	ft_putstr("] are accepted.");
	return (0);
}

int		ft_testnumber(char *n)
{
	int i;

	i = 0;
	if (n[i] == '+' || n[i] == '-')
		i++;
	if (n[i] == '\0')
		n[0] = '\0';
	while (n[i++])
		if (n[i - 1] > '9' || n[i - 1] < '0')
			n[0] = '\0';
	return (1);
}

int		ft_testargs(int argc, char **argv)
{
	int	i;
	int is_operateur;

	is_operateur = 0;
	i = -1;
	if (argc != 4)
		return (0);
	while (++i < NB_OPERATEURS)
		if (!ft_strcmp(argv[2], (g_opptab + i)->operateur))
			is_operateur = 1;
	if (!is_operateur)
	{
		argv[2][0] = '\0';
		return (1);
	}
	if (!(ft_testnumber(argv[1]) && ft_testnumber(argv[3])))
		return (0);
	if (!ft_strcmp(argv[2], (g_opptab + 3)->operateur) && ft_atoi(argv[3]) == 0)
		return (ft_return_with_message("Stop : division by zero\n"));
	if (!ft_strcmp(argv[2], (g_opptab + 4)->operateur) && ft_atoi(argv[3]) == 0)
		return (ft_return_with_message("Stop : modulo by zero\n"));
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	int display_usage;

	if (!ft_testargs(argc, argv))
		return (0);
	display_usage = 1;
	i = -1;
	while (++i < NB_OPERATEURS)
		if (!ft_strcmp((g_opptab + i)->operateur, argv[2]))
		{
			ft_putnbr(
				(g_opptab + i)->operation(ft_atoi(argv[1]), ft_atoi(argv[3])));
			display_usage = 0;
		}
	if (display_usage)
		((g_opptab + i)->operation)(0, 0);
	ft_putchar('\n');
	return (0);
}
