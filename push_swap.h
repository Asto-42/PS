/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:29:01 by jquil             #+#    #+#             */
/*   Updated: 2023/08/30 16:35:32 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <stdint.h>
# include <stdarg.h>
# include "Libft/libft.h"
# include "printf/ft_printf.h"

void		ft_setuplst(int argc, char **argv);
t_list		*ft_lstnew(int value);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
long long	ft_atoi(const char *nptr);
t_list		*ft_init_node(int x);
int			ft_len_lst(t_list **lst);
void		ft_swap(t_list **lst, char c);
void		ft_push(t_list **lst_a, t_list **lst_b, char c);
void		ft_rotate(t_list **lst, char c);
void		ft_printlst(t_list **lst);
void		ft_reverse_rotate(t_list **lst, char c);
void		sort_lst(int argc, t_list **lst_a, t_list **lst_b);
void		ft_sort_two(t_list **lst_a);
void		ft_sort_small(t_list **lst_a, t_list **lst_b, int x);
void		ft_sort_small_part_two(t_list **l_a, t_list **l_b, int min, int x);
int			check_sort(t_list *lst);
void		ft_sort_big(t_list **lst_a, t_list **lst_b, int argc);
int			ft_printf(const char *c, ...);
int			check_sort2(t_list **lst);
void		ft_reverse_rotate_a_b(t_list **lst_a, t_list **lst_b);
void		ft_rotate_a_b(t_list **lst_a, t_list **lst_b);
void		ft_swap_a_b(t_list **lst_a, t_list **lst_b);
int			ft_len_lst(t_list **lst);
int			*ft_file_tab(t_list **lst, int len);
void		ft_free_lst(t_list **lst);
void		ft_swap_a_b(t_list **lst_a, t_list **lst_b);
void		radix_sort(t_list **stack_a, t_list **stack_b);
t_list		*ft_lstnew(int value);
int			ft_parse_arg(char **argv, int argc);
int			is_number(char **argv);

#endif
