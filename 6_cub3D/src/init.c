/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:57:24 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/18 04:54:23 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			config_init(t_game *gm)
{
	int			idx;

	gm->conf.p_x = 0;
	gm->conf.p_y = 0;
	gm->conf.p_flag = 0;
	gm->conf.width = 0;
	gm->conf.height = 0;
	gm->conf.rows = 0;
	gm->conf.colums = 0;
	gm->conf.tile_size = 0;
	gm->conf.floor_color = 0;
	gm->conf.ceiling_color = 0;
	gm->conf.fov = 60 * (M_PI / 180);
	gm->conf.map = NULL;
	idx = -1;
	while (++idx < TEXTURES)
		gm->conf.tex[0].tex_path = NULL;
}

void			ray_init(t_game *gm, int idx)
{
	gm->r[idx] = (t_ray *)malloc(sizeof(t_ray));
	gm->r[idx]->ray_angle = 0;
	gm->r[idx]->hit_x = 0;
	gm->r[idx]->hit_y = 0;
	gm->r[idx]->distance = 0;
	gm->r[idx]->x_intercept = 0;
	gm->r[idx]->y_intercept = 0;
	gm->r[idx]->x_step = 0;
	gm->r[idx]->y_step = 0;
	gm->r[idx]->h_x = 0;
	gm->r[idx]->h_y = 0;
	gm->r[idx]->v_x = 0;
	gm->r[idx]->v_y = 0;
	gm->r[idx]->verti_flag = 0;
	gm->r[idx]->horiz_flag = 0;
}

void			rays_init(t_game *gm)
{
	gm->r = (t_ray **)malloc(sizeof(t_ray *) * gm->conf.width);
}

void			player_init(t_game *gm)
{
	gm->p = (t_player *)malloc(sizeof(t_player));
	gm->conf.p_x = gm->conf.p_x;
	gm->conf.p_y = gm->conf.p_y;
	gm->p->radius = 6;
	gm->p->turn_dir = 0;
	gm->p->walk_dir = 0;
	gm->p->rot_angle = 5 * (M_PI / 180);
	gm->p->mv_speed = 3.0;
	gm->p->rot_speed = 3.0 * (M_PI / 180);
	gm->p->go_left = 0;
	gm->p->go_right = 0;
}
