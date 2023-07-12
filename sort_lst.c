/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:30:30 by jquil             #+#    #+#             */
/*   Updated: 2023/05/15 16:11:45 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_sort2(t_list **lst)
{
	t_list	*tmp;
	int		x;
	int		y;

	tmp = (*lst);
	while (tmp -> next)
	{
		x = tmp -> content;
		tmp = tmp -> next;
		y = tmp -> content;
		if (x > y)
		{
			return (0);
		}
	}
	return (1);
}

int	check_sort(t_list *lst)
{
	t_list	*x;
	t_list	*y;

	x = (lst);
	y = (lst)-> next;
	while (lst)
	{
		if (y && (x -> content) > (y -> content))
			return (0);
		else
		{
			x = y;
			lst = lst -> next;
			y = lst;
		}
	}
	return (1);
}

void	sort_lst(int argc, t_list *lst_a)
{
	t_list	**lst_b;

	lst_b = malloc (sizeof (t_list *));
	*lst_b = NULL;
	argc = argc - 1;
	if (check_sort(lst_a) == 0 || argc)
	{
		if (argc == 2)
			ft_sort_two(&lst_a);
		else if (argc == 3)
			ft_sort_small(&lst_a, lst_b, 3);
		else if (argc == 4)
			ft_sort_small(&lst_a, lst_b, 4);
		else if (argc == 5)
			ft_sort_small(&lst_a, lst_b, 5);
		else
		{
			ft_radix(&lst_a, lst_b, argc);
		}
	}
	//ft_printlst(&lst_a, "A");
	ft_free_lst(lst_a);
}
