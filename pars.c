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


void	pars_map(char ***map)
{
	int	fd;
	char	*line;
	int	i;
	int	col;
	int	row;

	i = 0;
	row = 0;
	col = 0;
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		while (line[i])
		{
			col++;
			i++;
		}
		row++;
		free(line);
		line = get_next_line(fd);
	}
	/*printf("col: %d\n", col - 1);*/
	/*printf("row: %d\n", row);*/
	map = (char **)malloc(sizeof(char *) * row);
	i = 0;
	while (i < row)
	{
		map[i] = (char *)malloc(sizeof(char) * col);
		if (!map[i])
			return ;
		i++;
	}
	i = 0;
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	 for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
	char **map;
	pars_map(map);
	return 0;
}
