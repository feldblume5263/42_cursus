/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:30:45 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/17 16:49:43 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

double			get_transform_y(t_game *g, const int id)
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
		invdet * (-g->sprite.plane_y * sprite[0] +
			g->sprite.plane_x * sprite[1]);
	g->sprite.screen_x =\
		(int)((g->conf.width / 2) * (1 + -transform[0] / transform[1]));
	return (transform[1]);
}

void			get_sprite_draw_pos(t_game *g, const double sprite_size)
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

void			put_sprite_texture(t_game *g, int i, int j,
	const double sprite_size)
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

void			draw_sprite(t_game *g, t_sprite *sprite,
	const double transform_y, const double sprite_size)
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

void			get_sprite_distance(t_game *g, t_sprite *sprite)
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
