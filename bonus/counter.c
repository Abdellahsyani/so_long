/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:37:05 by asyani            #+#    #+#             */
/*   Updated: 2025/02/18 19:39:50 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * handle_close _ function to handle exit window
 * @game: the struct that contains all info
 */
int	handle_close(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->win.mlx, game->win.mlx_window);
	free_map(game->matrix->map);
	exit(1);
	return (0);
}

/**
 * handle_enemy _ th function that handle enemy speed and movements
 * @game: the struct that hold enemy
 */
void	handle_enemy(t_game *game)
{
	static int	frame_counter;
	int			i;

	frame_counter = 0;
	i = 0;
	frame_counter++;
	if (frame_counter % 2000 == 0)
	{
		while (i < game->enemy_count)
		{
			move_enemy(game, i);
			i++;
		}
	}
}

/**
 * ft_itoa _ the function that convert integer to string
 * @n: the number that we are convert to string 
 * 
 * return: the number converted to string
 */
static char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		temp;

	len = 1;
	temp = n;
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

/**
 * display_moves _ the function that display moves in teh screen
 * @game: the struct that contains all info and counter
 */
void	display_moves(t_game *game)
{
	char	*move_count;

	wall_draw(game, 0, 1);
	move_count = ft_itoa(game->counter);
	mlx_string_put(game->win.mlx, game->win.mlx_window, 20, 20, 0x12FD41,
		"Moves: ");
	mlx_string_put(game->win.mlx, game->win.mlx_window, 80, 20, 0xFFFF11,
		move_count);
	free(move_count);
}
