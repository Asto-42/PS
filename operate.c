/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:28:13 by jquil             #+#    #+#             */
/*   Updated: 2023/02/14 15:18:34 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst, char c)
{
	t_list		*tmp;
	t_list		*x;

	if (!(*lst))
		return ;
	tmp = (*lst)->next;
	x = (*lst);
	x->next = tmp->next;
	*lst = tmp;
	tmp -> next = x;
	if (c != 'c')
		ft_printf("s%c\n", c);
}

void	ft_push(t_list **lst_a, t_list **lst_b, char c)
{
	t_list	*tmp;

	if (!(*lst_a))
		return ;
	tmp = (*lst_a)->next;
	(*lst_a)->next = *lst_b;
	*lst_b = *lst_a;
	*lst_a = tmp;
	ft_printf("p%c\n", c);
}

void	ft_rotate(t_list **lst, char c)
{
	int		x;
	t_list	*tmp;

	tmp = (*lst);
	x = (*lst)->content;
	while ((*lst)->next)
	{
		(*lst)->content = (*lst)->next->content;
		(*lst) = (*lst)->next;
	}
	(*lst)->content = x;
	(*lst) = tmp;
	if (c != 'c')
		ft_printf("r%c\n", c);
}

void	ft_reverse_rotate(t_list **lst, char c)
{
	t_list	*last;
	t_list	*previous;

	if (!(*lst) || !(*lst)->next)
		return ;
	last = (*lst);
	previous = NULL;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *lst;
	*lst = last;
	if (c != 'c')
		ft_printf("rr%c\n", c);
}
