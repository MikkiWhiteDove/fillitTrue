/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:43:28 by bhoth             #+#    #+#             */
/*   Updated: 2020/01/30 21:54:03 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_elements(t_element *element)
{
	t_element	*temp;

	temp = element;
	if (temp != NULL)
	{
		if (temp->next != NULL)
			free_elements(temp->next);
		if (temp->matrix != NULL)
		{
			free_element_matrix(temp->matrix, 4);
		}
		free(temp);
	}
}

int			check_element(char **mas, t_element *temp)
{
	if (check_size_tetr(mas, temp)
			&& check_char_tetr(mas)
			&& check_tetr_form(mas))
	{
		tetr_char_replace(temp);
		return (1);
	}
	return (0);
}

void		free_element_matrix(char **matrix, int count)
{
	int			i;

	i = 0;
	while (i < count)
	{
		if (*matrix != NULL)
			free(matrix[i]);
		i++;
	}
}

char		**create_matrix(char **matrix, int count, char *buf)
{
	char		**temp;
	int			i;

	temp = (char**)malloc(sizeof(char*) * (count + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		temp[i] = ft_strdup(matrix[i]);
		i++;
	}
	temp[i] = ft_strdup(buf);
	if (temp != matrix)
		free_element_matrix(matrix, count);
	return (temp);
}
