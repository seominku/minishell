/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:35:12 by seojang           #+#    #+#             */
/*   Updated: 2024/12/08 02:23:57 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	handler_quit(int sig)
{
	if (sig == SIGQUIT)
	{
		write(1, "Quit (core dumped)\n", 19);
		g_signal_flag = 1;
		return ;
	}
}

void	handler_int(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_signal_flag = 2;
		return ;
	}
}
