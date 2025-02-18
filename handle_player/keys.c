/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:38:35 by asyani            #+#    #+#             */
/*   Updated: 2025/02/16 13:42:23 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


char    *ft_itoa(int n)
{
	char    *str;
	int     len = 1, temp = n;

	while (temp /= 10)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

void	display_moves(t_game *game)
{
	char *move_count;

	wall_draw(game->win, 0, 1);
	move_count = ft_itoa(game->counter);
	mlx_string_put(game->win.mlx, game->win.mlx_window, 20, 20, 0x12FD41, "Moves: ");
	mlx_string_put(game->win.mlx, game->win.mlx_window, 80, 20, 0xFFFF11, move_count);
	free(move_count);
}

/**
 * key_left_helper _  the function to help execute keys
 * @game: the struct that contains all data
 * @new_x: the new position of the player
 * @new_y: the new position of the player
 */
void	key_left_helper(t_game *game, int new_x, int new_y)
{
	new_y--;
	game->counter += 1;
	if (new_x < 0 || new_x >= game->matrix->row || 
		new_y < 0 || new_y >= game->matrix->col - 1)
		return ;
	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
	{
		if (game->matrix->map[new_x][new_y] != 'E' || game->matrix->coin == 0)
		{
			execute_key_left(game, new_x, new_y);
			write_number(game->counter);
			write(1, "\n", 1);
			display_moves(game);
		}
	}
}

/**
 * key_right_helper _  the function to help execute keys
 * @game: the struct that contains all data
 * @new_x: the new position of the player
 * @new_y: the new position of the player
 */
void	key_right_helper(t_game *game, int new_x, int new_y)
{
	new_y++;
	game->counter += 1;
	if (new_x < 0 || new_x >= game->matrix->row || 
		new_y < 0 || new_y >= game->matrix->col - 1)
		return ;
	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
	{
		if (game->matrix->map[new_x][new_y] != 'E' || game->matrix->coin == 0)
		{
			execute_key_right(game, new_x, new_y);
			write_number(game->counter);
			write(1, "\n", 1);
			display_moves(game);
		}
	}
}

/**
 * key_up_helper _  the function to help execute keys
 * @game: the struct that contains all data
 * @new_x: the new position of the player
 * @new_y: the new position of the player
 */
void	key_up_helper(t_game *game, int new_x, int new_y)
{
	new_x--;
	game->counter += 1;
	if (new_x < 0 || new_x >= game->matrix->row || 
		new_y < 0 || new_y >= game->matrix->col - 1)
		return ;
	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
	{
		if (game->matrix->map[new_x][new_y] != 'E' || game->matrix->coin == 0)
		{
			execute_key_up(game, new_x, new_y);
			write_number(game->counter);
			write(1, "\n", 1);
			display_moves(game);
		}
	}
}

/**
 * key_down_helper _  the function to help execute keys
 * @game: the struct that contains all data
 * @new_x: the new position of the player
 * @new_y: the new position of the player
 */
void	key_down_helper(t_game *game, int new_x, int new_y)
{
	new_x++;
	game->counter++;
	if (new_x < 0 || new_x >= game->matrix->row || 
		new_y < 0 || new_y >= game->matrix->col - 1)
		return ;
	if (game->matrix->map[new_x] && game->matrix->map[new_x][new_y] != '1')
	{
		if (game->matrix->map[new_x][new_y] != 'E' || game->matrix->coin == 0)
		{
			execute_key_down(game, new_x, new_y);
			write_number(game->counter);
			write(1, "\n", 1);
			display_moves(game);
		}
	}
}
