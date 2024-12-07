/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qoute_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:47:29 by mku               #+#    #+#             */
/*   Updated: 2024/12/06 18:02:11 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	ft_single_qoute(char *line, int i);
static int	ft_double_qoute(char *line, int i);

void	ft_qoute_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			i = ft_single_qoute(line, i);
		else if (line[i] == '\"')
			i = ft_double_qoute(line, i);
		i++;
	}
}

static int	ft_double_qoute(char *line, int i)
{
	i++;
	while (line[i])
	{
		if (line[i] == '\"')
			return (i);
		i++;
	}
	write(2, "QUOTE_ERROR\n", 12);
	exit(1);
}

static int	ft_single_qoute(char *line, int i)
{
	i++;
	while (line[i])
	{
		if (line[i] == '\'')
			return (i);
		i++;
	}
	write(2, "QUOTE_ERROR\n", 12);
	exit(1);
}
