/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 09:18:36 by qbreton           #+#    #+#             */
/*   Updated: 2017/08/05 14:14:44 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	display_ver(int x, char to_display)
{
	int count;

	ft_putchar(to_display);
	count = 0;
	while (count < x - 2)
	{
		ft_putchar(' ');
		count++;
	}
	if (x > 1)
		ft_putchar(to_display);
	ft_putchar('\n');
}

void	display_hor(int x, char start, char mid, char end)
{
	int count;

	count = 0;
	ft_putchar(start);
	while (count < x - 2)
	{
		ft_putchar(mid);
		count++;
	}
	if (x > 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int index;

	if ((x > 0) && (y > 0))
	{
		index = 0;
		display_hor(x, '/', '*', 92);
		while (index < y - 2)
		{
			display_ver(x, '*');
			index++;
		}
		if (y > 1)
			display_hor(x, 92, '*', '/');
	}
}
