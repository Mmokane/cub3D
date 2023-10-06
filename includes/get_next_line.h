/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:58:58 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/06 04:42:36 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>


char	*ft_strjoin2(char *s1, char *s2);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
char	*ft_strdup2(const char *s);
char	*get_next_line(int fd);
size_t	ft_strlen2(const char *s);
int		ft_strchr2(char *s);


#endif