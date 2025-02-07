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

	if (map[x][y] != 'E' && map[x][y] != 'C'
			&& map[x][y] != 'P')
		return; 
	top = (x > 0 && map[x - 1][y] == '1');
	down = (x < matrix->row - 1 && map[x + 1][y] == '1');
	left = (y > 0 && map[x][y - 1] == '1');
	right = (y < matrix->col - 1 && map[x][y + 1] == '1');

	if (top && down && left && right) {
		ft_error(map);
	}
}
