/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 03:24:32 by mku               #+#    #+#             */
/*   Updated: 2024/12/13 18:44:33 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
//ft_string
size_t		ft_strlen(char const *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
//ft_string2
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
long long	ft_atoll(char *nptr, int *flag);
int			ft_is_grammer(char c);
char		*ft_ctos(char a);
//ft_itoa.c
char		*ft_itoa(int n);
//ft_libft.c
int			ft_is_alpha(char c);
int			ft_is_digit(char c);
int			ft_find_c(char *str, char c);
char		**ft_ms_split(char const *s, char c);
int			ft_count_equal(char *content);
#endif
