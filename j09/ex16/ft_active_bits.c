/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 11:51:27 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/11 12:21:05 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	unsigned int active_bits;

	active_bits = 0;
	if (value < 0)
	{
		return (1 + ft_active_bits(2147483648 + value));
	}
	while (abs_value > 0)
	{
		if (abs_value % 2 == 1)
			active_bits++;
		abs_value /= 2;
	}
	return (active_bits);
}
