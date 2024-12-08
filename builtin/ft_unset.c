/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 04:09:54 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 15:16:46 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static t_tokken_list	*check_unset(t_tokken_list *tokken);
static void				check_list(t_tokken_list *tokken, t_envlist *t_envlist);
static void				remove_node(char *content, t_envlist *envlist);

int	builtin_unset(t_tokken_list *tokken, t_envlist *envlist, t_val *val)
{
	t_tokken_list	*node;

	node = check_unset(tokken);
	if (node == NULL)
		return (FAIL_TO_FIND_CMD);
	check_list(node->next, envlist);
	val->exit_code = BUILTIN_COMPLATE;
	return (COMPLETE);
}

static t_tokken_list	*check_unset(t_tokken_list *tokken)
{
	t_tokken_list	*list;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "unset", 5) && ft_strlen(list->content) == 5)
			return (list);
		list = list->next;
	}
	return (NULL);
}

static void	check_list(t_tokken_list *tokken, t_envlist *envlist)
{
	t_tokken_list	*list;

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
		if (!strncmp(content, node->content, ft_strlen(content)))
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
