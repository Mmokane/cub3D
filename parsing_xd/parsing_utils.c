/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:27:19 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/02 05:36:17 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	space_skipper(char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
}

void	check_nums(char *line)// check_lenght
{
	int		i;
	char	**f;

	i = 0;
	f = ft_split(line, ',');
	if (!f)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (f[i])
		i++;
	if (i != 3)
		exit_error("Invalid color", line);
	// free_loop(f);
}
