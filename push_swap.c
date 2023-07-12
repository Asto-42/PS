/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:09:19 by jquil             #+#    #+#             */
/*   Updated: 2023/02/14 14:51:56 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*ft_init_node(int x)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	lst -> content = x;
	lst -> next = NULL;
	return (lst);
}

t_list	*ft_setuplst(int argc, char **argv)
{
	t_list	*lst;
	int		*tab;
	t_list	*tmp;
	int		x;

	x = 0;
	tab = malloc ((argc - 1) * sizeof(int));
	while (x < argc - 1)
	{
		tab[x] = ft_atoi(argv[x + 1]);
		x++;
	}
	x = 1;
	lst = ft_init_node(tab[0]);
	while (x < argc - 1)
	{
		tmp = ft_init_node(tab[x]);
		ft_lstadd_back(&lst, tmp);
		x++;
	}
	free(tab);
	return (lst);
}

void	ft_free_lst(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*temp;

	lst_a = ft_setuplst(argc, argv);
	temp = lst_a;
	sort_lst(argc, lst_a);
	return (0);
}
