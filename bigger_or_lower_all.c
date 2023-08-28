/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_or_lower_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:10:29 by jquil             #+#    #+#             */
/*   Updated: 2023/08/25 12:42:55 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_all(int nb, t_list **lst, int size)
{
	int	i;
	int	*pile;

	pile = ft_file_tab(lst, ft_len_lst(lst));
	if (!pile)
		return (0);
	i = 0;
	while (i < size)
	{
		if (nb < pile[i])
			return (free(pile), 0);
		i++;
	}
	return (free(pile), 1);
}

int	lower_all(int nb, t_list **lst, int size)
{
	int	i;
	int	*pile;

	pile = ft_file_tab(lst, ft_len_lst(lst));
	if (!pile)
		return (0);
	i = 0;
	while (i < size)
	{
		if (nb > pile[i])
			return (free(pile), 0);
		i++;
	}
	return (free(pile), 1);
}
