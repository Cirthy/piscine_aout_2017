/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:18:37 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/16 17:19:16 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_testnumber(char *n)
{
	int i;

	i = 0;
	if (n[i] == '+' || n[i] == '-')
		i++;
	if (!ft_strlen(n + i))
	{
		ft_putstr("0\n");
		return (0);
	}
	while (n[i++])
		if (n[i - 1] > '9' || n[i - 1] < '0')
		{
			ft_putstr("0\n");
			return (0);
		}
	return (1);
}

int		ft_testargs(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (ft_strlen(argv[2]) != 1 ||
		(argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' &&
			argv[2][0] != '/' && argv[2][0] != '%'))
	{
		ft_putstr("0\n");
		return (0);
	}
	if (!(ft_testnumber(argv[1]) && ft_testnumber(argv[3])))
		return (0);
	if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (1);
}

void	ft_putresult(int a, int b, char c)
{
	int		(*operations[NB_OPERATEURS])(int, int);
	char	operateurs[NB_OPERATEURS];
	int		i;

	operations[0] = &addition;
	operations[1] = &soustraction;
	operations[2] = &multiplication;
	operations[3] = &division;
	operations[4] = &modulo;
	operateurs[0] = '+';
	operateurs[1] = '-';
	operateurs[2] = '*';
	operateurs[3] = '/';
	operateurs[4] = '%';
	i = -1;
	while (++i < NB_OPERATEURS)
		if (operateurs[i] == c)
			ft_putnbr((operations[i])(a, b));
}

int		main(int argc, char **argv)
{
	if (!ft_testargs(argc, argv))
		return (0);
	ft_putresult(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2][0]);
	ft_putchar('\n');
	return (0);
}
