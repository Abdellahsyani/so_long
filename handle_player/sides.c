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

/**
 * move_enemy_helper _ the helper function that help move enemy
 * @game: my struct lover
 * @i: the counter
 */
void	move_enemy_helper(t_game *game, int i)
{
	game->matrix->map[game->win.x][game->win.y] = '0';
	floor_draw(game, game->win.x, game->win.y);
	if (game->matrix->map[game->win.new_x][game->win.new_y] == 'P')
		exit_game(game);
	game->matrix->map[game->win.new_x][game->win.new_y] = 'N';
	game->enemy_arr[i].enemy_x = game->win.new_x;
	game->enemy_arr[i].enemy_y = game->win.new_y;
	enemy_draw(game, game->win.new_x, game->win.new_y);
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

	game->player_left[0] = mlx_xpm_file_to_image(win->mlx, "tools/p2_left.xpm",
					      &img_width, &img_height);
	game->player_left[1] = mlx_xpm_file_to_image(win->mlx, "tools/p1_left.xpm",
					      &img_width, &img_height);
	game->player_left[2] = mlx_xpm_file_to_image(win->mlx, "tools/p3_left.xpm",
					      &img_width, &img_height);
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

	game->player_up[0] = mlx_xpm_file_to_image(win->mlx, "tools/p2_up.xpm",
					    &img_width, &img_height);
	game->player_up[1] = mlx_xpm_file_to_image(win->mlx, "tools/p1_up.xpm",
					    &img_width, &img_height);
	game->player_up[2] = mlx_xpm_file_to_image(win->mlx, "tools/p3_up.xpm",
					    &img_width, &img_height);
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

	game->player_down[0] = mlx_xpm_file_to_image(win->mlx, "tools/p2_down.xpm",
					      &img_width, &img_height);
	game->player_down[1] = mlx_xpm_file_to_image(win->mlx, "tools/p1_down.xpm",
					      &img_width, &img_height);
	game->player_down[2] = mlx_xpm_file_to_image(win->mlx, "tools/p3_down.xpm",
					      &img_width, &img_height);
	if (!game->player_down[0] || !game->player_down[1] || !game->player_down[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}
