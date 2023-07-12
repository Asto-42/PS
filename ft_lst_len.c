/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:11:20 by jquil             #+#    #+#             */
/*   Updated: 2023/02/09 12:11:36 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
