/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:36:38 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/17 08:35:12 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int		ft_strlen(char *str)
{
	return (*str ? 1 + ft_strlen(str + 1) : 0);
}

void	ft_putstr(char *str)
{
	while (*(str++))
		ft_putchar(*(str - 1));
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

void	ft_print_words_table(char **tab)
{
	int i;
	int j;

	i = -1;
	while (tab[++i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;

	i = -1;
	while ((par + ++i)->str)
	{
		ft_putstr((par + i)->str);
		ft_putchar('\n');
		ft_putnbr(ft_strlen((par + i)->str));
		ft_putchar('\n');
		ft_print_words_table((par + i)->tab);
	}
}
