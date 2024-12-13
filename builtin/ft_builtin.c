/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:23:07 by mku               #+#    #+#             */
/*   Updated: 2024/12/13 19:36:57 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

int	ft_builtin(t_tlist *tokken, t_envlist **envlist, t_val *val)
{
	int	pipe;

	pipe = 1;
	if (builtin_cd(tokken, *envlist, val))
		return (COMPLETE);
	if (builtin_export(tokken, *envlist, val))
		return (COMPLETE);
	if (builtin_env(tokken, *envlist, val))
		return (COMPLETE);
	if (builtin_pwd(tokken, val))
		return (COMPLETE);
	if (builtin_exit(tokken, val, *envlist, pipe))
		return (COMPLETE);
	if (builtin_echo(tokken, val))
		return (COMPLETE);
	if (builtin_unset(tokken, envlist, val))
		return (COMPLETE);
	return (FALSE);
}

int	ft_no_pipe_builtin(t_tlist *tokken, t_envlist **envlist, t_val *val)
{
	t_tlist	*list;
	int		pipe;

	list = tokken;
	while (list != NULL)
	{
		if (list->node_type == N_PIPE)
			return (0);
		if (!ft_strncmp(list->content, "export", 6) && \
		list->next != NULL && list->next->node_type == N_RED && \
		ft_strlen(list->content) == 6)
			return (0);
		list = list->next;
	}
	pipe = 0;
	if (builtin_cd(tokken, *envlist, val))
		return (COMPLETE);
	if (builtin_export(tokken, *envlist, val))
		return (COMPLETE);
	if (builtin_unset(tokken, envlist, val))
		return (COMPLETE);
	if (builtin_exit(tokken, val, *envlist, pipe))
		return (COMPLETE);
	return (FALSE);
}
