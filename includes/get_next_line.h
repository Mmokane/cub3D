/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:16 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/10/07 09:43:15 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

size_t	ft_strlen2(const char *s);
size_t	ft_strlcpy2(char *dst, const char *src, size_t dstsize);
char	*ft_strchr2(const char *s, int c);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*get_line(char *s);
char	*get_remine(char *s);
char	*get_next_line(int fd);

#endif
