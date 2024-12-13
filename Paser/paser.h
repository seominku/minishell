/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 02:30:10 by mku               #+#    #+#             */
/*   Updated: 2024/12/13 23:54:44 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASER_H
# define PASER_H

typedef struct s_here_val	t_here_val;
typedef struct s_envlist	t_envlist;
typedef struct s_tlist		t_tlist;
typedef struct s_qlist		t_qlist;
typedef struct s_val		t_val;

//ft_paser.c
void	ft_paser_func(t_tlist **tokken, t_val **val);
void	ft_before_fork(t_tlist *tokken, int (*pipefd)[2]);
void	ft_wait_pipe(t_val **val, pid_t pid);
int		ft_after_redir(t_tlist *tokken);
void	ft_paser_manager(t_tlist *tokken, t_envlist **envlist, t_val **val);
//ft_paser_utils.c
void	error(char *s, int num);
void	ft_val_set(t_val **val);
void	ft_dup(t_val **val, t_envlist *envlist, int *pipefd, t_tlist *tokken);
//ft_paser_util_redir.c
void	ft_find_redir(t_tlist **tokken, t_val **val);
void	ft_redir_open(t_tlist *lst, t_val **val, t_tlist **tokken);
void	ft_redir_out(t_tlist *lst, t_val **val, t_tlist **tokken);
void	ft_redir_add(t_tlist *lst, t_val **val, t_tlist **tokken);
void	ft_redir_here(t_tlist *lst, t_val **val, t_tlist **tokken);
//ft_paser_util_redir_norm.c
void	ft_redir_open_util(t_tlist **tokken);
void	ft_redir_out_util(t_tlist **tokken);
void	ft_redir_add_util(t_tlist **tokken);
void	ft_redir_here_util(t_tlist **tokken);
//ft_paser_util_pipe.c
void	ft_find_pipe(t_tlist *tokken, t_val *val, int *pipefd);
int		ft_next_pipe(t_tlist *tokken);
//ft_paser_util_here.c
void	ft_here_util(t_here_val *here_val, t_tlist *tokken, t_val **val);
void	ft_here_free_set(t_here_val *here_val, t_tlist **tokken);
void	ft_push_doc(t_tlist **tokken, t_val **val);
void	ft_heredoc(t_tlist **tokken, t_val **val);
//ft_paser_util_here_first.c
void	ft_first_heredoc(t_tlist **tokken, t_val **val);
void	ft_here_first_util(t_here_val *here_val, t_tlist *tokken, t_val **val);
void	ft_here_free_first_set(t_here_val *here_val, t_tlist **tokken);
void	ft_push_first_doc(t_tlist **tokken, t_val **val);
//ft_paser_util_here_ex.c
void	ft_here_ex_norm(t_here_val *here_val, int i);
void	ft_here_ex_norm_second(t_here_val *here_val);
void	ft_here_ex(t_here_val *here_val);
//ft_paser_util_exe.c
void	free_path(char **paths);
void	ft_find_cmd(t_tlist *tokken, t_val **val);
char	*store_path(t_envlist *envlist);
char	*find_path(char *argv, const char *env);
void	execute_cmd(t_tlist *tokken, t_envlist *envlist);
//ft_paser_util_exe_norm.c
void	ft_excute_cmd_util_one(t_tlist *tokken, int *arg_count);
void	ft_excute_cmd_util_two(t_tlist *tokken, int arg_count, char **argv);
void	ft_find_path_set(char *paths, char **path, char *command);
//ft_paser_man_util.c
void	ft_move_token(t_tlist **tokken);
void	ft_parents_process(t_val **val, int (*pipefd)[2], pid_t pid);
void	ft_child_process(t_tlist *tokken, t_val **val, \
int (*pipefd)[2], t_envlist *envlist);
void	ft_wait_child(t_val **val, int *status);
//ft_paser_here_util.c
void	ft_here_child(t_tlist **tokken, t_val **val, int *here_flag);
void	ft_here_parents(t_val **val);
int		ft_find_here(t_tlist *tokken);
void	ft_heredoc_change(t_tlist **tokken);
void	ft_heredoc_ex(t_tlist **tokken, t_val **val, int *here_flag);
//ft_paser_func.c
int		ft_before_manager(t_tlist **tokken, t_envlist **envlist, t_val **val);
#endif