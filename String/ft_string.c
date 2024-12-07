/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 03:25:08 by mku               #+#    #+#             */
/*   Updated: 2024/12/07 02:24:02 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s);

size_t	ft_strlen(char const *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*src)
	{
		if (len + 1 < size)
			*dst++ = *src;
		src++;
		len++;
	}
	if (size > 0)
		*dst = '\0';
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	s1_len;
	size_t	s2_len;

	if (s1[0] == '\0')
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!p)
		return (NULL);
	if (s1[0] != '\0')
		ft_strlcpy(p, s1, s1_len + 1);
	ft_strlcpy((p + s1_len), s2, s2_len + 1);
	free(s1);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*p;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}

char	*ft_strdup(const char *s)
{
	size_t		len;
	size_t		i;
	char		*p;

	len = ft_strlen(s);
	i = 0;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < len)
		p[i++] = *s++;
	p[i] = '\0';
	return (p);
}
