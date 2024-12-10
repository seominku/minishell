/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:22:50 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 20:43:36 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "Tokenizer/ft_tokenizer.h"
# include "Utils/utils.h"
# include "builtin/builtin.h"
# include "Paser/paser.h"

# define EXIT_NORMAL_ERR 1

extern volatile int	g_signal_flag;

typedef enum e_node_type
{
	N_WORD,
	N_PIPE,
	N_RED,
	N_ENV,
	N_EXPORT_ENV,
	N_SINGLE,
	N_DOUBLE,
	N_DOLLAR,
	N_NULL
}	t_node_type;

typedef struct s_tlist
{
	char			*content;
	t_node_type		node_type;
	struct s_tlist	*next;
}	t_tlist;

typedef struct s_envlist
{
	char				*content;
	t_node_type			node_type;
	struct s_envlist	*next;
}	t_envlist;

typedef struct s_qlist
{
	char			*content;
	t_node_type		node_type;
	struct s_qlist	*next;
}	t_qlist;

typedef struct s_val
{
	int		pipe_flag;
	int		prev_pipe;
	int		fd_in;
	int		fd_out;
	int		heredoc_fd;
	int		tokken_len;
	int		redir_flag;
	int		tmp_out;
	char	*heredoc;
	int		doc_num;
	int		here_sig;
	int		exit_code;
	char	*home;
	t_tlist	*head;
	t_tlist	*cmd;
}			t_val;

typedef struct s_here_val
{
	char	*eof;
	char	*ret;
	char	*temp;
	char	*file;
	char	*doc_name;
	char	*doc_num;
	int		tmpfd;
}	t_here_val;

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

#endif /* MS_TEST_H*/
