/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 04:09:54 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 18:25:18 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static t_tlist	*check_unset(t_tlist *tokken);
static void				check_list(t_tlist *tokken, t_envlist *t_envlist);
static void				remove_node(char *content, t_envlist *envlist);
static int				find_node(char *content, char *content2);

int	builtin_unset(t_tlist *tokken, t_envlist *envlist, t_val *val)
{
	t_tlist	*node;

	node = check_unset(tokken);
	if (node == NULL)
		return (FAIL_TO_FIND_CMD);
	check_list(node->next, envlist);
	val->exit_code = BUILTIN_COMPLATE;
	return (COMPLETE);
}

static t_tlist	*check_unset(t_tlist *tokken)
{
	t_tlist	*list;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "unset", 5) && \
		ft_strlen(list->content) == 5)
			return (list);
		list = list->next;
	}
	return (NULL);
}

static void	check_list(t_tlist *tokken, t_envlist *envlist)
{
	t_tlist	*list;

	list = tokken;
	while (list != NULL && list->node_type == N_WORD)
	{
		remove_node(list->content, envlist);
		list = list->next;
	}
}

static void	remove_node(char *content, t_envlist *envlist)
{
	t_envlist	*node;
	t_envlist	*prevnode;
	t_envlist	*t_node;

	prevnode = NULL;
	node = envlist;
	while (node != NULL)
	{
		if (find_node(content, node->content))
		{
			t_node = node;
			if (prevnode == NULL)
				envlist = envlist->next;
			else if (t_node->next != NULL)
				prevnode->next = t_node->next;
			else
				prevnode->next = NULL;
			free(t_node->content);
			free(t_node);
			return ;
		}
		prevnode = node;
		node = node->next;
	}
}

static int	find_node(char *str, char *env_str)
{
	size_t	env_len;

	env_len = 0;
	while (env_str[env_len] != '=' && env_str[env_len] != '\0')
		env_len++;
	if (!strncmp(str, env_str, env_len) && ft_strlen(str) == env_len)
		return (1);
	else
		return (0);
}
