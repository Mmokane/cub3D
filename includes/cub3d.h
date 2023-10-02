/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 02:34:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/02 05:45:00 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include "../libft/libft.h"
# include "get_next_line.h"

enum e_content
{
	T_C,
	T_F,
	T_WE,
	T_SO,
	T_EA,
	T_NO,
	T_Error;
};

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*we;
	char	*no;
	char	*ea;
	char	*so;
	char	*dr;
	char	**map;
	int		F;
	int		C;
}	t_game;

#endif