#include "../includes/cub.h"

void			cast_ray(t_game *gm, int idx)
{
	double		x_intercept;
	double		y_intercept;
	double		x_step;
	double		y_step;

	// find y_coordinate
	y_intercept = floor(gm->player->y / TILE_SIZE) * TILE_SIZE;
	// find x_coordinate
	x_intercept = gm->player->x +
		(y_intercept - gm->player->y) / tan(gm->rays[idx]->ray_angle);
	y_step = TILE_SIZE;
	x_step = y_step / tan(gm->rays[idx]->ray_angle);

}

void			draw_ray(t_game *gm, double ray_angle)
{
	int			pix_idx;

	pix_idx = 0;
	while (pix_idx < 100)
	{
		mlx_pixel_put(
			gm->mlx,
			gm->win,
			gm->player->x + (cos(ray_angle) * pix_idx),
			gm->player->y + (sin(ray_angle) * pix_idx),
			0x444444
		);
		pix_idx++;
	}
}

void			cast_rays(t_game *gm)
{
	double		input_ray_angle;
	int			idx;

	idx = 0;
	input_ray_angle = gm->player->rotationAngle - (FOV / 2.0);
	while (idx < RAYS)
	{
		ray_init(gm, idx);
		gm->rays[idx]->ray_angle = noramalize_angle(input_ray_angle);
		cast_ray(gm, idx);
		draw_ray(gm, input_ray_angle);
		input_ray_angle += (FOV / RAYS);
		idx++;
	}
}
