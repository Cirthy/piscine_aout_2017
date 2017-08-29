/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 10:09:49 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/15 10:40:37 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_wordcount(char *str)
{
	int i;
	int wordcount;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == 9 || str[i] == 11 || str[i] == '\n')
			i++;
		wordcount++;
		while (str[i] &&
				str[i] != ' ' && str[i] != 9 && str[i] != 11 && str[i] != '\n')
			i++;
	}
	i--;
	if (str[i] == ' ' || str[i] == 9 || str[i] == 11 || str[i] == '\n')
		wordcount--;
	return (wordcount);
}

int		ft_wordlen(char *str)
{
	int i;

	i = 0;
	while (str[i] &&
			str[i] != ' ' && str[i] != 9 && str[i] != 11 && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_fill_string(char *split_whitespaces_i, char *str, int *i)
{
	int k;
	int len;

	k = -1;
	len = ft_wordlen(str + *i);
	split_whitespaces_i = (char*)malloc(len);
	if (split_whitespaces_i == NULL)
		return (NULL);
	while (++k < len && str[k])
		split_whitespaces_i[k] = str[(*i)++];
	split_whitespaces_i[k] = '\0';
	return (split_whitespaces_i);
}

char	**ft_split_whitespaces(char *str)
{
	char	**split_whitespaces;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_wordcount(str) + 1;
	split_whitespaces = (char**)malloc(sizeof(*split_whitespaces) * len);
	if (split_whitespaces == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == 9 || str[i] == 11 || str[i] == '\n')
			i++;
		if (str[i])
		{
			split_whitespaces[j] =
				ft_fill_string(split_whitespaces[j], str, &i);
			j++;
		}
	}
	split_whitespaces[j] = NULL;
	return (split_whitespaces);
}
