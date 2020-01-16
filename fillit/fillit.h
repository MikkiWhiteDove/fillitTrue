/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:09:59 by sreyne            #+#    #+#             */
/*   Updated: 2020/01/16 19:26:48 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 32
# define SIDE_SIZE 4
# define FREE_STR_GNL 0
# define SOLUTION_BUF 6
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_element
{
	char					**matrix;
	char					char_s;
	int						rows;
	struct	s_element		*next;
}					t_element;

typedef	struct		s_solution
{
	char					**map;
	int						size;
}					t_solution;

typedef	struct		s_element_g
{
	int						fd;
	char					*buf;
	struct	s_element_g		*next;
}					t_element_g;

int get_next_line(const int fd, char **line);
void tetr_char_replace(t_element *element);
int count_adj(char **matrix, int i, int j);
int check_tetr_form(char **matrix);
int check_char_tetr(char **matrix);
int check_size_tetr(char **matrix, t_element *temp);
int check_element(char **mas, t_element *temp);
int check_elements(t_element *element);
t_element *create_elements(char *str);
void free_elements(t_element *element);
void print_elements(t_element *element);
char **create_matrix(char **matrix, int count, char *buf);
int get_min_solution_size(t_element *element);
t_solution *create_new_sollution_with_copy(t_solution *solution);
char **create_solution_map(int solution_size);
char **create_char_solution_map(int solution_size);
t_solution *create_solution(int solution_size);
t_solution *create_char_solution(int solution_size);
t_solution *solution(t_element *element, t_solution *global_solution);
int find_solution(t_solution *solution, t_element *element,
t_solution *char_solution, t_solution *global_solution);
void paste_tetr_in_solution(t_solution *solution,
t_solution *char_sollution, t_element *element, int i, int j);
int check_char_solution(char **map, int i, int j, int size);
int check_solution(t_solution *solution);
void recovery_solution(t_solution *temp_solution,
t_solution *solution);
void print_solution(t_solution *solution);
void print_solution_char(t_solution *solution);
void free_solution(t_solution *solution);
void free_element_matrix(char **matrix, int count);
void print_char_elements(t_element *element);

#endif
