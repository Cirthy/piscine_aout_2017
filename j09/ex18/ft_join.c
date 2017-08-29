/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:41:13 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/11 13:16:57 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_count_total_len(char **tab, char *sep)
{
	int total_len;
	int i;
	int j;
	int sep_len;

	sep_len = ft_strlen(sep);
	total_len = 0;
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			total_len++;
		total_len += sep_len;
	}
	return (total_len);
}

char	*ft_join(char **tab, char *sep)
{
	int		i;
	int		j;
	int		count;
	int		total_len;
	char	*join;

	total_len = ft_count_total_len(tab, sep);
	join = (char*)malloc(sizeof(*join) * total_len);
	i = -1;
	count = 0;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			join[count++] = tab[i][j];
		j = -1;
		while (sep[++j])
			join[count++] = sep[j];
	}
	return (join);
}
