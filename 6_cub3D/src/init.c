/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:57:24 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/10 16:33:14 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			config_init(t_game *gm)
{
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
	gm->r[idx]->h_x = 0;;
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
	gm->p->rot_angle = M_PI / 2;
	gm->p->mv_speed = 3.0;
	gm->p->rot_speed = 3.0 * (M_PI / 180);
}

void			img_init(t_game *gm)
{
	gm->img.img = mlx_new_image(gm->mlx, gm->conf.width, gm->conf.height);
	gm->img.data = (int *)mlx_get_data_addr(gm->img.img,
		&gm->img.bpp, &gm->img.size_l, &gm->img.endian);
}


void			window_init(t_game *gm)
{
	gm->mlx = mlx_init();
	gm->win = mlx_new_window(gm->mlx, gm->conf.width, gm->conf.height, "mlx 42");
}
