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

void	so_long(char **map)
{
	void	*mlx;
	void	*mlx_window;
	void	*img;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 2000, 2000, "so_long");
	img = mlx_new_image(mlx, 1000. 1000);
	mlx_get_data_addr();

	mlx_loop(mlx);
}
