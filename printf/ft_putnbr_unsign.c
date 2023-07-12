/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:50:01 by jquil             #+#    #+#             */
/*   Updated: 2022/12/07 11:59:52 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reverse(char *r)
{
	int	x;
	int	y;
	int	tmp;

	x = (ft_strlen(r)) - 1;
	y = 0;
	while (r && x > y)
	{
		tmp = r[y];
		r[y] = r[x];
		r[x] = tmp;
		x--;
		y++;
	}
	return (r);
}

int	ft_putnbr_unsign(uintptr_t nbr, char *base)
{
	long unsigned int	bl;
	unsigned long int	i;
	int					x;
	char				*r;

	r = malloc((18) * sizeof(char));
	x = 0;
	i = nbr;
	bl = 16;
	while (nbr >= 1)
	{
		i = nbr % 16;
		r[x] = base[i];
		x++;
		nbr = nbr / 16;
	}
	r[x] = '\0';
	ft_putstr("0x");
	r = ft_reverse(r);
	ft_putstr(r);
	bl = ft_strlen(r);
	free(r);
	return (bl + 2);
}
/*
int	ft_putnbr_unsign(uintptr_t nbr, char *base)
{
	long unsigned int		bl;
	unsigned long long int		i;
	long long unsigned int		p;
	int						x;
	char					*r;

	r = malloc((18) * sizeof(char));
	x = 0;
	i = nbr;
	bl = 16;
	p = 1;
	while (p <= nbr)
		p = p * 16;
	while (p >= 1)
	{
		i = nbr / p;
		r[x] = base[i];
		x++;
		nbr = nbr % p;
		p = p / bl;
	}
	r[x] = '\0';
	r = ft_format(r);
	ft_putstr(r);
	bl = ft_strlen(r);
	free(r);
	return (bl);
}

char	*ft_format(char *r)
{
	int	x;
	int	y;

	y = 0;
	x = 2;
	while (r[y] == '0')
		y++;
	while (r[x])
	{
		r[x] = r[y];
		x++;
		y++;
	}
	r[1] = 'x';
	return (r);
}
*/
