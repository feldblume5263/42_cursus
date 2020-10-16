#include "../includes/cub.h"

void			player_init(t_game *game)
{
	game->player->x = WINDOW_WIDTH / 2;
	game->player->y = WINDOW_HEIGHT / 2;
	game->player->radius = 3;
	game->player->turnDirection = 0; // -1 if left, +1 if right
	game->player->walkDirection = 0; // -1 if back, +1 if front
	game->player->rotationAngle = M_PI / 2;
	game->player->moveSpeed = 2.0;
	game->player->rotationSpeed = 2.0 * (M_PI / 180);
}

void			map_init(t_game *game)
{
	int		walls[MAP_ROWS][MAP_COLS] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, walls, sizeof(int) * MAP_ROWS * MAP_COLS); // TO DO
	return ;
}

void			img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}


void			window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");
}
