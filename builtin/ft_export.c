/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:45:40 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 15:24:37 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static t_tokken_list	*check_export(t_tokken_list *tokken);
static void				add_var(t_tokken_list *tokken, \
t_envlist *t_envlist, int *error_flag);
static int				check_variable(char *content);
static void				add_list(char *content, t_envlist *envlist, int type);

int	builtin_export(t_tokken_list *tokken, t_envlist *envlist, t_val *val)
{
	t_tokken_list	*node;
	char			**env;
	int				error_flag;

	error_flag = 0;
	node = check_export(tokken);
	if (node == NULL)
		return (FAIL_TO_FIND_CMD);
	if (node->next == NULL || node->next->node_type != N_WORD)
	{
		env = sort_export(envlist);
		print_export(env);
		delete_all_env(env);
	}
	else
		add_var(node->next, envlist, &error_flag);
	if (error_flag == 1)
		val->exit_code = BUILTIN_ERROR;
	else
		val->exit_code = BUILTIN_COMPLATE;
	return (COMPLETE);
}

static t_tokken_list	*check_export(t_tokken_list *tokken)
{
	t_tokken_list	*list;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "export", 6) && ft_strlen(list->content) == 6)
			return (list);
		list = list->next;
	}
	return (NULL);
}

static void	add_var(t_tokken_list *tokken, t_envlist *envlist, int *flag)
{
	t_tokken_list	*list;
	int				type;

	list = tokken;
	while (list != NULL)
	{
		if (list->node_type == N_RED)
			list = list->next->next;
		if (list == NULL)
			return ;
		if (list->node_type == N_WORD)
		{
			type = check_variable(list->content);
			if (type == NO_IDENTYFIER)
				variable_error(list->content, flag);
			else
				add_list(list->content, envlist, type);
		}
		list = list->next;
	}
}

static int	check_variable(char *content)
{
	int	i;

	i = 0;
	if (ft_is_digit(content[0]) || content[0] == '=')
		return (NO_IDENTYFIER);
	if (check_special(content))
		return (NO_IDENTYFIER);
	if (content[ft_strlen(content) - 1] == '=')
		return (NAME_AND_EQUAL);
	while (content[i] != '\0')
	{
		if (content[i] == '=')
			return (FULL_ENV);
		i++;
	}
	return (NAME_ONLY);
}

static void	add_list(char *content, t_envlist *envlist, int type)
{
	char		*temp;
	t_envlist	*node;
	t_node_type	node_type;

	if (type == NAME_AND_EQUAL)
		temp = ft_strjoin(ft_strdup(content), "");
	if (type == FULL_ENV)
		temp = ft_strdup(content);
	if (type == NAME_ONLY)
		temp = ft_strdup(content);
	if (type == NAME_AND_EQUAL || type == FULL_ENV)
		node_type = N_ENV;
	else
		node_type = N_EXPORT_ENV;
	node = find_env(temp, envlist);
	if (node == NULL)
		ft_lstadd_back(&envlist, ft_lstnew(temp, node_type));
	else if (type != NAME_ONLY)
	{
		free(node->content);
		node->content = temp;
	}
	else
		free(temp);
}
