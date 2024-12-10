/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:23:07 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 15:17:16 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

int	ft_builtin(t_tokken_list *tokken, t_envlist *envlist, t_val *val)
{
	if (builtin_cd(tokken, envlist, val))
		return (COMPLETE);
	if (builtin_export(tokken, envlist, val))
		return (COMPLETE);
	if (builtin_env(tokken, envlist, val))
		return (COMPLETE);
	if (builtin_pwd(tokken, val))
		return (COMPLETE);
	if (builtin_exit(tokken, val, envlist))
		return (COMPLETE);
	if (builtin_echo(tokken, val))
		return (COMPLETE);
	if (builtin_unset(tokken, envlist, val))
		return (COMPLETE);
	return (FALSE);
}

int	ft_no_pipe_builtin(t_tokken_list *tokken, t_envlist *envlist, t_val *val)
{
	t_tokken_list	*list;

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
	if (builtin_cd(tokken, envlist, val))
		return (COMPLETE);
	if (builtin_export(tokken, envlist, val))
		return (COMPLETE);
	if (builtin_unset(tokken, envlist, val))
		return (COMPLETE);
	if (builtin_exit(tokken, val, envlist))
		return (COMPLETE);
	return (FALSE);
}
