/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:18:58 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/20 16:18:25 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE02_H
# define COLLE02_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# define NB_COLLE 5
# define NO_MATCH_MESSAGE "aucune"
# define BUFFER_SIZE 16384

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_get_first_line_size(char *str);
int		ft_get_nbr_line(char *str);
int		ft_not_same_len(char *str, int length);
void	ft_test_corners(char *str, int line_len, int line_nbr);
void	ft_test_line(char *str, int line_len, int line_nbr);

int		g_is_colle[NB_COLLE];

#endif
