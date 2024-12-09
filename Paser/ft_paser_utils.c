/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:15:18 by seojang           #+#    #+#             */
/*   Updated: 2024/12/08 03:14:25 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	error(char *s, int num)
{
	if (num == 1)
		write(2, s, ft_strlen(s));
	else if (num == 2)
		perror(s);
	else if (num == 3)
	{
		write(2, "command not found: ", ft_strlen("command not found: "));
		write(2, s, ft_strlen(s));
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

void	ft_val_set(t_val **val)
{
	(*val)->fd_in = -1;
	(*val)->fd_out = -1;
}

void	ft_dup(t_val **val, t_envlist *envlist, int *pipefd, t_tlist *tokken)
{
	if (!(*val)->cmd)
		exit(EXIT_FAILURE);
	if ((*val)->fd_in != -1)
	{
		close(pipefd[1]);
		if (dup2((*val)->fd_in, STDIN_FILENO) == -1)
			error("in dup2 failed", 2);
		close(pipefd[0]);
		close((*val)->fd_in);
	}
	if ((*val)->fd_out != -1)
	{
		close(pipefd[0]);
		if (dup2((*val)->fd_out, STDOUT_FILENO) == -1)
			error("out dup2 failed", 2);
		close(pipefd[1]);
		close((*val)->fd_out);
	}
	if (ft_builtin(tokken, envlist, *val))
		exit(0);
	execute_cmd((*val)->cmd, envlist);
	exit(EXIT_FAILURE);
}
