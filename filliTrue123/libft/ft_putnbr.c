/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:50:09 by bhoth             #+#    #+#             */
/*   Updated: 2019/09/20 18:50:12 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long chislo;

	chislo = (long)(nb);
	if (chislo < 0)
	{
		ft_putchar('-');
		chislo = -1 * chislo;
	}
	if (chislo <= 9 && chislo > 0)
		ft_putchar(chislo + 48);
	else if (chislo == 0)
		ft_putchar('0');
	else
	{
		ft_putnbr(chislo / 10);
		ft_putchar((chislo % 10) + 48);
	}
}
