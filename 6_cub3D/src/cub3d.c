/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:41:12 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/18 04:54:49 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			resize_resol(t_game *g)
{
	g->conf.width = g->conf.width > 1920 ? 1920 : g->conf.width;
	g->conf.height = g->conf.height > 1080 ? 1080 : g->conf.height;
	g->conf.width = g->conf.width < 400 ? 400 : g->conf.width;
	g->conf.height = g->conf.height < 400 ? 400 : g->conf.height;
}

int				check_input(int argc, char *argv[])
{
	if (argc == 2)
		return (1);
	else if (argc == 3)
	{
		if (!(ft_strncmp(argv[2], "--save", 6))
			&& (int)ft_strlen(argv[2]) == 6)
			return (1);
		else
			exit_with_error("wroing input\n");
	}
	else
		exit_with_error("wroing input\n");
	return (0);
}

int				close_game(void *game)
{
	(void)game;
	exit(0);
	return (0);
}

int				main_loop(t_game *gm)
{
	int			idx;

	idx = 0;
	mlx_hook(gm->win, X_EVENT_KEY_PRESS, 0, &player_keypressed, gm->p);
	mlx_hook(gm->win, X_EVENT_KEY_RELEASE, 0, &player_keyreleased, gm->p);
	update_player(gm);
	cast_rays(gm);
	rendering(gm);
	render_sprite(gm, &gm->sprite);
	draw_rectangles(gm);
	draw_player(gm);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img.img, 0, 0);
	while (idx < gm->conf.width)
	{
		free(gm->r[idx]);
		idx++;
	}
	return (0);
}

int				main(int argc, char *argv[])
{
	t_game		gm;
	char		*map;

	check_input(argc, argv);
	is_cub(argv[1]);
	player_init(&gm);
	config_init(&gm);
	if (!(map = parse_data(&gm, argv[1])))
		exit_with_error("file error!");
	if (gm.conf.p_flag == 0)
		exit_with_error("you have no player\n");
	map_init(&gm, map);
	window_init(&gm);
	img_init(&gm);
	load_texture(&gm);
	rays_init(&gm);
	sprite_init(&gm, &gm.sprite);
	mlx_hook(gm.win, X_EVENT_KEY_EXIT, 0, &close_game, &gm);
	mlx_loop_hook(gm.mlx, &main_loop, &gm);
	if (argc == 3)
		screenshot(&gm);
	mlx_loop(gm.mlx);
}
