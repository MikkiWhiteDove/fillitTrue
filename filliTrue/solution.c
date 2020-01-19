/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:36:32 by sreyne            #+#    #+#             */
/*   Updated: 2020/01/16 19:56:14 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_solution		*create_new_solution_with_copy(t_solution *solution)
{
	t_solution	*temp_solution;
	int			i;

	i = 0;
	temp_solution = (t_solution*)malloc(sizeof(t_solution));
	temp_solution->size = solution->size;
	temp_solution->map = (char**)malloc(sizeof(char*) *
			(solution->size + SOLUTION_BUF));
	while (i < (solution->size + SOLUTION_BUF))
	{
		temp_solution->map[i] = ft_strdup(solution->map[i]); 
		i++;
	}
	return (temp_solution);
}

t_solution		*create_char_solution(int solution_size)
{
	t_solution	*solution;

	solution = (t_solution*)malloc(sizeof(t_solution));
	solution->size = solution_size;
	solution->map = create_char_solution_map(solution_size);
	return (solution);
}

t_solution		*create_solution(int solution_size)
{
	t_solution	*solution;

	solution = (t_solution*)malloc(sizeof(t_solution));
	solution->size = solution_size;
	solution->map = create_solution_map(solution_size);
	return (solution);
}

t_solution		*solution(t_element *element, t_solution *global_solution)
{
	t_solution	*solution;
	t_solution	*char_solution;
	int			min_solution_size;

	min_solution_size = get_min_solution_size(element);
	global_solution = create_char_solution(min_solution_size);
	solution = create_solution(min_solution_size);
	char_solution = create_char_solution(min_solution_size);
	while (!(find_solution(solution, element, char_solution, global_solution)))
	{
		min_solution_size = min_solution_size + 1;
		free_solution(solution);
		free_solution(char_solution);
		free_solution(global_solution);
		solution = create_solution(min_solution_size);
		char_solution = create_char_solution(min_solution_size);
		global_solution = create_char_solution(min_solution_size);
	}
	free_solution(solution);
	free_solution(char_solution);
	return (global_solution);
}

int				find_solution(t_solution *solution, t_element *element,
				t_solution *char_solution, t_solution *global_solution)
{
	t_solution	*temp_solution;
	t_solution	*temp_char_sollution;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (element == NULL)
	{
		recovery_solution(global_solution, char_solution);
		return (1);
	}
	temp_solution = create_solution(solution->size);
	temp_char_sollution = create_char_solution(solution->size);
	while (i < solution->size + SOLUTION_BUF - 3)
	{
		while (j < solution->size + SOLUTION_BUF - 3)
		{
			recovery_solution(temp_solution, solution);
			recovery_solution(temp_char_sollution, char_solution);
			paste_tetr_in_solution(temp_solution, temp_char_sollution,
					element, i, j);
			if (check_solution(temp_solution)
					&& find_solution(temp_solution, element->next,
						temp_char_sollution, global_solution))
			{
				free_solution(temp_solution);
				free_solution(temp_char_sollution);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	free_solution(temp_solution);
	free_solution(temp_char_sollution);
	return (0);
}
