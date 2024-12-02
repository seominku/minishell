/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:23:07 by mku               #+#    #+#             */
/*   Updated: 2024/11/24 20:03:37 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../ms_test.h"
#include "../String/ft_string.h"

int	ft_builtin(t_tokken_list *tokken, t_envlist *envlist)
{
	if (builtin_cd(tokken, envlist))
		return (COMPLETE);
	if (builtin_export(tokken, envlist))
		return (COMPLETE);
	if (builtin_env(tokken, envlist))
		return (COMPLETE);
	if (builtin_pwd(tokken, envlist))
		return (COMPLETE);
	if (builtin_exit(tokken, envlist))
		return (COMPLETE);
	if (builtin_echo(tokken, envlist))
		return (COMPLETE);
	if (builtin_unset(tokken, envlist))
		return (COMPLETE);
	return (FALSE);
}

int	ft_no_pipe_builtin(t_tokken_list *tokken, t_envlist *envlist)
{
	t_tokken_list	*list;

	list = tokken;
	while (list != NULL)
	{
		if (list->node_type == N_PIPE)
			return (0);
		if (!ft_strncmp(list->content, "export", 6) && \
		list->next != NULL && list->next->node_type == N_REDIRECTION)
			return (0);
		list = list->next;
	}
	if (builtin_cd(tokken, envlist))
		return (COMPLETE);
	if (builtin_export(tokken, envlist))
		return (COMPLETE);
	if (builtin_unset(tokken, envlist))
		return (COMPLETE);
	if (builtin_exit(tokken, envlist))
		return (COMPLETE);
}
