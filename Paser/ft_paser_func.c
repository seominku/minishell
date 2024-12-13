/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:46:02 by seojang           #+#    #+#             */
/*   Updated: 2024/12/13 20:37:57 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

int	ft_before_manager(t_tlist **tokken, t_envlist **envlist, t_val **val)
{
	int	here_flag;

	(*val)->prev_pipe = -1;
	here_flag = 0;
	if (!here_flag && ft_find_here(*tokken))
	{
		ft_heredoc_ex(tokken, val, &here_flag);
		if ((*val)->exit_code == 130)
			return (1);
	}
	if (ft_no_pipe_builtin(*tokken, envlist, *val))
		return (1);
	return (0);
}
