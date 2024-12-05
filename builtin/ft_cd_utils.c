/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:10 by mku               #+#    #+#             */
/*   Updated: 2024/12/01 16:22:51 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "builtin.h"
#include "../String/ft_string.h"

char	*find_home_dir(t_envlist *envlist)
{
	t_envlist	*list;

	list = envlist;
	while (list != NULL)
	{
		if (!strncmp(list->content, "HOME=", 5))
			return (ft_substr(list->content, 5, ft_strlen(list->content)));
		list = list->next;
	}
	write(2, "cd: HOME not set\n", 17);
	return (NULL);
}

void	change_pwd(t_envlist *envlist)
{
	t_envlist	*list;
	char		*temp;
	char		*pwd;

	pwd = getcwd(NULL, 0);
	list = envlist;
	while (list != NULL)
	{
		if (!strncmp(list->content, "PWD=", 4))
		{
			temp = list->content;
			list->content = ft_strjoin(ft_strdup("PWD="), pwd);
			free(pwd);
			free(temp);
			return ;
		}
		list = list->next;
	}
	ft_lstadd_back(&envlist, \
	ft_lstnew(ft_strjoin(ft_strdup("PWD="), pwd), N_ENV));
	free(pwd);
}

void	change_oldpwd(t_envlist *envlist, char *path)
{
	t_envlist	*list;
	char		*temp;

	list = envlist;
	while (list != NULL)
	{
		if (!strncmp(list->content, "OLDPWD=", 7))
		{
			temp = list->content;
			list->content = ft_strjoin(ft_strdup("OLDPWD="), path);
			free(temp);
			return ;
		}
		list = list->next;
	}
	ft_lstadd_back(&envlist, \
	ft_lstnew(ft_strjoin(ft_strdup("OLDPWD="), path), N_ENV));
}

void	cd_error(char *path)
{
	write(2, "cd : ", 5);
	write(2, path, ft_strlen(path));
	write(2, ": No Such file or directory", 27);
	write(2, "\n", 2);
}

int	check_arg(t_tokken_list *tokken)
{
	t_tokken_list	*list;
	int				count;

	count = 0;
	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "cd", 2))
		{
			while (list->next != NULL && \
			(list->next->node_type == N_WORD || \
			list->next->node_type == N_ENV))
			{
				count++;
				list = list->next;
			}
			return (count);
		}
		list = list->next;
	}
	return (count);
}
