/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:48:12 by asyani            #+#    #+#             */
/*   Updated: 2025/02/04 17:15:07 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(char **map, t_pos *matrix)
{
	free(matrix);
	free_map(map);
	errno = EINVAL;
	perror("Map is not valid");
	exit(1);
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
	for (int i = 0; i < matrix->row; i++)
	{
		for (int j = 0; j < matrix->col - 1; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void	check_map(char **map, t_pos *matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < matrix->col - 1)
	{
		if (map[0][j] != '1' || map[matrix->row - 1][j] != '1')
			ft_error(map, matrix);
		j++;
	}
	while (i < matrix->row)
	{
		if (map[i][0] != '1' || map[i][matrix->col - 2] != '1')
			ft_error(map, matrix);
		i++;
	}
	check_inside(map, matrix);
	free_map(map);
	free(matrix);
}

void	fill_map(char **map, t_pos *matrix)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	if (!fd)
		perror("fail to open file");
	line = get_next_line(fd);
	while (line && i < matrix->row)
	{
		int j = 0;
		while (line[j] && j < matrix->col - 1)
		{
			map[i][j] = line[j];
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	check_map(map, matrix);
}

char	**allocation(char **map, t_pos *matrix)
{
	int	i;

	map = (char **)malloc(sizeof(char *) * (matrix->row + 1));
	if (!map)
		free_map(map);
	i = 0;
	while (i < matrix->row)
	{
		map[i] = (char *)malloc(sizeof(char) * (matrix->col - 1));
		if (!map[i])
			free_map(map);
		i++;
	}
	map[matrix->row] = NULL;
	return (map);
}

void	pars_map(int fd)
{
	char	*line;
	t_pos	*matrix;
	char	**map;
	int	i;

	i = 0;
	matrix = malloc(sizeof(t_pos));
	if (!matrix)
	{
		perror("Memory allocation failed");
		return ;
	}
	map = NULL;
	matrix->row = 0;
	matrix->col = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[i])
		{
			i++;
			matrix->col++;
		}
		matrix->row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = allocation(map, matrix);
	fill_map(map, matrix);
}

int main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("fail to open file");
		exit(1);
	}
	pars_map(fd);
	return 0;
}
