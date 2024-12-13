/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:08:50 by seojang           #+#    #+#             */
/*   Updated: 2024/12/13 18:51:05 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	ft_paser_func(t_tlist **tokken, t_val **val)
{
	ft_find_redir(tokken, val);
}

void	ft_before_fork(t_tlist *tokken, int (*pipefd)[2])
{
	if (ft_next_pipe(tokken))
	{
		if (pipe(*pipefd) == -1)
			error("pipe failed", 1);
	}
	else
	{
		(*pipefd)[0] = -1;
		(*pipefd)[1] = -1;
	}
}

void	ft_wait_pipe(t_val **val)
{
	int	status;

	while (wait(&status) > 0)
		ft_wait_child(val, &status);
}

int	ft_after_redir(t_tlist *tokken)
{
	while (tokken)
	{
		if (ft_strlen(tokken->content))
			return (0);
		tokken = tokken->next;
	}
	return (1);
}

void	ft_paser_manager(t_tlist *tokken, t_envlist *envlist, t_val **val)
{
	pid_t	pid;
	int		pipefd[2];

	if (ft_before_manager(&tokken, envlist, val))
		return ;
	while (tokken)
	{
		ft_before_fork(tokken, &pipefd);
		ft_val_set(val);
		pid = fork();
		ft_siganl_set();
		if (pid < 0)
			error("Fork error", 1);
		else if (pid == 0)
		{
			ft_paser_func(&tokken, val);
			ft_child_process(tokken, val, &pipefd, envlist);
		}
		else
			ft_parents_process(val, &pipefd);
		ft_move_token(&tokken);
	}
	if ((*val)->prev_pipe != -1)
		close((*val)->prev_pipe);
	ft_wait_pipe(val);
}
