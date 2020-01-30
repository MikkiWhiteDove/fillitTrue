/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:47:58 by bhoth             #+#    #+#             */
/*   Updated: 2019/09/19 22:47:59 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (0);
	while (*s)
	{
		if (*s == c)
			str = (char*)s;
		s++;
	}
	if (str)
		return (str);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
