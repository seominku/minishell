/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:02:13 by seojang           #+#    #+#             */
/*   Updated: 2024/12/10 18:25:18 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"

volatile int	g_signal_flag;

static void	get_envlist(char **envp, t_envlist **envlist, t_val *val);
static void	main_set(char **line, t_val *val);
static void	loop_prompt(char *line, t_envlist *envlist, t_val *val);
static void	line_null(void);
void	flag_check(t_val *val);

int main(int ac, char **av, char **envp)
{
	char	*line;
	t_val	val;
	t_envlist		*envlist;

	(void)ac;
	(void)av;
	envlist = NULL;
	get_envlist(envp, &envlist, &val);
	main_set(&line, &val);
	while (1)
	{
		loop_prompt(line, envlist, &val);
	}
	return (0);
}

static void	get_envlist(char **envp, t_envlist **envlist, t_val *val)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
			ft_lstadd_back(envlist, ft_lstnew(ft_strdup(envp[i]), N_ENV));
			if (!ft_strncmp(envp[i], "HOME", 4))
				val->home = envp[i] + 5;
		i++;
	}
}

static void	main_set(char **line, t_val *val)
{
	(*line) = NULL;
	g_signal_flag = 0;
	val->exit_code = 0;
}

static void	loop_prompt(char *line, t_envlist *envlist, t_val *val)
{
	t_tlist *tokken;

	main_signal();
	line = readline("minishell>");
	if (line == NULL)
		line_null();
	else if (!ft_strlen(line))
	{
		val->exit_code = 0;
		g_signal_flag = 0;
	}
	else if (line)
	{
		add_history(line);
		tokken = ft_tokenizer(line, envlist, val);
		if (tokken != NULL)
		{
			ft_paser_manager(tokken, envlist, &val);
			ft_lstclear(&tokken);
		}
	}
	free(line);
	line = NULL;
}

static void	line_null(void)
{
	write(1, "exit\n", 5);
	exit(1);
}

void	flag_check(t_val *val)
{
	if (g_signal_flag == 1)
	{
		g_signal_flag = 0;
		val->exit_code = 130;
	}
}