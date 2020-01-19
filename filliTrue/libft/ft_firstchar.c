/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firstchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:27:07 by bhoth             #+#    #+#             */
/*   Updated: 2019/10/15 20:28:47 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_firstchar(char *str, const char *charset)
{
	char			*ptr;
	int				index;
	unsigned int	count;
	unsigned int	tmp;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		index = 0;
		tmp = count;
		while (charset[index])
			if (charset[index++] == *ptr)
				++count;
		if (count == tmp)
			return (count);
		++ptr;
	}
	return (count);
}
