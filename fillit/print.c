/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:58:24 by sreyne            #+#    #+#             */
/*   Updated: 2020/01/16 20:10:39 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_char_elements(t_element *element)
{
	t_element *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = element;
	if (tmp == NULL)
		ft_putstr("null");
	while (tmp != NULL)
	{
		while (i < tmp->rows)
		{
			while (j < tmp->rows)
			{
				printf("%c", (char)(tmp->matrix[i][j] + 48));
				j++;
			}
			ft_putstr("\n");
			j = 0;
			i++;
		}
		ft_putstr("\n");
		i = 0;
		tmp = tmp->next;
	}
}

void	print_elements(t_element *element)
{
	t_element *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = element;
	if (tmp == NULL)
		ft_putstr("null");
	while (tmp != NULL)
	{
		while (i < tmp->rows)
		{
			while (j < tmp->rows)
			{
				printf("%c", (char)(tmp->matrix[i][j]));
				j++;
			}
			ft_putstr("\n");
			j = 0;
			i++;
		}
		ft_putstr("\n");
		i = 0;
		tmp = tmp->next;
	}
}

void	print_solution(t_solution *solution)
{
	t_solution *tmp;
	int i;
	int j;

	i = 3;
	j = 3;
	tmp = solution;
	if (tmp == NULL)
		printf("null");
	while (i < tmp->size + SOLUTION_BUF - 3)
	{
		while (j < tmp->size + SOLUTION_BUF - 3)
		{
			printf("%c", tmp->map[i][j]);
			j++;
		}
		printf("\n");
		j = 3;
		i++;
	}
	printf("\n");
	i = 0;
}

void	print_solution_char(t_solution *solution)
{
	t_solution *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = solution;
	if (tmp == NULL)
		printf("null");
	while (i < tmp->size + SOLUTION_BUF)
	{
		while (j < tmp->size + SOLUTION_BUF)
		{
			printf("%c", (char)(tmp->map[i][j] + 48));
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("\n");
	i = 0;
}

