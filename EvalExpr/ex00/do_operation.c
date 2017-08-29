/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:28:46 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/20 15:12:08 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

long	ft_get_intres(int operande1, int operande2, char operateur)
{
	long	res;

	if (operateur == '+')
		res = operande1 + operande2;
	if (operateur == '-')
		res = operande1 - operande2;
	if (operateur == '*')
		res = operande1 * operande2;
	if (operateur == '/')
		res = operande1 / operande2;
	if (operateur == '%')
		res = operande1 % operande2;
	return (res);
}

int		ft_get_malloc_size(long res)
{
	int len;

	len = 1;
	while (res / 10 > 0)
	{
		len++;
		res /= 10;
	}
	return (len);
}

char	*ft_get_strres(int operande1, int operande2, char operateur)
{
	char	*strres;
	long	res;
	int		len;
	int		neg;
	int		i;

	res = ft_get_intres(operande1, operande2, operateur);
	neg = (res < 0) ? 1 : 0;
	res = (res > 0) ? res : -res;
	len = ft_get_malloc_size(res);
	strres = (char *)malloc(len + neg + 1);
	i = -1;
	while (++i < len)
	{
		strres[i] = (res % 10) + '0';
		res /= 10;
	}
	if (neg)
		strres[i++] = '-';
	strres[i] = '\0';
	strres = ft_strrev(strres);
	return (strres);
}

void	ft_fill_with_space(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		str[i++] = ' ';
	while (str[i] == ' ' || ('0' <= str[i] && str[i] <= '9'))
		str[i++] = ' ';
	str[i++] = ' ';
	while (str[i] == ' ')
		str[i++] = ' ';
	if (str[i] == '-' || str[i] == '+')
		str[i++] = ' ';
	while ('0' <= str[i] && str[i] <= '9')
		str[i++] = ' ';
}

void	ft_do_op(char *str)
{
	int		i;
	int		operande1;
	int		operande2;
	char	operateur;
	char	*res;

	i = 0;
	operande1 = ft_atoi(str);
	i += ((str[i] == '+' || str[i] == '-') ? 1 : 0);
	while (str[i] == ' ' || ('0' <= str[i] && str[i] <= '9'))
		i++;
	operateur = str[i++];
	operande2 = ft_atoi(str + i);
	res = ft_get_strres(operande1, operande2, operateur);
	ft_fill_with_space(str);
	i = -1;
	while (res[++i])
		str[i] = res[i];
}
