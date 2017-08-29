/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standardftfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 22:19:55 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/13 11:48:13 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*(str++))
		ft_putchar(*(str - 1));
}