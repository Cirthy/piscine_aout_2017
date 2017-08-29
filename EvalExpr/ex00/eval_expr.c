/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:37:48 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/20 15:11:57 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		ft_find_indice_fermante(char *str)
{
	int ouvertes;
	int i;

	ouvertes = 1;
	i = 0;
	while (ouvertes)
	{
		if (str[i] == '(')
			ouvertes++;
		if (str[i] == ')')
			ouvertes--;
		i++;
	}
	return (i);
}

void	ft_remove_par(char *str)
{
	int i;
	int indice_ouvrante;
	int indice_fermante;
	int	loop;

	loop = 1;
	while (1)
	{
		i = -1;
		indice_ouvrante = -1;
		while (str[++i] && indice_ouvrante == -1)
			if (str[i] == '(')
				indice_ouvrante = i;
		if (indice_ouvrante == -1)
			return ;
		indice_fermante = i + ft_find_indice_fermante(str + i + 1);
		str[indice_fermante] = '\0';
		ft_formatstr(str + indice_ouvrante + 1);
		str[indice_ouvrante] = ' ';
		str[indice_fermante] = ' ';
	}
}

void	ft_formatstr_addsub(char *str)
{
	int	i;
	int	debut_op;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		debut_op = i;
		i += (str[i] == '+' || str[i] == '-') ? 1 : 0;
		while (str[i] && (str[i] == ' ' || ('0' <= str[i] && str[i] <= '9')))
			i++;
		if (str[i])
		{
			ft_do_op(str + debut_op);
			i = debut_op;
		}
	}
}

void	ft_formatstr(char *str)
{
	int	i;
	int	debut_op;

	ft_remove_par(str);
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		debut_op = i;
		i += ((str[i] == '+' || str[i] == '-') ? 1 : 0);
		while (str[i] && (str[i] == ' ' || ('0' <= str[i] && str[i] <= '9')))
			i++;
		if (str[i] == '*' || str[i] == '/' || str[i] == '%')
		{
			ft_do_op(str + debut_op);
			i = debut_op;
		}
		else if (str[i])
			i++;
	}
	ft_formatstr_addsub(str);
}

int		eval_expr(char *str)
{
	ft_formatstr(str);
	return (ft_atoi(str));
}
