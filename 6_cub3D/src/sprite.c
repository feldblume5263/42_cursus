/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 00:36:22 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/18 04:53:22 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			sort_sprite_by_distance(t_sprite *sprite)
{
	double		temp_distance;
	int			i[2];
	double		temp[2];

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

double			calculate_sprite_angle(t_game *g, const double x,
	const double y)
{
	double		player_to_sprite_angle;
	double		sprite_angle;
	double		player_angle;
	double		vec_x;
	double		vec_y;

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

int				is_sprite_visible(t_game *g, const int id,
	const double sprite_size)
{
	double		sprite_angle;
	double		sprite_end_angle;
	double		wall_sprite_angle;
	double		fov_sprite;

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

void			render_sprite(t_game *g, t_sprite *sp)
{
	int			id;
	double		distance_projection;
	double		sprite_size;
	double		transform_y;

	get_sprite_distance(g, sp);
	sort_sprite_by_distance(sp);
	id = -1;
	while (++id < sp->num_sprites)
	{
		distance_projection = (g->conf.width / 2) / tan(g->conf.fov / 2);
		sprite_size =\
			g->conf.tile_size * 1.0 / sp->distance[id] * distance_projection;
		sp->draw_start_x = 0;
		sp->draw_start_y = 0;
		sp->draw_end_x = 0;
		sp->draw_end_y = 0;
		sp->screen_x = 0;
		if (is_sprite_visible(g, id, sprite_size))
		{
			transform_y = get_transform_y(g, id);
			get_sprite_draw_pos(g, sprite_size);
			draw_sprite(g, sp, transform_y, sprite_size);
		}
	}
}
