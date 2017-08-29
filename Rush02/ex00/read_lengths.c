/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lengths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 19:49:58 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/20 10:02:48 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle02.h"

int		ft_get_first_line_size(char *str)
{
	int size;

	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	return (size);
}

int		ft_not_same_len(char *str, int length)
{
	int i;
	int len_current_line;

	i = 0;
	while (str[i])
	{
		len_current_line = 0;
		while (str[i] && str[i++] != '\n')
			len_current_line++;
		if (len_current_line != length)
			return (1);
	}
	return (0);
}

int		ft_get_nbr_line(char *str)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			count++;
	return (count);
}
