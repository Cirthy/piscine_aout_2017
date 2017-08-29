/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdfct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:03:47 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/17 10:32:46 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advanced_do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
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

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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
