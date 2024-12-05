/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qoute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:25:10 by seojang           #+#    #+#             */
/*   Updated: 2024/12/05 20:28:27 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "ft_tokenizer.h"

static char	*other_word(int *i, char *line, char *ptr, t_envlist *envlist);
static char	*other_qoute(int *i, char *line, char *ptr, t_envlist *envlist);

char	*ft_single_qoute_check(char *line, int *i, t_envlist *envlist)
{
	int		first_num;
	char	*ptr;

	(*i)++;
	ptr = NULL;
	first_num = *i;
	while (line[*i])
	{
		if (line[*i] == '\'')
		{
			ptr = ft_substr(line, first_num, (*i) - first_num);
			break ;
		}
		(*i)++;
	}
	ptr = other_word(i, line, ptr, envlist);
	return (ptr);
}

char	*ft_double_qoute_check(char *line, int *i, t_envlist *envlist)
{
	int		first_num;
	char	*ptr;
	char	*temp;

	ptr = NULL;
	(*i)++;
	first_num = *i;
	temp = NULL;
	if (line[*i] == '\"')
		return (ft_strdup(""));
	while (line[*i])
	{
		if (line[*i] == '\"')
		{
			if (!ptr && first_num != *i)
			{
				ptr = ft_substr(line, first_num, (*i) - first_num);
				break ;
			}
			temp = ft_substr(line, first_num, (*i) - first_num);
			ptr = ft_strjoin(ptr, temp);
			free(temp);
			break ;
		}
		else if (line[*i] == '$')
		{
			if (first_num < *i)
			{
				if (!ptr)
					ptr = ft_substr(line, first_num, (*i) - first_num);
				else
				{
					temp = ft_substr(line, first_num, (*i) - first_num);
					ptr = ft_strjoin(ptr, temp);
					temp = NULL;
				}
			}
			if (!ptr)
			{
				ptr = ft_strdup(ft_export_ptr(line, i, envlist));
				first_num = (*i) + 1;
			}
			else
			{
				temp = ft_strdup(ft_export_ptr(line, i, envlist));
				ptr = ft_strjoin(ptr, temp);
				free(temp);
				first_num = (*i) + 1;
			}
		}
		(*i)++;
	}
	ptr = other_word(i, line, ptr, envlist);
	return (ptr);
}

static char	*other_word(int *i, char *line, char *ptr, t_envlist *envlist)
{
	char	*line_temp;

	if (line[*i] == '\"' || line[*i] == '\'')
		(*i)++;
	while (line[*i] != '\0' && line[*i] != ' ')
	{
		if (line[*i] == '<' || line[*i] == '>' || line[*i] == '|')
		{
			(*i)--;
			break ;
		}
		if (line[*i] == '\'' || line[*i] == '\"')
			ptr = other_qoute(i, line, ptr, envlist);
		else
		{
			line_temp = (char *)malloc(sizeof(char) * 2);
			line_temp[0] = line[*i];
			line_temp[1] = '\0';
			ptr = ft_strjoin(ptr, line_temp);
			free(line_temp);
		}
		(*i)++;
	}
	(*i)--;
	return (ptr);
}

static char	*other_qoute(int *i, char *line, char *ptr, t_envlist *envlist)
{
	char	*temp;

	if (line[*i] == '\'')
	{
		temp = ft_single_qoute_check(line, i, envlist);
		ptr = ft_strjoin(ptr, temp);
	}
	else if (line[*i] == '\"')
	{
		temp = ft_double_qoute_check(line, i, envlist);
		ptr = ft_strjoin(ptr, temp);
	}
	return (ptr);
}
