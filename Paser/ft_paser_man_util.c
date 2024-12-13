/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser_man_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:00:01 by seojang           #+#    #+#             */
/*   Updated: 2024/12/13 18:56:03 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	ft_move_token(t_tlist **tokken)
{
	while ((*tokken) && (*tokken)->content && \
	ft_strncmp((*tokken)->content, "|", 1) != 0)
		(*tokken) = (*tokken)->next;
	if ((*tokken) && (*tokken)->content && \
	ft_strncmp((*tokken)->content, "|", 1) == 0)
		(*tokken) = (*tokken)->next;
}

void	ft_parents_process(t_val **val, int (*pipefd)[2])
{
	signal(SIGINT, handler_int);
	if ((*val)->prev_pipe != -1)
		close((*val)->prev_pipe);
	if ((*pipefd)[1] != -1)
		close((*pipefd)[1]);
	(*val)->prev_pipe = (*pipefd)[0];
	(*val)->cmd = NULL;
}

void	ft_child_process(t_tlist *tokken, t_val **val, \
int (*pipefd)[2], t_envlist *envlist)
{
	if (ft_after_redir(tokken))
		exit(0);
	ft_find_cmd(tokken, val);
	signal(SIGINT, SIG_DFL);
	if ((*val)->prev_pipe != -1)
	{
		dup2((*val)->prev_pipe, STDIN_FILENO);
		close((*val)->prev_pipe);
	}
	if ((*pipefd)[1] != -1)
	{
		dup2((*pipefd)[1], STDOUT_FILENO);
		close((*pipefd)[1]);
	}
	if ((*pipefd)[0] != -1)
		close((*pipefd)[0]);
	ft_dup(val, envlist, (*pipefd), tokken);
}

void	ft_wait_child(t_val **val, int *status)
{
	int	prev_exit_code;

	if ((*val)->exit_code > 0)
		prev_exit_code = (*val)->exit_code;
	else
		(*val)->exit_code = 0;
	if (WIFEXITED(*status))
		(*val)->exit_code = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status))
	{
		if (WTERMSIG(*status) == 13)
		{
			(*val)->exit_code = prev_exit_code;
			prev_exit_code = 0;
		}
		else
			(*val)->exit_code = WTERMSIG(*status) + 128;
	}
}
