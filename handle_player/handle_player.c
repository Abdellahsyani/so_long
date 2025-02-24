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

/**
 * free_images _ the function that free all player images
 * @game: a struct that contains info
 */
void	free_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->player_left[i])
			mlx_destroy_image(game->win.mlx, game->player_left[i]);
		if (game->player_right[i])
			mlx_destroy_image(game->win.mlx, game->player_right[i]);
		if (game->player_up[i])
			mlx_destroy_image(game->win.mlx, game->player_up[i]);
		if (game->player_down[i])
			mlx_destroy_image(game->win.mlx, game->player_down[i]);
		i++;
	}
}

/**
 * exit_game _ the function that exit the game
 * @game: the struct that contains info about player and all
 */
void	exit_game(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->win.mlx, game->win.mlx_window);
	mlx_destroy_display(game->win.mlx);
	free(game->win.mlx);
	free_map(game->matrix->map);
	exit(1);
}

/**
 * handle_keypress _ function to handle the press key
 * @keycode: a variable to track keys
 * @game: struct tha contains all info
 *
 * return: 0 if failure
 */
int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (!game || !game->matrix || !game->matrix->map
		|| !game->win.mlx || !game->win.mlx_window)
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

/**
 * find_player_position _ a function that find the player position
 * @matrix:  the struct that contains info about player
 * @game: a second struct
 */
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
		while (y < matrix->col)
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
