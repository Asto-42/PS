/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:53:37 by jquil             #+#    #+#             */
/*   Updated: 2023/08/30 17:22:23 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char **argv)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (argv[++x])
	{
		if (((argv[x][i] == 43) || argv[x][i] == 45) && argv[x][i + 1] != '\0')
			i++;
		while (argv[x][i] && ft_isdigit(argv[x][i]))
			i++;
		if (argv[x][i] != '\0' && !ft_isdigit(argv[x][i]))
			return (0);
		i = 0;
	}
	return (1);
}

int	ft_parse_arg2(int *tab, int argc)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (++x < argc - 1)
	{
		while (++y < argc - 1)
		{
			if (y == x)
				++y;
			if (y < argc - 1 && tab[x] == tab[y])
				return (0);
		}
		y = -1;
	}
	return (1);
}

int	ft_parse_arg(char **argv, int argc)
{
	int	*tab;
	int	x;
	int	y;

	x = 0;
	while (++x < argc)
		if ((((ft_atoi(argv[x]) > INT_MAX) || ft_atoi(argv[x]) < INT_MIN)
				|| (ft_strlen(argv[x]) > 11)))
			return (0);
	x = 0;
	while (++x < argc)
	{
		y = -1;
		while (++y < (int)ft_strlen(argv[x]))
			if (ft_isdigit(argv[x][y] == 0))
				return (0);
	}
	tab = malloc ((argc - 1) * sizeof(int));
	x = 0;
	while (++x < argc)
		tab[x - 1] = ft_atoi(argv[x]);
	if (ft_parse_arg2(tab, argc) == 0)
		return (free(tab), 0);
	return (free(tab), 1);
}
