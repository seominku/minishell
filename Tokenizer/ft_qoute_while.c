/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qoute_while.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:21:43 by seojang           #+#    #+#             */
/*   Updated: 2024/12/14 00:26:01 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	ft_qoute_while(char *line, int *i, const char c)
{
	(*i)++;
	while (line[*i] != c)
		(*i)++;
	(*i)++;
}
