/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:52:16 by mmokane           #+#    #+#             */
/*   Updated: 2022/10/27 22:21:29 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	d_c(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i = i * -1;
		count++;
	}
	if (i == 0)
		count++;
	while (i > 0)
	{
		count++;
		i = i / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;
	int		x;

	nb = n;
	x = 0;
	i = d_c(nb);
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
		x = 1;
	}	
	while (--i >= x)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
