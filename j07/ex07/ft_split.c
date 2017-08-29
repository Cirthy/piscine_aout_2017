/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 21:29:46 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/15 10:39:06 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_in_str(char c, char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

int		ft_wordcount(char *str, char *charset)
{
	int i;
	int wordcount;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_in_str(str[i], charset))
			i++;
		wordcount++;
		while (str[i] && !ft_is_in_str(str[i], charset))
			i++;
	}
	i--;
	if (ft_is_in_str(str[i], charset))
		wordcount--;
	return (wordcount);
}

int		ft_wordlen(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] && !ft_is_in_str(str[i], charset))
		i++;
	return (i);
}

char	*ft_fill_string(char *split_i, char *str, int *i, char *charset)
{
	int k;
	int len;

	k = -1;
	len = ft_wordlen(str + *i, charset);
	split_i = (char*)malloc(len);
	if (split_i == NULL)
		return (NULL);
	while (++k < len && str[k])
		split_i[k] = str[(*i)++];
	split_i[k] = '\0';
	return (split_i);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_wordcount(str, charset) + 1;
	split = (char**)malloc(sizeof(*split) * len);
	if (split == NULL)
		return (NULL);
	while (str[i])
	{
		while (ft_is_in_str(str[i], charset))
			i++;
		if (str[i])
		{
			split[j] = ft_fill_string(split[j], str, &i, charset);
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}
