/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:40:38 by mku               #+#    #+#             */
/*   Updated: 2024/12/12 23:43:48 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static t_tlist	*find_echo_cmd(t_tlist *tokken);
static int		find_option(t_tlist *tokken);
static void		print_newline(char *content);
static char		*sub_string(t_tlist *tokken);

int	builtin_echo(t_tlist *tokken, t_val *val)
{
	t_tlist	*node;
	int		option;
	char	*string;

	node = find_echo_cmd(tokken);
	if (node == NULL)
		return (FAIL_TO_FIND_CMD);
	option = find_option(node);
	if (node == NULL || node->node_type != N_WORD)
		write(1, "\n", 2);
	else if (option > 0)
	{
		while (option-- > 0)
			node = node->next;
		string = sub_string(node);
		write(1, string, ft_strlen(string));
		free(string);
	}
	else if (option == NO_OPTION)
	{
		string = sub_string(node);
		print_newline(string);
	}
	val->exit_code = BUILTIN_COMPLATE;
	return (COMPLETE);
}

static t_tlist	*find_echo_cmd(t_tlist *tokken)
{
	t_tlist	*list;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "echo", 4) && \
		ft_strlen(list->content) == 4)
			return (list->next);
		list = list->next;
	}
	return (NULL);
}

static int	find_option(t_tlist *tokken)
{
	t_tlist	*list;
	int		place;
	int		i;

	place = 0;
	list = tokken;
	while (list != NULL)
	{
		i = 1;
		if (list->content[0] == '-')
		{
			while (list->content[i] != '\0')
			{
				if (list->content[i] != 'n')
					return (place);
				i++;
			}
			place++;
		}
		list = list->next;
	}
	return (place);
}

static void	print_newline(char *content)
{
	char	*temp;

	temp = ft_strjoin(content, "\n");
	write(1, temp, ft_strlen(temp));
	free(temp);
}

static char	*sub_string(t_tlist *tokken)
{
	t_tlist	*list;
	char	*string;

	string = ft_strdup("");
	list = tokken;
	while (list != NULL && list->node_type == N_WORD)
	{
		if (list->content[0] == '\0')
		{
			list = list->next;
			continue ;
		}
		string = ft_strjoin(string, list->content);
		if (list->next != NULL && list->next->node_type == N_WORD)
			string = ft_strjoin(string, " ");
		list = list->next;
	}
	return (string);
}
