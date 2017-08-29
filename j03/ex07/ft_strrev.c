/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 20:58:59 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/08 10:53:50 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_strrev(char *str)
{
	int len;
	int i;

	len = 0;
	while (str[len] != '\0')
		len++;
	i = 0;
	while (++i <= len / 2)
		ft_swap(str + i - 1, str + len - i);
	return (str);
}
