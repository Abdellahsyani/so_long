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

	coins = mlx_xpm_file_to_image(win.mlx, "coin.xpm", &img_width, &img_height);
	if (coins)
		mlx_put_image_to_window(win.mlx, win.mlx_window, coins, x, y);
	else
		perror("fail to draw coin");
}

void	player_draw(t_data win, int x, int y);

void	exit_draw(t_data win, int x, int y);
