/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:30:26 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 18:43:57 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static	void	print_syntax_err(int type, t_val *val);
static	int	double_pipe_check(t_tlist *tokken);
static	int	single_pipe_check(t_tlist *tokken);
static	int	brace_check(t_tlist *tokken);

int	check_token(t_tlist *tokken, t_val *val)
{
	if (double_pipe_check(tokken) == ERROR)
	{
		print_syntax_err(DOUBLE_PIPE, val);
		return (ERROR);
	}
	else if (single_pipe_check(tokken) == ERROR)
	{
		print_syntax_err(SINGLE_PIPE, val);
		return (ERROR);
	}
	else if (brace_check(tokken) == ERROR)
	{
		print_syntax_err(BRACE, val);
		return (ERROR);
	}
	return (NO_ERROR);
}

static	void	print_syntax_err(int type, t_val *val)
{
	val->exit_code = 1;
	write(2, "bash: syntax error near unexpected token '", 43);
	if (type == SINGLE_PIPE)
		write(2, "|", 1);
	if (type == DOUBLE_PIPE)
	{
		write(2, "|", 1);
		write(2, "|", 1);
	}
	if (type == BRACE)
		write(2, "newline", 7);
	write(2, "\'\n", 2);
}

static	int	double_pipe_check(t_tlist *tokken)
{
	t_tlist	*list;
	int		flag;

	flag = 0;
	list = tokken;
	while (list != NULL)
	{
		if (list->node_type == N_PIPE && flag == 1)
			return (ERROR);
		if (list->node_type == N_PIPE && flag == 0)
			flag = 1;
		if (list->node_type == N_WORD && flag == 1)
			flag = 0;
		list = list->next;
	}
	return (NO_ERROR);
}

static	int	single_pipe_check(t_tlist *tokken)
{
	t_tlist	*list;

	list = tokken;
	if (list->node_type == N_PIPE)
		return (ERROR);
	while (list != NULL)
	{
		if (list->node_type == N_PIPE && list->next == NULL)
			return (ERROR);
		list = list->next;
	}
	return (NO_ERROR);
}

static	int	brace_check(t_tlist *tokken)
{
	t_tlist	*list;

	list = tokken;
	while (list != NULL)
	{
		if (ft_strncmp(list->content, "<<", 2) == SAME)
		{
			if (list->next == NULL || list->next->node_type != N_WORD)
				return (ERROR);
		}
		if (ft_strncmp(list->content, ">>", 2) == SAME)
		{
			if (list->next == NULL || list->next->node_type != N_WORD)
				return (ERROR);
		}
		list = list->next;
	}
	return (NO_ERROR);
}
