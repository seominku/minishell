/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 02:28:46 by seojang           #+#    #+#             */
/*   Updated: 2024/12/03 22:13:44 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	ft_free(char **p, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
		free(p[i++]);
	free(p);
}

void	init_word(t_word *word)
{
	word->count = 0;
	word->flag = 1;
	word->single_quote_flag = 0;
	word->double_quote_flag = 0;
}

int	is_quote(const char *s)
{
	return (*s == '\'' || *s == '\"');
}
