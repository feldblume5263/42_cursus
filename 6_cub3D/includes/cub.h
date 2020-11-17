/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:24:11 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/17 15:59:52 by Feldblume        ###   ########.fr       */
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
# include "libft.h"

# define USE_MATH_DEFINES

# define WALL_STRIP_WIDTH		1
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

typedef struct				s_flag
{
	int						r;
	int						path_n;
	int						path_s;
	int						path_e;
	int						path_w;
	int						path_i;
	int						color_f;
	int						color_c;
	int						map;
}							t_flag;


typedef struct				s_sprite
{
	int						screen_x;
	int						num_sprites;
	int						bpp;
	int						sl;
	int						end;
	int						width;
	int						height;
	double					angle;
	void					*ptr;
	int						*data;
	double					*distance;
	double					*x;
	double					*y;
	double					*buffer;
	int						draw_start_x;
	int						draw_start_y;
	int						draw_end_x;
	int						draw_end_y;
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;
}							t_sprite;

typedef struct	s_tex
{
	char		*tex_path;
	int			*texture;
	int			width;
	int			height;
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
	double		p_x;
	double		p_y;
	int			p_flag;
	int			width;
	int			height;
	int			rows;
	int			colums;
	int			tile_size;
	t_tex		tex[TEXTURES];
	int			floor_color;
	int			ceiling_color;
	int			**map;
	double		fov;
	char		nsew;
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
	double		radius;
	double		turn_dir;
	double		walk_dir;
	double		rot_angle;
	double		mv_speed;
	double		rot_speed;
	double		go_left;
	double		go_right;
}				t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	*p;
	t_ray		**r;
	t_config	conf;
	t_sprite	sprite;
	t_flag		flag;
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
int				is_map(char *d);
char			*parse_data(t_game *gm, char *path);
int				flag_blank(char *d);
int				flag_data(char *d, t_flag f);
int				is_map(char *d);
char			*put_config(t_game *g, char *d, int f, char *temp);
void			draw_rectangles(t_game *gm);
void			draw_rectangle(t_game *gm, int x, int y, int color);
void			draw_player(t_game *gm);
int				player_keypressed(int keycode, t_player *player);
int				player_keyreleased(int keycode, t_player *player);
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
int				inspect_sprite(t_game *gm, double x, double y);
double			normalize_angle(double angle);
double			get_distance(double x1, double y1, double x2, double y2);
int				to_coord(t_game *gm, double x, double y);
void			exit_with_error(char *message);
void			resize_colums(t_game *gm);
void			check_up_left(int **map, int start, int end, int flag);
void			check_down_right(int **map, int start, int end, int flag);
void			check_blank(int **map, int rows, int cols);
int				make_color(char **num);
int				get_color_value(char *hexa);
char			*make_hexa(int n, char *base);
int				safer_free_pp(void **pp);
int				safer_free_p(void *p);
void			check_player_num(t_game *g, char *d);
void			is_cub(char *file_name);
void			screenshot(t_game *game);
void			init_parsing_flag(t_game *gm);
int				inspect_t(t_flag *flag);
void			get_path_flag(t_flag *flag, int f);

int		sprite_init(t_game *g, t_sprite *sprite);
void	get_sprite_vector(t_sprite *sprite, const char direction);
void	get_sprite_position(t_game *g, t_sprite *sprite);
int		set_sprite_memory(t_game *g, t_sprite *sprite);
int		count_sprite(t_game *g);
void		render_sprite(t_game *g, t_sprite *sprite);
int		is_sprite_visible(t_game *g, const int id, const double sprite_size);
double	calculate_sprite_angle(t_game *g, const double x, const double y);
void	sort_sprite_by_distance(t_sprite *sprite);
void	get_sprite_distance(t_game *g, t_sprite *sprite);
void		draw_sprite(t_game *g, t_sprite *sprite, const double transform_y, const double sprite_size);
void		put_sprite_texture(t_game *g, int i, int j, const double sprite_size);
void	get_sprite_draw_pos(t_game *g, const double sprite_size);
double	get_transform_y(t_game *g, const int id);

#endif
