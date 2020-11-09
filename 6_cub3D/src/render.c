/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:36:10 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/10 01:38:17 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				get_wall_color(t_game *gm, int idx, int landscape, int type)
{
	int			tex_x;
	int			tex_y;
	double		project_height;
	int			wall_strip_height;
	int			distance_top;

	project_height = (gm->conf.width / 2.0) / tan(gm->conf.fov / 2.0);
	wall_strip_height = floor((gm->conf.tile_size / gm->r[idx]->distance)
		* project_height);
	distance_top = landscape + ((int)wall_strip_height / 2) - (gm->conf.height / 2);
	if (gm->r[idx]->verti_flag)
		tex_x = (int)(gm->r[idx]->hit_y) % gm->conf.tile_size;
	else
		tex_x = (int)(gm->r[idx]->hit_x) % gm->conf.tile_size;
	tex_y = (distance_top *
		((double)gm->conf.tex[type].height / wall_strip_height));
	return (gm->conf.tex[type].texture
		[(int)gm->conf.tex[type].width * tex_y + tex_x]);
}

int				get_wall_type(t_game *gm, int idx)
{
	if (gm->r[idx]->horiz_flag && gm->r[idx]->is_down)
		return (0);
	else if (gm->r[idx]->horiz_flag && gm->r[idx]->is_up)
		return (1);
	else if (gm->r[idx]->verti_flag && gm->r[idx]->is_right)
		return (2);
	else
		return (3);
}

void			render_wall(t_game *gm, int idx, int top, int bot)
{
	int			ceil;
	int			landscape;
	int			floor;
	int			tex_color;

	ceil = 0;
	landscape = top;
	while (ceil < top)
	{
		gm->img.data[(gm->conf.width * ceil) + idx] = 0x00B5F2;
		ceil++;
	}
	while (landscape < bot)
	{
		if (((gm->conf.width * landscape) + idx) >= gm->conf.width * gm->conf.height)
			break ;
		tex_color = get_wall_color(gm, idx, landscape, get_wall_type(gm, idx));
		gm->img.data[(gm->conf.width * landscape) + idx] = tex_color;
		landscape++;
	}
	floor = bot;
	while (floor < gm->conf.height)
	{
		if (((gm->conf.width * landscape) + idx) >= gm->conf.width * gm->conf.height)
			break ;
		gm->img.data[(gm->conf.width * floor) + idx] = 0x19E586;
		floor++;
	}
}

void			rendering(t_game *gm)
{
	int			ray_idx;
	double		project_height;
	int			wall_strip_height;
	int			wall_top;
	int			wall_botton;

	ray_idx = 0;
	while (ray_idx < gm->conf.width)
	{
		project_height = (gm->conf.width / 2) / tan(gm->conf.fov / 2);
		wall_strip_height = floor((gm->conf.tile_size / gm->r[ray_idx]->distance)
			* project_height);
		wall_top = (gm->conf.height / 2) - (wall_strip_height / 2);
		wall_top = wall_top < 0 ? 0 : wall_top;
		wall_botton = (gm->conf.height / 2) + (wall_strip_height / 2);
		wall_botton = wall_botton > gm->conf.height ?
			gm->conf.height : wall_botton;
		render_wall(gm, ray_idx, wall_top, wall_botton);
		ray_idx++;
	}
}
