/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positionchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:49:54 by bhoth             #+#    #+#             */
/*   Updated: 2019/10/15 21:04:13 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_positionchar(const char *str, char c)
{
	int position;

	if (str)
	{
		position = 0;
		while (str[position] != '\0')
		{
			if (str[position] == c)
				return (position);
			position++;
		}
		return (-1);
	}
	return (-1);
}
