/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:25:09 by asyani            #+#    #+#             */
/*   Updated: 2025/02/08 18:56:45 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coins_draw(t_data win, int x, int y)
{
	void	*coins;
	int	img_width;
	int	img_height;

	coins = mlx_xpm_file_to_image(win.mlx, "tools/coin.xpm", &img_width, &img_height);
	if (!coins)
	{
		perror("fail to draw coin");
		return ;
	}
	mlx_put_image_to_window(win.mlx, win.mlx_window, coins, y * 50, x * 50);
}

void	player_draw(t_data win, int x, int y)
{
	void	*player;
	int	img_width;
	int	img_height;

	player = mlx_xpm_file_to_image(win.mlx, "tools/player.xpm", &img_width, &img_height);
	if (player)
		mlx_put_image_to_window(win.mlx, win.mlx_window, player, y * 50, x * 50);
	else
		perror("fail to draw player");
}

void	exit_draw(t_data win, int x, int y)
{
	void	*exit;
	int	img_width;
	int	img_height;

	exit = mlx_xpm_file_to_image(win.mlx, "tools/door.xpm", &img_width, &img_height);
	if (exit)
		mlx_put_image_to_window(win.mlx, win.mlx_window, exit, y * 50, x * 50);
	else
		perror("fail to draw exit");
}

void	wall_draw(t_data win, int x, int y)
{
	void	*wall;
	int	img_width;
	int	img_height;

	wall = mlx_xpm_file_to_image(win.mlx, "tools/wall.xpm", &img_width, &img_height);
	if (!wall)
	{
		perror("fail to draw wall");
		return ;
	}
	mlx_put_image_to_window(win.mlx, win.mlx_window, wall, y * 50, x * 50);
}

void	floor_draw(t_data win, int x, int y)
{
	void	*floor;
	int	img_width;
	int	img_height;

	floor = mlx_xpm_file_to_image(win.mlx, "tools/floor.xpm", &img_width, &img_height);
	if (!floor)
	{
		perror("fail to draw floor");
		return ;
	}
	mlx_put_image_to_window(win.mlx, win.mlx_window, floor, y * 50, x * 50);
}
