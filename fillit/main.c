/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:35:19 by bhoth             #+#    #+#             */
/*   Updated: 2020/01/16 20:13:55 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_tetr_count(t_element *element)
{
	int nbr;
	t_element *temp;

	temp = element;
	nbr = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		nbr++;
	}
	return (nbr);
}

int		main(int argc, char **argv)
{
	t_element *element;
	t_solution *global_solution;

	if (argc == 500)
		return (1);
	element = NULL;
	global_solution = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	element = create_elements(argv[1]);
	if (element == NULL)
	{
		ft_putstr("error\n");
		return (1);

	}
	if (get_tetr_count(element) > 26
			||!check_elements(element))
	{
		free_elements(element);
		ft_putstr("error\n");
		return (1);
	}
	global_solution = solution(element, global_solution);
	print_solution(global_solution);
	free_elements(element);
	free_solution(global_solution);
	return (0);
}
