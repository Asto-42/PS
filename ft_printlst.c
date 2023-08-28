/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:53:33 by jquil             #+#    #+#             */
/*   Updated: 2023/08/25 19:35:19 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_list **lst, char *c)
{
	t_list		*tmp;

	if (!lst)
		ft_printf("%s : VIDE\n", c);
	tmp = *(lst);
	while (tmp)
	{
		ft_printf("lst %s: %i\n", c, tmp->value);
		tmp = tmp -> next;
	}
	ft_printf("\n");
}
