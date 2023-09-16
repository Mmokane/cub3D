/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:19:39 by mmokane           #+#    #+#             */
/*   Updated: 2022/10/26 18:20:03 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (a > b)
	{
		while (i < len)
		{
			a[len - 1] = b[len - 1];
			len --;
		}
	}
	else
		ft_memcpy(a, b, len);
	return (a);
}
