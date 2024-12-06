/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:47:45 by seojang           #+#    #+#             */
/*   Updated: 2024/12/08 01:38:00 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alpha(char c)
{
	if ((c >= 64 && c <= 90) || (c >= 97 && c <= 122) || \
	c == 46 || c == 47 || c == '=' || \
	c == '~' || c == '$' || c == '\"' || c == '\'' || c == '-')
		return (1);
	return (0);
}

int	ft_is_digit(char c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int	ft_find_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}
