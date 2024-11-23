/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:23:30 by mku               #+#    #+#             */
/*   Updated: 2024/11/23 03:38:21 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "../String/ft_string.h"

int	builtin_exit(t_tokken_list *tokken, t_envlist *envlist)
{
	t_tokken_list	*list;
	char			*pwd;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "exit", 4))
			exit(0);
		list = list->next;
	}
	return (0);
}
