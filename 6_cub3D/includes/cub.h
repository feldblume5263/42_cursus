/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:24:11 by junhpark          #+#    #+#             */
/*   Updated: 2020/10/16 18:41:11 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"

# define USE_MATH_DEFINES
# define TILE_SIZE				32
# define MAP_ROWS				11
# define MAP_COLS				15
# define TILE_SIZE				32

# define WINDOW_WIDTH			MAP_COLS * TILE_SIZE
# define WINDOW_HEIGHT			MAP_ROWS * TILE_SIZE
# define TO_COORD(X, Y)			((int)floor(Y) * WINDOW_WIDTH + (int)floor(X))

# define FOV					60 * (M_PI / 180)
# define WALL_STRIP_WIDTH		4
# define RAYS					WINDOW_WIDTH / WALL_STRIP_WIDTH

# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define TEXTURES				5
# define TEX_NORTH				0
# define TEX_SOUTH				1
# define TEX_WEST				2
# define TEX_EAST				3
# define TEX_SPRITE				4

typedef struct	s_tex
{
	char		*tex_path;
	int			*texture;
	double		width;
	double		height;
}				t_tex;

typedef struct	s_config
{
	int			width;
	int			height;
	int			rows;
	int			colums;
	double		tile;
	t_tex		tex[TEXTURES];
	int			floor_color;
	int			ceiling_color;
	char		**map;
	double		rotation_speed;
	double		move_speed;
}				t_config;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_player
{
	int			x;
	int			y;
	double		radius;
	double		turnDirection;
	double		walkDirection;
	double		rotationAngle;
	double		moveSpeed;
	double		rotationSpeed;
}				t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			map[MAP_ROWS][MAP_COLS];
	t_player	*player;
	t_config	config;
}				t_game;

int				main(void);
int				main_loop(t_game *game);

void			window_init(t_game *game);
void			img_init(t_game *game);
void			map_init(t_game *game);
void			player_init(t_game *game);
int				inspect_wall(t_game *game, double x, double y);

void			draw_rectangles(t_game *game);
void			draw_rectangle(t_game *game, int x, int y, int color);
void			draw_lines(t_game *game);
void			draw_line(t_game *game, double x1, double y1, double x2, double y2);

void			draw_player(t_game *game);
int				player_keypressed(int keycode, t_player *player);
int				player_keyReleased(int keycode, t_player *player);
void			draw_view(t_game *game);
void			update_player(t_game *game);

#endif
