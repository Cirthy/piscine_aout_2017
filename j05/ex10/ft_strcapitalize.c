/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:13:55 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/16 09:01:56 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_a_alphanum_char(char c)
{
	int is_a_letter;
	int is_a_number;

	is_a_letter = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	is_a_number = c >= '0' && c <= '9';
	return (is_a_letter || is_a_number);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_a_alphanum_char(str[i]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] += 'A' - 'a';
			i++;
			while (is_a_alphanum_char(str[i]))
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 'a' - 'A';
				i++;
			}
		}
		i++;
	}
	return (str);
}
