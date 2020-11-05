/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:59:02 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/05 21:02:50 by junhpark         ###   ########.fr       */
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
		gm->img.data[TO_COORD(x1 * MINI, y1 * MINI)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void			draw_lines(t_game *gm)
{
	int			i;
	int			j;

	i = 0;
	while (i < MAP_COLS)
	{
		draw_line(gm, i * TILE_SIZE, 0,
			i * TILE_SIZE, WINDOW_HEIGHT);
		i++;
	}
	draw_line(gm, MAP_COLS * TILE_SIZE - 1, 0,
		MAP_COLS * TILE_SIZE - 1, WINDOW_HEIGHT);
	j = 0;
	while (j < MAP_ROWS)
	{
		draw_line(gm, 0, j * TILE_SIZE, WINDOW_WIDTH,
			j * TILE_SIZE);
		j++;
	}
	draw_line(gm, 0, MAP_ROWS * TILE_SIZE - 1,
		WINDOW_WIDTH, MAP_ROWS * TILE_SIZE - 1);
}

void			draw_rectangle(t_game *gm, int x, int y, int color)
{
	int			i;
	int			j;

	x *= (TILE_SIZE * MINI);
	y *= (TILE_SIZE * MINI);
	i = 0;
	while (i < TILE_SIZE * MINI)
	{
		j = 0;
		while (j < TILE_SIZE * MINI)
		{
			gm->img.data[(y  + i) * WINDOW_WIDTH + x + j] = color;
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
	while (i < MAP_ROWS)
	{
		j = 0;
		while (j < MAP_COLS)
		{
			if (gm->map[i][j] == 1)
				draw_rectangle(gm, j, i, 0x000000);
			else if (gm->map[i][j] == 0)
				draw_rectangle(gm, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
