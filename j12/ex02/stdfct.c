/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdfct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:13:14 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/23 10:20:09 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		ft_strlen(char *str)
{
	return (*str ? 1 + ft_strlen(str + 1) : 0);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	i = -1;
	cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(src) + 1));
	while (src[++i])
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}

void	ft_putstrerror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_atoi(char *str)
{
	unsigned int	integer;
	int				sgn;

	while (((*str > '9') || (*str < '0')) && (*str != '-') && (*str != '+'))
	{
		if (*str != 32 && (*str < 9 || *str > 13))
			return (0);
		str++;
	}
	sgn = 1;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		sgn = -1;
		str++;
	}
	integer = 0;
	while (*str <= '9' && *str >= '0')
	{
		integer = (integer * 10) + (*str - '0');
		str++;
	}
	return (sgn * integer);
}
