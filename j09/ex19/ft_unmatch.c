/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 11:44:39 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/11 11:50:22 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unmatch(int *tab, int length)
{
	int i;

	i = -1;
	while (++i < length)
	{
		count = 0;
		j = -1;
		while (++j < length)
		{
			if (tab[j] == tab[i])
				count++;
		}
		if (count == 1)
			return (tab[i]);
	}
	return (0);
}
