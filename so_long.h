/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:57:59 by asyani            #+#    #+#             */
/*   Updated: 2025/02/07 16:45:49 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "mlx.h"
# include "../get_next_line/get_next_line.h"

typedef struct	s_pos
{
	int	coin;
	int	player;
	int	exit;
	int	row;
	int	col;
}		t_pos;

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_window;
	void	*img;
	char	*data;
	int	color;
	int	*addr;
	int	bpp;
	int	size_len;
	int	endian;
}		t_data;

void			free_map(char **map);
void	ft_error(char **map, t_pos *matrix);
void	verify_map(char **map, t_pos *matrix);
void	check_inside(char **map, t_pos *matrix);
void	check_map(char **map, t_pos *matrix);
void	fill_map(char **map, t_pos *matrix);
char	**allocation(char **map, t_pos *matrix);
void			pars_map(int fd);
void	flood_fill(char **map, t_pos *matrix, int x, int y);
void	draw_game(char **map, t_data win, t_pos *matrix);
void	so_long(char **map, t_pos *matrix);

/* all tools about game */
void	floor_draw(t_data win, int x, int y);
void	wall_draw(t_data win, int x, int y);
void	coins_draw(t_data win, int x, int y);
void	player_draw(t_data win, int x, int y);
void	exit_draw(t_data win, int x, int y);

#endif
