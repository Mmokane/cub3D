# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 02:38:17 by mmokane           #+#    #+#              #
#    Updated: 2023/10/04 03:57:49 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

SRCS =  parsing_xd/checks.c parsing_xd/map_parsing.c \
		parsing_xd/parsing.c parsing_xd/map_parsing2.c \
		parsing_xd/parsing_utils.c \
		

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@make -C libft
		@cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) $(LDFLAGS) $(INCLUDES)
		@cc $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[1;32m   ---- DONE ----\033[0m"	

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

clean : 
		@rm -rf	$(OBJS)
		@make clean -C libft

fclean :
		@rm -rf	$(NAME)
		@rm -rf	$(OBJS)
		@make fclean -C libft

re : clean all