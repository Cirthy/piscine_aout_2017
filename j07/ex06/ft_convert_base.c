/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:12:47 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/18 12:28:58 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_test_str(char *str, char *base)
{
	int i;
	int j;
	int is_valid;

	if (!str[0])
		return (0);
	i = -1;
	while (str[++i])
	{
		is_valid = 0;
		j = -1;
		while (base[++j])
			if (base[j] == str[i])
				is_valid = 1;
		if (!is_valid)
			return (0);
	}
	return (1);
}

int		ft_test_base(char *base)
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
	return (base_len);
}

int		ft_convert_to_10(char *nbr, char *base)
{
	int nbr_10;
	int base_len;
	int indice;
	int i;
	int j;

	nbr_10 = 0;
	base_len = ft_test_base(base);
	i = -1;
	while (nbr[++i])
	{
		j = -1;
		while (base[++j])
			if (nbr[i] == base[j])
				indice = j;
		nbr_10 = nbr_10 * base_len + indice;
	}
	return (nbr_10);
}

char	*ft_convert_from_10(int nbr, char *base, char *nbr_final)
{
	int		len_base;
	int		i;
	char	tmp;
	int		len_str;

	i = 0;
	len_base = ft_test_base(base);
	nbr_final[0] = base[0];
	if (nbr == 0)
		return (nbr_final);
	while (nbr)
	{
		nbr_final[i++] = base[nbr % len_base];
		nbr /= len_base;
	}
	len_str = i;
	i = -1;
	while (++i < len_str / 2)
	{
		tmp = nbr_final[i];
		nbr_final[i] = nbr_final[len_str - i - 1];
		nbr_final[len_str - i - 1] = tmp;
	}
	return (nbr_final);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*nbr_final;
	unsigned int	nbr_10;
	int				neg;
	int				base_to_l;
	int				malloc_len;

	neg = (nbr[0] == '-') ? 1 : 0;
	base_to_l = ft_test_base(base_to);
	if (nbr[0] == '-' || nbr[0] == '+')
		nbr++;
	if (!ft_test_base(base_from) || !base_to_l || !ft_test_str(nbr, base_from))
		return (NULL);
	nbr_10 = ft_convert_to_10(nbr, base_from);
	malloc_len = 0;
	while (nbr_10 / base_to_l != 0)
	{
		malloc_len++;
		nbr_10 /= base_to_l;
	}
	nbr_10 = ft_convert_to_10(nbr, base_from);
	nbr_final = (char*)malloc(sizeof(*nbr_final) * (malloc_len + neg));
	if (nbr_final == NULL)
		return (NULL);
	nbr_final = ft_convert_from_10(nbr_10, base_to, nbr_final);
	return (nbr_final);
}
