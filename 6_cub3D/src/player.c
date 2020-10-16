#include "../includes/cub.h"

void			update_player(t_game *game)
{
	double		moveStep;
	double		newX;
	double		newY;

	moveStep = game->player->walkDirection * game->player->moveSpeed;
	game->player->rotationAngle += game->player->turnDirection * game->player->rotationSpeed;
	newX = game->player->x + cos(game->player->rotationAngle) * moveStep;
	newY = game->player->y + sin(game->player->rotationAngle) * moveStep;
	if (!(inspect_wall(game, newX, newY))) // only set new position if it is not colliding with the map walls
	{
		game->player->x = newX;
		game->player->y = newY;
	}
}

void			draw_view(t_game *game)
{
	int			len;

	len = 0;
	while (len < 30)
	{
		mlx_pixel_put(game->mlx, game->win, game->player->x +
		(cos(game->player->rotationAngle) * len),game->player->y
		+ (sin(game->player->rotationAngle) * len), 0xCC0000);
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
		player->turnDirection = +1;
	}
	else if (keycode == KEY_LEFT)
	{
		player->turnDirection = -1;
	}
	return (0);
}

void			draw_player(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->player->radius)
	{
		j = 0;
		while (j < game->player->radius)
		{
			game->img.data[(game->player->y  + i) * WINDOW_WIDTH + game->player->x + j] = 0xCC0000;
			j++;
		}
		i++;
	}
}
