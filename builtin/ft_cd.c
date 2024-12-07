/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:07:07 by mku               #+#    #+#             */
/*   Updated: 2024/12/08 01:34:35 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static char	*find_cd_command(t_tokken_list *tokken);
static void	absolute_path(char *path, \
t_envlist *envlist, t_val *val, int *flag);
static void	relative_path(char *path, \
t_envlist *envlist, t_val *val, int *flag);
static void	home_path(char *path, t_envlist *envlist, t_val *val, int *flag);

int	builtin_cd(t_tokken_list *tokken, t_envlist *envlist, t_val *val)
{
	char	*path;
	int		flag;

	flag = 1;
	path = find_cd_command(tokken);
	if (path == NULL)
		return (FAIL_TO_FIND_CMD);
	if (check_arg(tokken) > 1)
	{
		write(2, "cd: too many arguments\n", 24);
		val->exit_code = EXIT_NORMAL_ERR;
		return (ARG_ERROR);
	}
	if (path[0] == '~')
		home_path(path, envlist, val, &flag);
	else if (path[0] == '/')
		absolute_path(path, envlist, val, &flag);
	else
		relative_path(path, envlist, val, &flag);
	free(path);
	if (flag)
		val->exit_code = BUILTIN_COMPLATE;
	return (COMPLETE);
}

static char	*find_cd_command(t_tokken_list *tokken)
{
	t_tokken_list	*list;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "cd", 2))
		{
			if (list->next == NULL || \
			(list->next->node_type != N_WORD && list->next->node_type != N_ENV))
				return (ft_strdup("~"));
			else if (list->next->content[0] == '\0')
				return (ft_strdup("~"));
			else
				return (ft_strdup((list->next->content)));
		}
		list = list->next;
	}
	return (NULL);
}

static void	absolute_path(char *path, t_envlist *envlist, t_val *val, int *flag)
{
	char		*temp;
	char		*old_pwd;

	temp = getcwd(NULL, 0);
	old_pwd = ft_strdup(temp);
	if (chdir(path))
		cd_error(path, val, flag);
	else
	{
		change_oldpwd(envlist, old_pwd);
		change_pwd(envlist);
	}
	free(old_pwd);
	free(temp);
}

static void	relative_path(char *path, t_envlist *envlist, t_val *val, int *flag)
{
	char	*current_path;
	char	*join_path;
	char	*temp;
	char	*old_pwd;

	temp = getcwd(NULL, 0);
	old_pwd = ft_strdup(temp);
	current_path = ft_strjoin(temp, "/");
	if (current_path == NULL)
		write(2, "getcwd error", 13);
	join_path = ft_strjoin(current_path, path);
	if (chdir(join_path))
		cd_error(path, val, flag);
	else
	{
		change_oldpwd(envlist, old_pwd);
		change_pwd(envlist);
	}
	free(old_pwd);
	free(join_path);
}

static void	home_path(char *path, t_envlist *envlist, t_val *val, int *flag)
{
	char	*old_pwd;
	char	*home_dir;

	old_pwd = getcwd(NULL, 0);
	home_dir = find_home_dir(envlist, val);
	if (home_dir == NULL)
	{
		free(old_pwd);
		return ;
	}
	if (chdir(home_dir))
		cd_error(path, val, flag);
	change_oldpwd(envlist, old_pwd);
	change_pwd(envlist);
	free(home_dir);
	free(old_pwd);
}
