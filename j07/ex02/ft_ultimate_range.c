/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 11:13:03 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/13 09:45:49 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(**range) * (max - min));
	if (*range == NULL)
		return (0);
	i = -1;
	while (++i < max - min)
		(*range)[i] = i + min;
	return (max - min);
}
