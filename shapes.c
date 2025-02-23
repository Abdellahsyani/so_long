/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:25:09 by asyani            #+#    #+#             */
/*   Updated: 2025/02/08 18:56:45 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * coins_draw _ the function that draw coins
 * @win: a struct that contains information about mlx
 * @x: the coordinate of each frame that acts coin
 * @y: the coordinate of each frame that acts coin
 */
void	coins_draw(t_game *game, int x, int y)
{
	void	*coins;
	int	img_width;
	int	img_height;

	coins = mlx_xpm_file_to_image(game->win.mlx, "tools/coin.xpm", &img_width, &img_height);
	if (!coins)
	{
		perror("fail to draw coin");
		return ;
	}
	mlx_put_image_to_window(game->win.mlx, game->win.mlx_window, coins, y * 50, x * 50);
	mlx_destroy_image(game->win.mlx, coins);
}

/**
 * exit_draw _ the function that draw exit
 * @win: a struct that contains information about mlx
 * @x: the coordinate of each frame that acts exit
 * @y: the coordinate of each frame that acts exit
 */
void	exit_draw(t_game *game, int x, int y)
{
	void	*exit_door;
	int	img_width;
	int	img_height;

	exit_door = mlx_xpm_file_to_image(game->win.mlx, "tools/door2.xpm", &img_width, &img_height);
	if (!exit_door)
	{
		perror("fail to draw exit");
		return ;
	}
	mlx_put_image_to_window(game->win.mlx, game->win.mlx_window, exit_door, y * 50, x * 50);
	mlx_destroy_image(game->win.mlx, exit_door);
}

/**
 * wall_draw _ the function that draw wall
 * @win: a struct that contains information about mlx
 * @x: the coordinate of each frame that acts wall
 * @y: the coordinate of each frame that acts wall
 */
void	wall_draw(t_game *game, int x, int y)
{
	void	*wall;
	int	img_width;
	int	img_height;

	wall = mlx_xpm_file_to_image(game->win.mlx, "tools/wall.xpm", &img_width, &img_height);
	if (!wall)
	{
		perror("fail to draw wall");
		return ;
	}
	mlx_put_image_to_window(game->win.mlx, game->win.mlx_window, wall, y * 50, x * 50);
	mlx_destroy_image(game->win.mlx, wall);
}

/**
 * floor_draw _ the function that draw floor
 * @win: a struct that contains information about mlx
 * @x: the coordinate of each frame that acts floor
 * @y: the coordinate of each frame that acts floor
 */
void	floor_draw(t_game *game, int x, int y)
{
	void	*floor;
	int	img_width;
	int	img_height;

	floor = mlx_xpm_file_to_image(game->win.mlx, "tools/floor.xpm", &img_width, &img_height);
	if (!floor)
	{
		perror("fail to draw floor");
		return ;
	}
	mlx_put_image_to_window(game->win.mlx, game->win.mlx_window, floor, y * 50, x * 50);
	mlx_destroy_image(game->win.mlx, floor);
}

/**
 * enemy_draw _ function to draw enemy to atack player
 * @game: a struct that contains mlx
 * @x: coordinate of enemy
 * @y: coordinate of enemy
 */
void	enemy_draw(t_game *game, int x, int y)
{
	void	*enemy;
	int	img_width;
	int	img_height;

	enemy = mlx_xpm_file_to_image(game->win.mlx, "tools/enimy.xpm", &img_width, &img_height);
	if (!enemy)
	{
		perror("fail tp draw enemy");
		return ;
	}
	mlx_put_image_to_window(game->win.mlx, game->win.mlx_window, enemy, y * 50, x * 50);
	mlx_destroy_image(game->win.mlx, enemy);
}
