/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:12:16 by mku               #+#    #+#             */
/*   Updated: 2024/12/08 18:22:38 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKENIZER_H
# define FT_TOKENIZER_H

# define ERROR 0
# define NO_ERROR 1
# define SINGLE_PIPE 1
# define DOUBLE_PIPE 2
# define BRACE 3
# define SAME 0

typedef struct s_tokken_list t_envlist,t_tokken_list,t_qlist;
typedef struct s_val		t_val;

t_tokken_list	*ft_tokenizer(char *line, t_envlist *envlist, t_val *val);
char			*ft_export_ptr(char *line, int *i, \
t_envlist *envlist, t_val *val);
int				ft_qoute_check(char *line, t_val *val);
//ft_check_token.c
int				check_token(t_tokken_list *tokken, t_val *val);
//qoute.c
void			qoute_check(t_tokken_list *tokken, \
t_envlist *envlist, t_val *val);
//export.c
void			qoute_export(t_qlist *qlist, t_envlist *envlist, t_val *val);
//qoute_utils.c
void			single_q(int *start, int *end, t_qlist **qlist, char *content);
void			double_q(int *start, int *end, t_qlist **qlist, char *content);
void			alpha_q(int *start, int *end, t_qlist **qlist, char *content);
void			dollar_q(int *start, int *end, t_qlist **qlist, char *content);
void			alpha_dollar(int *start, int *end, \
t_qlist **qlist, char *content);
#endif
