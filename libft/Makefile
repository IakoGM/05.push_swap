# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 19:14:05 by jakgonza          #+#    #+#              #
#    Updated: 2023/08/21 12:36:04 by jakgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c\
	   ft_split.c\
	   ft_substr.c\
	   ft_strdup.c\
	   ft_memcpy.c\
	   ft_atoi.c\
	   ft_itoa.c\
	   ft_strlcpy.c\

OBJS = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)
	@echo "Object files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Library removed"

re: fclean all

.PHONY: all clean fclean re
