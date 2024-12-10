/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:58:08 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 18:27:24 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_word		t_word;
typedef struct s_tlist	t_tlist;
typedef struct s_tlist	t_envlist;
typedef struct s_tlist	t_qlist;
typedef enum e_node_type	t_node_type;
//env_utils
char			**convert_env(t_envlist *envlist);
void			delete_all_env(char **env);
//lst_utils
t_tlist	*ft_lstnew(char *content, t_node_type type);
void			ft_lstadd_back(t_tlist **lst, t_tlist *new);
void			ft_lstclear(t_tlist **lst);
char			*join_list(t_qlist *qlist);

//split
char			**ft_split(const char *s, char c);
//split_utils
void			ft_free(char **p, int sz);
void			init_word(t_word *word);
int				is_quote(const char *s);

#endif
