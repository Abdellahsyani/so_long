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

/**
 * draw_shapes _ the function that draw coin and enemy
 * @game: struct that hold coin and enemy
 * @x: row coordinate
 * @y: column cooradinate
 */
void	draw_shapes(t_game *game, int x, int y)
{
	if (game->matrix->map[x][y] == 'C')
		coins_draw(game, x, y);
	if (game->matrix->map[x][y] == 'N')
	{
		game->enemy_arr[game->enemy_count].enemy_x = x;
		game->enemy_arr[game->enemy_count].enemy_y = y;
		game->enemy_count++;
		enemy_draw(game, x, y);
	}
}

/**
 * draw_game _ function to draw all game
 * @game: struct that hold all things
 */
void	draw_game(t_game *game)
{
	int	x;
	int	y;

	if (!game->matrix || !game->matrix->map || !game->win.mlx
		|| !game->win.mlx_window)
		return ;
	x = 0;
	while (x < game->matrix->row)
	{
		y = 0;
		while (y < game->matrix->col)
		{
			if (game->matrix->map[x][y] == '1')
				wall_draw(game, x, y);
			else
				floor_draw(game, x, y);
			draw_shapes(game, x, y);
			y++;
		}
		x++;
	}
}

/**
 * all_arrays _ a function that fill all arrays by players image
 * @game: struct that hold all things
 * @win: struct that hold windows
 */
void	all_arrays(t_game *game, t_data *win)
{
	p_left(game, win);
	p_right(game, win);
	p_up(game, win);
	p_down(game, win);
}

/**
 * init_game _ the function that initiliaze the game
 * @win: struct that hold window's
 * @game: struct that hold all info
 * @matrix: struct that hold map
 */
void	init_game(t_data *win, t_game *game, t_pos *matrix)
{
	game->frame = 0;
	game->counter = 0;
	game->player_x = -1;
	game->player_y = -1;
	game->matrix = matrix;
	game->enemy_count = 0;
	win->mlx = mlx_init();
	if (!win->mlx)
	{
		ft_putstr_fd("Error: Failed to initialize MLX", 2);
		exit(1);
	}
	win->mlx_window = mlx_new_window(win->mlx, matrix->col * WIN_WIDTH,
			matrix->row * WIN_HEIGHT, "so_long");
	find_player_position(matrix, game);
	if (game->player_x == -1 || game->player_y == -1)
	{
		ft_putstr_fd("Error: Player position not found", 2);
		exit(1);
	}
	all_arrays(game, win);
}

/**
 * so_long _ the function that start the  game
 * @matrix: the struct that hold map
 */
void	so_long(t_pos *matrix)
{
	t_data	win;
	t_game	game;

	if (!matrix || !matrix->map || matrix->row <= 0 || matrix->col <= 0)
	{
		ft_putstr_fd("Error: Invalid map data", 2);
		return ;
	}
	init_game(&win, &game, matrix);
	draw_game(&game);
	player_draw_down(win, &game, game.player_x, game.player_y);
	mlx_key_hook(win.mlx_window, handle_keypress, &game);
	mlx_hook(win.mlx_window, 17, 0, handle_close, &game);
	mlx_loop_hook(win.mlx, (void *)handle_enemy, &game);
	mlx_loop(win.mlx);
}
