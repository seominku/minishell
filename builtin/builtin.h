/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:07:26 by mku               #+#    #+#             */
/*   Updated: 2024/11/30 19:57:37 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define COMPLETE 1
# define FAIL_TO_FIND_CMD 0
# define BUILTIN_ERROR 0
# define TRUE 1
# define FALSE 0
# define ARG_ERROR 1
# define NO_OPTION 0
//export
# define NO_IDENTYFIER 1
# define NAME_ONLY 2
# define NAME_AND_EQUAL 3
# define FULL_ENV 4

typedef struct s_tokken_list t_tokken_list,t_envlist;
typedef struct s_exit_status
{
	int	status;
}t_exit_status;
//change_directory
int			builtin_cd(t_tokken_list *tokken, t_envlist *envlist);
char		*find_home_dir(t_envlist *envlist);
void		change_oldpwd(t_envlist *envlist, char *path);
void		change_pwd(t_envlist *envlist, char *path);
//print_env
int			builtin_env(t_tokken_list *tokken, t_envlist *envlist);
//pwd
int			builtin_pwd(t_tokken_list *tokken, t_envlist *envlist);
void		print_env(t_envlist *envlist);
//export
int			builtin_export(t_tokken_list *tokken, t_envlist *envlist);
void		variable_error(char *content);
t_envlist	*find_env(char *content, t_envlist *envlist);
char		**sort_export(t_envlist *envlist);
void		print_export(char **env);
int			check_special(char *content);
//exit
int			builtin_exit(t_tokken_list *tokken, t_envlist *envlist);
//builtin
int			ft_builtin(t_tokken_list *tokken, t_envlist *envlist);
void		cd_error(char *path);
int			check_arg(t_tokken_list *tokken);
int			ft_no_pipe_builtin(t_tokken_list *tokken, t_envlist *envlist);
//echo
int			builtin_echo(t_tokken_list *tokken, t_envlist *envlist);
//unset
int			builtin_unset(t_tokken_list *tokken, t_envlist *envlist);
#endif
