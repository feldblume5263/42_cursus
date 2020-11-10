/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_detail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:59:46 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/10 17:05:23 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				intercept_verti(t_game *gm, int idx)
{
	double		touch_x;
	double		touch_y;
	int			hit_flag;

	hit_flag = 0;
	touch_x = gm->r[idx]->x_intercept;
	touch_y = gm->r[idx]->y_intercept;
	while (touch_x > 0 && touch_x < gm->conf.width
		&& touch_y > 0 && touch_y < gm->conf.height)
	{
		if (inspect_wall(gm, touch_x - (gm->r[idx]->is_left ? 1 : 0), touch_y))
		{
			hit_flag = 1;
			gm->r[idx]->v_x = touch_x;
			gm->r[idx]->v_y = touch_y;
			break ;
		}
		else
		{
			touch_x += gm->r[idx]->x_step;
			touch_y += gm->r[idx]->y_step;
		}
	}
	return (hit_flag);
}

void			cast_verti(t_game *gm, int idx)
{
	double		temp;
	int			hit_flag;

	hit_flag = 0;
	gm->r[idx]->x_intercept = floor(gm->conf.p_x / gm->conf.tile_size) * gm->conf.tile_size;
	gm->r[idx]->x_intercept += gm->r[idx]->is_right ? gm->conf.tile_size : 0;
	gm->r[idx]->y_intercept = gm->conf.p_y +
		(gm->r[idx]->x_intercept - gm->conf.p_x) * tan(gm->r[idx]->ray_angle);
	gm->r[idx]->x_step = gm->conf.tile_size;
	gm->r[idx]->x_step *= gm->r[idx]->is_left ? -1 : 1;
	gm->r[idx]->y_step = gm->r[idx]->x_step * tan(gm->r[idx]->ray_angle);
	gm->r[idx]->y_step *= (gm->r[idx]->is_up
		&& gm->r[idx]->y_step > 0) ? -1 : 1;
	gm->r[idx]->y_step *= (gm->r[idx]->is_down
		&& gm->r[idx]->y_step < 0) ? -1 : 1;
	hit_flag = intercept_verti(gm, idx);
	temp = get_distance(gm->conf.p_x, gm->conf.p_y, gm->r[idx]->v_x,
		gm->r[idx]->v_y);
	if (temp < gm->r[idx]->distance && hit_flag)
	{
		gm->r[idx]->distance = temp;
		gm->r[idx]->verti_flag = 1;
		gm->r[idx]->horiz_flag = 0;
	}
}

int				intercept_horiz(t_game *gm, int idx)
{
	double		touch_x;
	double		touch_y;
	int			hit_flag;

	hit_flag = 0;
	touch_x = gm->r[idx]->x_intercept;
	touch_y = gm->r[idx]->y_intercept;
	while (touch_x > 0 && touch_x < gm->conf.width
		&& touch_y > 0 && touch_y < gm->conf.height)
	{
		if (inspect_wall(gm, touch_x, touch_y - (gm->r[idx]->is_up ? 1 : 0)))
		{
			hit_flag = 1;
			gm->r[idx]->h_x = touch_x;
			gm->r[idx]->h_y = touch_y;
			break ;
		}
		else
		{
			touch_x += gm->r[idx]->x_step;
			touch_y += gm->r[idx]->y_step;
		}
	}
	return (hit_flag);
}

void			cast_horiz(t_game *gm, int idx)
{
	int			hit_flag;

	hit_flag = 0;
	gm->r[idx]->y_intercept = floor(gm->conf.p_y / gm->conf.tile_size) * gm->conf.tile_size;
	gm->r[idx]->y_intercept += gm->r[idx]->is_down ? gm->conf.tile_size : 0;
	gm->r[idx]->x_intercept = gm->conf.p_x +
		(gm->r[idx]->y_intercept - gm->conf.p_y) / tan(gm->r[idx]->ray_angle);
	gm->r[idx]->y_step = gm->conf.tile_size;
	gm->r[idx]->y_step *= gm->r[idx]->is_up ? -1 : 1;
	gm->r[idx]->x_step = gm->r[idx]->y_step / tan(gm->r[idx]->ray_angle);
	gm->r[idx]->x_step *= (gm->r[idx]->is_left
		&& gm->r[idx]->x_step > 0) ? -1 : 1;
	gm->r[idx]->x_step *= (gm->r[idx]->is_right
		&& gm->r[idx]->x_step < 0) ? -1 : 1;
	hit_flag = intercept_horiz(gm, idx);
	if (hit_flag)
	{
		gm->r[idx]->distance =
			get_distance(gm->conf.p_x, gm->conf.p_y, gm->r[idx]->h_x, gm->r[idx]->h_y);
		gm->r[idx]->horiz_flag = 1;
	}
	else
		gm->r[idx]->distance = INT_MAX;
}
