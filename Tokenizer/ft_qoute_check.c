/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qoute_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:47:29 by mku               #+#    #+#             */
/*   Updated: 2024/12/08 18:38:22 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static int	ft_single_qoute(char *line, int i, t_val *val);
static int	ft_double_qoute(char *line, int i, t_val *val);

int	ft_qoute_check(char *line, t_val *val)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			i = ft_single_qoute(line, i, val);
			if (i < 0)
				return (1);
		}
		else if (line[i] == '\"')
		{
			i = ft_double_qoute(line, i, val);
			if (i < 0)
				return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_double_qoute(char *line, int i, t_val *val)
{
	i++;
	while (line[i])
	{
		if (line[i] == '\"')
			return (i);
		i++;
	}
	write(2, "QUOTE_ERROR\n", 12);
	val->exit_code = 1;
	return (-1);
}

static int	ft_single_qoute(char *line, int i, t_val *val)
{
	i++;
	while (line[i])
	{
		if (line[i] == '\'')
			return (i);
		i++;
	}
	write(2, "QUOTE_ERROR\n", 12);
	val->exit_code = 1;
	return (-1);
}
