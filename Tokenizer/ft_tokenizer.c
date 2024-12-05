/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:25:52 by seojang           #+#    #+#             */
/*   Updated: 2024/12/05 20:26:44 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "../Utils/utils.h"
#include "ft_tokenizer.h"

static void	ft_in_pipe(char *line, t_tokken_list **tokken, t_envlist *envlist);
static char	*ft_alpha_digit(char *line, int *i);
static char	*ft_red_check(char *line, int *i);

void	ft_tokenizer(char *line, t_envlist *envlist)
{
	t_tokken_list	*tokken;
	t_tokken_list	*lst;
	int				i;

	i = 0;
	tokken = NULL;
	ft_qoute_check(line);
	ft_in_pipe(line, &tokken, envlist);
	lst = tokken;
	while (lst != NULL)
	{
		printf("ptr[%d] = %s          %d\n", i, lst->content, lst->node_type);
		lst = lst->next;
		i++;
	}
	ft_lstclear(&tokken);
}

static void	ft_in_pipe(char *line, t_tokken_list **tokken, t_envlist *envlist)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<' || line[i] == '>')
			ft_lstadd_back(tokken, ft_lstnew(ft_red_check(line, &i), N_RED));
		else if (line[i] == '|')
			ft_lstadd_back(tokken, ft_lstnew(ft_strdup("|"), N_PIPE));
		else if (line[i] == '\'')
			ft_lstadd_back(tokken, \
			ft_lstnew(ft_single_qoute_check(line, &i, envlist), N_WORD));
		else if (line[i] == '\"')
			ft_lstadd_back(tokken, \
			ft_lstnew(ft_double_qoute_check(line, &i, envlist), N_WORD));
		else if (ft_is_alpha(line[i]) || ft_is_digit(line[i]))
			ft_lstadd_back(tokken, ft_lstnew(ft_alpha_digit(line, &i), N_PIPE));
		else if (line[i] == ' ' || line[i] == '\t')
		{
			i++;
			continue ;
		}
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
