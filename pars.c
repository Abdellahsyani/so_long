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

#include "get_next_line.h"
#include <stdio.h>

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

void	ft_error(char **map)
{
	free_map(map);
	perror("Map must be surrounded by walls\n");
	exit(1);
}

void	check_map(char **map, int *col, int *row)
{
	int	co;
	int	ro;
	int	i;
	int	j;

	i = 0;
	j = 0;
	co = *col;
	ro = *row;
	while (j < co - 1)
	{
		if (map[0][j] != '1' || map[ro - 1][j] != '1')
			ft_error(map);
		j++;
	}
	while (i < ro)
	{
		if (map[i][0] != '1' || map[i][co - 2] != '1')
			ft_error(map);
		i++;
	}
	free_map(map);
}

void	fill_map(char **map, int *row, int *col)
{
	int	fd;
	char	*line;
	int	co = *col;
	int	ro = *row;
	int	i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	if (!fd)
		perror("fail to open file");
	line = get_next_line(fd);
	while (line && i < ro)
	{
		int j = 0;
		while (line[j] && j < co - 1)
		{
			map[i][j] = line[j];
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	check_map(map, &co, &ro);
}

char	**allocation(char **map, int *row, int *col)
{
	int	ro;
	int	co;
	int	i;

	ro = *row;
	co = *col;
	map = (char **)malloc(sizeof(char *) * (ro + 1));
	if (!map)
		free_map(map);
	i = 0;
	while (i < ro)
	{
		map[i] = (char *)malloc(sizeof(char) * co - 1);
		if (!map[i])
			free_map(map);
		i++;
	}
	map[ro] = NULL;
	return (map);
}

void	pars_map(int fd)
{
	char	*line;
	int	col;
	int	row;
	char	**map;

	map = NULL;
	row = 0;
	col = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[col])
		{
			col++;
		}
		row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = allocation(map, &row, &col);
	fill_map(map, &row, &col);
}

int main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	pars_map(fd);
	return 0;
}
