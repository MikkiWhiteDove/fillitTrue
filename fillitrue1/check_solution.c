/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:01:44 by sreyne            #+#    #+#             */
/*   Updated: 2020/01/19 17:11:00 by sreyne           ###   ########.fr       */
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

int		check_solution(t_solution *solution)
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

void	paste_tetr_in_solution(t_solution *solution,
		t_solution *char_sollution, t_element *element, int i, int j)// 5 праметров
{
	int a;
	int b;

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
