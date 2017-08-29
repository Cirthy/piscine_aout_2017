/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:28:38 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/06 16:43:18 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int ret;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 0;
	ret = nb;
	while (++i < power)
		ret *= nb;
	return (ret);
}
