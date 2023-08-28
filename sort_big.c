/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:06:29 by jquil             #+#    #+#             */
/*   Updated: 2023/08/25 19:35:35 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_var *var)
{
	int	temp;
	int	i;
	int	*pile_b;

	temp = -1;
	i = -1;
	pile_b = ft_file_tab(var->lst_b, ft_len_lst(var->lst_b));
	if (!pile_b)
		return ;
	while (++i < ft_len_lst(var->lst_b))
	{
		if (pile_b[i] > temp)
			temp = pile_b[i];
	}
	i = 0;
	while (pile_b[i] != temp)
		i++;
	push_back_two(var, pile_b, temp, i);
}

void	push_top_b(t_var *var, int r_min, int r_max, int moves)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = (*var->lst_a);
	lst_b = (*var->lst_b);
	if (moves > 1)
	{
		while (lst_a->value > lst_b->value
			&& !bigger_all(lst_a->value, var->lst_b, ft_len_lst(var->lst_b))
			&& !lower_all(lst_a->value, var->lst_b, ft_len_lst(var->lst_b)))
			ft_rotate(var->lst_b, 'b');
	}
	ft_push(var->lst_a, var->lst_b, 'b');
	if (lst_b && lst_b->value >= (r_max - ((r_max - r_min) / 2)) && ft_len_lst(var->lst_a) + ft_len_lst(var->lst_b) > 101)
	{
		if (lst_a->value > r_max || lst_a->value < r_min)
			ft_reverse_rotate_a_b(var->lst_a, var->lst_b);
		else
			ft_reverse_rotate(var->lst_b, 'b');
	}
}

void	move_opt(t_var *var, int r_moves, int rr_moves)
{
	int		first_data_b;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = (*var->lst_a);
	lst_b = (*var->lst_b);
	if (ft_len_lst(var->lst_b) > 0)
		first_data_b = lst_b->value;
	if (r_moves <= rr_moves)
	{
		while (--r_moves > 0)
		{
			if (ft_len_lst(var->lst_b) > 0
				&& r_moves == 1 && lst_a->next->value > first_data_b)
				ft_rotate_a_b(var->lst_a, var->lst_b);
			else
				ft_rotate(var->lst_a, 'a');
		}
	}
	else
		while (--rr_moves > 0)
			ft_reverse_rotate(var->lst_a, 'a');
}

void	ft_find_top(t_var *var, int r_min, int r_max)
{
	int	i;
	int	r_moves;
	int	rr_moves;
	int	size;
	int	*pile_a;

	i = -1;
	r_moves = 1;
	rr_moves = 1;
	pile_a = ft_file_tab(var->lst_a, ft_len_lst(var->lst_a));
	if (!pile_a)
		return ;
	size = ft_len_lst(var->lst_a);
	//ft_printf("r_min = %i\tr_max =%i\n", r_min, r_max);
	while (++i <= size / 2)
		if (pile_a[i] >= r_min && pile_a[i] <= r_max)
			break ;
	while (--i >= 0)
		r_moves++;
	while (--size > ft_len_lst(var->lst_a) / 2)
		if (pile_a[size] >= r_min && pile_a[size] <= r_max)
			break ;
	while (++size <= ft_len_lst(var->lst_a))
		rr_moves++;
	free(pile_a);
	//ft_printf("r_moves = %i\trr_moves =%i\n", r_moves, rr_moves);
	move_opt(var, r_moves, rr_moves);
}

void	ft_sort_big(t_var *var, int len)
{
	int	chunk;
	int	moves;
	int	size;
	int	r_min;
	int	r_max;

	moves = 0;
	chunk = 0;
	size = ft_len_lst(var->lst_a);
	while (ft_len_lst(var->lst_a) > 0)
	{
		r_min = size / len * chunk;
		r_max = size / len * (chunk + 1) - 1;
		ft_find_top(var, r_min, r_max);
		push_top_b(var, r_min, r_max, moves);
		moves++;
		if (moves == size / len)
		{
			chunk++;
			moves = 0;
		}
	}
	while (ft_len_lst(var->lst_b) > 0)
		push_back(var);
}
