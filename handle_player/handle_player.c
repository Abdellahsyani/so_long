/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:22:09 by asyani            #+#    #+#             */
/*   Updated: 2025/02/16 13:42:31 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*int	idle_animate(t_game *game)*/
/*{*/
/*	static int direction = 1;*/
/*	if (game->jumping == 1)*/
/*	{*/
/*		game->jump_offset += direction;*/
/*		if (game->jump_offset > 5 || game->jump_offset < -5)*/
/*			direction *= -1;*/
/*	}*/
/*	player_draw(game->win, game, game->player_x, game->player_y);*/
/*	return (0);*/
/*}*/


static void exit_game(t_game *game)
{
    if (game->win.mlx)
    {
        mlx_destroy_window(game->win.mlx, game->win.mlx_window);
        mlx_destroy_display(game->win.mlx);
        free(game->win.mlx);
    }
    if (game->matrix && game->matrix->map)
    {
        free_map(game->matrix->map);
        free(game->matrix);
    }

    exit(1);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (!game || !game->matrix || !game->matrix->map || 
		!game->win.mlx || !game->win.mlx_window)
		return (0);
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_LEFT || keycode == 'a') 
		key_left_helper(game, new_x, new_y);
	if (keycode == KEY_RIGHT || keycode == 'd')
		key_right_helper(game, new_x, new_y);
	if (keycode == KEY_UP || keycode == 'w')
		key_up_helper(game, new_x, new_y);
	if (keycode == KEY_DOWN || keycode == 's')
		key_down_helper(game, new_x, new_y);
	if (keycode == ESC_KEY)
		exit_game(game);
	return (0);
}

void	find_player_position(t_pos *matrix, t_game *game)
{
	int	x;
	int	y;

	if (!matrix || !matrix->map || !game)
		return ;
	game->player_x = -1;
	game->player_y = -1;
	x = 0;
	while (x < matrix->row)
	{
		y = 0;
		while (y < matrix->col - 1)
		{
			if (matrix->map[x][y] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
