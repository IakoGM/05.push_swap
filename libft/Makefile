# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 15:24:43 by jakgonza          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/08/02 18:40:22 by jakgonza         ###   ########.fr        #
=======
#    Updated: 2023/08/02 18:48:10 by jakgonza         ###   ########.fr        #
>>>>>>> 05eff5f (renamed all list methods)
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_strlen.c\
	   ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strncmp.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strnstr.c\
	   ft_atoi.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_striteri.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
<<<<<<< HEAD
	   ft_lstnew_bonus.c\
=======
	   ft_lstnew.c\
>>>>>>> 05eff5f (renamed all list methods)
	   ft_lstadd_front.c\
	   ft_lstsize.c\
	   ft_lstlast.c\
	   ft_lstadd_back.c\
	   ft_lstdelone.c\
	   ft_lstclear.c\
	   ft_lstiter.c\
	   ft_lstmap.c\

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
