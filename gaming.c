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

void	draw_pixels(t_data win, t_pos *matrix, int x, int y, int dx)
{
	int	dy;
	int	pixel;

	while (dx < 50)
	{
		dy = 0;
		while (dy < 50)
		{
			pixel = (x * 50 + dx) * ((matrix->col - 1) * 50) + (y * 50 + dy);
			win.addr[pixel] = win.color;
			dy++;
		}
		dx++;
	}

}

void	draw_game(char **map, t_data win, t_pos *matrix)
{
	int	x;
	int	y;
	int	dx;

	x = 0;
	while (x < matrix->row)
	{
		y = 0;
		while (y < matrix->col - 1)
		{
			if (map[x][y] == '1')
				win.color = 0xCD7054;
			else if (map[x][y] == '0')
				win.color = 0xF1F7F7;
			else
				draw_shapes(win, map, x, y);
			dx = 0;
			draw_pixels(win, matrix, x, y, dx);
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
	win.mlx_window = mlx_new_window(win.mlx, (matrix->col - 1) * 70, matrix->row * 70, "so_long");
	win.img = mlx_new_image(win.mlx, (matrix->col - 1) * 50, matrix->row * 50);
	win.addr = (int *)mlx_get_data_addr(win.img, &win.bpp, &win.size_len, &win.endian);

	draw_game(map, win, matrix);

	mlx_loop(win.mlx);
}
