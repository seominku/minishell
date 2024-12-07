/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:59:56 by seojang           #+#    #+#             */
/*   Updated: 2024/12/08 02:44:00 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	handler_here(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_flag = 1;
		write(1, "\n", 1);
		exit(1);
	}
}

void	handler(int sig)
{
	if (sig != SIGINT)
		return ;
	g_signal_flag = 1;
	write(1, "minishell>\n", 11);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	main_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_DFL);
	signal(SIGINT, handler);
}

void	ft_siganl_set(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGQUIT, handler_quit);
	signal(SIGINT, SIG_IGN);
}