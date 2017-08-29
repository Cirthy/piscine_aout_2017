/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:33:45 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/13 10:07:34 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_totallen(int argc, char **argv)
{
	int total_len;
	int i;
	int j;

	i = 0;
	total_len = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			total_len++;
		total_len++;
	}
	return (total_len);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*concat_str;
	int		total_len;
	int		i;
	int		j;

	total_len = ft_count_totallen(argc, argv);
	i = 0;
	concat_str = (char*)malloc(sizeof(*concat_str) * total_len);
	if (concat_str == NULL)
		return (concat_str);
	total_len = -1;
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
			concat_str[++total_len] = argv[i][j++];
		concat_str[++total_len] = '\n';
	}
	concat_str[total_len] = '\0';
	return (concat_str);
}
