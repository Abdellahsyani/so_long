/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:43:50 by asyani            #+#    #+#             */
/*   Updated: 2025/02/07 17:06:15 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_shapes(t_data win, char **map, int x, int y)
{
	if (map[x][y] == 'C')
		coins_draw(win, x, y);
	if (map[x][y] == 'P')
		player_draw(win, x, y);
	if (map[x][y] == 'E')
		exit_draw(win, x, y);
}

void	draw_game(t_data win, t_pos *matrix)
{
	int	x;
	int	y;

	x = 0;
	while (x < matrix->row)
	{
		y = 0;
		while (y < matrix->col - 1)
		{
			if (matrix->map[x][y] == '1')
				wall_draw(win, x, y);
			else 
				floor_draw(win, x, y);
			draw_shapes(win, matrix->map, x, y);
			y++;
		}
		x++;
	}
}

void	so_long(t_pos *matrix)
{
	t_data	win;

	win.mlx = mlx_init();
	win.mlx_window = mlx_new_window(win.mlx, (matrix->col - 1) * WIN_WIDTH, matrix->row * WIN_HEIGHT, "so_long");

	draw_game(win, matrix);
	mlx_hook_loop();

	mlx_loop(win.mlx);
}
