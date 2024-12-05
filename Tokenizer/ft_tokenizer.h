/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:12:16 by mku               #+#    #+#             */
/*   Updated: 2024/12/05 20:27:01 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKENIZER_H
# define FT_TOKENIZER_H

typedef struct s_tokken_list	t_envlist;
void	ft_tokenizer(char *line, t_envlist *envlist);

char	*ft_export_ptr(char *line, int *i, t_envlist *envlist);

char	*ft_single_qoute_check(char *line, int *i, t_envlist *envlist);
char	*ft_double_qoute_check(char *line, int *i, t_envlist *envlist);

void	ft_qoute_check(char *line);
#endif