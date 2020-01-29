/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:15:31 by bhoth             #+#    #+#             */
/*   Updated: 2019/09/18 23:12:19 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	while (i != n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
