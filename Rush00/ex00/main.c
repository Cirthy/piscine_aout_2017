/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 08:49:42 by qbreton           #+#    #+#             */
/*   Updated: 2017/08/22 15:16:57 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
void	display_hor(int x, char start, char mid, char end);
void	display_ver(int x, char to_display);

#include <libc.h>

int		main(int argc, char **argv)
{
	rush(atoi(argv[1]), atoi(argv[2]));
	return (0);
}
