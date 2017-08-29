/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdfct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:03:47 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/16 12:48:10 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

int		ft_strlen(char *str)
{
	return (*str ? 1 + ft_strlen(str + 1) : 0);
}

void	ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	else
		n = nb;
	while (n / 10 > 0)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
}

int		ft_atoi(char *str)
{
	unsigned int	integer;
	int				sgn;

	while (((*str > '9') || (*str < '0')) && (*str != '-') && (*str != '+'))
	{
		if (*str != 32 && (*str < 9 || *str > 13))
			return (0);
		str++;
	}
	sgn = 1;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		sgn = -1;
		str++;
	}
	integer = 0;
	while (*str <= '9' && *str >= '0')
	{
		integer = (integer * 10) + (*str - '0');
		str++;
	}
	return (sgn * integer);
}
