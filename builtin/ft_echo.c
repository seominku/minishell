/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:40:38 by mku               #+#    #+#             */
/*   Updated: 2024/11/23 03:38:16 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "builtin.h"
#include "../String/ft_string.h"

static t_tokken_list	*find_echo_cmd(t_tokken_list *tokken);
static int				find_option(t_tokken_list *tokken);
static void				print_newline(char *content);
static char				*sub_string(t_tokken_list *tokken);

int	builtin_echo(t_tokken_list *tokken, t_envlist *envlist)
{
	t_tokken_list	*node;
	int				option;
	char			*string;

	node = find_echo_cmd(tokken);
	if (node == NULL)
		return (FAIL_TO_FIND_CMD);
	option = find_option(node);
	if (node->next == NULL || node->next->node_type != N_WORD)
		write(1, "\n", 2);
	else if (option == YES_OPTION)
	{
		string = sub_string(node->next->next);
		write(1, string, ft_strlen(string));
	}
	else if (option == NO_OPTION)
	{
		string = sub_string(node->next);
		print_newline(string);
	}
	return (COMPLETE);
}

static t_tokken_list	*find_echo_cmd(t_tokken_list *tokken)
{
	t_tokken_list	*list;
	char			*pwd;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "echo", 4))
			return (list);
		list = list->next;
	}
	return (NULL);
}

static int	find_option(t_tokken_list *tokken)
{
	t_tokken_list	*list;
	char			*option;
	int				i;

	i = 1;
	list = tokken;
	if (list->next != NULL && list->next->node_type == N_WORD)
	{
		option = list->next->content;
		if (option[0] == '-')
		{
			while (option[i] != '\0')
			{
				if (option[i] != 'n')
					return (NO_OPTION);
				i++;
			}
			return (YES_OPTION);
		}
	}
	return (NO_OPTION);
}

static void	print_newline(char *content)
{
	write(1, content, ft_strlen(content));
	write(1, "\n", 2);
}

static char	*sub_string(t_tokken_list *tokken)
{
	t_tokken_list	*list;
	char			*string;

	string = ft_strdup("");
	list = tokken;
	while (list != NULL && list->node_type == N_WORD)
	{
		string = ft_strjoin(string, list->content);
		if (list->next != NULL || list->next == N_WORD)
			string = ft_strjoin(string, " ");
		list = list->next;
	}
	return (string);
}
