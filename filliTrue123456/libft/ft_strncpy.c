/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:13:42 by bhoth             #+#    #+#             */
/*   Updated: 2019/09/18 23:26:24 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t count_src;

	count_src = 0;
	while (src[count_src] != '\0' && count_src < len)
	{
		dst[count_src] = src[count_src];
		count_src++;
	}
	while (count_src < len)
	{
		dst[count_src] = '\0';
		count_src++;
	}
	return (dst);
}
