# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 13:37:35 by jakgonza          #+#    #+#              #
#    Updated: 2023/08/28 09:58:37 by jakgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	main.c\
		ft_error.c\
		lists.c\
		movements01.c\
		movements02.c\
		sort.c\
		sort_radix.c\
		push_swap.c\
		checkdata.c\
		checkdata_utils.c\

OBJS = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

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

.PHONY: all clean fclean re
