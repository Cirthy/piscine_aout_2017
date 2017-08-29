/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 10:23:04 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/19 16:18:42 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int is_croissant;
	int is_decroissant;

	is_croissant = 1;
	is_decroissant = 1;
	i = -1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) > 0)
			is_croissant = 0;
	i = -1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) < 0)
			is_decroissant = 0;
	return (is_croissant || is_decroissant);
}
