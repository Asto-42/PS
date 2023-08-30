/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:48:03 by jquil             #+#    #+#             */
/*   Updated: 2023/08/29 11:29:44 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a_b(t_list **lst_a, t_list **lst_b)
{
	char	c;

	if (ft_len_lst(lst_a) < 2 || ft_len_lst(lst_b) < 2)
	{
		ft_printf("error\n");
		return ;
	}
	c = 'c';
	ft_swap(lst_a, c);
	ft_swap(lst_b, c);
	ft_printf("ss\n");
}

void	ft_rotate_a_b(t_list **lst_a, t_list **lst_b)
{
	char	c;

	if (ft_len_lst(lst_a) < 2 || ft_len_lst(lst_b) < 2)
	{
		ft_printf("error\n");
		return ;
	}
	c = 'c';
	ft_rotate(lst_a, c);
	ft_rotate(lst_b, c);
	ft_printf("rr\n");
}

void	ft_reverse_rotate_a_b(t_list **lst_a, t_list **lst_b)
{
	char	c;

	if (ft_len_lst(lst_a) < 2 || ft_len_lst(lst_b) < 2)
	{
		ft_printf("error\n");
		return ;
	}
	c = 'c';
	ft_reverse_rotate(lst_a, c);
	ft_reverse_rotate(lst_b, c);
	ft_printf("rrr\n");
}
