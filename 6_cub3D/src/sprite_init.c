/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:29:19 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/17 16:40:41 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				count_sprite(t_game *g)
{
	int			num_sprites;
	int			row;
	int			col;

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

int				set_sprite_memory(t_game *g, t_sprite *sprite)
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

void			get_sprite_position(t_game *g, t_sprite *sprite)
{
	int			id;
	int			row;
	int			col;

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

void			get_sprite_vector(t_sprite *sprite, const char direction)
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

int				sprite_init(t_game *g, t_sprite *sprite)
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
	mlx_xpm_file_to_image(g->mlx, "./textures/ITEM.xpm",
		&sprite->width, &sprite->height)) == (void *)0)
		return (0);
	sprite->data =\
		(int *)mlx_get_data_addr(sprite->ptr, &sprite->bpp,\
									&sprite->sl, &sprite->end);
	get_sprite_position(g, sprite);
	get_sprite_vector(sprite, g->conf.nsew);
	return (0);
}
