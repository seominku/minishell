/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:47:45 by seojang           #+#    #+#             */
/*   Updated: 2024/12/10 17:34:29 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || \
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

int	ft_count_equal(char *content)
{
	int	count;

	count = 0;
	while (content[count] != '\0' && content[count] != '=')
		count++;
	if (content[count] == '=')
		count++;
	return (count);
}
