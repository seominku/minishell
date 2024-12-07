/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser_util_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:08:54 by seojang           #+#    #+#             */
/*   Updated: 2024/12/08 02:11:34 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	ft_find_pipe(t_tlist *tokken, t_val *val, int *pipefd)
{
	t_tlist	*lst;

	lst = tokken;
	while (lst)
	{
		if (lst->content && ft_strncmp(lst->content, "|", 1) == 0)
		{
			val->fd_out = pipefd[1];
			return ;
		}
		lst = lst->next;
	}
}

int	ft_next_pipe(t_tlist *tokken)
{
	t_tlist	*head;

	head = tokken;
	while (tokken && tokken->next != NULL)
	{
		if (tokken->content && ft_strncmp(tokken->content, "|", 1) == 0)
		{
			tokken = head;
			return (1);
		}
		tokken = tokken->next;
	}
	tokken = head;
	return (0);
}
