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

	printf("x: %d\n", x);
	printf("y: %d\n", y);
	coins = mlx_xpm_file_to_image(win.mlx, "tools/coin.xpm", &img_width, &img_height);
	if (coins)
		mlx_put_image_to_window(win.mlx, win.mlx_window, coins, x, y);
	else
		perror("fail to draw coin");
}

void	player_draw(t_data win, int x, int y)
{
	void	*player;
	int	img_width;
	int	img_height;

	player = mlx_xpm_file_to_image(win.mlx, "player.xpm", &img_width, &img_height);
	if (player)
		mlx_put_image_to_window(win.mlx, win.mlx_window, player, x, y);
	else
		perror("fail to draw player");
}

void	exit_draw(t_data win, int x, int y)
{
	void	*exit;
	int	img_width;
	int	img_height;

	exit = mlx_xpm_file_to_image(win.mlx, "exit.exp", &img_width, &img_height);
	if (exit)
		mlx_put_image_to_window(win.mlx, win.mlx_window, exit, x, y);
	else
		perror("fail to draw exit");
}
