/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:18:34 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/17 11:19:04 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
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
