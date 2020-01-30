/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:08:42 by sreyne            #+#    #+#             */
/*   Updated: 2020/01/30 15:09:57 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #define FT_LOG_MAX 9223372036854775807

// static int			ft_overmax(int sign)
// {
// 	if (sign == -1)
// 		return ((int)(-FT_LOG_MAX - 1));
// 	if (sign)
// 		return ((int)(FT_LOG_MAX));
// 	return (0);
// }

// int					ft_atoi(const char *str)
// {
// 	int				i;
// 	long long int	res;

// 	res = 0;
// 	i = 1;
// 	while (ft_ispace(*str))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 		i = (*str++ == '-') ? -1 : 1;
// 	while (ft_isdigit(*str))
// 	{
// 		res = 10 * res + (int)(*str++ - '0');
// 		if (res >= (FT_LOG_MAX) / 10 && ft_isdigit(*str))
// 			return (ft_overmax(i));
// 	}
// 	return (res * i);
// }

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}