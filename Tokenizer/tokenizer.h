/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:37:01 by mku               #+#    #+#             */
/*   Updated: 2024/11/24 22:00:20 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

#define ERROR 1
#define NO_ERROR 0
#define SINGLE_PIPE 1
#define DOUBLE_PIPE 2
#define BRACE 3
#define SAME 0

typedef struct s_tokken_list t_tokken_list;
int	check_token(t_tokken_list *tokken);

#endif