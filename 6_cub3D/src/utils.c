/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:58:44 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/13 19:52:59 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			check_player_num(t_game *g, char *d)
{
	int			idx;

	idx = -1;
	while (d[++idx])
	{
		if (ft_strchr("NSWE", d[idx]))
		{
			if (g->conf.p_flag == 1)
				exit_with_error("you have 2 player\n");
			else
				g->conf.p_flag = 1;
		}
	}
}

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
