/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 08:21:32 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/05 15:51:33 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr_comb2(int a)
{
	while (a / 10 > 0)
	{
		ft_putnbr_comb2(a / 10);
		a %= 10;
	}
	ft_putchar(a + '0');
}

void	ft_display_comb2(int a, int b)
{
	if (a < 10)
		ft_putchar('0');
	ft_putnbr_comb2(a);
	ft_putchar(' ');
	if (b < 10)
		ft_putchar('0');
	ft_putnbr_comb2(b);
	if (a != 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_display_comb2(a, b);
			b++;
		}
		a++;
	}
}
