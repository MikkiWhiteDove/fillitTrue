/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:47:08 by bhoth             #+#    #+#             */
/*   Updated: 2019/09/20 20:50:42 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t j;

	if (!*find)
		return ((char*)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == find[j])
		{
			while (i + j < len)
			{
				j++;
				if (find[j] == '\0')
					return ((char*)&str[i]);
				if (str[i + j] != find[j])
					break ;
			}
		}
		i++;
	}
	return (NULL);
}
