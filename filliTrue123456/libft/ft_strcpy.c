/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:48:16 by bhoth             #+#    #+#             */
/*   Updated: 2019/09/20 18:48:56 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int count_src;

	count_src = 0;
	while (src[count_src] != '\0')
	{
		dest[count_src] = src[count_src];
		count_src++;
	}
	dest[count_src] = '\0';
	return (dest);
}
