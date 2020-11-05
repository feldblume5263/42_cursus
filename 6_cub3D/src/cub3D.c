/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:41:12 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/04 19:50:55 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				game_close(int key)
{
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int				main_loop(t_game *gm)
{
	draw_rectangles(gm);
	//draw_lines(gm);
	draw_player(gm);
	mlx_hook(gm->win, X_EVENT_KEY_PRESS, 0, &game_close, &gm);
	mlx_hook(gm->win, X_EVENT_KEY_PRESS, 0, &player_keypressed, gm->p);
	mlx_hook(gm->win, X_EVENT_KEY_RELEASE, 0, &player_keyReleased, gm->p);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img.img, 0, 0);
	update_player(gm);
	cast_rays(gm);
	rendering(gm);
	return (0);
}

int				main(void)
{
	t_game		gm;

	map_init(&gm);
	window_init(&gm);
	img_init(&gm);
	load_texture(&gm);
	player_init(&gm);
	rays_init(&gm);
	mlx_loop_hook(gm.mlx, &main_loop, &gm);
	mlx_loop(gm.mlx);
}
