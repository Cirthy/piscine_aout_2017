/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:20:02 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/11 14:51:14 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H
# define SAVE_THE_WOLRD 5
# include <string.h>

typedef struct		s_perso{
	char			*name;
	float			life;
	int				age;
	int				profession;
}					t_perso;

#endif
