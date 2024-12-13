/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:03:45 by mku               #+#    #+#             */
/*   Updated: 2024/12/14 00:18:22 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "utils.h"

static int	count_env(t_envlist *envlist);
static char	**insert_char(t_envlist *envlist, char **result, int length);

char	**convert_env(t_envlist *envlist)
{
	int		length;
	char	**result;

	length = count_env(envlist);
	result = (char **)malloc(sizeof(char *) * (length + 1));
	if (result == NULL)
		return (NULL);
	result = insert_char(envlist, result, length);
	return (result);
}

void	delete_all_spl(char **spl)
{
	int	i;

	i = 0;
	while (spl[i] != NULL)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

static int	count_env(t_envlist *envlist)
{
	int			count;
	t_envlist	*list;

	list = envlist;
	count = 0;
	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	return (count);
}

static char	**insert_char(t_envlist *envlist, char **result, int length)
{
	t_envlist	*list;
	int			count;

	count = 0;
	list = envlist;
	while (count < length)
	{
		result[count] = ft_strdup(list->content);
		list = list->next;
		count++;
	}
	result[count] = NULL;
	return (result);
}
