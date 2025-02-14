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


void	animate_player(t_game *game)
{
	if (!game || !game->win.mlx || !game->win.mlx_window || 
		game->player_x < 0 || game->player_y < 0)
		return ;
	game->frame = (game->frame + 1) % 3;
	if (!game->player_left[game->frame])
		game->frame = 0;  
	if (game->player_left[game->frame])
		player_draw(game->win, game, game->player_x, game->player_y);
}

void	player_draw(t_data win, t_game *game, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_window, game->player_left[game->frame], y * 50, x * 50);
}
