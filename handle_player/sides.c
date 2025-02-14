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

void	p_left(t_game *game, t_data *win)
{
	int	img_width;
	int	img_height;

	game->player_left[0] = mlx_xpm_file_to_image(win->mlx, "tools/p2_left.xpm", &img_width, &img_height);
	game->player_left[1] = mlx_xpm_file_to_image(win->mlx, "tools/p1_left.xpm", &img_width, &img_height);
	game->player_left[2] = mlx_xpm_file_to_image(win->mlx, "tools/p3_left.xpm", &img_width, &img_height);
	if (!game->player_left[0] || !game->player_left[1] || !game->player_left[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}

void	p_right(t_game *game, t_data *win)
{
	int	img_width;
	int	img_height;

	game->player_right[0] = mlx_xpm_file_to_image(win->mlx, "tools/p2_right.xpm", &img_width, &img_height);
	game->player_right[1] = mlx_xpm_file_to_image(win->mlx, "tools/p1_right.xpm", &img_width, &img_height);
	game->player_right[2] = mlx_xpm_file_to_image(win->mlx, "tools/p3_right.xpm", &img_width, &img_height);
	if (!game->player_right[0] || !game->player_right[1] || !game->player_right[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}

void	p_up(t_game *game, t_data *win)
{
	int	img_width;
	int	img_height;

	game->player_up[0] = mlx_xpm_file_to_image(win->mlx, "tools/p2_up.xpm", &img_width, &img_height);
	game->player_up[1] = mlx_xpm_file_to_image(win->mlx, "tools/p1_up.xpm", &img_width, &img_height);
	game->player_up[2] = mlx_xpm_file_to_image(win->mlx, "tools/p3_up.xpm", &img_width, &img_height);
	if (!game->player_up[0] || !game->player_up[1] || !game->player_up[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}

void	p_down(t_game *game, t_data *win)
{
	int	img_width;
	int	img_height;

	game->player_down[0] = mlx_xpm_file_to_image(win->mlx, "tools/p2_down.xpm", &img_width, &img_height);
	game->player_down[1] = mlx_xpm_file_to_image(win->mlx, "tools/p1_down.xpm", &img_width, &img_height);
	game->player_down[2] = mlx_xpm_file_to_image(win->mlx, "tools/p3_down.xpm", &img_width, &img_height);
	if (!game->player_down[0] || !game->player_down[1] || !game->player_down[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}
