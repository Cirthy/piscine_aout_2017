/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:49:21 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/10 18:47:26 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
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

void	ft_puthour(int hour)
{
	if (hour == 0)
		ft_putstr("12.00 A.M.");
	if (hour == 12)
		ft_putstr("12.00 P.M.");
	if (hour < 12 && hour != 0)
	{
		ft_putnbr(hour);
		ft_putstr(" A.M.");
	}
	if (hour > 12)
	{
		ft_putnbr(hour - 12);
		ft_putstr(" P.M.");
	}
}

void	ft_takes_place(int hour)
{
	if (hour / 100 > 0)
		hour /= 100;
	if (hour < 0 || hour > 23)
		return ;
	ft_putstr("THE FOLLOWING TAKES PLACE BETWEEN ");
	ft_puthour(hour);
	ft_putstr(" AND ");
	ft_puthour(hour + 1);
	ft_putchar('\n');
}
