/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:07:26 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 18:27:24 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define COMPLETE 1
# define FAIL_TO_FIND_CMD 0
# define BUILTIN_ERROR 1
# define BUILTIN_COMPLATE 0
# define TRUE 1
# define FALSE 0
# define ARG_ERROR 1
# define NO_OPTION 0
//export
# define NO_IDENTYFIER 1
# define NAME_ONLY 2
# define NAME_AND_EQUAL 3
# define FULL_ENV 4

typedef struct s_tlist t_tlist,t_envlist;

//change_directory
int			builtin_cd(t_tlist *tokken, t_envlist *envlist, t_val *val);
char		*find_home_dir(t_envlist *envlist, t_val *val);
void		change_oldpwd(t_envlist *envlist, char *path);
void		change_pwd(t_envlist *envlist);
void		cd_error(char *path, t_val *val, int *flag);
//print_env
int			builtin_env(t_tlist *tokken, t_envlist *envlist, t_val *val);
//pwd
int			builtin_pwd(t_tlist *tokken, t_val *val);
void		print_env(t_envlist *envlist);
//export
int			builtin_export(t_tlist *tokken, \
t_envlist *envlist, t_val *val);
void		variable_error(char *content, int *flag);
t_envlist	*find_env(char *content, t_envlist *envlist);
char		**sort_export(t_envlist *envlist);
void		print_export(char **env);
int			check_special(char *content);
//exit
int			builtin_exit(t_tlist *tokken, t_val *val, t_envlist *envlist);
//builtin
int			ft_builtin(t_tlist *tokken, t_envlist *envlist, t_val *val);
int			check_arg(t_tlist *tokken);
int			ft_no_pipe_builtin(t_tlist *tokken, \
t_envlist *envlist, t_val *val);
//echo
int			builtin_echo(t_tlist *tokken, t_val *val);
//unset
int			builtin_unset(t_tlist *tokken, \
t_envlist *envlist, t_val *val);
#endif
