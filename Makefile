# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 13:37:35 by jakgonza          #+#    #+#              #
#    Updated: 2023/07/27 21:07:49 by jakgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C ./libft

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	@echo "Object files removed"
	@make clean -C ./libft

fclean:
	rm -f $(NAME)
	@echo "Library removed"
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean bonus fclean re
