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

void	flood_fill(t_pos *matrix, char **map, int x, int y)
{
	if (x < 0 || x >= matrix->row || y < 0 || y >= matrix->col - 1
		|| map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'C') 
		matrix->v_coin--;
	else if (map[x][y] == 'E')
	{
		matrix->exit_x = x;
		matrix->exit_y = y;
		matrix->exit--;
	}
	map[x][y] = 'V';
	flood_fill(matrix, map, x - 1, y);
	flood_fill(matrix, map, x + 1, y);
	flood_fill(matrix, map, x, y - 1);
	flood_fill(matrix, map, x, y + 1);
}

static void	find_p(t_pos *matrix, char **map_copy)
{
	int	i;
	int	j;
	int	player_x = -1;
	int	player_y = -1;

	i = 0;
	while (i < matrix->row)
	{
		j = 0;
		while (j < matrix->col - 1)
		{
			if (map_copy[i][j] == 'P')
			{
				player_x = i;
				player_y = j;
				break;
			}
			j++;
		}
		i++;
	}
	if (player_x == -1 || player_y == -1)
		ft_error(matrix);
	flood_fill(matrix, map_copy, player_x, player_y);
}

void	verify_map(t_pos *matrix)
{
	int	i;
	char	**map_copy;

    	if (!matrix || !matrix->map)
        	ft_error(matrix);
	map_copy = malloc(matrix->row * sizeof(char *));
	if (!map_copy)
		return ;
	i = 0;
	while (i < matrix->row)
	{
		map_copy[i] = ft_strdup(matrix->map[i]);
		i++;
	}
	find_p(matrix, map_copy);
	if (matrix->v_coin != 0 || matrix->exit != 0)
	{
		perror("invalid map");
		exit(1);
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
	matrix->v_coin = matrix->coin;
	verify_map(matrix);
}
