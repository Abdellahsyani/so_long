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

# define WIN_WIDTH 50
# define WIN_HEIGHT 50

typedef struct	s_pos
{
	int	coin;
	int	player;
	int	exit;
	int	row;
	int	col;
	char	**map;
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

typedef struct	s_game
{
	void	*player[3];
	int frame;
}		t_game;


void	ft_putstr_fd(char *s, int fd);
void			free_map(char **map);
void	ft_error(t_pos *matrix);
void	verify_map(t_pos *matrix);
void	check_inside(t_pos *matrix);
void	check_map(t_pos *matrix);
void	fill_map(t_pos *matrix, char **av);
void	allocation(t_pos *matrix);
void			pars_map(int fd, char **av);
void	flood_fill(t_pos *matrix, int x, int y);
void	draw_game(t_data win, t_pos *matrix);
void	so_long(t_pos *matrix);

/* all tools about game */
void	floor_draw(t_data win, int x, int y);
void	wall_draw(t_data win, int x, int y);
void	coins_draw(t_data win, int x, int y);
void	player_draw(t_data win, int x, int y);
void	exit_draw(t_data win, int x, int y);

#endif
