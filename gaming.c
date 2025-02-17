/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:43:50 by asyani            #+#    #+#             */
/*   Updated: 2025/02/13 16:29:22 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_shapes(t_game *game, int x, int y)
{
	if (game->matrix->map[x][y] == 'C')
		coins_draw(game->win, x, y);
	if (game->matrix->map[x][y] == 'E')
		exit_draw(game->win, x, y);
}

void	draw_game(t_game *game)
{
	int	x;
	int	y;

	if (!game->matrix || !game->matrix->map || !game->win.mlx || !game->win.mlx_window)
		return ;
	x = 0;
	while (x < game->matrix->row)
	{
		y = 0;
		while (y < game->matrix->col - 1)
		{
			if (game->matrix->map[x][y] == '1')
				wall_draw(game->win, x, y);
			else 
				floor_draw(game->win, x, y);
			draw_shapes(game, x, y);
			y++;
		}
		x++;
	}
}

void	all_arrays(t_game *game, t_data *win)
{
	p_left(game, win);
	p_right(game, win);
	p_up(game, win);
	p_down(game, win);
}

void init_game(t_data *win, t_game *game, t_pos *matrix)
{
	game->frame = 0;
	game->counter = 0;
	game->player_x = -1;
	game->player_y = -1;
	game->matrix = matrix;

	win->mlx = mlx_init();
	if (!win->mlx)
	{
		perror("Failed to initialize MLX");
		exit(1);
	}
	win->mlx_window = mlx_new_window(win->mlx, matrix->col * 50, matrix->row * 50, "so_long");
	if (!win->mlx_window)
	{
		perror("Failed to create window");
		exit(1);
	}
	find_player_position(matrix, game);
	if (game->player_x == -1 || game->player_y == -1)
	{
		perror("Player position not found");
		exit(1);
	}
	all_arrays(game, win);
}

/*void	first_handle(t_game *game, t_data *win)*/
/*{*/
/*	if (game->is_moving == 1)*/
/*		mlx_xpm_file_to_image(win->mlx, "tools/p1_down.xpm", &img_width, &img_height);*/
/*	else*/
/*}*/

void so_long(t_pos *matrix)
{
	t_data	win;
	t_game	game;

	if (!matrix || !matrix->map || matrix->row <= 0 || matrix->col <= 0)
	{
		perror("Invalid map data");
		return;
	}
	init_game(&win, &game, matrix);
	draw_game(&game);
	player_draw_down(win, &game, game.player_x, game.player_y);
	//mlx_loop_hook(win.mlx, idle_animate, &game);
	mlx_key_hook(win.mlx_window, handle_keypress, &game);

	mlx_loop(win.mlx);
}
