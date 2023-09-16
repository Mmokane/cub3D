/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:22:56 by mmokane           #+#    #+#             */
/*   Updated: 2022/10/26 18:23:07 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c1;

	c1 = (char)c;
	i = ft_strlen(s) - 1;
	if (c1 == 0)
		return ((char *)(s + i + 1));
	while (i > 0 && s[i] != c1)
		i--;
	if (s[i] == c1)
		return ((char *)(s + i));
	else
		return (NULL);
}
