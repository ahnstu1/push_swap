# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 16:30:03 by hahn              #+#    #+#              #
#    Updated: 2022/07/31 01:18:30 by hahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

//CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
NAME = push_swap
OBJS = main.o \
		lst.o \
		rule.o \
		err.o \
		stack.o \
		sort.o \
		sort_utils.o \
		rule_simply_sp.o \
		rule_simply_r.o

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT)
	cc $(OBJS) -o $(NAME) -Llibft -lft -g -fsanitize=address
	
clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re