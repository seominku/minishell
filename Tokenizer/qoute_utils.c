/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qoute_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <seojang@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:48:53 by mku               #+#    #+#             */
/*   Updated: 2024/12/10 19:31:03 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	single_q(int *start, int *end, t_qlist **qlist, char *content)
{
	if (*end == 0 || content[*end + 1 == '\''])
		(*start)++;
	(*end)++;
	while (content[*end] != '\0' && content[*end] != '\'')
		(*end)++;
	ft_qladd_back(qlist, ft_qlnew(\
	ft_substr(content, *start, *end - *start), N_SINGLE));
	*start = *end + 1;
}

void	double_q(int *start, int *end, t_qlist **qlist, char *content)
{
	if (*end == 0 || content[*end + 1 == '\"'])
		(*start)++;
	(*end)++;
	while (content[*end] != '\0' && content[*end] != '\"')
		(*end)++;
	ft_qladd_back(qlist, ft_qlnew(\
	ft_substr(content, *start, *end - *start), N_DOUBLE));
	*start = *end + 1;
}

void	alpha_q(int *start, int *end, t_qlist **qlist, char *content)
{
	while (content[*end] != '\0' && \
	(content[*end] != '\"' && content[*end] != '\''))
		(*end)++;
	ft_qladd_back(qlist, ft_qlnew(\
	ft_substr(content, *start, *end - *start), N_WORD));
	*start = *end;
}

void	alpha_dollar(int *start, int *end, t_qlist **qlist, char *content)
{
	while (content[*end] != '\0' && content[*end] != '$')
		(*end)++;
	ft_qladd_back(qlist, ft_qlnew(\
	ft_substr(content, *start, *end - *start), N_WORD));
	*start = *end;
}

void	dollar_q(int *start, int *end, t_qlist **qlist, char *content)
{
	(*end)++;
	if (content[*start] == '$')
		(*start)++;
	while (content[*end] != '\0' && content[*end] != '$')
		(*end)++;
	ft_qladd_back(qlist, ft_qlnew(\
	ft_substr(content, *start, *end - *start), N_DOLLAR));
	*start = *end + 1;
}
