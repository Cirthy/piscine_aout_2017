/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 16:33:04 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/13 16:36:57 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int nmatch(char *s1, char *s2);

int main(int argc, char **argv)
{
	printf("%d", nmatch(argv[1], argv[2]));
	return 0;
}
