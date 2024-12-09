/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:23:30 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 19:34:15 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static int		count_arg(t_tlist *tokken);
static int		check_exit_arg(char *content);
static t_tlist	*find_exit(t_tlist *tokken);
static void		print_error_arg(char *content, t_val *val);

int	builtin_exit(t_tlist *tokken, t_val *val, t_envlist *envlist)
{
	int		status;
	int		count;
	t_tlist	*node;

	node = find_exit(tokken);
	if (node == NULL)
		return (0);
	status = check_exit_arg(node->next->content);
	if (status == -1)
		print_error_arg(node->next->content, val);
	count = count_arg(node->next);
	if (count > 1)
	{
		write(2, "exit: too many arguments\n", 25);
		val->exit_code = BUILTIN_ERROR;
		return (2);
	}
	write(1, "exit\n", 5);
	ft_lstclear(&tokken);
	ft_enlclear(&envlist);
	exit(status);
	return (0);
}

static t_tlist	*find_exit(t_tlist *tokken)
{
	t_tlist	*list;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "exit", 4) && \
		ft_strlen(list->content) == 4)
		{
			if (list->next == NULL || list->next->node_type != N_WORD)
				exit(0);
			else
				return (list);
		}
		list = list->next;
	}
	return (NULL);
}

static int	count_arg(t_tlist *tokken)
{
	t_tlist	*list;
	int		count;

	list = tokken;
	count = 0;
	while (list != NULL && list->node_type == N_WORD)
	{
		count++;
		list = list->next;
	}
	return (count);
}

static int	check_exit_arg(char *content)
{
	int	i;

	i = 0;
	while (content[i] != '\0')
	{
		if (!ft_is_digit(content[i]))
			return (-1);
		i++;
	}
	i = ft_atoi(content);
	return (i);
}

static void	print_error_arg(char *content, t_val *val)
{
	write(2, "exit: ", 6);
	write(2, content, ft_strlen(content));
	write(2, ": numeric argument required\n", 28);
	val->exit_code = BUILTIN_ERROR;
	exit(2);
}
