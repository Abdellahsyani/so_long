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

void	draw_game(char **map, void *mlx, void *mlx_win, t_data win, t_pos *matrix)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	color;

	x = 0;
	while (x < matrix->row)
	{
		y = 0;
		while (y < matrix->col - 1)
		{
			if (map[x][y] == '1')
			{
				color = 0xCD7054;
			}
			else if (map[x][y] == '0')
				color = 0xF1F7F7;
			else
				color = 0x00FF00;
			dx = 0;
			while (dx < 32)
			{
				dy = 0;
				while (dy < 32)
				{
					win.addr[(x * 32 + dx) * ((matrix->col - 1) * 32) + (y * 32 + dy)] = color;
					dy++;
				}
				dx++;
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, win.img, 0, 0);
}

void	so_long(char **map, t_pos *matrix)
{
	void	*mlx;
	void	*mlx_window;
	t_data	win;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, (matrix->col - 1) * 62, matrix->row * 62, "so_long");
	win.img = mlx_new_image(mlx, (matrix->col - 1) * 32, matrix->row * 32);
	win.addr = (int *)mlx_get_data_addr(win.img, &win.bpp, &win.size_len, &win.endian);

	draw_game(map, mlx, mlx_window, win, matrix);

	mlx_loop(mlx);
}
