# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 02:38:17 by mmokane           #+#    #+#              #
#    Updated: 2023/11/05 18:47:27 by oubelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc 

CFLAGS =  -Wall -Wextra -Werror #-g3 -fsanitize=address 

MFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS =  parsing_xd/checks.c parsing_xd/map_parsing.c \
		parsing_xd/parsing.c parsing_xd/map_parsing2.c \
		parsing_xd/parsing_utils.c cub3d.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c parsing_xd/utils.c \
		raycasting/cast_rays.c raycasting/hooks.c raycasting/init.c \
		raycasting/intersections.c raycasting/textures.c raycasting/utils.c \


OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@make -C libft
		@$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) libft/libft.a -o $(NAME)
		@echo "\033[1;32m----   DONE!  ----\033[0m"

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

re : fclean all 