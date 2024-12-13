/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:41:55 by mku               #+#    #+#             */
/*   Updated: 2024/12/14 00:17:00 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static char		*check_dollar(char *content, t_envlist *envlist, t_val *val);
static void		export_env(t_qlist *qlist, t_envlist *envlist);
static t_qlist	*sub_content(char *content, t_qlist *qlist, t_val *val);
static void		export_space(t_qlist *node);

void	qoute_export(t_qlist *qlist, t_envlist *envlist, t_val *val)
{
	t_qlist	*list;

	list = qlist;
	while (list != NULL)
	{
		if (list->node_type == N_DOUBLE)
			list->content = check_dollar(list->content, envlist, val);
		list = list->next;
	}
}

static char	*check_dollar(char *content, t_envlist *envlist, t_val *val)
{
	t_qlist		*qlist;
	char		*result;

	qlist = NULL;
	if (content[0] == '$' && content[1] == '\0')
	{
		free(content);
		return (ft_strdup("$"));
	}
	qlist = sub_content(content, qlist, val);
	export_env(qlist, envlist);
	result = join_list(qlist);
	ft_qlstclear(&qlist);
	free(content);
	return (result);
}

static t_qlist	*sub_content(char *content, t_qlist *qlist, t_val *val)
{
	int	start;
	int	end;

	end = 0;
	start = 0;
	while (content[end] != '\0')
	{
		if (content[end] != '$')
			alpha_dollar(&start, &end, &qlist, content);
		else if (content[end] == '$' && content[end + 1] == '?')
		{
			ft_qladd_back(&qlist, ft_qlnew(ft_itoa(val->exit_code), N_WORD));
			end += 2;
			start = end;
		}
		else if (content[end] == '$')
			dollar_q(&start, &end, &qlist, content);
	}
	return (qlist);
}

static void	export_env(t_qlist *qlist, t_envlist *envlist)
{
	t_qlist		*list;
	t_envlist	*env;
	int			i;

	list = qlist;
	while (list != NULL)
	{
		if (list->node_type == N_DOLLAR)
		{
			i = 0;
			env = find_env(list->content, envlist);
			free(list->content);
			if (env == NULL)
				list->content = ft_strdup("");
			else
			{
				while (env->content[i] != '\0' && env->content[i] != '=')
					i++;
				list->content = ft_substr(\
				env->content, i + 1, ft_strlen(env->content));
				export_space(list);
			}
		}
		list = list->next;
	}
}

static void	export_space(t_qlist *node)
{
	char	**sp;
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup("");
	sp = ft_ms_split(node->content, ' ');
	while (sp[i] != NULL)
	{
		temp = ft_strjoin(temp, sp[i]);
		if (sp[i + 1] != NULL)
			temp = ft_strjoin(temp, " ");
		i++;
	}
	free(node->content);
	node->content = temp;
	delete_all_spl(sp);
}
