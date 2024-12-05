/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser_util_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:25:40 by seojang           #+#    #+#             */
/*   Updated: 2024/12/03 16:58:32 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"

void	ft_push_doc(t_tokken_list **tokken, t_val *val)
{
	//char	*prev_cmd;
	char	*eof;
	char	*ret;
	char	*temp;
	char	*file;
	char	*doc_name;
	char	*doc_num;
	int		tmpfd;
	int		i;

	i = 0;
	val->doc_num += 1;
	doc_name = ft_strdup("a");
	doc_num = ft_itoa(val->doc_num);
	doc_name = ft_strjoin(doc_name, doc_num);
	free(doc_num);
	file = ft_strdup(doc_name);
	eof = ft_strdup((*tokken)->next->next->content);
	temp = NULL;
	ret = NULL;
	while (1)
	{
		temp = readline(">");
		if (temp && !ft_strncmp(temp, eof, ft_strlen(eof)))
		{
			if (!i)
				ret = ft_strdup("");
			free(temp);
			temp = NULL;
			break ;
		}
		else if (temp == NULL)
		{
			printf("경고 %s가 행의 마지막 열에 없습니다\n", eof);
			if (!i)
				ret = ft_strdup("");
			free(temp);
			temp = NULL;
			break ;
		}
		if (ft_strncmp(temp, "\n", 1))
			temp = ft_strjoin(temp, ft_strdup("\n"));
		if (!ret)
			ret = ft_strdup(temp);
		else
			ret = ft_strjoin(ret, ft_strdup(temp));
		i++;
		free(temp);
		temp = NULL;
	}
	tmpfd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(tmpfd, ret, ft_strlen(ret));
	close(tmpfd);
	//printf("{%s}\n", (*tokken)->next->next->content);
	free((*tokken)->next->next->content);
	(*tokken)->next->next->content = ft_strdup(file);
	free(file);
	free(eof);
	free(ret);
	free(doc_name);
}

void	ft_heredoc(t_tokken_list **tokken, t_val *val)
{
	t_tokken_list	*head;

	head = (*tokken);
	while (*tokken && (*tokken)->next)
	{
		if (!ft_strncmp((*tokken)->next->content, "<<", 2))
			ft_push_doc(tokken, val);
		(*tokken) = (*tokken)->next;
	}
	
	(*tokken) = head;
}

void	ft_push_first_doc(t_tokken_list **tokken, t_val *val)
{
	//char	*prev_cmd;
	char	*eof;
	char	*ret;
	char	*temp;
	char	*file;
	char	*doc_name;
	char	*doc_num;
	int		tmpfd;
	int		i;

	i = 0;
	val->doc_num += 1;
	doc_name = ft_strdup("a");
	doc_num = ft_itoa(val->doc_num);
	doc_name = ft_strjoin(doc_name, doc_num);
	free(doc_num);
	file = ft_strdup(doc_name);
	eof = ft_strdup((*tokken)->next->content);
	temp = NULL;
	ret = NULL;
	while (1)
	{
		temp = readline(">");
		if (temp && !ft_strncmp(temp, eof, ft_strlen(eof)))
		{
			if (!i)
				ret = ft_strdup("");
			free(temp);
			temp = NULL;
			break ;
		}
		else if (temp == NULL)
		{
			printf("경고 %s가 행의 마지막 열에 없습니다\n", eof);
			if (!i)
				ret = ft_strdup("");
			free(temp);
			temp = NULL;
			break ;
		}
		if (ft_strncmp(temp, "\n", 1))
			temp = ft_strjoin(temp, "\n");
		if (!ret)
			ret = ft_strdup(temp);
		else
			ret = ft_strjoin(ret, ft_strdup(temp));
		i++;
		free(temp);
		temp = NULL;
	}
	tmpfd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(tmpfd, ret, ft_strlen(ret));
	close(tmpfd);
	free((*tokken)->next->content);
	(*tokken)->next->content = ft_strdup(file);
	free(file);
	free(eof);
	free(ret);
	free(doc_name);
}

void	ft_first_heredoc(t_tokken_list **tokken, t_val *val)
{
	t_tokken_list	*head;

	head = (*tokken);
	while (*tokken && (*tokken)->next)
	{
		if (!ft_strncmp((*tokken)->content, "<<", 2))
			ft_push_first_doc(tokken, val);
		(*tokken) = (*tokken)->next;
	}
	(*tokken) = head;
}