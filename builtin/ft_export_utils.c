/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:33:10 by mku               #+#    #+#             */
/*   Updated: 2024/11/26 17:44:02 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../ms_test.h"
#include "../String/ft_string.h"

void	variable_error(char *content)
{
	write(2, "export: \'", 9);
	write(2, content, ft_strlen(content));
	write(2, "\': not a valid identifier", 25);
	write(2, "\n", 2);
}

t_envlist	*find_env(char *content, t_envlist *envlist)
{
	t_envlist	*list;
	int			length;

	length = 0;
	list = envlist;
	while (content[length] != '=' && content[length] != '\0')
		length++;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, content, length))
			return (list);
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

void	print_export(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		write(1, "declare -x ", 11);
		write(1, env[i], ft_strlen(env[i]));
		write(1, "\n", 2);
		i++;
	}
	delete_all_env(env);
}

int	check_special(char *content)
{
	int	i;

	i = 0;
	while (content[i] != '\0' && content[i] != '=')
	{
		if ((content[i] >= 'a' && content[i] <= 'z') || \
		(content[i] >= 'A' && content[i] <= 'Z'))
			i++;
		else
			return (NO_IDENTYFIER);
	}
	return (0);
}
