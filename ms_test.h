#ifndef MS_TEST_H
# define MS_TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include "Signal/ft_signal.h"
# include "String/ft_string.h"



typedef struct s_flag
{
	int	pipe;
}	t_flag;

typedef enum e_node_type
{
	N_WORD,
	N_PIPE,
	N_RED,
	N_ENV,
	N_EXPORT_ENV,
	N_NULL
}				t_node_type;

typedef struct s_tokken_list
{
	char			*content;
	t_node_type	node_type;
	struct s_tokken_list	*next;
}					t_tokken_list, t_envlist;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_val
{
	int	pipe_flag;
	int	prev_pipe;
	int	fd_in;
	int	fd_out;
	int	heredoc_fd;
	int	tokken_len;
	int	redir_flag;
	int	tmp_out;
	char	*heredoc;
	int		doc_num;
	int		here_sig;
	t_tokken_list	*head;
	t_tokken_list	*cmd;
}			t_val;

typedef struct s_word
{
	int			count;
	int			flag;
	int			single_quote_flag;
	int			double_quote_flag;
	int			quote_flag;
	const char	*start;
	const char	*end;
}			t_word;

//ft_paser
char	*store_path(char **envp);
char	*find_path(char *argv, const char *env);
void	ft_val_set(t_val *val);
void	error(char *s, int num);
void	execute_cmd(t_tokken_list *tokken, char **envp);
void	ft_paser_manager(t_tokken_list *tokken, char **envp);
void	free_path(char **paths);

//redir
void	ft_redir_open(t_tokken_list *lst, t_val *val, t_tokken_list **tokken);
void	ft_redir_out(t_tokken_list *lst, t_val *val, t_tokken_list **tokken);
void	ft_redir_add(t_tokken_list *lst, t_val *val, t_tokken_list **tokken);
void	ft_redir_here(t_tokken_list *lst, t_val *val, t_tokken_list **tokken);

void	ft_find_cmd(t_tokken_list *tokken, t_val *val);
void	ft_dup(t_val *val, char **envp, int *pipe);
void	ft_find_pipe(t_tokken_list *tokken, t_val *val, int *pipefd);
void	ft_find_redir(t_tokken_list **tokken, t_val *val);

int	ft_next_pipe(t_tokken_list *tokken);

//heredoc
void	ft_heredoc(t_tokken_list **tokken, t_val *val);
void	ft_push_doc(t_tokken_list **tokken, t_val *val);
void	ft_first_heredoc(t_tokken_list **tokken, t_val *val);
void	ft_push_first_doc(t_tokken_list **tokken, t_val *val);


#endif /* MS_TEST_H*/