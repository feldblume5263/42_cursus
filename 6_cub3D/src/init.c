#include "../includes/cub.h"

void			ray_init(t_game *gm, int idx)
{
	gm->rays[idx] = (t_ray *)malloc(sizeof(t_ray));
	gm->rays[idx]->ray_angle = 0;
	gm->rays[idx]->hit_x = 0;
	gm->rays[idx]->hit_y = 0;
	gm->rays[idx]->distance = 0;
	gm->rays[idx]->x_intercept = 0;
	gm->rays[idx]->y_intercept = 0;
	gm->rays[idx]->x_step = 0;
	gm->rays[idx]->y_step = 0;
}

void			rays_init(t_game *gm)
{
	gm->rays = (t_ray **)malloc(sizeof(t_ray *) * RAYS);
}

void			player_init(t_game *gm)
{
	gm->player = (t_player *)malloc(sizeof(t_player));
	gm->player->x = WINDOW_WIDTH / 2;
	gm->player->y = WINDOW_HEIGHT / 2;
	gm->player->radius = 3;
	gm->player->turnDirection = 0; // -1 if left, +1 if right
	gm->player->walkDirection = 0; // -1 if back, +1 if front
	gm->player->rotationAngle = M_PI / 2;
	gm->player->moveSpeed = 2.0;
	gm->player->rotationSpeed = 2.0 * (M_PI / 180);
}

void			map_init(t_game *gm)
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
	memcpy(gm->map, walls, sizeof(int) * MAP_ROWS * MAP_COLS); // TO DO
	return ;
}

void			img_init(t_game *gm)
{
	gm->img.img = mlx_new_image(gm->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	gm->img.data = (int *)mlx_get_data_addr(gm->img.img,
		&gm->img.bpp, &gm->img.size_l, &gm->img.endian);
}


void			window_init(t_game *gm)
{
	gm->mlx = mlx_init();
	gm->win = mlx_new_window(gm->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");
}
