/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:18:53 by asyani            #+#    #+#             */
/*   Updated: 2025/02/16 09:20:01 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * player_draw_left _ function to draw player that going left
 * @win: the struct that hold window's
 * @game: the struct that hold array's that store images
 * @x: the player coordinate in row
 * @y: the player coordinate in column
 */
void	player_draw_left(t_data win, t_game *game, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_window,
		game->player_left[game->frame], y * 50, x * 50);
}

/**
 * player_draw_rigth _ function to draw player that going right
 * @win: the struct that hold window's
 * @game: the struct that hold array's that store images
 * @x: the player coordinate in row
 * @y: the player coordinate in column
 */
void	player_draw_right(t_data win, t_game *game, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_window,
		game->player_right[game->frame], y * 50, x * 50);
}

/**
 * player_draw_up _ function to draw player that going up
 * @win: the struct that hold window's
 * @game: the struct that hold array's that store images
 * @x: the player coordinate in row
 * @y: the player coordinate in column
 */
void	player_draw_up(t_data win, t_game *game, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_window,
		game->player_up[game->frame], y * 50, x * 50);
}

/**
 * player_draw_down _ function to draw player that going down
 * @win: the struct that hold window's
 * @game: the struct that hold array's that store images
 * @x: the player coordinate in row
 * @y: the player coordinate in column
 */
void	player_draw_down(t_data win, t_game *game, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_window,
		game->player_down[game->frame], y * 50, x * 50);
}
