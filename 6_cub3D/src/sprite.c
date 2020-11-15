/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:36:22 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/15 15:08:07 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

double	get_transform_y(t_game *g, const int id)
{
	double			invdet;
	double			sprite[2];
	double			transform[2];

	sprite[0] = g->sprite.x[id] - g->conf.p_x;
	sprite[1] = g->sprite.y[id] - g->conf.p_y;
	invdet = 1.0 / (g->sprite.plane_x * g->sprite.dir_y -\
					g->sprite.dir_x * g->sprite.plane_y);
	transform[0] =\
		invdet * (g->sprite.dir_y * sprite[0] - g->sprite.dir_x * sprite[1]);
	transform[1] =\
		invdet * (-g->sprite.plane_y * sprite[0] + g->sprite.plane_x * sprite[1]);
	g->sprite.screen_x =\
		(int)((g->conf.width / 2) * (1 + -transform[0] / transform[1]));
	return (transform[1]);
}

void	get_sprite_draw_pos(t_game *g, const double sprite_size)
{
	int				sprite_width;
	int				sprite_height;
	t_sprite		*sprite;

	sprite = &g->sprite;
	sprite_width = sprite_size;
	sprite_height = sprite_width;
	sprite->draw_start_x = -sprite_width / 2 + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite_width / 2 + sprite->screen_x;
	if (sprite->draw_end_x >= g->conf.width)
		sprite->draw_end_x = g->conf.width - 1;
	sprite->draw_start_y = -sprite_height / 2 + g->conf.height / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite_height / 2 + g->conf.height / 2;
	if (sprite->draw_end_y >= g->conf.height)
		sprite->draw_end_y = g->conf.height - 1;
}

void		put_sprite_texture(t_game *g, int i, int j, const double sprite_size)
{
	int				color;
	int				distance_from_top;
	int				tex[2];
	t_sprite		*sprite;

	sprite = &g->sprite;
	tex[0] =\
		(int)(256 * (i - (-sprite_size / 2 + sprite->screen_x)) *\
		sprite->width / sprite_size) / 256;
	distance_from_top = j * 256 -\
						g->conf.height * 128 + sprite_size * 128;
	tex[1] = ((distance_from_top * sprite->height) / sprite_size) / 256;
	if ((tex[1] * sprite->width + tex[0]) < (int)sizeof(sprite->data))
		return ;
	color = sprite->data[tex[1] * sprite->width + tex[0]];
	if (color != 0x000000)
		g->img.data[j * g->conf.width + i] = color;
}

void		draw_sprite(t_game *g, t_sprite *sprite, const double transform_y, const double sprite_size)
{
	int			i;
	int			j;

	i = sprite->draw_start_x - 1;
	while (++(i) < sprite->draw_end_x)
	{
		if (transform_y > 0 && i > 0 &&\
			i < g->conf.width && transform_y < sprite->buffer[i])
		{
			j = sprite->draw_start_y - 1;
			while (++(j) < sprite->draw_end_y)
				put_sprite_texture(g, i, j, sprite_size);
		}
	}
}

void	get_sprite_distance(t_game *g, t_sprite *sprite)
{
	int				id;
	double			sprite_pos[2];

	id = -1;
	while (++id < sprite->num_sprites)
	{
		sprite_pos[0] = sprite->x[id];
		sprite_pos[1] = sprite->y[id];
		sprite->distance[id] = get_distance(g->conf.p_x,
			g->conf.p_y, sprite_pos[0], sprite_pos[1]);
	}
}

void	sort_sprite_by_distance(t_sprite *sprite)
{
	double			temp_distance;
	int				i[2];
	double			temp[2];

	i[1] = -1;
	while (++(i[1]) < sprite->num_sprites)
	{
		i[0] = i[1];
		while (++(i[0]) < sprite->num_sprites)
		{
			if (sprite->distance[i[0]] > sprite->distance[i[1]])
			{
				temp_distance = sprite->distance[i[0]];
				temp[0] = sprite->x[i[0]];
				temp[1] = sprite->y[i[0]];
				sprite->distance[i[0]] = sprite->distance[i[1]];
				sprite->x[i[0]] = sprite->x[i[1]];
				sprite->y[i[0]] = sprite->y[i[1]];
				sprite->distance[i[1]] = temp_distance;
				sprite->x[i[1]] = temp[0];
				sprite->y[i[1]] = temp[1];
			}
		}
	}
}

double	calculate_sprite_angle(t_game *g, const double x, const double y)
{
	double			player_to_sprite_angle;
	double			sprite_angle;
	double			player_angle;
	double			vec_x;
	double			vec_y;

	vec_x = x - g->conf.p_x;
	vec_y = y - g->conf.p_y;
	player_to_sprite_angle = atan2(vec_y, vec_x);
	player_angle = normalize_angle(g->p->rot_angle);
	sprite_angle = player_angle - player_to_sprite_angle;
	if (sprite_angle < -M_PI)
		sprite_angle += (2.0 * M_PI);
	if (sprite_angle > M_PI)
		sprite_angle -= (2.0 * M_PI);
	return (fabs(sprite_angle));
}

int		is_sprite_visible(t_game *g, const int id, const double sprite_size)
{
	double			sprite_angle;
	double			sprite_end_angle;
	double			wall_sprite_angle;
	double			fov_sprite;

	sprite_angle =\
		fabs(calculate_sprite_angle(g, g->sprite.x[id], g->sprite.y[id]));
	sprite_end_angle =\
		fabs(calculate_sprite_angle(g, (g->sprite.x[id] + sprite_size),\
									(g->sprite.y[id] + sprite_size)));
	wall_sprite_angle = fabs(sprite_end_angle - sprite_angle);
	fov_sprite = g->conf.fov / 2 + wall_sprite_angle;
	if (sprite_angle < fov_sprite)
		return (1);
	return (0);
}

void		render_sprite(t_game *g, t_sprite *sprite)
{
	int				id;
	double			distance_projection;
	double			sprite_size;
	double			transform_y;

	get_sprite_distance(g, sprite);
	sort_sprite_by_distance(sprite);
	id = -1;
	while (++id < sprite->num_sprites)
	{
		distance_projection = (g->conf.width / 2) / tan(g->conf.fov / 2);
		sprite_size =\
			g->conf.tile_size * 1.0 / sprite->distance[id] * distance_projection;
		sprite->draw_start_x = 0;
		sprite->draw_start_y = 0;
		sprite->draw_end_x = 0;
		sprite->draw_end_y = 0;
		sprite->screen_x = 0;
		if (is_sprite_visible(g, id, sprite_size))
		{
			transform_y = get_transform_y(g, id);
			get_sprite_draw_pos(g, sprite_size);
			draw_sprite(g, sprite, transform_y, sprite_size);
		}
	}
}


int		count_sprite(t_game *g)
{
	int					num_sprites;
	int				row;
	int				col;

	row = -1;
	num_sprites = 0;
	while (++row < g->conf.rows)
	{
		col = -1;
		while (++col < g->conf.colums)
			if (g->conf.map[row][col] == 2)
				num_sprites++;
	}
	return (num_sprites);
}

int		set_sprite_memory(t_game *g, t_sprite *sprite)
{
	if (!(sprite->x = malloc(sizeof(double) * sprite->num_sprites)))
		return (0);
	if (!(sprite->y = malloc(sizeof(double) * sprite->num_sprites)))
	{
		free(sprite->x);
		return (0);
	}
	if (!(sprite->distance = malloc(sizeof(double) * sprite->num_sprites)))
	{
		free(sprite->x);
		free(sprite->y);
		return (0);
	}
	if (!(sprite->buffer = malloc(sizeof(double) * g->conf.width)))
	{
		free(sprite->x);
		free(sprite->y);
		free(sprite->distance);
		return (0);
	}
	ft_bzero(sprite->buffer, sizeof(double) * g->conf.width);
	return (sprite->num_sprites);
}

void	get_sprite_position(t_game *g, t_sprite *sprite)
{
	int					id;
	int					row;
	int					col;

	row = -1;
	id = 0;
	while (++(row) < g->conf.rows)
	{
		col = -1;
		while (++(col) < g->conf.colums)
		{
			if (g->conf.map[row][col] == 2)
			{
				sprite->x[id] = col * g->conf.tile_size + g->conf.tile_size / 2;
				sprite->y[id] = row * g->conf.tile_size + g->conf.tile_size / 2;
				sprite->distance[id] = 0;
				id++;
			}
		}
	}
}

void	get_sprite_vector(t_sprite *sprite, const char direction)
{
	sprite->dir_x = 0;
	sprite->dir_y = 0;
	sprite->plane_x = 0;
	sprite->plane_y = 0;
	if (direction == 'E')
	{
		sprite->dir_x = 1;
		sprite->plane_y = -0.6;
	}
	else if (direction == 'W')
	{
		sprite->dir_x = -1;
		sprite->plane_y = 0.6;
	}
	else if (direction == 'S')
	{
		sprite->dir_y = 1;
		sprite->plane_x = 0.6;
	}
	else if (direction == 'N')
	{
		sprite->dir_y = -1;
		sprite->plane_x = -0.6;
	}
}

int		sprite_init(t_game *g, t_sprite *sprite)
{
	sprite->num_sprites = count_sprite(g);
	if (!(set_sprite_memory(g, sprite)))
		return (0);
	sprite->angle = 0;
	sprite->ptr = 0;
	sprite->data = 0;
	sprite->bpp = 0;
	sprite->sl = 0;
	sprite->end = 0;
	sprite->width = 0;
	sprite->height = 0;

	if ((sprite->ptr =\
	mlx_xpm_file_to_image(g->mlx, "./textures/ITEM.xpm", &sprite->width, &sprite->height))\
	== (void *)0)
		return (0);
	sprite->data =\
		(int *)mlx_get_data_addr(sprite->ptr, &sprite->bpp,\
									&sprite->sl, &sprite->end);
	get_sprite_position(g, sprite);
	get_sprite_vector(sprite, g->conf.nsew);
	return (0);
}
