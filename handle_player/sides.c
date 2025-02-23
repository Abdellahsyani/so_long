/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_left.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:32:02 by asyani            #+#    #+#             */
/*   Updated: 2025/02/14 11:34:53 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_enemy(t_game *game, int i)
{
	int x = game->enemy_arr[i].enemy_x;
	int y = game->enemy_arr[i].enemy_y;

	int direction = rand() % 6;

	int new_x = x;
	int new_y = y;

	if (direction == 0)
		new_x--;
	if (direction == 1)
		new_x++;
	if (direction == 2)
		new_y--;
	if (direction == 3)
		new_y++;
	if (game->matrix->map[new_x][new_y] != '1' &&
		game->matrix->map[new_x][new_y] != 'C' &&
		game->matrix->map[new_x][new_y] != 'E' &&
		game->matrix->map[new_x][new_y] != 'N')
	{
		game->matrix->map[x][y] = '0';
		floor_draw(game, x, y);
		if (game->matrix->map[new_x][new_y] == 'P')
			exit_game(game);
		game->matrix->map[new_x][new_y] = 'N';
		game->enemy_arr[i].enemy_x = new_x;
		game->enemy_arr[i].enemy_y = new_y;
		enemy_draw(game, new_x, new_y);
	}
}

/**
 * p_left _ function to fill array of images: player left
 * @game: struct that contains array's
 * @win: struct that contains windows
 */
void	p_left(t_game *game, t_data *win)
{
	int	img_width;
	int	img_height;

	game->player_left[0] = mlx_xpm_file_to_image(win->mlx,
					      "tools/p2_left.xpm", &img_width, &img_height);
	game->player_left[1] = mlx_xpm_file_to_image(win->mlx,
					      "tools/p1_left.xpm", &img_width, &img_height);
	game->player_left[2] = mlx_xpm_file_to_image(win->mlx,
					      "tools/p3_left.xpm", &img_width, &img_height);
	if (!game->player_left[0] || !game->player_left[1] || !game->player_left[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}

/**
 * p_right _ function to fill array of images: player right
 * @game: struct that contains array's
 * @win: struct that contains windows
 */
void	p_right(t_game *game, t_data *win)
{
	int	img_width;
	int	img_height;

	game->player_right[0] = mlx_xpm_file_to_image(win->mlx,
					       "tools/p2_right.xpm", &img_width, &img_height);
	game->player_right[1] = mlx_xpm_file_to_image(win->mlx,
					       "tools/p1_right.xpm", &img_width, &img_height);
	game->player_right[2] = mlx_xpm_file_to_image(win->mlx,
					       "tools/p3_right.xpm", &img_width, &img_height);
	if (!game->player_right[0] || !game->player_right[1]
		|| !game->player_right[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}

/**
 * p_up _ function to fill array of images: player up
 * @game: struct that contains array's
 * @win: struct that contains windows
 */
void	p_up(t_game *game, t_data *win)
{
	int	img_width;
	int	img_height;

	game->player_up[0] = mlx_xpm_file_to_image(win->mlx,
					    "tools/p2_up.xpm", &img_width, &img_height);
	game->player_up[1] = mlx_xpm_file_to_image(win->mlx,
					    "tools/p1_up.xpm", &img_width, &img_height);
	game->player_up[2] = mlx_xpm_file_to_image(win->mlx,
					    "tools/p3_up.xpm", &img_width, &img_height);
	if (!game->player_up[0] || !game->player_up[1] || !game->player_up[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}

/**
 * p_down _ function to fill array of images: player down
 * @game: struct that contains array's
 * @win: struct that contains windows
 */
void	p_down(t_game *game, t_data *win)
{
	int	img_width;
	int	img_height;

	game->player_down[0] = mlx_xpm_file_to_image(win->mlx,
					      "tools/p2_down.xpm", &img_width, &img_height);
	game->player_down[1] = mlx_xpm_file_to_image(win->mlx,
					      "tools/p1_down.xpm", &img_width, &img_height);
	game->player_down[2] = mlx_xpm_file_to_image(win->mlx,
					      "tools/p3_down.xpm", &img_width, &img_height);
	if (!game->player_down[0] || !game->player_down[1] || !game->player_down[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}
