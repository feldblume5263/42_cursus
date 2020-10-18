#include "../includes/cub.h"

void			update_player(t_game *gm)
{
	double		move_step;
	double		new_x;
	double		new_y;

	move_step = (gm->player->walkDirection * gm->player->moveSpeed);
	gm->player->rotationAngle += (gm->player->turnDirection * gm->player->rotationSpeed);
	new_x = gm->player->x + cos(gm->player->rotationAngle) * move_step;
	new_y = gm->player->y + sin(gm->player->rotationAngle) * move_step;
	if (!(inspect_wall(gm, new_x, new_y))) // only set new position if it is not colliding with the map walls
	{
		gm->player->x = new_x;
		gm->player->y = new_y;
	}
}

void			draw_view(t_game *gm)
{
	int			len;

	len = 0;
	while (len < 30)
	{
		mlx_pixel_put (
			gm->mlx,
			gm->win,
			gm->player->x + (cos(gm->player->rotationAngle) * len),
			gm->player->y + (sin(gm->player->rotationAngle) * len),
			0xCC0000
		);
		len ++;
	}
}

int				player_keyReleased(int keycode, t_player *player)
{
	if (keycode == KEY_UP)
	{
		player->walkDirection = 0;
	}
	else if (keycode == KEY_DOWN)
	{
		player->walkDirection = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		player->turnDirection = 0;
	}
	else if (keycode == KEY_LEFT)
	{
		player->turnDirection = 0;
	}
	return (0);
}

int				player_keypressed(int keycode, t_player *player)
{
	if (keycode == KEY_UP)
	{
		player->walkDirection = 1;
	}
	else if (keycode == KEY_DOWN)
	{
		player->walkDirection = -1;
	}
	else if (keycode == KEY_RIGHT)
	{
		player->turnDirection = 1;
	}
	else if (keycode == KEY_LEFT)
	{
		player->turnDirection = -1;
	}
	return (0);
}

void			draw_player(t_game *gm)
{
	double		i;
	double		j;

	i = 0;
	while (i < gm->player->radius)
	{
		j = 0;
		while (j < gm->player->radius)
		{
			gm->img.data[TO_COORD(gm->player->x + j, gm->player->y + i)] = 0xCC0000;
			j++;
		}
		i++;
	}
}
