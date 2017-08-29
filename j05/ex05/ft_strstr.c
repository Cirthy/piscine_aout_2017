/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:46:40 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/08 12:54:16 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int is_inside;

	if (to_find[0] == '\0')
		return (str);
	is_inside = 0;
	i = 0;
	while (str[i] != '\0' && !is_inside)
	{
		is_inside = 1;
		j = 0;
		while (to_find[j] != '\0' && str[i + j] != '\0' && is_inside)
		{
			if (to_find[j] != str[i + j])
				is_inside = 0;
			j++;
		}
		if (to_find[j] == '\0' && is_inside)
			return (str + i);
		i++;
	}
	return (NULL);
}
