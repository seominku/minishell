/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:45:45 by mku               #+#    #+#             */
/*   Updated: 2024/12/12 19:29:15 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

int	builtin_pwd(t_tlist *tokken, t_val *val)
{
	t_tlist	*list;
	char	*pwd;

	list = tokken;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "pwd", 3) && \
		ft_strlen(list->content) == 3)
		{
			pwd = getcwd(NULL, 0);
			pwd = ft_strjoin(pwd, "\n");
			write(1, pwd, ft_strlen(pwd));
			free(pwd);
			val->exit_code = BUILTIN_COMPLATE;
			return (1);
		}
		list = list->next;
	}
	return (0);
}
