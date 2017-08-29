/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 17:46:05 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/10 09:58:19 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	if (nb < 2 || (nb != 2 && nb % 2 == 0) || (nb != 3 && nb % 3 == 0))
		return (0);
	i = 1;
	while (i < (nb / ((36 * i) - 6) + 2))
	{
		if (nb % ((6 * i) - 1) == 0 || nb % ((6 * i) + 1) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	return (ft_find_next_prime(nb + 1));
}
