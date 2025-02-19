/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qoute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:35:12 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 19:26:55 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static char	*split_qoute(char *content, t_envlist *envlist, t_val *val);

void	qoute_check(t_tlist *tokken, t_envlist *envlist, t_val *val)
{
	t_tlist	*list;

	list = tokken;
	while (list != NULL)
	{
		if (list->node_type == N_WORD)
			list->content = split_qoute(list->content, envlist, val);
		list = list->next;
	}
}

static char	*split_qoute(char *content, t_envlist *envlist, t_val *val)
{
	t_qlist	*qlist;
	char	*result;
	int		start;
	int		end;

	end = 0;
	start = 0;
	qlist = NULL;
	while (content[end] != '\0')
	{
		if (content[end] != '\"' && content[end] != '\'')
			alpha_q(&start, &end, &qlist, content);
		if (content[end] == '\"')
			double_q(&start, &end, &qlist, content);
		if (content[end] == '\'')
			single_q(&start, &end, &qlist, content);
		if (content[end] != '\0')
			end++;
	}
	qoute_export(qlist, envlist, val);
	result = join_list(qlist);
	ft_qlstclear(&qlist);
	free(content);
	return (result);
}
