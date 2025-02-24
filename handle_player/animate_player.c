/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:15:55 by asyani            #+#    #+#             */
/*   Updated: 2025/02/16 09:16:45 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * animate_player_left _ the function that set animation in player left
 * @game: the struct that hold all information about player
 */
void	animate_player_left(t_game *game)
{
	if (!game || !game->win.mlx || !game->win.mlx_window
		|| game->player_x < 0 || game->player_y < 0)
		return ;
	game->frame = (game->frame + 1) % 3;
	if (!game->player_left[game->frame])
		game->frame = 0;
	if (game->player_left[game->frame])
		player_draw_left(game->win, game, game->player_x, game->player_y);
}

/**
 * animate_player_right _ the function that set animation in player right
 * @game: the struct that hold all information about player
 */
void	animate_player_right(t_game *game)
{
	if (!game || !game->win.mlx || !game->win.mlx_window
		|| game->player_x < 0 || game->player_y < 0)
		return ;
	game->frame = (game->frame + 1) % 3;
	if (!game->player_right[game->frame])
		game->frame = 0;
	if (game->player_right[game->frame])
		player_draw_right(game->win, game, game->player_x, game->player_y);
}

/**
 * animate_player_up _ the function that set animation in player up
 * @game: the struct that hold all information about player
 */
void	animate_player_up(t_game *game)
{
	if (!game || !game->win.mlx || !game->win.mlx_window
		|| game->player_x < 0 || game->player_y < 0)
		return ;
	game->frame = (game->frame + 1) % 3;
	if (!game->player_up[game->frame])
		game->frame = 0;
	if (game->player_up[game->frame])
		player_draw_up(game->win, game, game->player_x, game->player_y);
}

/**
 * animate_player_down _ the function that set animation in player down
 * @game: the struct that hold all information about player
 */
void	animate_player_down(t_game *game)
{
	if (!game || !game->win.mlx || !game->win.mlx_window
		|| game->player_x < 0 || game->player_y < 0)
		return ;
	game->frame = (game->frame + 1) % 3;
	if (!game->player_down[game->frame])
		game->frame = 0;
	if (game->player_down[game->frame])
		player_draw_down(game->win, game, game->player_x, game->player_y);
}
