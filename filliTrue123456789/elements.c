/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:43:28 by bhoth             #+#    #+#             */
/*   Updated: 2020/01/31 22:15:57 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_elements(t_element *element)
{
	int	i;

	if (element != NULL)
	{
		if (element->next != NULL)
			free_elements(element->next);
		if (element->matrix != NULL)
		{
			i = 0;
			while (i < 4)
			{
				free(element->matrix[i]);
				i++;
			}
		}
		free(element);
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

void		free_element_matrix(char ***matrix, int count)
{
	int			i;

	i = 0;
	while (i < count)
	{
		free(*matrix[i]);
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

void		create_matrix(t_element *element, int count, char *buf)
{
	char		**temp;
	int			i;

	temp = element->matrix;
	element->matrix = (char**)ft_memalloc(sizeof(char*) * (count + 1));
	i = 0;
	while (i < count)
	{
		element->matrix[i] = ft_strdup(temp[i]);
		i++;
	}
	element->matrix[i] = ft_strdup(buf);
	return ;
}
