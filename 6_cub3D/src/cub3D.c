/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:41:12 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/10 22:35:37 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				check_input(int argc, char *argv[])
{
	if (!(argc == 2 || (argc == 3 && ft_strncmp(argv[2], "--save", 6))))
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
	draw_rectangles(gm);
	draw_player(gm);
	mlx_hook(gm->win, X_EVENT_KEY_PRESS, 0, &player_keypressed, gm->p);
	mlx_hook(gm->win, X_EVENT_KEY_RELEASE, 0, &player_keyReleased, gm->p);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img.img, 0, 0);
	update_player(gm);
	cast_rays(gm);
	rendering(gm);
	return (0);
}

int				main(int argc, char *argv[])
{
	t_game		gm;
	char		*map;

	if (check_input(argc, argv) < 0)
		exit(0);
	config_init(&gm);
	if (!(map = parse_data(&gm, argv[1])))
		exit_with_error("file error!");
	map_init(&gm, map);
	window_init(&gm);
	img_init(&gm);
	load_texture(&gm);
	player_init(&gm);
	rays_init(&gm);
	mlx_hook(gm.win, X_EVENT_KEY_EXIT, 0, &close_game, &gm);
	mlx_loop_hook(gm.mlx, &main_loop, &gm);
	mlx_loop(gm.mlx);
}
