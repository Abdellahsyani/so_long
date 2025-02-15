/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:18:53 by asyani            #+#    #+#             */
/*   Updated: 2025/02/13 16:20:18 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	animate_player_left(t_game *game)
{
	if (!game || !game->win.mlx || !game->win.mlx_window || 
		game->player_x < 0 || game->player_y < 0)
		return ;
	game->frame = (game->frame + 1) % 3;
	if (!game->player_left[game->frame])
		game->frame = 0;  
	if (game->player_left[game->frame])
		player_draw_left(game->win, game, game->player_x, game->player_y);
}

void	animate_player_right(t_game *game)
{
	if (!game || !game->win.mlx || !game->win.mlx_window || 
		game->player_x < 0 || game->player_y < 0)
		return ;
	game->frame = (game->frame + 1) % 3;
	if (!game->player_right[game->frame])
		game->frame = 0;  
	if (game->player_right[game->frame])
		player_draw_right(game->win, game, game->player_x, game->player_y);
}

void	animate_player_up(t_game *game)
{
	if (!game || !game->win.mlx || !game->win.mlx_window || 
		game->player_x < 0 || game->player_y < 0)
		return ;
	game->frame = (game->frame + 1) % 3;
	if (!game->player_up[game->frame])
		game->frame = 0;  
	if (game->player_up[game->frame])
		player_draw_up(game->win, game, game->player_x, game->player_y);
}

void	animate_player_down(t_game *game)
{
	if (!game || !game->win.mlx || !game->win.mlx_window || 
		game->player_x < 0 || game->player_y < 0)
		return ;
	game->frame = (game->frame + 1) % 3;
	if (!game->player_down[game->frame])
		game->frame = 0;  
	if (game->player_down[game->frame])
		player_draw_down(game->win, game, game->player_x, game->player_y);
}

void	player_draw_left(t_data win, t_game *game, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_window, game->player_left[game->frame], y * 50, x * 50);
}

void	player_draw_right(t_data win, t_game *game, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_window, game->player_right[game->frame], y * 50, x * 50);
}

void	player_draw_up(t_data win, t_game *game, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_window, game->player_up[game->frame], y * 50, x * 50);
}

void	player_draw_down(t_data win, t_game *game, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_window, game->player_down[game->frame], y * 50, x * 50);
}
