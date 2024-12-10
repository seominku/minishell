/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:41:39 by seojang           #+#    #+#             */
/*   Updated: 2024/12/08 18:07:56 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

static char	*ft_export_push(char *temp, t_envlist *envlist);
static char	*find_env_var(char *temp, t_envlist *envlist);
static int	find_equal(char *content, char *content2);

char	*ft_export_ptr(char *line, int *i, t_envlist *envlist, t_val *val)
{
	char	*temp;
	char	*ret;
	int		first_num;

	first_num = ++(*i);
	if (line[*i] == '?')
	{
		ret = ft_itoa(val->exit_code);
		return (ret);
	}
	while (line[*i])
	{
		if (line[*i + 1] == ' ' || line[*i + 1] == '\t' || \
		line[*i + 1] == '"' || line[*i + 1] == '\0' || line[*i + 1] == '$')
		{
			temp = ft_substr(line, first_num, *i + 1 - first_num);
			ret = ft_export_push(temp, envlist);
			free(temp);
			break ;
		}
		(*i)++;
	}
	return (ret);
}

static char	*ft_export_push(char *temp, t_envlist *envlist)
{
	char	*content;
	char	*result;
	int		i;

	i = 0;
	content = find_env_var(temp, envlist);
	if (content == NULL)
		return (ft_strdup(""));
	while (content[i] != '\0' && content[i] != '=')
		i++;
	if (content[i] == '=')
		i++;
	result = ft_substr(content, i, ft_strlen(content) - i);
	free(content);
	return (result);
}

static char	*find_env_var(char *temp, t_envlist *envlist)
{
	t_envlist	*list;
	int			equal_place;

	list = envlist;
	while (list != NULL)
	{
		equal_place = find_equal(list->content, temp);
		if (!strncmp(list->content, temp, equal_place))
			return (ft_strdup(list->content));
		list = list->next;
	}
	return (NULL);
}

static int	find_equal(char *content, char *content2)
{
	int	c_len;
	int	c2_len;

	c_len = 0;
	while (content[c_len] != '\0' && content[c_len] != '=')
		c_len++;
	c2_len = ft_strlen(content2);
	if (c_len > c2_len)
		return (c_len);
	else
		return (c2_len);
}
