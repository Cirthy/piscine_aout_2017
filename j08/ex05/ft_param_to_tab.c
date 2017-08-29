/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 12:38:28 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/15 14:22:10 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	return (*str ? 1 + ft_strlen(str + 1) : 0);
}

char				*ft_strdup(char *str, char *cpy)
{
	int i;

	cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(str) + 1));
	i = -1;
	while (str[++i])
		cpy[i] = str[i];
	cpy[i] = '\0';
	return (cpy);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par	*param_to_tab;
	int					i;

	param_to_tab =
		(struct s_stock_par*)malloc(sizeof(*param_to_tab) * (ac + 1));
	i = -1;
	while (++i < ac)
	{
		(param_to_tab + i)->size_param = ft_strlen(av[i]);
		(param_to_tab + i)->str = av[i];
		(param_to_tab + i)->copy = ft_strdup(av[i], (param_to_tab + i)->copy);
		(param_to_tab + i)->tab = ft_split_whitespaces(av[i]);
	}
	(param_to_tab + i)->str = NULL;
	return (param_to_tab);
}
