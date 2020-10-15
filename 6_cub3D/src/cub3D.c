/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:41:12 by Feldblume         #+#    #+#             */
/*   Updated: 2020/10/15 21:34:17 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				main_loop(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);
	draw_player(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &player_keypressed, game->player);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &player_keyReleased, game->player);
	printf("%f\n", game->player->walkDirection);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int				main(void)
{
	t_game		game;

	map_init(&game);
	window_init(&game);
	img_init(&game);
	player_init(&game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}