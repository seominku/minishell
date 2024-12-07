/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:58:08 by mku               #+#    #+#             */
/*   Updated: 2024/12/08 02:05:11 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_word t_word;
typedef struct s_tokken_list t_tokken_list,t_envlist,t_qlist;
typedef enum e_node_type t_node_type;
//env_utils
char			**convert_env(t_envlist *envlist);
void			delete_all_env(char **env);
//lst_utils
t_tokken_list	*ft_lstnew(char *content, t_node_type type);
void			ft_lstadd_back(t_tokken_list **lst, t_tokken_list *new);
void			ft_lstclear(t_tokken_list **lst);
char			*join_list(t_qlist *qlist);

//split
char			**ft_split(const char *s, char c);
//split_utils
void			ft_free(char **p, int sz);
void			init_word(t_word *word);
int				is_quote(const char *s);

#endif
