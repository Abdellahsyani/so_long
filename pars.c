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

#include "../get_next_line/get_next_line.h"


void	pars_map(char **map)
{
	int	fd;
	char	*line;
	int	i;
	int	col;
	int	row;

	i = 0;
	row = 0;
	col = 0;
	line = get_next_line(fd);
	while (line)
	{
		while (line[i] && row == 0)
		{
			col++;
			i++;
		}
		row++;
		free(line);
		line = get_next_line(fd);
	}
}
