/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:49:31 by asyani            #+#    #+#             */
/*   Updated: 2025/02/06 18:49:43 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_pos *matrix, int x, int y)
{
	int	top;
	int	down;
	int	left;
	int	right;

	if (map[x][y] != 'E' && map[x][y] != 'C' && map[x][y] != 'P')
		return; 
	top = (x > 0 && map[x - 1][y] == '1');
	down = (x < matrix->row - 1 && map[x + 1][y] == '1');
	left = (y > 0 && map[x][y - 1] == '1');
	right = (y < matrix->col - 1 && map[x][y + 1] == '1');
	if (top && down && left && right)
		ft_error(map, matrix);
}

void	verify_map(char **map, t_pos *matrix)
{
	int	i;
	int	j;

	if (matrix->coin < 1 || matrix->exit != 1 || matrix->player != 1)
		ft_error(map, matrix);
	else
	{
		i = 1;
		while (i < matrix->row - 1)
		{
			j = 1;
			while (j < matrix->col - 2)
			{
				if (map[i][j] == 'C')
					flood_fill(map, matrix, i, j);
				if (map[i][j] == 'E')
					flood_fill(map, matrix, i, j);
				if (map[i][j] == 'P')
					flood_fill(map, matrix, i, j);
				j++;
			}
			i++;
		}
	}
}

void	check_inside(char **map, t_pos *matrix)
{
	int	i;
	int	j;

	i = 1;
	matrix->coin = 0;
	matrix->player = 0;
	matrix->exit = 0;
	while (i < matrix->row - 1)
	{
		j = 1;
		while (j < matrix->col - 2)
		{
			if (map[i][j] == 'C')
				matrix->coin++;
			if (map[i][j] == 'E')
				matrix->exit++;
			if (map[i][j] == 'P')
				matrix->player++;
			j++;
		}
		i++;
	}
	verify_map(map, matrix);
}
