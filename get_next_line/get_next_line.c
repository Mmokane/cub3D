/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:06:56 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/10/06 17:17:17 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*fill_and_join(int fd, char **saved, char *line, char *tmp)
{
	while (!ft_strchr2(*saved, '\n'))
	{
		tmp = fill_buff(fd);
		if (!tmp)
		{
			line = *saved;
			*saved = NULL;
			return (line);
		}
		*saved = ft_strjoin2(*saved, tmp);
		free(tmp);
	}
	line = ft_substr2(*saved, 0, ft_strchr2(*saved, '\n') - *saved + 1);
	tmp = *saved;
	*saved = ft_substr2(ft_strchr2(*saved, '\n') + 1, 0,
			ft_strlen2(ft_strchr2(*saved, '\n')));
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*line;
	static char	*saved;

	tmp = NULL;
	line = NULL;
	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	return (fill_and_join(fd, &saved, line, tmp));
}
