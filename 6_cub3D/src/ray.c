/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:34:43 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/03 17:51:56 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			cast_ray(t_game *gm, int idx)
{
	gm->r[idx]->is_down = (gm->r[idx]->ray_angle > 0
		&& gm->r[idx]->ray_angle < M_PI);
	gm->r[idx]->is_up = !(gm->r[idx]->is_down);
	gm->r[idx]->is_right = gm->r[idx]->ray_angle
	< (0.5 * M_PI) || gm->r[idx]->ray_angle > (1.5 * M_PI);
	gm->r[idx]->is_left = !(gm->r[idx]->is_right);
	cast_horiz(gm, idx);
	cast_verti(gm, idx);
	gm->r[idx]->hit_x = gm->r[idx]->h_x < gm->r[idx]->v_x ?
		gm->r[idx]->h_x : gm->r[idx]->v_x;
	gm->r[idx]->hit_x = gm->r[idx]->h_y < gm->r[idx]->v_y ?
		gm->r[idx]->h_y : gm->r[idx]->v_y;
}

void			draw_ray(t_game *gm, double ray_angle, int idx)
{
	int			pix_idx;

	pix_idx = 0;
	while (pix_idx < gm->r[idx]->distance)
	{
		mlx_pixel_put(
			gm->mlx,
			gm->win,
			gm->p->x * MINI + (cos(ray_angle) * pix_idx * MINI),
			gm->p->y * MINI + (sin(ray_angle) * pix_idx * MINI),
			0xEAE200);
		pix_idx++;
	}
}

void			cast_rays(t_game *gm)
{
	double		input_ray_angle;
	int			ray_idx;

	ray_idx = 0;
	input_ray_angle = gm->p->rot_angle - (FOV / 2.0);
	while (ray_idx < RAYS)
	{
		ray_init(gm, ray_idx);
		gm->r[ray_idx]->ray_angle = noramalize_angle(input_ray_angle);
		cast_ray(gm, ray_idx);
		//draw_ray(gm, input_ray_angle, ray_idx);
		input_ray_angle += (FOV / RAYS);
		ray_idx++;
	}
}
