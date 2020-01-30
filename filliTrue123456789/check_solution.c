/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:01:44 by sreyne            #+#    #+#             */
/*   Updated: 2020/01/29 20:48:12 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_char_solution(char **map, int i, int j, int size)
{
	if (map[i][j] > 1)
		return (0);
	if (map[i][j] > 0 &&
			(i < 3 || i > size + SOLUTION_BUF - 4 ||
			j < 3 || j > size + SOLUTION_BUF - 4))
		return (0);
	return (1);
}

int		check_sol(t_solution *solution)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < SOLUTION_BUF + solution->size)
	{
		while (j < SOLUTION_BUF + solution->size)
		{
			if (!check_char_solution(solution->map, i, j, solution->size))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	pst_tetr_in_sol(t_solution *solution,
		t_solution *char_sollution, t_element *element, int position[])
{
	int a;
	int b;
	int i;
	int j;

	i = position[0];
	j = position[1];
	a = 0;
	b = 0;
	while (a < 4)
	{
		while (b < 4)
		{
			solution->map[a + i][b + j] = solution->map[a + i][b + j] +
				element->matrix[a][b];
			if (element->matrix[a][b] == 1)
				char_sollution->map[a + i][b + j] = element->char_s;
			else if (char_sollution->map[a + i][b + j] == 0)
				char_sollution->map[a + i][b + j] = '.';
			b++;
		}
		b = 0;
		a++;
	}
}

int		check_elements(t_element *element)
{
	t_element	*temp;
	int			i;

	i = 0;
	temp = element;
	while (temp != NULL)
	{
		if (check_element(temp->matrix, temp))
		{
			temp->char_s = (char)(65 + i);
			temp = temp->next;
			i++;
		}
		else
			return (0);
	}
	return (1);
}
