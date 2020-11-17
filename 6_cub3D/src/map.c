/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:59:02 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/17 18:28:11 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char			*get_blank_map(char *d)
{
	if (ft_strlen(d) == 0)
	{
		free(d);
		d = (char *)malloc(sizeof(char) * 2);
		d[0] = ' ';
		d[1] = '\0';
	}
	return (d);
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
			gm->img.data[(y + i) * gm->conf.width + x + j] = color;
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
			else if (gm->conf.map[i][j] == 2)
				draw_rectangle(gm, j, i, 0x9696be);
			j++;
		}
		i++;
	}
}
