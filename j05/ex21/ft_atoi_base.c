/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 10:57:04 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/18 11:09:21 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_test_param(char *str, char *base)
{
	int	base_len;
	int	i;

	base_len = -1;
	while (base[++base_len])
	{
		i = -1;
		if (base[base_len] == '+' || base[base_len] == '-')
			return (0);
		while (++i < base_len)
			if (base[i] == base[base_len])
				return (0);
	}
	if (base_len < 2)
		return (0);
	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (is_in_base(base, str[i]) == -1)
			return (0);
	if (!str[0])
		return (0);
	return (base_len);
}

int	ft_atoi_clean_str(char *str, char *base)
{
	int res;
	int base_len;
	int i;

	base_len = 0;
	res = 0;
	i = -1;
	while (base[base_len])
		base_len++;
	while (str[++i])
		res = res * base_len + is_in_base(base, str[i]);
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	integer;
	int				sgn;

	if (!ft_test_param(str, base))
		return (0);
	sgn = 1;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		sgn = -1;
		str++;
	}
	integer = ft_atoi_clean_str(str, base);
	return (sgn * integer);
}
