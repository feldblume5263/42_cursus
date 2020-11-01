/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:36:10 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/01 15:34:36 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			rendering(t_game *gm)
{
	t_ray		*ray;
	int			ray_idx;
	double		wall_height;
	double		sight_height;

	ray_idx = 0;
	while (ray_idx < RAYS)
	{
		ray = gm->r[ray_idx];
		sight_height = (WINDOW_WIDTH / 2) / tan(FOV / 2);
		wall_height = (TILE_SIZE / gm->r[ray_idx]->distance) * sight_height;

	}
}
