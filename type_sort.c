/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:12:26 by jquil             #+#    #+#             */
/*   Updated: 2023/08/30 17:21:06 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list **lst_a)
{
	ft_swap(lst_a, 'a');
}

void	ft_sort_three(t_list **lst_a, int min, int max)
{
	t_list	*tmp;

	tmp = (*lst_a);
	if (tmp->value == min)
	{
		ft_rotate(lst_a, 'a');
		ft_swap(lst_a, 'a');
		ft_reverse_rotate(lst_a, 'a');
	}
	else if (tmp -> next -> value == min)
	{
		if (tmp->value == max)
		{
			ft_swap(lst_a, 'a');
			ft_reverse_rotate(lst_a, 'a');
		}
		ft_swap(lst_a, 'a');
	}
	else if (tmp->value != min && tmp -> next -> value != min)
	{
		if (tmp->value == max)
			ft_swap(lst_a, 'a');
		ft_reverse_rotate(lst_a, 'a');
	}
}

void	ft_sort_small_part_two(t_list **l_a, t_list **l_b, int min, int x)
{
	t_list	*tmp;
	int		*tab;
	int		y;

	tmp = (*l_a);
	tab = ft_file_tab(l_a, x);
	y = -1;
	while (++y < ft_len_lst(l_a))
		if (tab[y] == min)
			break ;
	if (y > ft_len_lst(l_a) / 2)
	{
		while ((++y - 1) < ft_len_lst(l_a))
			ft_reverse_rotate(l_a, 'a');
	}
	else
	{
		while (tmp->value != min)
			ft_rotate(l_a, 'a');
	}
	free(tab);
	ft_push(l_a, l_b, 'b');
	ft_sort_small(l_a, l_b, (x - 1));
	ft_push(l_b, l_a, 'a');
}

void	ft_sort_small(t_list **lst_a, t_list **lst_b, int x)
{
	t_list	*tmp;
	int		*tab;
	int		y;
	int		min;
	int		max;

	y = 0;
	tmp = (*lst_a);
	max = tmp->value;
	min = max;
	tab = ft_file_tab(lst_a, x);
	while (y < x)
	{
		if (tab[y] < min)
			min = tab[y];
		if (tab[y] > max)
			max = tab[y];
		y++;
	}
	free(tab);
	if ((x == 3) && (check_sort(*lst_a) != 1))
		ft_sort_three(lst_a, min, max);
	if ((x > 3) && (check_sort(*lst_a)) != 1)
		ft_sort_small_part_two(lst_a, lst_b, min, x);
}
