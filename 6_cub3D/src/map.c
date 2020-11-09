/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:59:02 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/09 23:29:22 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			draw_line(t_game *gm, double x1, double y1, double x2, double y2)
{
	double		deltaX;
	double		deltaY;
	double		step;

	deltaX = (x2 - x1);
	deltaY = (y2 - y1);
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		gm->img.data[to_coord(gm, x1 * MINI, y1 * MINI)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void			draw_lines(t_game *gm)
{
	int			i;
	int			j;

	i = 0;
	while (i < gm->conf.colums)
	{
		draw_line(gm, i * gm->conf.tile_size, 0,
			i * gm->conf.tile_size, gm->conf.height);
		i++;
	}
	draw_line(gm, gm->conf.colums * gm->conf.tile_size - 1, 0,
		gm->conf.colums * gm->conf.tile_size - 1, gm->conf.height);
	j = 0;
	while (j < gm->conf.rows)
	{
		draw_line(gm, 0, j * gm->conf.tile_size, gm->conf.width,
			j * gm->conf.tile_size);
		j++;
	}
	draw_line(gm, 0, gm->conf.rows * gm->conf.tile_size - 1,
		gm->conf.width, gm->conf.rows * gm->conf.tile_size - 1);
}

void			draw_rectangle(t_game *gm, int x, int y, int color)
{
	int			i;
	int			j;

	x *= (gm->conf.tile_size * MINI);
	y *= (gm->conf.tile_size * MINI);
	i = 0;
	while (i < gm->conf.tile_size * MINI)
	{
		j = 0;
		while (j < gm->conf.tile_size * MINI)
		{
			gm->img.data[(y  + i) * gm->conf.width + x + j] = color;
			j++;
		}
		i++;
	}
}

void			draw_rectangles(t_game *gm)
{
	int			i;
	int			j;

	i = 0;
	while (i < gm->conf.rows)
	{
		j = 0;
		while (j < gm->conf.colums)
		{
			if (gm->conf.map[i][j] == 1)
				draw_rectangle(gm, j, i, 0x000000);
			else if (gm->conf.map[i][j] == 0)
				draw_rectangle(gm, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
