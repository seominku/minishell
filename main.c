/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:02:13 by seojang           #+#    #+#             */
/*   Updated: 2024/11/25 22:01:17 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"
#include "String/ft_string.h"

void	handler(int sig)
{
	if (sig != SIGINT)
		return ;
	write(1, "minishell>^C\n", 13);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	get_envlist(char **envp, t_envlist **envlist)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
			ft_lstadd_back(envlist, ft_lstnew(ft_strdup(envp[i]), N_ENV));
		i++;
	}
}

int main(int ac, char **av, char **envp)
{
	char	*line;
	t_envlist	*envlist;

	envlist = NULL;
	get_envlist(envp, &envlist);
	line = NULL;
	(void)ac;
	(void)av;
	signal(SIGINT,handler);
	while (1)
	{
		line = readline("minishell>");
		if (!ft_strlen(line))
			continue ;
		if (line)
		{
			add_history(line);
			ft_tokenizer(line, envp, envlist);
			free(line);
			line = NULL;
		}
	}
	return (0);
}