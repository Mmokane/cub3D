/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:21:00 by mmokane           #+#    #+#             */
/*   Updated: 2022/10/26 18:21:09 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	i = 0;
	srclen = ft_strlen(src);
	if (!destsize || destsize <= ft_strlen(dest))
		return (srclen + destsize);
	destlen = ft_strlen(dest);
	while (src[i] != '\0' && destlen + i + 1 < destsize)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
