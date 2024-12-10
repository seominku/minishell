/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qoute_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:27:25 by seojang           #+#    #+#             */
/*   Updated: 2024/12/10 19:36:16 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

t_qlist	*ft_qlnew(char *content, t_node_type type)
{
	t_qlist	*p;

	p = (t_qlist *)malloc(sizeof(t_qlist));
	if (!p)
		return (NULL);
	p->content = content;
	p->node_type = type;
	p->next = (NULL);
	return (p);
}

void	ft_qladd_back(t_qlist **lst, t_qlist *new)
{
	t_qlist	*temp;

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

void	ft_qlclear(t_qlist **lst)
{
	t_qlist	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->content);
		free(temp);
	}
	*lst = (NULL);
}
