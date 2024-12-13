/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_atoll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:04:48 by mku               #+#    #+#             */
/*   Updated: 2024/12/13 19:13:37 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long long	convert_str(char *nptr, int *i, int *sign, int *flag);
static long long	check_flow(long long *result, \
long long *prev, int *flag, int *sign);

long long	ft_atoll(char *nptr, int *flag)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	result = convert_str(nptr, &i, &sign, flag);
	return (result);
}

static long long	convert_str(char *nptr, int *i, int *sign, int *flag)
{
	long long	result;
	long long	prev;

	result = 0;
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		prev = result;
		if (*sign == -1)
			result = result * 10 - (nptr[*i] - '0');
		else
			result = result * 10 + (nptr[*i] - '0');
		(*i)++;
		if (check_flow(&result, &prev, flag, sign))
			return (2);
	}
	return (result);
}

static long long	check_flow(long long *result, \
long long *prev, int *flag, int *sign)
{
	if (*sign == -1)
	{
		if (*prev < *result)
		{
			*flag = 1;
			return (2);
		}
	}
	else
	{
		if (*prev > *result)
		{
			*flag = 1;
			return (2);
		}
	}
	return (0);
}
