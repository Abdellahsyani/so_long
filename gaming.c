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

	if (!matrix || !matrix->map || !win.mlx || !win.mlx_window)
		return ;
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
	if (!game || !game->matrix || !game->matrix->map || 
		!game->win.mlx || !game->win.mlx_window)
		return (0);

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
	if (new_x < 0 || new_x >= game->matrix->row || 
		new_y < 0 || new_y >= game->matrix->col - 1)
		return (0);

	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
	{
		game->matrix->map[game->player_x][game->player_y] = '0';
		game->matrix->map[new_x][new_y] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
		mlx_clear_window(game->win.mlx, game->win.mlx_window);
		draw_game(game->win, game->matrix);
		animate_player(game);
	}
	return (0);
}

void find_player_position(t_pos *matrix, t_game *game)
{
	if (!matrix || !matrix->map || !game)
		return;

	game->player_x = -1;
	game->player_y = -1;

	for (int x = 0; x < matrix->row; x++)
	{
		if (!matrix->map[x])
			continue;
		for (int y = 0; y < matrix->col - 1; y++)
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

void	init_game(t_data win, t_game game)
{
	game.win = win;
	game.matrix = matrix;
	game.frame = 0;
	game.player_x = -1;
	game.player_y = -1;

}

void so_long(t_pos *matrix)
{
	int	img_width;
	int	img_height;

	if (!matrix || !matrix->map || matrix->row <= 0 || matrix->col <= 0)
		return;
	win.mlx = mlx_init();
	if (!win.mlx)
		return;
	win.mlx_window = mlx_new_window(win.mlx, matrix->col * 50, 
				 matrix->row * 50, "so_long");
	if (!win.mlx_window)
	{
		mlx_destroy_display(win.mlx);
		free(win.mlx);
		return;
	}
	find_player_position(matrix, &game);
	if (game.player_x == -1 || game.player_y == -1)
	{
		mlx_destroy_window(win.mlx, win.mlx_window);
		mlx_destroy_display(win.mlx);
		free(win.mlx);
		return;
	}
	game.player[0] = mlx_xpm_file_to_image(win.mlx, "tools/p_1.xpm", 
					&img_width, &img_height);
	game.player[1] = mlx_xpm_file_to_image(win.mlx, "tools/p_2.xpm", 
					&img_width, &img_height);
	game.player[2] = mlx_xpm_file_to_image(win.mlx, "tools/p_3.xpm", 
					&img_width, &img_height);
	if (!game.player[0])
	{
		mlx_destroy_window(win.mlx, win.mlx_window);
		mlx_destroy_display(win.mlx);
		free(win.mlx);
		return ;
	}

	draw_game(win, matrix);
	player_draw(win, &game, game.player_x, game.player_y);
	//mlx_hook(win.mlx_window, 17, 0, (void *)mlx_loop_end, win.mlx);  // Handle window close
	mlx_key_hook(win.mlx_window, handle_keypress, &game);
	mlx_loop(win.mlx);
}
