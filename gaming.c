/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:43:50 by asyani            #+#    #+#             */
/*   Updated: 2025/02/07 17:06:15 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_shapes(t_data win, t_pos *matrix, int x, int y)
{
	if (matrix->map[x][y] == 'C')
		coins_draw(win, x, y);
	if (matrix->map[x][y] == 'E')
		exit_draw(win, x, y);
}

void	draw_game(t_data win, t_pos *matrix)
{
	int	x;
	int	y;

	x = 0;
	while (x < matrix->row)
	{
		y = 0;
		while (y < matrix->col - 1)
		{
			if (matrix->map[x][y] == '1')
				wall_draw(win, x, y);
			else 
				floor_draw(win, x, y);
			draw_shapes(win, matrix, x, y);
			y++;
		}
		x++;
	}
}

int handle_keypress(int keycode, t_game *game)
{
	int new_x = game->player_x;
	int new_y = game->player_y;

	if (keycode == 65361 || keycode == 'a') 
		new_y--;
	if (keycode == 65363 || keycode == 'd')
		new_y++;
	if (keycode == 65362 || keycode == 'w')
		new_x--;
	if (keycode == 65364 || keycode == 's')
		new_x++;
	if (game->matrix->map[new_x][new_y] != '1')
	{
		game->matrix->map[game->player_x][game->player_y] = '0';
		game->matrix->map[new_x][new_y] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
		animate_player(game);
	}
	return (0);
}

void find_player_position(t_pos *matrix, t_game *game)
{
	int x, y;

	for (x = 0; x < matrix->row; x++)
	{
		for (y = 0; y < matrix->col - 1; y++)
		{
			if (matrix->map[x][y] == 'P')  
			{
				game->player_x = x;
				game->player_y = y;
				return;
			}
		}
	}
}

void so_long(t_pos *matrix)
{
	t_data win;
	t_game game;
	int	img_width;
	int	img_height;

	win.mlx = mlx_init();
	win.mlx_window = mlx_new_window(win.mlx, matrix->col * WIN_WIDTH, matrix->row * WIN_HEIGHT, "so_long");

	game.win = win;
	game.matrix = matrix;
	game.frame = 0;

	find_player_position(matrix, &game);

	game.player[0] = mlx_xpm_file_to_image(win.mlx, "tools/p_1.xpm", &img_width, &img_height);
	game.player[1] = mlx_xpm_file_to_image(win.mlx, "tools/p_2.xpm", &img_width, &img_height);
	game.player[2] = mlx_xpm_file_to_image(win.mlx, "tools/p_3.xpm", &img_width, &img_height);

	draw_game(win, matrix);
	player_draw(win, &game, game.player_x, game.player_y);

	mlx_key_hook(win.mlx_window, handle_keypress, &game);

	mlx_loop(win.mlx);
}

/*void	so_long(t_pos *matrix)*/
/*{*/
/*	t_data	win;*/
/**/
/*	win.mlx = mlx_init();*/
/*	win.mlx_window = mlx_new_window(win.mlx, (matrix->col - 1) * WIN_WIDTH, matrix->row * WIN_HEIGHT, "so_long");*/
/**/
/*	draw_game(win, matrix);*/
/*	mlx_loop_hook(win.mlx, update_frame, matrix);*/
/**/
/*	mlx_loop(win.mlx);*/
/*}*/
