# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 02:38:17 by mmokane           #+#    #+#              #
#    Updated: 2023/09/16 02:42:30 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

SRCS =  

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@cc $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[1;32m   ---- DONE ----\033[0m"	

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

clean : 
		@rm -rf	$(OBJS)

fclean :
		@rm -rf	$(NAME)
		@rm -rf	$(OBJS)

re : clean all