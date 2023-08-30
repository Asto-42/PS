# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquil <jquil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:45:16 by jquil             #+#    #+#              #
#    Updated: 2023/08/29 14:58:04 by jquil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		=	\
		push_swap.c						\
		sort_lst.c						\
		type_sort.c						\
		operate.c						\
		operate_double.c				\
		ft_printlst.c					\
		ft_tools.c						\
		radix.c							\
		ft_parse.c						\
		ft_lst.c						\


OBJS		=	$(SRCS:.c=.o)
LIBS		=	-LLibft -lft -Lprintf -lftprintf
CC			=	cc
FLAGS		=	-g3 -Werror -Wextra -Wall

#------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------------------------

.PHONY: clean fclean re
