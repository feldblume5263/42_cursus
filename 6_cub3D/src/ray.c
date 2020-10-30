#include "../includes/cub.h"

int				intercept_verti(t_game *gm, int idx)
{
	double		touch_x;
	double		touch_y;
	int			hit_flag;

	hit_flag = 0;
	touch_x = gm->rays[idx]->x_intercept;
	touch_y = gm->rays[idx]->y_intercept;
	if (gm->rays[idx]->is_left)
		touch_x--;
	while (touch_x >= 0 && touch_x <= WINDOW_WIDTH
		&& touch_y >= 0 && touch_y <= WINDOW_HEIGHT)
	{
		if (inspect_wall(gm, touch_x, touch_y))
		{
			hit_flag = 1;
			gm->rays[idx]->wall_hit_x = touch_x;
			gm->rays[idx]->wall_hit_y = touch_y;
			break ;
		}
		else
		{
			touch_x += gm->rays[idx]->x_step;
			touch_y += gm->rays[idx]->y_step;
		}
	}
	return (hit_flag);
}

int				intercept_horiz(t_game *gm, int idx)
{
	double		touch_x;
	double		touch_y;
	int			hit_flag;

	hit_flag = 0;
	touch_x = gm->rays[idx]->x_intercept;
	touch_y = gm->rays[idx]->y_intercept;
	if (gm->rays[idx]->is_up)
		touch_y--;
	while (touch_x >= 0 && touch_x <= WINDOW_WIDTH
		&& touch_y >= 0 && touch_y <= WINDOW_HEIGHT)
	{
		if (inspect_wall(gm, touch_x, touch_y))
		{
			hit_flag = 1;
			gm->rays[idx]->wall_hit_x = touch_x;
			gm->rays[idx]->wall_hit_y = touch_y;
			break ;
		}
		else
		{
			touch_x += gm->rays[idx]->x_step;
			touch_y += gm->rays[idx]->y_step;
		}
	}
	return (hit_flag);
}

void			cast_verti(t_game *gm, int idx)
{
	double		temp;
	int			hit_flag;
	int			was_hit_verti;

	hit_flag = 0;
	gm->rays[idx]->x_intercept = floor(gm->player->x / TILE_SIZE) * TILE_SIZE;
	gm->rays[idx]->x_intercept += gm->rays[idx]->is_right ? TILE_SIZE : 0;
	gm->rays[idx]->y_intercept = gm->player->y +
		(gm->rays[idx]->x_intercept - gm->player->x) * tan(gm->rays[idx]->ray_angle);
	gm->rays[idx]->x_step = TILE_SIZE;
	gm->rays[idx]->x_step *= gm->rays[idx]->is_left ? -1 : 1;
	gm->rays[idx]->y_step = gm->rays[idx]->x_step * tan(gm->rays[idx]->ray_angle);
	gm->rays[idx]->y_step *= (gm->rays[idx]->is_up && gm->rays[idx]->y_step > 0) ? -1 : 1;
	gm->rays[idx]->y_step *= (gm->rays[idx]->is_down && gm->rays[idx]->y_step < 0) ? -1 : 1;
	hit_flag = intercept_verti(gm, idx);
	temp = get_distance(gm->player->x, gm->player->y, gm->rays[idx]->wall_hit_x,
		gm->rays[idx]->wall_hit_y);
	was_hit_verti = 0;
	if (temp < gm->rays[idx]->distance && hit_flag)
	{
		gm->rays[idx]->distance = temp;
		was_hit_verti = 1;
	}
}

void			cast_horiz(t_game *gm, int idx)
{
	int			hit_flag;

	hit_flag = 0;
	gm->rays[idx]->y_intercept = floor(gm->player->y / TILE_SIZE) * TILE_SIZE;
	gm->rays[idx]->y_intercept += gm->rays[idx]->is_down ? TILE_SIZE : 0;
	gm->rays[idx]->x_intercept = gm->player->x +
		(gm->rays[idx]->y_intercept - gm->player->y) / tan(gm->rays[idx]->ray_angle);
	gm->rays[idx]->y_step = TILE_SIZE;
	gm->rays[idx]->y_step *= gm->rays[idx]->is_up ? -1 : 1;
	gm->rays[idx]->x_step = gm->rays[idx]->y_step / tan(gm->rays[idx]->ray_angle);
	gm->rays[idx]->x_step *= (gm->rays[idx]->is_left && gm->rays[idx]->x_step > 0) ? -1 : 1;
	gm->rays[idx]->x_step *= (gm->rays[idx]->is_right && gm->rays[idx]->x_step < 0) ? -1 : 1;
	hit_flag = intercept_horiz(gm, idx);
	gm->rays[idx]->distance = (hit_flag) ?
	get_distance(gm->player->x, gm->player->y, gm->rays[idx]->wall_hit_x, gm->rays[idx]->wall_hit_y)
	: INT_MAX;
}

void			cast_ray(t_game *gm, int idx)
{
	gm->rays[idx]->is_down = (gm->rays[idx]->ray_angle > 0 && gm->rays[idx]->ray_angle < M_PI);
	gm->rays[idx]->is_up = !(gm->rays[idx]->is_down);
	gm->rays[idx]->is_right = gm->rays[idx]->ray_angle
	< (0.5 * M_PI) || gm->rays[idx]->ray_angle > (1.5 * M_PI);
	gm->rays[idx]->is_left = !(gm->rays[idx]->is_right);
	cast_horiz(gm, idx);
	cast_verti(gm, idx);
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
