/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:57:59 by asyani            #+#    #+#             */
/*   Updated: 2025/02/19 16:30:01 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include "mlx.h"
# include "../get_next_line/get_next_line.h"

# define WIN_WIDTH 50
# define WIN_HEIGHT 50
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define ESC_KEY 65307

typedef struct	s_pos
{
	int	exit_x;
	int	exit_y;
	int	coin;
	int	v_coin;
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
}		t_data;

typedef struct s_enemy
{
	int	enemy_x;
	int	enemy_y;
}	t_enemy;

typedef struct	s_game
{
	void	*player_left[3];
	void	*player_right[3];
	void	*player_up[3];
	void	*player_down[3];
	int	frame;
	int	counter;
	int	player_x;
	int	player_y;
	int	enemy_count;
	t_pos	*matrix;
	t_data	win;
	t_enemy enemy_arr[10];

}		t_game;

void	move_enemy(t_game *game, int i);
/* ========> error handling <======== */
void			free_map(char **map);
void	ft_error(t_pos *matrix);
void	exit_game(t_game *game);
void	free_map_copy(t_pos *matrix, char **map);
void	free_images(t_game *game);

/* =====> parsing function's <========= */
void	ft_putstr_fd(char *s, int fd);
void	verify_map(t_pos *matrix);
void	check_inside(t_pos *matrix);
void	check_map(t_pos *matrix);
void	fill_map(t_pos *matrix, char **av);
void	allocation(t_pos *matrix);
void			pars_map(int fd, char **av);
void	flood_fill(t_pos *matrix, char **map, int x, int y);

/* =========> all tools about game <========== */
int	handle_keypress(int keycode, t_game *game);
void	so_long(t_pos *matrix);
void	draw_game(t_game *game);
void	find_player_position(t_pos *matrix, t_game *game);
void	floor_draw(t_game *game, int x, int y);
void	wall_draw(t_game *game, int x, int y);
void	coins_draw(t_game *game, int x, int y);
void	player_draw(t_data win, t_game *game, int x, int y);
void	exit_draw(t_game *game, int x, int y);
int	update_frame(t_pos *matrix, t_data win, int x, int y);
void	display_moves(t_game *game);
void	enemy_draw(t_game *game, int x, int y);

/* ===========> animate players <=========== */
void	animate_player_left(t_game *game);
void	animate_player_right(t_game *game);
void	animate_player_up(t_game *game);
void	animate_player_down(t_game *game);
void	player_draw_left(t_data win, t_game *game, int x, int y);
void	player_draw_right(t_data win, t_game *game, int x, int y);
void	player_draw_up(t_data win, t_game *game, int x, int y);
void	player_draw_down(t_data win, t_game *game, int x, int y);

int	idle_animate(t_game *game);

/* ==========> fill the array's <=========== */
void	p_left(t_game *game, t_data *win);
void	p_right(t_game *game, t_data *win);
void	p_up(t_game *game, t_data *win);
void	p_down(t_game *game, t_data *win);

/* =========> helper functions <========== */
void	execute_key_left(t_game *game, int new_x, int new_y);
void	execute_key_right(t_game *game, int new_x, int new_y);
void	execute_key_up(t_game *game, int new_x, int new_y);
void	execute_key_down(t_game *game, int new_x, int new_y);
void	key_left_helper(t_game *game, int new_x, int new_y);
void	key_right_helper(t_game *game, int new_x, int new_y);
void	key_up_helper(t_game *game, int new_x, int new_y);
void	key_down_helper(t_game *game, int new_x, int new_y);
void	write_number(int num);
/*int	ft_strcmp(char *s1, char *s2);*/

#endif
