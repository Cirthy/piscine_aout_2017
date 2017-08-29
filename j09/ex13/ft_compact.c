/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:14:16 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/11 09:23:29 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int		ft_compact(char **tab, int length)
{
	int i;
	int j;
	int reduc;

	reduc = 0;
	i = -1;
	while (++i < length)
	{
		if (!tab[i])
		{
			j = i;
			while (j++ < length)
				ft_swap(tab[j - 1], tab[j]);
			reduc++;
		}
	}
	return (len - reduc);
}
