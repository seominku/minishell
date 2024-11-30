#ifndef MS_TEST_H
# define MS_TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>

typedef enum e_node_type
{
	N_WORD,
	N_PIPE,
	N_REDIRECTION,
	N_ENV,
	N_EXPORT_ENV,
	N_NULL
}				t_node_type;

typedef struct s_flag
{
	int	pipe;
}	t_flag;

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

//libft.c
int		ft_is_digit(char c);
int		ft_is_alpha(char c);

//lst_util.c
t_tokken_list	*ft_lstnew(char *content, t_node_type type);
void	ft_lstadd_back(t_tokken_list **lst, t_tokken_list *new);
void	ft_lstclear(t_tokken_list **lst);

//token
void	ft_tokenizer(char *line, char **envp, t_envlist *envlist);
void	ft_in_pipe(char *line, t_tokken_list **tokken, t_envlist *envlist);
char	*ft_alpha_digit(char *line, int *i);
char	*ft_double_qoute_check(char *line, int *i, t_envlist *envlist);
char	*ft_export_ptr(char *line, int *i, t_envlist *envlist);
char	*ft_export_push(char *temp, t_envlist *envlist);
char	*ft_single_qoute_check(char *line, int *i);
char	*ft_redirection_check(char *line, int *i);
char	*ft_option(char	*line, int *i);

// ft_split.c
char	**split(const char *s, char c, int size, char **p);
char	**ft_split(const char *s, char c);
void	flag1_case(t_word *word, char s, char c);
int		count_words(const char *s, char c);
void	end_of_word(const char **s, char c, t_word *word);

//ft_split_utils.c
void	ft_free(char **p, int sz);
void	init_word(t_word *word);
int		is_quote(const char *s);

//ft_qoute.c
int		ft_double_qoute(char *line, int i, char **envp);
int		ft_single_qoute(char *line, int i);
void	ft_qoute_check(char *line, char **envp, t_flag *flag);

//ft_export.c
void	ft_print_export(char *temp, char **envp);
int		ft_export_check(char *line, int i, char **envp);

//ft_paser
char	*store_path(char **envp);
char	*find_path(char *argv, const char *env);
void	ft_val_set(t_tokken_list *tokken, t_val *val);
void	error(char *s, int num);
void	execute_cmd(t_tokken_list *tokken, char **envp, t_envlist *envlist);
void	ft_paser_manager(t_tokken_list *tokken, char **envp, t_envlist *envlist);
void	free_path(char **paths);

//redir
void	ft_redir_open(t_tokken_list *lst, t_val *val, t_tokken_list **tokken);
void	ft_redir_out(t_tokken_list *lst, t_val *val, t_tokken_list **tokken);
void	ft_redir_add(t_tokken_list *lst, t_val *val, t_tokken_list **tokken);
void	ft_redir_here(t_tokken_list *lst, t_val *val, t_tokken_list **tokken);

void	ft_find_cmd(t_tokken_list *tokken, t_val *val);
void	ft_dup(t_val *val, char **envp, int *pipe, t_envlist *envlist);
void	ft_find_pipe(t_tokken_list *tokken, t_val *val, int *pipefd);
void	ft_find_redir(t_tokken_list **tokken, t_val *val);

int	ft_next_pipe(t_tokken_list *tokken);

//heredoc
void	ft_heredoc(t_tokken_list **tokken, t_val *val);
void	ft_push_doc(t_tokken_list **tokken, t_val *val);
void	ft_first_heredoc(t_tokken_list **tokken, t_val *val);
void	ft_push_first_doc(t_tokken_list **tokken, t_val *val);

//ft_itoa
//static int	ft_ditcheck(int n);
char	*ft_itoa(int n);
//ft_env_utils
char	**convert_env(t_envlist *envlist);
void	delete_all_env(char **env);

void	handler(int sig);

#endif /* MS_TEST_H*/
