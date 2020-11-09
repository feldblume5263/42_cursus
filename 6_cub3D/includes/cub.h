/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:24:11 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/08 19:23:35 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include "gnl.h"
# include "../libft/libft.h"

# define USE_MATH_DEFINES
# define TILE_SIZE				64
# define MAP_ROWS				11
# define MAP_COLS				15

# define WINDOW_WIDTH			MAP_COLS * TILE_SIZE
# define WINDOW_HEIGHT			MAP_ROWS * TILE_SIZE
# define TO_COORD(X, Y)			((int)floor(Y) * WINDOW_WIDTH + (int)floor(X)) // TO DO

# define FOV					60 * (M_PI / 180)
# define WALL_STRIP_WIDTH		1
# define RAYS					(WINDOW_WIDTH / WALL_STRIP_WIDTH) * 1.0

# define MINI					0.2

# define KEY_ESC				53
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

# define TEX_WIDTH				64
# define TEX_HEIGHT				64

# define R						1
# define NO						2
# define SO						3
# define WE						4
# define EA						5
# define S						6
# define F						7
# define C						8
# define M						9

# define INT_MAX				2147483647

typedef struct	s_tex
{
	char		*tex_path;
	int			*texture;
	double		width;
	double		height;
}				t_tex;

typedef struct	s_ray
{
	double		ray_angle;
	double		hit_x;
	double		hit_y;
	double		distance;
	double		h_x;
	double		h_y;
	double		v_x;
	double		v_y;
	double		verti_flag;
	double		horiz_flag;
	double		is_up;
	double		is_down;
	double		is_left;
	double		is_right;
	double		x_intercept;
	double		y_intercept;
	double		x_step;
	double		y_step;
}				t_ray;

typedef struct	s_config
{
	int			p_x;
	int			p_y;
	int			p_flag;
	int			width;
	int			height;
	int			rows;
	int			colums;
	double		tile_size;
	t_tex		tex[TEXTURES];
	int			floor_color;
	int			ceiling_color;
	char		**map;
	double		fov;
}				t_config;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_player
{
	double		x;
	double		y;
	double		radius;
	double		turn_dir;
	double		walk_dir;
	double		rot_angle;
	double		mv_speed;
	double		rot_speed;
}				t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			map[MAP_ROWS][MAP_COLS];
	t_player	*p;
	t_ray		**r;
	t_config	conf;
}				t_game;

int				main(int argc, char *argv[]);
int				main_loop(t_game *gm);

void			window_init(t_game *gm);
void			img_init(t_game *gm);
void			map_init(t_game *gm, char *map);
void			player_init(t_game *gm);
void			rays_init(t_game *gm);
void			ray_init(t_game *gm, int idx);
void			config_init(t_game *gm);

char			*parse_data(t_game *gm, char *path);
int				flag_blank(char *d);
int				flag_data(char *d);
int				is_map(char *d);
char			*put_config(t_game *g, char *d, int f, char *temp);

void			draw_rectangles(t_game *gm);
void			draw_rectangle(t_game *gm, int x, int y, int color);
void			draw_lines(t_game *gm);
void			draw_line(t_game *gm, double x1, double y1, double x2, double y2);

void			draw_player(t_game *gm);
int				player_keypressed(int keycode, t_player *player);
int				player_keyReleased(int keycode, t_player *player);
void			draw_view(t_game *gm);
void			update_player(t_game *gm);

void			cast_rays(t_game *gm);
void			draw_ray(t_game *gm, double ray_angle, int idx);
void			cast_ray(t_game *gm, int idx);

void			cast_horiz(t_game *gm, int idx);
void			cast_verti(t_game *gm, int idx);
int				intercept_horiz(t_game *gm, int idx);
int				intercept_verti(t_game *gm, int idx);

void			rendering(t_game *gm);
void			render_wall(t_game *gm, int idx, int top, int bot);
int				get_wall_type(t_game *gm, int idx);
int				get_wall_color(t_game *gm, int idx, int landscape, int type);

void			load_texture(t_game *game);
int				*load_image(t_game *game, char *path, t_img *tex, int i);

int				is_blank(char c);
int				inspect_wall(t_game *gm, double x, double y);
double			noramalize_angle(double angle);
double			get_distance(double x1, double y1, double x2, double y2);

void			exit_with_error(char *message);


#endif
