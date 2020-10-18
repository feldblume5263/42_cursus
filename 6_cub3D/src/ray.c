#include "../includes/cub.h"

void			draw_ray(t_game *gm, double ray_angle)
{
	int			pix_idx;

	// ray_idx = 0;
	// while (gm->rays[ray_idx])
	// {
		pix_idx = 0;
		while (pix_idx < 30)
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
	// 	ray_idx++;
	// }aor
}

void			cast_rays(t_game *gm)
{
	int			colum_id = 0;
	double		input_ray_angle;
	int			idx;

	idx = 0;
	input_ray_angle = gm->player->rotationAngle - (FOV / 2);
	while (idx < RAYS)
	{
		gm->rays[idx] = (t_ray *)malloc(sizeof(t_ray));
		gm->rays[idx]->ray_angle = input_ray_angle;
		draw_ray(gm, input_ray_angle);
		input_ray_angle += FOV / RAYS;
		colum_id++;
		idx++;
	}
}
