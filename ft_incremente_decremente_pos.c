/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_incremente_decremente_pos.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:57:12 by jquil             #+#    #+#             */
/*   Updated: 2023/05/16 17:10:58 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	*ft_incremente_pos(t_var *var, int len)
{
	struct radix *var2;
	int	x;

	var2 = var;
	x = -1;
	while (++x + 1 < len)
	{
		var2->data[x] = var->data[x + 1];
		var2->push_order[x] = var->push_order[x + 1];
	}
	var2->data[0] = var->data[x];
	var2->push_order[0] = var->push_order[x];
	x = -1;
	while (++x < len)
		var2->pos[x] = x;
	x = 0;
	ft_printf("oui");
	while (var2->data[x])
	{
		ft_printf("nb = %i\tpos = %i\tpush_order = %i\n", var2->data[x], var2->pos[x], var2->push_order[x]);
		x++;
	}
	return (var2);
}

t_var	*ft_decremente_pos(t_var *var, int len)
{
	struct radix *var2;
	int	x;

	var2 = var;
	x = 0;
	while (var2->data[x])
	{
		ft_printf("nb = %i\tpos = %i\tpush_order = %i\n", var2->data[x], var2->pos[x], var2->push_order[x]);
		x++;
	}
	x = len;
	while (--x + 1 < len)
	{
		var2->data[x] = var->data[x + 1];
		var2->push_order[x] = var->push_order[x + 1];
	}
	var2->data[0] = var->data[len];
	var2->push_order[0] = var->push_order[len];
	x = -1;
	while (++x < len)
		var2->pos[x] = x;
	x = 0;
	while (var2->data[x])
	{
		ft_printf("nb = %i\tpos = %i\tpush_order = %i\n", var2->data[x], var2->pos[x], var2->push_order[x]);
		x++;
	}
	return (var2);
}
