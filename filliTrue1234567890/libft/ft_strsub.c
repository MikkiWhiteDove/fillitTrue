/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:09:29 by bhoth             #+#    #+#             */
/*   Updated: 2019/10/15 20:33:41 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	res = NULL;
	if (s)
	{
		i = 0;
		res = ft_strnew(len);
		if (res)
		{
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
		}
	}
	return (res);
}
