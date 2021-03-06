/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 08:35:51 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/13 08:58:14 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		nmatch(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i] && s2[i] != '*')
			return (0);
		if (s2[i] == '*')
			return (nmatch(s1 + i, s2 + i + 1) + nmatch(s1 + i + 1, s2 + i));
		i++;
	}
	if (s2[i] == '*')
		return (nmatch(s1 + i, s2 + i + 1));
	if ((!s1[i] && !s2[i]))
		return (1);
	return (0);
}
