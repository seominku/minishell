/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:47:34 by seojang           #+#    #+#             */
/*   Updated: 2024/11/22 22:48:44 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"

t_tokken_list	*ft_lstnew(char *content, t_node_type type)
{
	t_tokken_list	*p;

	p = (t_tokken_list *)malloc(sizeof(t_tokken_list));
	if (!p)
		return (NULL);
	p -> content = content;
	p -> next = (NULL);
	p -> node_type = type;
	return (p);
}

void	ft_lstadd_back(t_tokken_list **lst, t_tokken_list *new)
{
	t_tokken_list	*temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_lstclear(t_tokken_list **lst)
{
	t_tokken_list	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->content);
		free(temp);
	}
	*lst = (NULL);
}
