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

void	flood_fill(t_pos *matrix, int x, int y)
{
	int	top;
	int	down;
	int	left;
	int	right;

	if (matrix->map[x][y] != 'E' && matrix->map[x][y] != 'C' && matrix->map[x][y] != 'P')
		return;
	top = (x > 0 && matrix->map[x - 1][y] == '1');
	down = (x < matrix->row - 1 && matrix->map[x + 1][y] == '1');
	left = (y > 0 && matrix->map[x][y - 1] == '1');
	right = (y < matrix->col - 1 && matrix->map[x][y + 1] == '1');
	if (top && down && left && right)
		ft_error(matrix);
}

void	verify_map(t_pos *matrix)
{
	int	i;
	int	j;

	if (matrix->coin < 1 || matrix->exit != 1 || matrix->player != 1)
		ft_error(matrix);
	else
	{
		i = 1;
		while (i < matrix->row - 1)
		{
			j = 1;
			while (j < matrix->col - 2)
			{
				if (matrix->map[i][j] == 'C')
					flood_fill(matrix, i, j);
				if (matrix->map[i][j] == 'E')
					flood_fill(matrix, i, j);
				if (matrix->map[i][j] == 'P')
					flood_fill(matrix, i, j);
				j++;
			}
			i++;
		}
	}
}

void	check_inside(t_pos *matrix)
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
			if (matrix->map[i][j] == 'C')
				matrix->coin++;
			if (matrix->map[i][j] == 'E')
				matrix->exit++;
			if (matrix->map[i][j] == 'P')
				matrix->player++;
			j++;
		}
		i++;
	}
	verify_map(matrix);
}
