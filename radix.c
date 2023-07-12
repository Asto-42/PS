/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:06:29 by jquil             #+#    #+#             */
/*   Updated: 2023/05/17 18:49:26 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	ft_setup_radix_var(t_list **lst_a, int len, int max)
{
	int	x;
	struct radix var;

	x = -1;
	var.data = ft_file_tab(lst_a, len);
	while (var.data[++x])
	{
		if (var.data[x] > max)
			max = var.data[x];
	}
	x = 1;
	while (x < max)
		x = x * 10;
	x = x / 10;
	var.max = x;
	x = -1;
	var.pos = malloc(len * sizeof(int));
	while (var.data[++x])
		var.pos[x] = x;
	var.push_order = malloc (len * sizeof(int));
	return (var);
}

void	ft_define_push_order(t_var *var, int len, int rank_target)
{
	int	x;
	int	rank;
	int	tmp;
	int	push_order;

	push_order = 1;
	x = -1;
	rank = 9;
		while (rank >= 0)
		{
			while (++x < len)
			{
				tmp = var->data[x];
				if (tmp < (rank_target / 10))
					tmp = 0;
				while (tmp > rank_target)
					tmp = tmp % 10;
				while (tmp > 10)
					tmp = tmp / 10;
				if (tmp == rank && var->data[x] >= rank_target / 10)
				{
					var->push_order[x] = push_order;
					push_order++;
				}
			}
			x = -1;
			rank--;
		}
}

void	ft_actualize_var(t_var *var, t_list **lst_a, int param)
{
	int	x;

	x = 0;
	if (param == 1)
	{
		var->pos[x] = ft_len_lst(lst_a) - 1;
		while (++x != ft_len_lst(lst_a))
			var->pos[x] = x - 1;
	}
	else if (param == 2)
	{
		while (x < ft_len_lst(lst_a) - 1)
		{
			var->pos[x] = x + 1;
			++x;
		}
		var->pos[x] = 0;
	}
}

void	ft_actualize_var_push(t_var *var, t_list **lst_a, int len)
{
	int	x;
	int	*tab;

	x = -1;
	tab = ft_file_tab(lst_a, len);
	while (++x < len)
	{
		var->data[x] = tab[x];
		var->pos[x] = x;
	}
	var->data[x] = 0;
	var->pos[x] = 0;
}

void	ft_process(t_var *var, size_t magnitude, t_list **lst_a, t_list **lst_b)
{
	int y;

	y = -1;
	while (ft_len_lst(lst_a) > 0)
	{
		ft_define_push_order(var, ft_len_lst(lst_a), magnitude); // defini l'ordre de push en fonctionde l'ordre de grandeur "magnitude"
		while (var->push_order[++y] != 1)
			;
		if (y <= ft_len_lst(lst_a) / 2)
		{
			while (y != 0)
			{
				ft_rotate(lst_a, 'a');
				ft_actualize_var(var, lst_a, 1);
				--y;
			}
		}
		else
		{
			while (y < ft_len_lst(lst_a))
			{
				ft_reverse_rotate(lst_a, 'a');
				ft_actualize_var(var, lst_a, 2);
				++y;
			}
		}
		y = 0;
		ft_push(lst_a, lst_b, 'b');
		ft_actualize_var_push(var, lst_a, ft_len_lst(lst_a));
	}
}

void	ft_define_repush_order(t_var *var, int len, int magnitude)
{
	int	x;
	int	y;
	x = -1;
	y = 0;
	while (++x < len)
	{
		if (var->data[x] >= magnitude)
			var->push_order[x] = ++y;
		else
			var->push_order[x] = -1;
	}
}

void	ft_repush(t_list **lst_a, t_list **lst_b, int magnitude)
{
	struct	radix	var;
	int	x;
	int	achieve;

	achieve = 0;
	x = -1;
	var = ft_setup_radix_var(lst_b, ft_len_lst(lst_b), INT_MIN);
	ft_printf("len = %i\n", ft_len_lst(lst_b));
	while (++x < ft_len_lst(lst_b))
	{
		ft_printf("data =%i\tmagnitude = %i\n", var.data[x], magnitude);
		if (var.data[x] >= magnitude)
			++achieve;
	}
	ft_printf("achieve = %i\n", achieve);
	x = -1;
	while (achieve != 0)
	{
		ft_define_repush_order(&var, ft_len_lst(lst_a), magnitude);
		if (var.push_order[0] == 1)
			ft_push(lst_b, lst_a, 'a');
		ft_actualize_var_push(&var, lst_b, ft_len_lst(lst_b));
	}
}

void	ft_radix(t_list **lst_a, t_list **lst_b, int argc)
{
	struct radix var;
	// t_list	**tmp;
	size_t	magnitude;

	magnitude = 10;
	var = ft_setup_radix_var(lst_a, argc, INT_MIN); // malloc tout, initialise data, pos
	if (!var.data || !var.pos || !var.push_order)
	{
		free(var.data);
		free(var.pos);
		free(var.push_order);
		return ;
	}
	while (magnitude != var.max * 10)
	{
		ft_process(&var, magnitude, lst_a, lst_b);
		ft_printlst(lst_b, "b");
		// tmp = lst_b;
		// lst_b = lst_a;
		// lst_a = tmp;
		ft_repush(lst_a, lst_b, magnitude);
		magnitude = magnitude * 10;
		ft_printlst(lst_a, "A");
	}
}
