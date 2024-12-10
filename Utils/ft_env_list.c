/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:20:09 by seojang           #+#    #+#             */
/*   Updated: 2024/12/10 19:36:11 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

t_envlist	*ft_enlnew(char *content, t_node_type type)
{
	t_envlist	*p;

	p = (t_envlist *)malloc(sizeof(t_envlist));
	if (!p)
		return (NULL);
	p->content = content;
	p->node_type = type;
	p->next = (NULL);
	return (p);
}

void	ft_enladd_back(t_envlist **lst, t_envlist *new)
{
	t_envlist	*temp;

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

void	ft_enlclear(t_envlist **lst)
{
	t_envlist	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->content);
		free(temp);
	}
	*lst = (NULL);
}
