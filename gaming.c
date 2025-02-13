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


void init_game(t_data *win, t_game *game, t_pos *matrix)
{
	int	img_width;
	int	img_height;

	game->frame = 0;
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
	game->player[0] = mlx_xpm_file_to_image(win->mlx, "tools/p_1.xpm", &img_width, &img_height);
	game->player[1] = mlx_xpm_file_to_image(win->mlx, "tools/p_2.xpm", &img_width, &img_height);
	game->player[2] = mlx_xpm_file_to_image(win->mlx, "tools/p_3.xpm", &img_width, &img_height);
	if (!game->player[0] || !game->player[1] || !game->player[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}

void so_long(t_pos *matrix)
{
	t_data win;
	t_game game;

	if (!matrix || !matrix->map || matrix->row <= 0 || matrix->col <= 0)
	{
		perror("Invalid map data");
		return;
	}
	init_game(&win, &game, matrix);
	draw_game(win, matrix);
	player_draw(win, &game, game.player_x, game.player_y);
	mlx_key_hook(win.mlx_window, handle_keypress, &game);

	mlx_loop(win.mlx);
}
