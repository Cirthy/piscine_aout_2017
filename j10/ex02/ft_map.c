/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 17:35:24 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/15 17:39:31 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int	*tabf;
	int	i;

	tabf = (int*)malloc(sizeof(*tabf) * length);
	if (tabf == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		tabf[i] = f(tab[i]);
	return (tabf);
}
