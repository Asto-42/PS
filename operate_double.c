/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:48:03 by jquil             #+#    #+#             */
/*   Updated: 2023/02/14 16:43:43 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a_b(t_list **lst_a, t_list **lst_b)
{
	char	c;

	c = 'c';
	ft_swap(lst_a, c);
	ft_swap(lst_b, c);
	ft_printf("ss\n");
}

void	ft_rotate_a_b(t_list **lst_a, t_list **lst_b)
{
	char	c;

	c = 'c';
	ft_rotate(lst_a, c);
	ft_rotate(lst_b, c);
	ft_printf("rab\n");
}

void	ft_reverse_rotate_a_b(t_list **lst_a, t_list **lst_b)
{
	char	c;

	c = 'c';
	ft_reverse_rotate(lst_a, c);
	ft_reverse_rotate(lst_b, c);
	ft_printf("rrab\n");
}
