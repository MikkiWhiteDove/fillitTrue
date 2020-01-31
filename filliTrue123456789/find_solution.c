/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:04:58 by sreyne            #+#    #+#             */
/*   Updated: 2020/01/31 21:32:02 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			find_sol(t_solution *solution, t_element *element,
				t_solution *char_solution, t_solution *gl_sol)
{
	t_solution	*tmp_sol;
	t_solution	*tmp_ch_sol;
	int			i;
	int			j;
	int			position[2];

	i = 0;
	j = 0;
	if (element == NULL)
	{
		recovery_solution(gl_sol, char_solution);
		return (1);
	}
	tmp_sol = create_solution(solution->size);
	tmp_ch_sol = create_char_solution(solution->size);
	while (i < solution->size + SOLUTION_BUF - 3)
	{
		while (j < solution->size + SOLUTION_BUF - 3)
		{
			recovery_solution(tmp_sol, solution);
			recovery_solution(tmp_ch_sol, char_solution);
			position[0] = i;
			position[1] = j;
			pst_tetr_in_sol(tmp_sol, tmp_ch_sol, element, position);
			if (check_sol(tmp_sol)
			&& find_sol(tmp_sol, element->next, tmp_ch_sol, gl_sol))
			{
				global_free_solutions(tmp_sol, tmp_ch_sol);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	global_free_solutions(tmp_sol, tmp_ch_sol);
	return (0);
}

t_element	*create_elements(char *str)
{
	int			fd;
	int			i;
	char		*buf;
	t_element	*temp;
	t_element	*element;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	element = (t_element*)ft_memalloc(sizeof(t_element));
	temp = element;
	while (get_next_line(fd, &buf) > 0)
	{
		if (*buf == FREE_STR_GNL)
		{
			if (if_buf_free_str(temp, element))
				return (NULL);
			temp = temp->next;
			i = 0;
		}
		else
			i = create_temp_matrix(temp, i, buf);
		free(buf);
	}
	free(buf);
	close (fd);
	return (element);
}

int			create_temp_matrix(t_element *temp, int i, char *buf)
{
	create_matrix(temp, i, buf);
	temp->next = NULL;
	i++;
	temp->rows = i;
	return (i);
}

int			if_buf_free_str(t_element *temp, t_element *element)
{
	if (temp->matrix == NULL)
	{
		free_elements(element);
		return (1);
	}
	temp->next = (t_element*)ft_memalloc(sizeof(t_element));
	return (0);
}
