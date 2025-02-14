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

	game->player[0] = mlx_xpm_file_to_image(win->mlx, "tools/p2.xpm", &img_width, &img_height);
	game->player[1] = mlx_xpm_file_to_image(win->mlx, "tools/p1.xpm", &img_width, &img_height);
	game->player[2] = mlx_xpm_file_to_image(win->mlx, "tools/p3.xpm", &img_width, &img_height);
	if (!game->player[0] || !game->player[1] || !game->player[2])
	{
		perror("Failed to load player sprites");
		exit(1);
	}
	game->win = *win;
}
