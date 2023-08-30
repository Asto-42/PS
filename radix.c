/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:06:29 by jquil             #+#    #+#             */
/*   Updated: 2023/08/29 11:26:48 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **lst_a, t_list **lst_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *lst_a;
	size = ft_len_lst(&head_a);
	max_bits = get_max_bits(lst_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *lst_a;
			if (((head_a->index >> i) & 1) == 1)
				ft_rotate(lst_a, 'a');
			else
				ft_push(lst_a, lst_b, 'b');
		}
		while (ft_len_lst(lst_b) != 0)
			ft_push(lst_b, lst_a, 'a');
		i++;
	}
}
