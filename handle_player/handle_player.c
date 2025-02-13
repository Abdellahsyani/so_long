/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:22:09 by asyani            #+#    #+#             */
/*   Updated: 2025/02/13 16:25:39 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	execute_key(t_game *game, int new_x, int new_y)
{
	game->matrix->map[game->player_x][game->player_y] = '0';
	game->matrix->map[new_x][new_y] = 'P';
	floor_draw(game->win, game->player_x, game->player_y);
	game->player_x = new_x;
	game->player_y = new_y;
	animate_player(game);
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
	if (keycode == 65361 || keycode == 'a') 
		new_y--;
	if (keycode == 65363 || keycode == 'd')
		new_y++;
	if (keycode == 65362 || keycode == 'w')
		new_x--;
	if (keycode == 65364 || keycode == 's')
		new_x++;
	if (new_x < 0 || new_x >= game->matrix->row || 
		new_y < 0 || new_y >= game->matrix->col - 1)
		return (0);
	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
		execute_key(game, new_x, new_y);
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
