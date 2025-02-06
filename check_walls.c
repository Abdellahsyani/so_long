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

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] != 'E' && map[x][y] != 'C' && map[x][y] != 'P')
		return; 
	int top = (x > 0 && map[x - 1][y] == '1');
	int down = (x < rows - 1 && map[x + 1][y] == '1');
	int left = (y > 0 && map[x][y - 1] == '1');
	int right = (y < cols - 1 && map[x][y + 1] == '1');

	if (top && down && left && right) {
		ft_error(map);
	}
}
