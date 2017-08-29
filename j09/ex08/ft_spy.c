/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 08:41:01 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/11 14:33:20 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}
	return (str);
}

int		ft_trigger_alert(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	while ((str[i] > 'Z' || str[i] < 'A') && (str[i] > 'z' || str[i] < 'a'))
	{
		if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	j = 0;
	while (to_find[j] && str[i] && str[i] == to_find[j])
	{
		i++;
		j++;
	}
	if (to_find[j] != '\0')
		return (0);
	while (str[i])
	{
		if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_trigger_alert(ft_strlowcase(argv[i]), "president") ||
			ft_trigger_alert(ft_strlowcase(argv[i]), "attack") ||
			ft_trigger_alert(ft_strlowcase(argv[i]), "powers"))
		{
			ft_putstr("Alert!!!\n");
			return (0);
		}
	}
	return (0);
}
