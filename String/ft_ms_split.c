/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:27:58 by mku               #+#    #+#             */
/*   Updated: 2024/12/07 17:02:18 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_word(char const *s, char c)
{
	int		count;
	int		flag;
	int		i;

	i = 0;
	count = 0;
	if (s[0] == c)
		flag = 0;
	else
		flag = 1;
	while (s[i])
	{
		if (s[i] != c && flag)
		{
			count++;
			flag = 0;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static int	word_length(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (s[i] == c)
		return (0);
	while (s[i] != c && s[i] != 0)
	{
		count++;
		i++;
	}
	return (count);
}

static char	*putstr(const char *s, char c, int *s_place)
{
	int		i;
	int		length;
	char	*buffer;

	length = word_length(s + *s_place, c);
	i = 0;
	buffer = (char *)malloc(sizeof(char) * (length + 1));
	if (!buffer)
		return (NULL);
	while (i < length)
	{
		buffer[i] = s[*s_place];
		i++;
		(*s_place)++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static void	malloc_error(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_ms_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		c_word;
	int		index;

	i = 0;
	index = 0;
	c_word = count_word(s, c);
	split = (char **)malloc(sizeof(char *) * (c_word + 1));
	if (!split)
		return (NULL);
	while (i < c_word)
	{
		while (s[index] == c)
			index++;
		split[i] = putstr(s, c, &index);
		if (!split[i])
		{
			malloc_error(split);
			return (NULL);
		}
		i++;
	}
	split[i] = 0;
	return (split);
}
