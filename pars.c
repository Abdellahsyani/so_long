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

void	check_map(char **map, int *col, int *row)
{
	int co = *col;
	int ro = *row;
	 for (int i = 0; i < ro; i++) {
        for (int j = 0; j < co; j++) {
            printf("%c", map[i][j]);
        }
        	printf("\n");
	}
}

void	fill_map(int *row, int *col)
{
	char **map;
	int	fd;
	char	*line;
	int	co;
	int	ro;
	int	i;

	ro = *row;
	co = *col;
	map = (char **)malloc(sizeof(char *) * ro);
	if (!map)
		return;
	i = 0;
	while (i < ro)
	{
		map[i] = (char *)malloc(sizeof(char) * co);
		if (!map[i])
			return ;
		i++;
	}
	i = 0;
	fd = open("file.txt", O_RDONLY);
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


void	pars_map(int fd)
{
	char	*line;
	int	col;
	int	row;

	row = 0;
	col = 0;
	line = get_next_line(fd);
	while (line)
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
	fill_map(&row, &col);
}

int main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	pars_map(fd);
	return 0;
}
