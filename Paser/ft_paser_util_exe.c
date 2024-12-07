/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser_util_exe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:13:15 by seojang           #+#    #+#             */
/*   Updated: 2024/12/08 02:54:32 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	free_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	paths = NULL;
}

void	ft_find_cmd(t_tlist *tokken, t_val **val)
{
	while (tokken && ft_strncmp(tokken->content, "|", 1) != 0)
	{
		if (tokken->content != NULL && ft_strlen(tokken->content) != 0)
		{
			(*val)->cmd = tokken;
			return ;
		}
		tokken = tokken->next;
	}
	exit(1);
}

char	*store_path(t_envlist *envlist)
{
	char	*path;
	t_envlist *list;

	list = envlist;
	while (list != NULL)
	{
		if (ft_strncmp(list->content, "PATH=", 5) == 0)
			path = list->content + 5;
		list = list->next;
	}
	return (path);
}

char	*find_path(char *argv, const char *env)
{
	char	**paths;
	char	*command;
	char	*path;
	int		i;

	paths = ft_split(env, ':');
	command = ft_strdup(argv);
	i = 0;
	if (access(command, F_OK | X_OK) == 0)
		path = ft_strdup(command);
	else
	{
		while (paths[i])
		{
			ft_find_path_set(paths[i++], &path, command);
			if (access(path, F_OK | X_OK) == 0)
				break ;
			free(path);
			path = NULL;
		}
	}
	free_path(paths);
	free(command);
	return (path);
}

void	execute_cmd(t_tlist *tokken, t_envlist *envlist)
{
	char *const	env[] = {store_path(envlist), NULL};
	char	**c_env;
	char		**argv;
	char		*path;
	int			arg_count;

	arg_count = 0;
	ft_excute_cmd_util_one(tokken, &arg_count);
	argv = malloc(sizeof(char *) * (arg_count + 1));
	if (!argv)
		error("Memory allocation failed", 2);
	ft_excute_cmd_util_two(tokken, arg_count, argv);
	argv[arg_count] = NULL;
	path = find_path(argv[0], env[0]);
	if (!path)
		error(argv[0], 3);
	c_env = convert_env(envlist);
	execve(path, argv, c_env);
	delete_all_env(c_env);
	error("execve failed", 2);
}
