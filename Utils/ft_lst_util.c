/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:47:34 by seojang           #+#    #+#             */
/*   Updated: 2024/12/10 18:25:18 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../ms_test.h"

t_tlist	*ft_lstnew(char *content, t_node_type type)
{
	t_tlist	*p;

	p = (t_tlist *)malloc(sizeof(t_tlist));
	if (!p)
		return (NULL);
	p->content = content;
	p->node_type = type;
	p->next = (NULL);
	return (p);
}

void	ft_lstadd_back(t_tlist **lst, t_tlist *new)
{
	t_tlist	*temp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_lstclear(t_tlist **lst)
{
	t_tlist	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->content);
		free(temp);
	}
	*lst = (NULL);
}

char	*join_list(t_qlist *qlist)
{
	char	*result;
	t_qlist	*list;

	result = ft_strdup("");
	list = qlist;
	while (list != NULL)
	{
		result = ft_strjoin(result, list->content);
		list = list->next;
	}
	return (result);
}
