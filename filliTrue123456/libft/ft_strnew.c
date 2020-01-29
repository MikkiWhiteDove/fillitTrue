/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:47:47 by bhoth             #+#    #+#             */
/*   Updated: 2019/10/15 20:17:28 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	if (size + 1 == 0)
		return (NULL);
	if ((res = (char*)malloc(sizeof(char) * (size + 1))))
	{
		ft_bzero(res, size + 1);
		return (res);
	}
	return (NULL);
}
