/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:38:35 by asyani            #+#    #+#             */
/*   Updated: 2025/02/16 13:42:23 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * key_left_helper _  the function to help execute keys
 * @game: the struct that contains all data
 * @new_x: the new position of the player
 * @new_y: the new position of the player
 */
void	key_left_helper(t_game *game, int new_x, int new_y)
{
	new_y--;
	if (new_x < 0 || new_x >= game->matrix->row
		|| new_y < 0 || new_y >= game->matrix->col)
		return ;
	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
	{
		game->counter += 1;
		execute_key_left(game, new_x, new_y);
		write_number(game->counter);
		write(1, "\n", 1);
		display_moves(game);
	}
}

/**
 * key_right_helper _  the function to help execute keys
 * @game: the struct that contains all data
 * @new_x: the new position of the player
 * @new_y: the new position of the player
 */
void	key_right_helper(t_game *game, int new_x, int new_y)
{
	new_y++;
	if (new_x < 0 || new_x >= game->matrix->row
		|| new_y < 0 || new_y >= game->matrix->col)
		return ;
	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
	{
		game->counter += 1;
		execute_key_right(game, new_x, new_y);
		write_number(game->counter);
		write(1, "\n", 1);
		display_moves(game);
	}
}

/**
 * key_up_helper _  the function to help execute keys
 * @game: the struct that contains all data
 * @new_x: the new position of the player
 * @new_y: the new position of the player
 */
void	key_up_helper(t_game *game, int new_x, int new_y)
{
	new_x--;
	if (new_x < 0 || new_x >= game->matrix->row
		|| new_y < 0 || new_y >= game->matrix->col)
		return ;
	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
	{
		game->counter += 1;
		execute_key_up(game, new_x, new_y);
		write_number(game->counter);
		write(1, "\n", 1);
		display_moves(game);
	}
}

/**
 * key_down_helper _  the function to help execute keys
 * @game: the struct that contains all data
 * @new_x: the new position of the player
 * @new_y: the new position of the player
 */
void	key_down_helper(t_game *game, int new_x, int new_y)
{
	new_x++;
	if (new_x < 0 || new_x >= game->matrix->row
		|| new_y < 0 || new_y >= game->matrix->col)
		return ;
	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
	{
		game->counter++;
		execute_key_down(game, new_x, new_y);
		write_number(game->counter);
		write(1, "\n", 1);
		display_moves(game);
	}
}
