/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:16 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/10/06 17:15:52 by mmokane          ###   ########.fr       */
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

char	*fill_buff(int fd);
char	*get_next_line(int fd);
size_t	ft_strlen2(const char *str);
char	*ft_strchr2(char *buff, char c);
char	*ft_strjoin2(char *s1, char const *s2);
char	*ft_substr2(char const *s, unsigned int start, size_t len);

#endif
