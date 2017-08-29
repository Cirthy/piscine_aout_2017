/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clhoffma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 20:31:40 by clhoffma          #+#    #+#             */
/*   Updated: 2017/08/10 10:14:50 by clhoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

void	ft_init_argv_sorter(int *argv_sorter, char **argv, int argc)
{
	int i;
	int j;
	int count;

	i = 0;
	while (++i < argc)
	{
		count = 0;
		j = 0;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) < 0)
				count++;
		}
		argv_sorter[i - 1] = count;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int count;
	int argv_sorter[argc - 1];

	ft_init_argv_sorter(argv_sorter, argv, argc);
	i = -1;
	while (++i < argc - 1)
	{
		count = 0;
		j = -1;
		while (++j < argc - 1)
		{
			if (argv_sorter[j] >= argv_sorter[count])
				count = j;
		}
		argv_sorter[count] = -1;
		ft_putstr(argv[count + 1]);
	}
	return (0);
}
