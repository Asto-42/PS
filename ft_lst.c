/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:54:29 by jquil             #+#    #+#             */
/*   Updated: 2023/08/29 14:56:12 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_init_node(int x)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->value = x;
	lst->index = -1;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

int	ft_len_lst(t_list **lst)
{
	t_list	*tmp;
	int		x;

	x = 0;
	tmp = (*lst);
	while (tmp)
	{
		if (tmp -> next)
			tmp = tmp -> next;
		else
			return (x + 1);
		x++;
	}
	return (0);
}

void	ft_free_lst(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(lst);
}
