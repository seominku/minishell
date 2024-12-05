/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:03:44 by mku               #+#    #+#             */
/*   Updated: 2024/12/03 18:34:17 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

//ft_signal
void	set_signal_quit_ig(void);
void	set_signal_quit_ex(void);
void	set_signal_int_ig(void);
void	set_signal_int_ex(void);
void	set_signal(void);
//ft_sig_handler
void	handler_quit(int sig);
void	handler_int(int sig);
void	handler(int sig);
void	handler_here(int sig);
void	handler_fork(int sig);

#endif