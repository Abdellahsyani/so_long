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

/**
 * flood_fill _ the function that check for a valid path in the map
 * @matrix: struct contains col and row
 * @map: teh new map that will use to check a valid path
 * @x: the x player coordinate 
 * @y: the y player coordinate
 */
void	flood_fill(t_pos *matrix, char **map, int x, int y)
{
	if (x < 0 || x >= matrix->row || y < 0 || y >= matrix->col
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

/**
 * find_p _ the function that find the player position in new map
 * @matrix: struct used for get rwo and col
 */
static void	find_p(t_pos *matrix, char **map_copy)
{
	int	i;
	int	j;
	int	player_x;
	int	player_y;

	player_x = -1;
	player_y = -1;
	i = 0;
	while (i < matrix->row)
	{
		j = 0;
		while (j < matrix->col)
		{
			if (map_copy[i][j] == 'P')
			{
				player_x = i;
				player_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	if (player_x == -1 || player_y == -1)
		ft_error(matrix);
	flood_fill(matrix, map_copy, player_x, player_y);
}

/**
 * verify_map _ the function that handle the copy map
 * @matrix: the struct that contains all info
 */
void	verify_map(t_pos *matrix)
{
	int		i;
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
		ft_putstr_fd("Invalid path try another map\n", 2);
		free_map_copy(matrix, map_copy);
		free_map(matrix->map);
		exit(1);
	}
	free_map_copy(matrix, map_copy);
}

/**
 * check_inside _ function to check teh map exluding walls
 * @matrix: the struct that contains all about game
 */
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
		while (j < matrix->col - 1)
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

/**
 * is_valid_file _ the function that check if the file is valid
 * @av: the file that will check
 */
int	is_valid_file(char **av)
{
	int	i;
	int	len;

	len = ft_strlen(av[1]);
	if (ft_strcmp(av[1] + len - 4, ".ber") != 0)
		return (0);
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '/')
		{
			if (av[1][i + 1] >= 'a' && av[1][i + 1] <= 'z')
				return (1);
		}
		i++;
	}
	return (0);
}
