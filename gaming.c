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
	/*if (map[x][y] == '1')*/
	/*	wall_draw(win, x, y);*/
	/*else*/
	/*	floor_draw(win, x, y);*/
}

void	draw_game(char **map, t_data win, t_pos *matrix)
{
	int	x;
	int	y;

	x = 0;
	while (x < matrix->row)
	{
		y = 0;
		while (y < matrix->col - 2)
		{
			if (map[x][y] == '1')
				wall_draw(win, x, y);
			else if (map[x][y] == 'C' || map[x][y] == 'E' || map[x][y] == 'P')
				draw_shapes(win, map, x, y);
			else 
				floor_draw(win, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(win.mlx, win.mlx_window, win.img, 0, 0);
}

void	so_long(char **map, t_pos *matrix)
{
	t_data	win;

	win.mlx = mlx_init();
	win.mlx_window = mlx_new_window(win.mlx, (matrix->col - 1) * 50, matrix->row * 50, "so_long");

	draw_game(map, win, matrix);

	mlx_loop(win.mlx);
}
