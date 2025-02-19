/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:33:10 by mku               #+#    #+#             */
/*   Updated: 2024/12/13 23:00:53 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	variable_error(char *content, int *flag)
{
	*flag = 1;
	write(2, "export: \'", 9);
	write(2, content, ft_strlen(content));
	write(2, "\': not a valid identifier", 25);
	write(2, "\n", 2);
}

t_envlist	*find_env(char *content, t_envlist *envlist)
{
	t_envlist	*list;
	int			e_length;
	int			c_length;

	c_length = 0;
	list = envlist;
	while (content[c_length] != '\0' && content[c_length] != '=')
		c_length++;
	while (list != NULL)
	{
		e_length = 0;
		if (!ft_strncmp(list->content, content, c_length))
		{
			while (list->content[e_length] != '\0' && \
			list->content[e_length] != '=')
				e_length++;
			if (c_length == e_length)
				return (list);
		}
		list = list->next;
	}
	return (NULL);
}

char	**sort_export(t_envlist *envlist)
{
	char	**env;
	int		i;
	int		j;
	char	*temp;

	i = 0;
	env = convert_env(envlist);
	while (env[i] != NULL)
	{
		j = i + 1;
		while (env[j] != NULL)
		{
			if (ft_strcmp(env[i], env[j]) > 0)
			{
				temp = env[i];
				env[i] = env[j];
				env[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (env);
}

void	print_export(char **env, int i)
{
	int	j;
	int	flag;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		flag = 0;
		write(1, "declare -x ", 11);
		while (env[i][j] != '\0')
		{
			write(1, &(env[i][j]), 1);
			if (env[i][j] == '=')
			{
				write(1, "\"", 1);
				flag = 1;
			}
			j++;
		}
		if (flag == 1)
			write(1, "\"\n", 2);
		else
			write(1, "\n", 1);
		i++;
	}
}

int	check_special(char *content)
{
	int	i;

	i = 0;
	while (content[i] != '\0' && content[i] != '=')
	{
		if ((content[i] >= 'a' && content[i] <= 'z') || \
		(content[i] >= 'A' && content[i] <= 'Z') || \
		ft_is_digit(content[i]) || content[i] == '_')
			i++;
		else
			return (NO_IDENTYFIER);
	}
	return (0);
}
