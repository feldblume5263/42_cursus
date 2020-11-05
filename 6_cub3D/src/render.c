/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:36:10 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/03 19:28:40 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			render_wall(t_game *gm, int idx, int top, int bot)
{
	int			ceil;
	int			landscape;
	int			floor;

	ceil = 0;
	landscape = top;
	while (ceil < top)
	{
		gm->img.data[(WINDOW_WIDTH * ceil) + idx] = 0x00B5F2;
		ceil++;
	}
	while (landscape < bot)
	{
		gm->img.data[(WINDOW_WIDTH * landscape) + idx] =
			gm->r[idx]->verti_flag ? 0xEFDB00 : 0xF2EA00;
		landscape++;
	}
	floor = bot;
	while (floor < WINDOW_HEIGHT)
	{
		gm->img.data[(WINDOW_WIDTH * floor) + idx] = 0x19E586;
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
	while (ray_idx < RAYS)
	{
		project_height = (WINDOW_WIDTH / 2) / tan(FOV / 2);
		wall_strip_height = floor((TILE_SIZE / gm->r[ray_idx]->distance)
			* project_height);
		wall_top = (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
		wall_top = wall_top < 0 ? 0 : wall_top;
		wall_botton = (WINDOW_HEIGHT / 2) + (wall_strip_height / 2);
		wall_botton = wall_botton > WINDOW_HEIGHT ?
			WINDOW_HEIGHT : wall_botton;
		render_wall(gm, ray_idx, wall_top, wall_botton);
		ray_idx++;
	}
}
