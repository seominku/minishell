/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:02:13 by seojang           #+#    #+#             */
/*   Updated: 2024/12/05 20:35:28 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"
#include "Tokenizer/ft_tokenizer.h"
#include "Utils/utils.h"

static void	loop_prompt(t_envlist *envlist);
static void	get_envlist(char **envp, t_envlist **envlist);
static int	check_line(char *line);
void	set_error_code(int	code);

int main(int ac, char **av, char **envp)
{
	t_envlist *envlist;

	envlist = NULL;
	(void)ac;
	(void)av;
	get_envlist(envp, &envlist);
	set_error_code(1);
	loop_prompt(envlist);
	return (0);
}

static void	loop_prompt(t_envlist *envlist)
{
	char	*line;

	line = NULL;
	while (1)
	{
		set_signal();
		signal(SIGINT,handler);
		line = readline("minishell>");
		check_line(line);
		if (!ft_strlen(line))
			continue ;
		if (line)
		{
			add_history(line);
			ft_tokenizer(line, envlist);
			free(line);
			line = NULL;
		}
	}
	return ;
}

static void	get_envlist(char **envp, t_envlist **envlist)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
			ft_lstadd_back(envlist, ft_lstnew(ft_strdup(envp[i]), N_ENV));
			if (!ft_strncmp(envp[i], "HOME", 4))
				ft_lstadd_back(envlist, ft_lstnew(ft_strjoin(ft_strdup("temp"), \
				ft_strdup(envp[i])), N_NULL));
		i++;
	}
}

static int	check_line(char *line)
{
	if (line == NULL)
	{
		write(1, "exit\n", 5);
		exit(0) ;
	}
}

void	set_error_code(int	code)
{
	static int	prev_code;
	static int	now_code;

	prev_code = now_code;
	now_code = code;
}