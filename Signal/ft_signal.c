/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:59:56 by seojang           #+#    #+#             */
/*   Updated: 2024/12/03 18:34:11 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	set_signal_quit_ig(void)
// 현재 프로세스가 자식 프로세스를 생성하고 종료를 기다리는동안의 시그널 상태로 설정
{
	//signal(SIGINT, SIG_IGN); // ctrl+c 시그널 입력시 시그널을 무시함
	signal(SIGQUIT, SIG_IGN); // ctrl+\ 시그널 입력시 시그널을 무시함
}

void	set_signal_quit_ex(void)
// 현재 프로세스가 시그널 동작을 기본 설정대로 동작하도록 원상복귀시켜줌
{
	//signal(SIGINT, SIG_DFL); // ctrl+c 시그널 입력시 동작을 기본 시그널 설정으로 되돌림
	signal(SIGQUIT, SIG_DFL); // ctrl+\ 시그널 입력시 동작을 기본 시그널 설정으로 되돌림
}

void	set_signal_int_ig(void)
// 현재 프로세스가 자식 프로세스를 생성하고 종료를 기다리는동안의 시그널 상태로 설정
{
	signal(SIGINT, SIG_IGN); // ctrl+c 시그널 입력시 시그널을 무시함
	//signal(SIGQUIT, SIG_IGN); // ctrl+\ 시그널 입력시 시그널을 무시함
}

void	set_signal_int_ex(void)
// 현재 프로세스가 시그널 동작을 기본 설정대로 동작하도록 원상복귀시켜줌
{
	signal(SIGINT, SIG_DFL); // ctrl+c 시그널 입력시 동작을 기본 시그널 설정으로 되돌림
	//signal(SIGQUIT, SIG_DFL); // ctrl+\ 시그널 입력시 동작을 기본 시그널 설정으로 되돌림
}

void	set_signal(void)
{
	set_signal_quit_ig();
	set_signal_int_ex();
}

