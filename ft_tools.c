/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:26:59 by jquil             #+#    #+#             */
/*   Updated: 2023/08/29 13:24:22 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_file_tab(t_list **lst, int len)
{
	int		*tab;
	int		x;
	t_list	*tmp;

	tab = malloc((len) * sizeof(int));
	x = 0;
	tmp = (*lst);
	while (tmp)
	{
		tab[x] = tmp->value;
		x++;
		if (tmp->next)
			tmp = tmp -> next;
		else
			break ;
	}
	return (tab);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (lst == NULL || *lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(tmp);
		tmp->next = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != 0)
	{
		lst = lst -> next;
	}
	return (lst);
}
