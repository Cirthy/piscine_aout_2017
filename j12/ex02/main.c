/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 09:12:40 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/23 13:40:16 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		ft_no_argument(void)
{
	while (1)
		read(0, NULL, 1);
	return (0);
}

int		ft_valid_c_argument(char *str)
{
	while (!('0' <= *str && *str <= '9') && *str != '+' && *str != '-')
	{
		if ((*str < 9 || *str > 13) && *(str) != ' ')
			return (0);
		str++;
	}
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	ft_read_and_close_file(int fd, int c_arg, int argc, char *fn)
{
	int		ret;
	char	*str;

	str = (char *)malloc(sizeof(*str) * (c_arg + 1));
	str[c_arg] = '\0';
	ret = c_arg;
	while (ret == c_arg)
		ret = read(fd, str, c_arg);
	if (argc > 4)
	{
		ft_putstr("==> ");
		ft_putstr(fn);
		ft_putstr(" <==\n");
	}
	ft_putstr(str + ret);
	str[ret] = '\0';
	ft_putstr(str);
	if (argc > 4)
		write(1, "\n", 1);
}

int		ft_display_message(char *s1, char *s2, char *s3)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
	return (0);
}

int		main(int argc, char **argv)
{
	int		c_argument;
	int		fd;
	int		i;

	if (argc == 1)
		return (ft_no_argument());
	if (!ft_valid_c_argument(argv[2]))
	{
		return (ft_display_message(
					"tail: illegal offset -- ", argv[2], "\n"));
	}
	c_argument = ft_atoi(argv[2]);
	i = 2;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			if (errno == 2)
				return (ft_display_message(
						"tail: ", argv[i], ": No such file or directory\n"));
		}
		ft_read_and_close_file(fd, c_argument, argc, argv[i]);
	}
	return (0);
}
