/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:01:47 by asyani            #+#    #+#             */
/*   Updated: 2025/02/16 10:07:02 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * you_loser _ function to handle when enemy atack player
 * @game: a struct that contains everything about the game
 */
static void	you_loser(t_game *game)
{
	ft_putstr_fd("❌❌❌❌❌❌❌❌❌❌❌\n", 2);
	ft_putstr_fd("😅 You are out of the game\n", 2);
	exit_game(game);
}

/**
 * execute_key_left _ the fucntion to execute key left
 * @game: the struct that contains all information's
 * @new_x: the new coordinate of the player
 * @new_y: the new coordinate of the player
 */
void	execute_key_left(t_game *game, int new_x, int new_y)
{
	int	exit_x;
	int	exit_y;

	exit_x = game->matrix->exit_x;
	exit_y = game->matrix->exit_y;
	game->matrix->map[game->player_x][game->player_y] = '0';
	if (game->matrix->map[new_x][new_y] == 'C')
		game->matrix->coin--;
	if (game->matrix->map[new_x][new_y] == 'N')
		you_loser(game);
	game->matrix->map[new_x][new_y] = 'P';
	if (game->matrix->coin == 0)
	{
		exit_draw(game, exit_x, exit_y);
		if (game->matrix->map[new_x][new_y] ==
			game->matrix->map[exit_x][exit_y])
		{
			ft_putstr_fd("Game Over 🥳\n", 1);
			exit_game(game);
		}
	}
	floor_draw(game, game->player_x, game->player_y);
	game->player_x = new_x;
	game->player_y = new_y;
	animate_player_left(game);
}

/**
 * execute_key_right _ the fucntion to execute key right
 * @game: the struct that contains all information's
 * @new_x: the new coordinate of the player
 * @new_y: the new coordinate of the player
 */
void	execute_key_right(t_game *game, int new_x, int new_y)
{
	int	exit_x;
	int	exit_y;

	exit_x = game->matrix->exit_x;
	exit_y = game->matrix->exit_y;
	game->matrix->map[game->player_x][game->player_y] = '0';
	if (game->matrix->map[new_x][new_y] == 'C')
		game->matrix->coin--;
	if (game->matrix->map[new_x][new_y] == 'N')
		you_loser(game);
	game->matrix->map[new_x][new_y] = 'P';
	if (game->matrix->coin == 0)
	{
		exit_draw(game, exit_x, exit_y);
		if (game->matrix->map[new_x][new_y] ==
			game->matrix->map[exit_x][exit_y])
		{
			ft_putstr_fd("Game Over 🥳\n", 1);
			exit_game(game);
		}
	}
	floor_draw(game, game->player_x, game->player_y);
	game->player_x = new_x;
	game->player_y = new_y;
	animate_player_right(game);
}

/**
 * execute_key_up _ the fucntion to execute key up
 * @game: the struct that contains all information's
 * @new_x: the new coordinate of the player
 * @new_y: the new coordinate of the player
 */
void	execute_key_up(t_game *game, int new_x, int new_y)
{
	int	exit_x;
	int	exit_y;

	exit_x = game->matrix->exit_x;
	exit_y = game->matrix->exit_y;
	game->matrix->map[game->player_x][game->player_y] = '0';
	if (game->matrix->map[new_x][new_y] == 'C')
		game->matrix->coin--;
	if (game->matrix->map[new_x][new_y] == 'N')
		you_loser(game);
	game->matrix->map[new_x][new_y] = 'P';
	if (game->matrix->coin == 0)
	{
		exit_draw(game, exit_x, exit_y);
		if (game->matrix->map[new_x][new_y] ==
			game->matrix->map[exit_x][exit_y])
		{
			ft_putstr_fd("Game Over 🥳\n", 1);
			exit_game(game);
		}
	}
	floor_draw(game, game->player_x, game->player_y);
	game->player_x = new_x;
	game->player_y = new_y;
	animate_player_up(game);
}

/**
 * execute_key_down _ the fucntion to execute key down
 * @game: the struct that contains all information's
 * @new_x: the new coordinate of the player
 * @new_y: the new coordinate of the player
 */
void	execute_key_down(t_game *game, int new_x, int new_y)
{
	int	exit_x;
	int	exit_y;

	exit_x = game->matrix->exit_x;
	exit_y = game->matrix->exit_y;
	game->matrix->map[game->player_x][game->player_y] = '0';
	if (game->matrix->map[new_x][new_y] == 'C')
		game->matrix->coin--;
	if (game->matrix->map[new_x][new_y] == 'N')
		you_loser(game);
	game->matrix->map[new_x][new_y] = 'P';
	if (game->matrix->coin == 0)
	{
		exit_draw(game, exit_x, exit_y);
		if (game->matrix->map[new_x][new_y] ==
			game->matrix->map[exit_x][exit_y])
		{
			ft_putstr_fd("Game Over 🥳\n", 1);
			exit_game(game);
		}
	}
	floor_draw(game, game->player_x, game->player_y);
	game->player_x = new_x;
	game->player_y = new_y;
	animate_player_down(game);
}
