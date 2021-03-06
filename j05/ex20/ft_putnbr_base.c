/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:19:07 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/18 09:31:51 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_init_base(char *base, int nbr, unsigned int *abs_nbr)
{
	int		base_len;
	int		i;

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
	if (nbr > 0)
		*abs_nbr = nbr;
	else
	{
		*abs_nbr = -nbr;
		ft_putchar('-');
	}
	return (base_len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;
	int				i;
	unsigned int	abs_nbr;

	base_len = 0;
	i = 1;
	base_len = ft_init_base(base, nbr, &abs_nbr);
	if (base_len < 2)
		return ;
	if (abs_nbr / base_len)
		ft_putnbr_base(abs_nbr / base_len, base);
	ft_putchar(base[abs_nbr % base_len]);
}
