#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ireva <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 17:26:49 by ireva             #+#    #+#              #
#    Updated: 2017/10/24 21:19:33 by ireva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC =  validation.c ft_wordslen.c lem_in.c  work_with_net.c work_with_links.c get_next_line.c init.c work_with_arr.c norma.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

LIBFT_I = ./libft/libft.h

LIBFT = ./libft/

all: $(LIBFT)libft.a $(NAME)

$(NAME):  $(OBJECTS)
	@gcc $(OBJECTS) $(LIBFT)libft.a -o $(NAME)
	@echo "\033[31mCompleted!!!\033[0m"

%.o: %.c
	@gcc -c $< $(CFLAGS) -o $@

$(LIBFT)libft.a:
	@make -C $(LIBFT)

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all