/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:25:52 by seojang           #+#    #+#             */
/*   Updated: 2024/12/10 18:25:18 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static void	ft_in_pipe(char *line, \
t_tlist **tokken, t_envlist *envlist, t_val *val);
static char	*ft_alpha_digit(char *line, int *i);
static char	*ft_red_check(char *line, int *i);
static void	change_wave(t_tlist *tokken, t_val *val);

t_tlist	*ft_tokenizer(char *line, t_envlist *envlist, t_val *val)
{
	t_tlist	*tokken;

	tokken = NULL;
	if(ft_qoute_check(line, val))
		return (NULL);
	ft_in_pipe(line, &tokken, envlist, val);
	if (!tokken)
	{
		val->exit_code = 0;
		return (NULL);
	}
	change_wave(tokken, val);
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
t_tlist **tokken, t_envlist *envlist, t_val *val)
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
		else if (line[i] == '$')
			ft_lstadd_back(tokken, \
			ft_lstnew(ft_export_ptr(line, &i, envlist, val), N_WORD));
		else if (ft_is_alpha(line[i]) || ft_is_digit(line[i]))
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
		if (line[*i] == '|')
			break ;
		if (line[*i] == '<')
			break ;
		if (line[*i] == '>')
			break ;
		if (line[*i] == ' ')
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
	{
		write(2, "REDIRECTION_ERROR\n", 18);
		exit(1);
	}
	return (ptr);
}

static void	change_wave(t_tlist *tokken, t_val *val)
{
	t_tlist	*list;

	list = tokken;
	while (list != NULL)
	{
		if (list->node_type == N_WORD)
		{
			if (list->content[0] == '~' && list->content[1] == '\0')
			{
				free(list->content);
				list->content = ft_strdup(val->home);
			}
		}
		list = list->next;
	}
}
