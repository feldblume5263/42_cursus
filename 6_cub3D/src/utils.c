/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:58:44 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/18 04:55:20 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				to_coord(t_game *gm, double x, double y)
{
	return ((int)floor(y) * gm->conf.width + (int)floor(x));
}

int				is_blank(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

double			get_distance(double x1, double y1, double x2, double y2)
{
	double		x;
	double		y;
	double		ret;

	x = x2 - x1;
	y = y2 - y1;
	ret = sqrt((x * x) + (y * y));
	return (ret);
}

int				inspect_sprite(t_game *gm, double x, double y)
{
	int			idx_x;
	int			idx_y;

	idx_x = floor(x / gm->conf.tile_size);
	idx_y = floor(y / gm->conf.tile_size);
	if (idx_x >= gm->conf.colums || idx_y >= gm->conf.rows)
		return (1);
	return (gm->conf.map[idx_y][idx_x] == 2);
}

int				inspect_wall(t_game *gm, double x, double y)
{
	int			idx_x;
	int			idx_y;

	idx_x = floor(x / gm->conf.tile_size);
	idx_y = floor(y / gm->conf.tile_size);
	if (idx_x >= gm->conf.colums || idx_y >= gm->conf.rows)
		return (1);
	return (gm->conf.map[idx_y][idx_x] == 1);
}
