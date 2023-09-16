/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:27:47 by mmokane           #+#    #+#             */
/*   Updated: 2022/10/26 18:27:49 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) >= start)
		j = ft_strlen(s) - start;
	if (len < j)
		j = len;
	sub = (char *)malloc(sizeof(char) * (j + 1));
	if (!sub)
		return (NULL);
	while (s[i] && i < j)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
