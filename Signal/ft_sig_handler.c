/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:02:57 by mku               #+#    #+#             */
/*   Updated: 2024/12/03 17:59:23 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>

void	handler_quit(int sig)
{
	if (sig == SIGQUIT)
	{
		write(1, "Quit (core dumped)\n", 19);
		return ;
	}
}

void	handler_int(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		return ;
	}
}

void	handler(int sig)
{
	if (sig != SIGINT)
		return ;
	write(1, "minishell>\n", 11);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handler_here(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		exit(1);
	}
}

void	handler_fork(int sig)
{
	if (sig != SIGINT)
		return ;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}