/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 08:18:49 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/23 11:00:16 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_no_argument(void)
{
	char	str[BUFFER_SIZE];
	int		ret;

	while (1)
	{
		ret = BUFFER_SIZE;
		while (ret == BUFFER_SIZE)
		{
			ret = read(0, str, BUFFER_SIZE);
			write(1, str, ret);
		}
	}
}

void	ft_read_and_close_file(int fd)
{
	int		ret;
	char	str[BUFFER_SIZE];

	ret = BUFFER_SIZE;
	while (ret == BUFFER_SIZE)
	{
		ret = read(fd, str, BUFFER_SIZE);
		write(1, str, ret);
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc == 1)
	{
		ft_no_argument();
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			if (errno == 2)
			{
				ft_putstr("cat: ");
				ft_putstr(argv[i]);
				ft_putstr(": No such file or directory\n");
			}
		}
		else
			ft_read_and_close_file(fd);
	}
	return (0);
}
