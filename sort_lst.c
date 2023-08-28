/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:30:30 by jquil             #+#    #+#             */
/*   Updated: 2023/08/28 14:58:32 by jquil            ###   ########.fr       */
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
		x = tmp->value;
		tmp = tmp->next;
		y = tmp->value;
		if (x > y)
			return (0);
	}
	return (1);
}

int	check_sort(t_list *lst)
{
	t_list	*x;
	t_list	*y;

	x = (lst);
	y = (lst)->next;
	while (lst)
	{
		if (y && (x->value) > (y->value))
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

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

void	sort_lst(int argc, t_list *lst_a, t_list *lst_b)
{
	index_stack(&lst_a);
	argc = argc - 1;
	if (check_sort(lst_a) == 0)
	{
		if (argc == 2)
			ft_sort_two(&lst_a);
		else if (argc == 3)
			ft_sort_small(&lst_a, &lst_b, 3);
		else if (argc == 4)
			ft_sort_small(&lst_a, &lst_b, 4);
		else if (argc == 5)
			ft_sort_small(&lst_a, &lst_b, 5);
		else
		{
			ft_printf("oui\n");
			radix_sort(&lst_a, &lst_b);
		}
	}
	ft_printlst(&lst_a, "A");
	ft_free_lst(lst_a);
}
