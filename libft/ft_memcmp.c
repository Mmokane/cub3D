/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:25:25 by mmokane           #+#    #+#             */
/*   Updated: 2022/10/26 18:25:27 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		res;
	size_t	i;

	i = 0;
	res = 0;
	while (i < n && res == 0)
	{
		res = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		i++;
	}
	return (res);
}
