/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:03:44 by mku               #+#    #+#             */
/*   Updated: 2024/12/08 02:31:25 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

//ft_signal
void	handler_here(int sig);
void	handler(int sig);
void	main_signal(void);
void	ft_siganl_set(void);
//ft_sig_handler
void	handler_int(int sig);
void	handler_quit(int sig);
#endif