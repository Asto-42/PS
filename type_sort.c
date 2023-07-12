/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:12:26 by jquil             #+#    #+#             */
/*   Updated: 2023/05/15 15:45:21 by jquil            ###   ########.fr       */
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
	if (tmp -> content == min)
	{
		ft_rotate(lst_a, 'a');
		ft_swap(lst_a, 'a');
		ft_reverse_rotate(lst_a, 'a');
	}
	else if (tmp -> next -> content == min)
	{
		if (tmp -> content == max)
		{
			ft_swap(lst_a, 'a');
			ft_reverse_rotate(lst_a, 'a');
		}
		ft_swap(lst_a, 'a');
	}
	else if (tmp -> content != min && tmp -> next -> content != min)
	{
		if (tmp -> content == max)
			ft_swap(lst_a, 'a');
		ft_reverse_rotate(lst_a, 'a');
	}
}

void	ft_sort_small_part_two(t_list **l_a, t_list **l_b, int min, int x)
{
	t_list	*tmp;

	tmp = (*l_a);
	while (tmp -> content != min)
		ft_rotate(l_a, 'a');
	ft_push(l_a, l_b, 'b');
	ft_sort_small(l_a, l_b, (x - 1));
	ft_push(l_b, l_a, 'a');
}

int	*ft_tab(t_list **lst_a, int x)
{
	t_list	*tmp;
	int		*tab;
	int		y;

	y = 0;
	tmp = (*lst_a);
	tab = malloc(x * sizeof(int));
	while (tmp)
	{
		tab[y] = tmp -> content;
		y++;
		tmp = tmp -> next;
	}
	return (tab);
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
	max = tmp -> content;
	min = max;
	tab = ft_tab(lst_a, x);
	while (tab[y])
	{
		if (tab[y] < min)
			min = tab[y];
		if (tab[y] > max)
			max = tab[y];
		y++;
	}
	if (x == 3)
		ft_sort_three(lst_a, min, max);
	if (x > 3)
		ft_sort_small_part_two(lst_a, lst_b, min, x);
}
