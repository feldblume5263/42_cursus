/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:57:38 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/10 16:32:04 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			update_player(t_game *gm)
{
	double		move_step;
	double		new_x;
	double		new_y;

	move_step = (gm->p->walk_dir * gm->p->mv_speed);
	gm->p->rot_angle += (gm->p->turn_dir * gm->p->rot_speed);
	new_x = gm->conf.p_x + cos(gm->p->rot_angle) * move_step;
	new_y = gm->conf.p_y + sin(gm->p->rot_angle) * move_step;
	if (!(inspect_wall(gm, new_x, new_y))) // only set new position if it is not colliding with the map walls
	{
		gm->conf.p_x = new_x;
		gm->conf.p_y = new_y;
	}
}

int				player_keyReleased(int keycode, t_player *player)
{
	if (keycode == KEY_UP)
	{
		player->walk_dir = 0;
	}
	else if (keycode == KEY_DOWN)
	{
		player->walk_dir = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		player->turn_dir = 0;
	}
	else if (keycode == KEY_LEFT)
	{
		player->turn_dir = 0;
	}
	return (0);
}

int				player_keypressed(int keycode, t_player *player)
{
	if (keycode == KEY_UP)
	{
		player->walk_dir = 1;
	}
	else if (keycode == KEY_DOWN)
	{
		player->walk_dir = -1;
	}
	else if (keycode == KEY_RIGHT)
	{
		player->turn_dir = 1;
	}
	else if (keycode == KEY_LEFT)
	{
		player->turn_dir = -1;
	}
	return (0);
}

void			draw_player(t_game *gm)
{
	double		i;
	double		j;

	i = 0;
	while (i < gm->p->radius)
	{
		j = 0;
		while (j < gm->p->radius)
		{
			gm->img.data[to_coord(gm, gm->conf.p_x * MINI + j, gm->conf.p_y * MINI + i)] = 0xCC0000;
			j++;
		}
		i++;
	}
}
