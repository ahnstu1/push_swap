# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 16:30:03 by hahn              #+#    #+#              #
#    Updated: 2022/07/04 18:12:12 by hahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
NAME = push_swap
OBJS = main.o \
		lst.o \
		rule.o

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT)
	cc -Llibft -lft $(OBJS) -o $(NAME)
	
clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re