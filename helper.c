/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:54:06 by asyani            #+#    #+#             */
/*   Updated: 2025/02/24 08:55:22 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_pos *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix->row)
	{
		j = 0;
		while (j < matrix->col)
		{
			matrix->map[i][j] = '0';
			j++;
		}
		matrix->map[i][matrix->col] = '\0';
		i++;
	}
}

void	short_line(t_pos *matrix, char *line, int fd)
{
	free(line);
	ft_putstr_fd("Map is not valid: Misaling lines\n", 2);
	free_map(matrix->map);
	close(fd);
	exit(1);
}

/**
 * ft_strcmp _ the function that compare strings
 * @s1: the first string
 * @s2: teh second string
 *
 * return: the different between the strings
 */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/**
 * check_char _ the function to for strange characters inside the map
 * @matrix: the struct that hold's all map
 */
void	check_char(t_pos *matrix)
{
	int	i;
	int	j;

	i = 1;
	while (i < matrix->row - 1)
	{
		j = 1;
		while (j < matrix->col - 1)
		{
			if (matrix->map[i][j] != '0' && matrix->map[i][j] != 'N'
				&& matrix->map[i][j] != 'C' && matrix->map[i][j] != 'P'
				&& matrix->map[i][j] != 'E' && matrix->map[i][j] != '1')
			{
				ft_putstr_fd("searching.......\n", 2);
				ft_putstr_fd("Ooop's you are breaking the map rules\n", 2);
				free_map(matrix->map);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
