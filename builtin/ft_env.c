/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:59:22 by mku               #+#    #+#             */
/*   Updated: 2024/12/13 18:47:15 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	print_env(t_envlist *envlist);

int	builtin_env(t_tlist *tokken, t_envlist *envlist, t_val *val)
{
	t_tlist	*list;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "env", 3) && \
		ft_strlen(list->content) == 3)
		{
			print_env(envlist);
			val->exit_code = BUILTIN_COMPLATE;
			return (COMPLETE);
		}
		list = list->next;
	}
	return (FAIL_TO_FIND_CMD);
}

void	print_env(t_envlist *envlist)
{
	t_envlist	*list;
	char		*temp;

	list = envlist;
	while (list != NULL)
	{
		if (list->node_type == N_ENV)
		{
			temp = ft_strjoin(ft_strdup(list->content), "\n");
			write(1, temp, ft_strlen(temp));
			free(temp);
		}
		list = list->next;
	}
}
