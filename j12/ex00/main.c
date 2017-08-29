/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:36:06 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/23 08:09:47 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	str[BUFFER_SIZE + 1];

	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ret = BUFFER_SIZE;
	while (ret == BUFFER_SIZE)
	{
		ret = read(fd, str, BUFFER_SIZE);
		write(1, str, ret);
	}
	close(fd);
	return (0);
}
