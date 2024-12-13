/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:25:52 by seojang           #+#    #+#             */
/*   Updated: 2024/12/14 00:26:16 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static void	ft_in_pipe(char *line, t_tlist **tokken);
static char	*ft_alpha_digit(char *line, int *i);
static char	*ft_red_check(char *line, int *i);
static void	change_wave(t_tlist *tokken, t_val *val, \
t_envlist *envlist);

t_tlist	*ft_tokenizer(char *line, t_envlist *envlist, t_val *val)
{
	t_tlist	*tokken;

	tokken = NULL;
	if (ft_qoute_check(line, val))
		return (NULL);
	ft_in_pipe(line, &tokken);
	if (!tokken)
	{
		val->exit_code = 0;
		return (NULL);
	}
	change_wave(tokken, val, envlist);
	if (check_token(tokken, val))
	{
		qoute_check(tokken, envlist, val);
		return (tokken);
	}
	else
	{
		ft_lstclear(&tokken);
		return (NULL);
	}
}

static void	ft_in_pipe(char *line, \
t_tlist **tokken)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<' || line[i] == '>')
			ft_lstadd_back(tokken, ft_lstnew(ft_red_check(line, &i), N_RED));
		else if (line[i] == '|')
			ft_lstadd_back(tokken, ft_lstnew(ft_strdup("|"), N_PIPE));
		else if (line[i] == '$' && line[i + 1] == '\0')
			ft_lstadd_back(tokken, ft_lstnew(ft_strdup("$"), N_WORD));
		else if (line[i] == ' ')
			;
		else
			ft_lstadd_back(tokken, \
			ft_lstnew(ft_alpha_digit(line, &i), N_WORD));
		i++;
	}
}

static char	*ft_alpha_digit(char *line, int *i)
{
	int		start;
	char	*result;

	start = *i;
	while (line[*i] != '\0')
	{
		if (line[*i] == '\"')
		{
			ft_qoute_while(line, i, 34);
			continue ;
		}
		else if (line[*i] == '\'')
		{
			ft_qoute_while(line, i, 39);
			continue ;
		}
		if (line[*i] == '|' || line[*i] == '<' \
		|| line[*i] == '>' || line[*i] == ' ')
			break ;
		(*i)++;
	}
	result = ft_substr(line, start, *i - start);
	(*i)--;
	return (result);
}

static char	*ft_red_check(char *line, int *i)
{
	char	*ptr;

	ptr = NULL;
	if (line[*i] == '<' && line[*i + 1] == '<' && \
	line[*i + 2] != '<' && line[*i + 2] != '>')
	{
		ptr = ft_strdup("<<");
		(*i)++;
	}
	else if (line[*i] == '<' && line[*i + 1] != '<' && line[*i + 1] != '>')
		ptr = ft_strdup("<");
	else if (line[*i] == '>' && line[*i + 1] == '>' && \
	line[*i + 2] != '<' && line[*i + 2] != '>')
	{
		ptr = ft_strdup(">>");
		(*i)++;
	}
	else if (line[*i] == '>' && line[*i + 1] != '<' && line[*i + 1] != '>')
		ptr = ft_strdup(">");
	else
		ptr = ft_strdup("");
	return (ptr);
}

static void	change_wave(t_tlist *tokken, t_val *val, t_envlist *envlist)
{
	t_tlist		*list;
	t_envlist	*env;

	list = tokken;
	while (list != NULL)
	{
		if (list->node_type == N_WORD)
		{
			if (list->content[0] == '~' && list->content[1] == '\0')
			{
				free(list->content);
				env = find_env("HOME", envlist);
				if (env == NULL)
					list->content = ft_strdup(val->home);
				else
					list->content = ft_strdup(env->content + 5);
			}
		}
		list = list->next;
	}
}
