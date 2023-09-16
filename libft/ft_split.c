/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:50:08 by mmokane           #+#    #+#             */
/*   Updated: 2022/10/27 05:07:30 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	w_c(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*w_m(char *klma, char const *s, int j, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		klma[i++] = s[j - word_len];
		word_len--;
	}
	klma[i] = '\0';
	return (klma);
}

char	**words_len(char **result, char const *s, char c, int word_num)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[j] && i < word_num)
	{	
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_len++;
		}
		result[i] = malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
			return (NULL);
		w_m(result[i], s, j, word_len);
		word_len = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**result;

	if (s == 0)
		return (NULL);
	word_num = w_c(s, c);
	result = malloc(sizeof(char *) * (word_num + 1));
	if (!result)
		return (NULL);
	words_len(result, s, c, word_num);
	return (result);
}
