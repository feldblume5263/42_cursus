/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:41:12 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/16 00:53:08 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				check_input(int argc, char *argv[])
{
	if (!(argc == 2 || (argc == 3 && !ft_strncmp(argv[2], "--save", 6))))
	{
		write(1, "wrong input!\n", 19);
		return (-1);
	}
	return (1);
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
	draw_rectangles(gm);
	draw_player(gm);
	mlx_hook(gm->win, X_EVENT_KEY_PRESS, 0, &player_keypressed, gm->p);
	mlx_hook(gm->win, X_EVENT_KEY_RELEASE, 0, &player_keyreleased, gm->p);
	update_player(gm);
	cast_rays(gm);
	rendering(gm);
	render_sprite(gm, &gm->sprite);
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

	if (check_input(argc, argv) < 0)
		exit(0);
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
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		screenshot(&gm);
	mlx_loop(gm.mlx);
}
