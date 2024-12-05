/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:45:45 by mku               #+#    #+#             */
/*   Updated: 2024/12/01 15:31:57 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "builtin.h"
#include "../String/ft_string.h"

int	builtin_pwd(t_tokken_list *tokken)
{
	t_tokken_list	*list;
	char			*pwd;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "pwd", 3))
		{
			pwd = getcwd(NULL, 0);
			write(1, pwd, ft_strlen(pwd));
			write(1, "\n", 2);
			free(pwd);
			return (1);
		}
		list = list->next;
	}
	return (0);
}
